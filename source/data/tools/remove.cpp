export module data.tools:remove;

import :pendable;
import :reverse;

namespace data {

    template <typename X, typename elem> concept has_remove_method = requires (const X &x, const elem &e) {
        { x.remove () } -> std::convertible_to<const X&>;
    };

    template <typename list, typename elem> requires has_remove_method<X, elem>
    export auto inline remove (const list &x, const elem &e) {
        return x.remove (e);
    }

    template <typename list, typename elem> requires stack<list, elem>
    const list remove_pendable (
        function<const list (const list &, const elem &)> pend,
        const list &x, const elem &e, const list &y = {}) {
        return (empty (x)) ? y : e == first (x) ?
            remove_pendable (pend, rest (x), e, y) : remove_pendable (pend, rest (x), e, pend (y, e));
    }

    template <typename list, typename elem> requires pendable<list, elem>
    export const list inline remove (const list &x, const elem &e) {
        if constexpr (queue<list>) return remove_pendable (append, x, e);
        else return reverse (remove_pendable (prepend, x, e));
    }
}
