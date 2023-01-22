module;

#include <type_traits>
#include <concepts>
#include <utility>

export module data.tools:sequence;

import :types;
export import :empty;

namespace data {

    template <typename X> concept has_first_method = requires (const X &x) {
        { x.first () };
    };

    template <typename X> concept has_rest_method = requires (const X &x) {
        { x.rest () } -> std::convertible_to<const X&>;
    };

    export template <has_first_method X> auto inline first (const X &x) {
        return x.first ();
    }

    export template <has_rest_method X> const X inline rest (const X &x) {
        return x.rest ();
    }

    export template <
        typename list,
        typename elem = unreference<decltype (first (std::declval<list> ()))>
    > concept sequence = requires (const list &x) {
        { empty (x) } -> std::same_as<bool>;
        { first (x) } -> std::convertible_to<elem>;
        { rest (x) } -> std::same_as<const list>;
    };

    export template <typename list, typename elem> requires sequence<list, elem>
    std::size_t size (const list &x, std::size_t n = 0) {
        if (empty (x)) return n;
        return size (rest (x), n + 1);
    }

    export template <typename list, typename elem> requires sequence<list, elem>
    bool contains (const list &x, const elem &e) {
        if (empty (x)) return false;
        if (first (x) == e) return true;
        return contains (rest (x), e);
    }

    export template <sequence list, typename N> list drop (const list &x, N n) {
        return empty (x) || n == 0 ? x : drop (rest (x), n - 1);
    }

    template <typename list, typename elem> concept has_prepend_method = requires (const list &x, const elem &e) {
        { x.prepend (e) } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_prepend_method<list, elem>
    auto inline prepend (const list &x, const elem &e) {
        return x.prepend (e);
    }

    export template <
        typename list,
        typename elem = unreference<decltype (first (std::declval<list> ()))>
    > concept stack = sequence<list, elem> && std::default_initializable<list> && requires (const list &x) {
        { prepend (x, first (x)) };
    };

    template <typename list, typename elem> concept has_append_method = requires (const list &x, const elem &e) {
        { x.append (e) } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_append_method<list, elem>
    auto inline append (const list &x, const elem &e) {
        return x.append (e);
    }

    export template <
        typename list,
        typename elem = unreference<decltype (first (std::declval<list> ()))>
    > concept queue = sequence<list, elem> && std::default_initializable<list> && requires (const list &x) {
        { append (x, first (x)) };
    };

    export template <queue list, typename N> list rotate (const list &x, N n) {
        return empty (x) || n <= 0 ? x : rotate (append (rest (x), first (x)), n - 1);
    }

    // pendable is either a stack or a queue.
    template <typename Q, typename elem = unreference<decltype (first (std::declval<Q> ()))>>
    concept pendable = stack<Q, elem> || queue<Q, elem>;

    template <stack list>
    const list reverse_stack (const list &x, const list &reversed = {}) {
        if (empty (x)) return reversed;
        return reverse_stack (rest (x), prepend (reversed, first (x)));
    }

    template <queue list>
    const list reverse_queue (const list &x) {
        if (empty (x)) return x;
        return append (reverse_queue (rest (x)), first (x));
    }

    export template <pendable list>
    list inline reverse (const list &x) {
        if constexpr (queue<list>) return reverse_queue (x);
        else return reverse_stack (x);
    }

    template <typename list, typename elem> requires pendable<list, elem>
    const list remove_pendable (
        function<const list (const list &, const elem &)> pend,
        const list &x, const elem &e, const list &y = {}) {
        return (empty (x)) ? y : e == first (x) ?
            remove_pendable (pend, rest (x), e, y) : remove_pendable (pend, rest (x), e, pend (y, e));
    }

    export template <typename list, typename elem> requires pendable<list, elem>
    const list inline remove (const list &x, const elem &e) {
        if constexpr (queue<list>) return remove_pendable (append, x, e);
        else return reverse (remove_pendable (prepend, x, e));
    }

    template <queue list, typename N>
    list inline take_queue (const list &x, N n, const list &taken = {}) {
        if (n <= 0 || empty (x)) return taken;
        return take_queue (rest (x), n - 1, append (taken, first (n)));
    }

    template <stack list, typename N>
    list inline take_stack (const list &x, N n, const list &taken = {}) {
        if (n <= 0 || empty (x)) return taken;
        return take_stack (rest (x), n - 1, prepend (taken, first (n)));
    }

    export template <pendable list, typename N>
    list inline take (const list &x, N n) {
        if constexpr (queue<list>) return take_queue (x, n);
        else return reverse (take_stack (x, n));
    }

    template <queue list>
    list inline join_queue (const list &a, const list &b) {
        if (empty (b)) return a;
        return join_queue (append (a, first (b)), rest (b));
    }

    template <stack list>
    list inline join_stack (const list &a, const list &b) {
        if (empty (a)) return b;
        return join_stack (rest (a), prepend (b, first (a)));
    }

    export template <pendable list>
    list inline join (const list &a, const list &b) {
        if constexpr (queue<list>) return join_queue (a, b);
        else return reverse (join_stack (a, reverse (b)));
    }

}

