export module data.tools:join;

import :pendable;
import :reverse;

namespace data {

    template <queue list>
    list inline join_queue (const list &a, const list &b) {
        if (empty (b)) return a;
        return join_queue (append (a, first (b)), rest (b));
    }

    template <stack list>
    list inline join_stack (const list &a, const list &b) {
        if (empty (a)) return b;
        return join_stack (rest (a), prepend (b, first (a)));
    }

    export template <pendable list>
    list inline join (const list &a, const list &b) {
        if constexpr (queue<list>) return join_queue (a, b);
        else return reverse (join_stack (a, reverse (b)));
    }
}
