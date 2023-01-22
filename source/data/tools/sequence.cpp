export module data.tools:sequence;

import <concepts>
export import :empty;

namespace data {

    template <typename X> concept has_first_method = requires (const X &x) {
        { x.first () };
    };

    template <typename X> concept has_rest_method = requires (const X &x) {
        { x.rest () } -> std::convertible_to<const X&>;
    };

    template <has_first_method X> export auto inline first (const X &x) {
        return x.first ();
    }

    template <has_rest_method X> export const X inline rest (const X &x) {
        return x.rest ();
    }

    template <
        typename list,
        typename elem = std::remove_reference_v<decltype (first (std::declval<list> ())>
    > export concept sequence = requires (const list &x) {
        { empty (x) } -> std::same_as<bool>;
        { first (x) } -> std::convertible_to<elem>;
        { rest (x) } -> std::same_as<const list>;
    };

    template <typename X, typename elem> concept has_append_method = requires (const X &x, const elem &e) {
        { x.append (e) } -> std::convertible_to<const X&>;
    };

    template <typename X, typename elem> concept has_prepend_method = requires (const X &x, const elem &e) {
        { x.prepend (e) } -> std::convertible_to<const X&>;
    };

    template <typename list, typename elem> requires has_prepend_method<X, elem>
    export auto inline prepend (const list &x, const elem &e) {
        return x.prepend (e);
    }

    template <typename list, typename elem> requires has_append_method<X, elem>
    export auto inline append (const list &x, const elem &e) {
        return x.append (e);
    }

    template <
        typename list,
        typename elem = std::remove_reference_v<decltype (first (std::declval<list> ())>
    > export concept stack = requires sequence<list, elem> && std::default_initializable<list> && requires (const X &x) {
        { prepend (x, first (x)) };
    };

    template <
        typename list,
        typename elem = std::remove_reference_v<decltype (first (std::declval<list> ())>
    > export concept queue = requires sequence<list, elem> && std::default_initializable<list> && requires (const X &x) {
        { append (x, first (x)) };
    };
}

