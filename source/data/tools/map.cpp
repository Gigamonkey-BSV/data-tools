module;

#include <concepts>

export module data.tools:map;

import :container;
import :indexed;
import :entry;

namespace data {

    export template <typename M, typename key, typename value = unreference<decltype (std::declval<const M> ()[std::declval<const key> ()])>>
    concept map = container<M, entry<key, value>> && indexed<M, key, value>;

}

