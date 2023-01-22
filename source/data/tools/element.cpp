module;

#include <concepts>

export module data.tools:element;

export import :sequence;

namespace data {

    // used to find the element of a sequence or container.
    export template <typename X> struct element;

    export template <sequence X>
    struct element<X> {
        using type = std::remove_reference_t<decltype(std::declval<X>().first())>;
    };

    export template <typename X> using element_of = element<X>::type;

}

export template <data::sequence X, data::sequence Y> requires std::equality_comparable_with<data::element_of<X>, data::element_of<Y>>
bool inline operator == (const X &a, const Y &b) {
    return (void*)&a == (void*)&b ? true :
        data::empty (a) && data::empty (b) ? true :
            data::empty (a) || data::empty (b) ? false :
                data::first (a) != data::first (b) ? false :
                    data::rest (a) == data::rest (b);
}

