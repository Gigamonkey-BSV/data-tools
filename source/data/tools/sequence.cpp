module;

#include <type_traits>
#include <concepts>
#include <utility>

export module data.tools:sequence;

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
        typename elem = std::remove_reference_t<decltype (first (std::declval<list> ()))>
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

}

