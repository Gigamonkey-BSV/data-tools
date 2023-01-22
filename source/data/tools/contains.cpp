module;

#include <concepts>

export module data.tools:contains;

import :sequence;

namespace data {

    template <typename list, typename elem> concept has_contains_method = requires (const list &x, const elem &e) {
        { x.contains (e) } -> std::convertible_to<bool>;
    };

    export template <typename list, typename elem> requires has_contains_method<list, elem>
    bool inline contains (const list &x, const elem &e) {
        return x.contains (e);
    }

}

