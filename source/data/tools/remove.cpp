module;

#include <concepts>

export module data.tools:remove;

import :types;
import :pendable;
import :reverse;

namespace data {

    template <typename list, typename elem> concept has_remove_method = requires (const list &x, const elem &e) {
        { x.remove () } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_remove_method<list, elem>
    auto inline remove (const list &x, const elem &e) {
        return x.remove (e);
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
}
