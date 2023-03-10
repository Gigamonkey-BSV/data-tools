module;

#include <concepts>

export module data.tools:indexed;

import :types;

namespace data {

    export template <typename M, typename key, typename value = unreference<decltype (std::declval<const M> ()[std::declval<const key> ()])>>
    concept indexed = requires(const M m, const key k) {
        { m[k] } -> std::convertible_to<const value>;
    };

}
