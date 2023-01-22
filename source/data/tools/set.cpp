module;

#include <concepts>

export module data.tools:set;
import :container;
import :insert;
import :values;

namespace data {

    export template <typename X, typename element>
    concept set = container<X, element> && std::default_initializable<X> && requires (const X &x, const element &e) {
        { insert (x, e) } -> std::convertible_to<const X&>;
    };

    export template <typename X, typename element = decltype(std::declval<X> ().values ().first ())>
    concept ordered_set = set<const X, element> && std::totally_ordered<element> && requires (const X &x) {
        { values (x) } -> sequence<element>;
    };

}

