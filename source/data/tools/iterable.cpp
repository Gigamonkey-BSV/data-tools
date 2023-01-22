module;

#include <ranges>

export module data.tools:iterable;

namespace data {

    export template <typename X, typename elem = std::remove_const_t<decltype (*std::begin (std::declval<X> ()))>>
    concept const_iterable = std::ranges::input_range<X> && requires (const X x) {
        { *std::begin (x) } -> std::convertible_to<const elem>;
    };

    export template <typename X, typename elem = decltype (*std::declval<const X> ().begin ())>
    concept iterable = const_iterable<X, elem> && std::ranges::output_range<X, elem> && requires () {
        typename X::iterator;
    };

    // used to represent the end of a data structure.
    export template <typename X>
    struct sentinel {
        const X *Structure;
        sentinel (): Structure {} {}
        sentinel (const X &s) : Structure {&s} {}
    };

}

