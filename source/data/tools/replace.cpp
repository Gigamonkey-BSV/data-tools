module;

export module data.tools:replace;

import :types;

namespace data {

    export template <typename T, typename x, typename y> struct replacement;

    export template <typename T, typename x, typename y> using replace = replacement<T, x, y>::type;

    export template <typename T, typename A> struct replacement<T, T, A> {
        using type = A;
    };

    export template <typename T, typename x, typename y> struct replacement<const T, x, y> {
        using type = const replace<T, x, y>;
    };

    export template <typename T, typename x, typename y> struct replacement<T*, x, y> {
        using type = replace<T, x, y>*;
    };

    export template <typename T, typename x, typename y> struct replacement<T&, x, y> {
        using type = replace<T, x, y>&;
    };

    export template <typename T, typename x, typename y> struct replacement<ptr<T>, x, y> {
        using type = ptr<replace<T, x, y>>;
    };

    export template <typename T, typename x, typename y> struct replacement<maybe<T>, x, y> {
        using type = maybe<replace<T, x, y>>;
    };

    export template <typename A, typename B, typename x, typename y> struct replacement<either<A, B>, x, y> {
        using type = either<replace<A, x, y>, replace<B, x, y>>;
    };

    export template <typename A, typename B, typename x, typename y>
    struct replacement<function<A (B)>, x, y> {
        using type = function<replace<A, x, y> (replace<B, x, y>)>;
    };

    export template <typename A, typename B, typename C, typename x, typename y>
    struct replacement<function<A (B, C)>, x, y> {
        using type = function<replace<A, x, y> (replace<B, x, y>, replace<C, x, y>)>;
    };

    export template <typename A, typename B, typename C, typename D, typename x, typename y>
    struct replacement<function<A (B, C, D)>, x, y> {
        using type = function<replace<A, x, y> (replace<B, x, y>, replace<C, x, y>, replace<D, x, y>)>;
    };

    export template <typename A, typename B, typename C, typename D, typename E, typename x, typename y>
    struct replacement<function<A (B, C, D, E)>, x, y> {
        using type = function<replace<A, x, y> (replace<B, x, y>, replace<C, x, y>, replace<D, x, y>, replace<E, x, y>)>;
    };

    export template <typename A, typename B, typename C, typename D, typename E, typename F, typename x, typename y>
    struct replacement<function<A (B, C, D, E, F)>, x, y> {
        using type = function<replace<A, x, y> (replace<B, x, y>, replace<C, x, y>, replace<D, x, y>, replace<E, x, y>, replace<F, x, y>)>;
    };

}
