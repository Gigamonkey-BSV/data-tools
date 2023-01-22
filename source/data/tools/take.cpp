export module data.tools:take;

import :pendable;
import :reverse;

namespace data {

    template <queue list, typename N>
    list inline take_queue (const list &x, N n, const list &taken = {}) {
        if (n <= 0 || empty (x)) return taken;
        return take_queue (rest (x), n - 1, append (taken, first (n)));
    }

    template <stack list, typename N>
    list inline take_stack (const list &x, N n, const list &taken = {}) {
        if (n <= 0 || empty (x)) return taken;
        return take_stack (rest (x), n - 1, prepend (taken, first (n)));
    }

    export template <pendable list, typename N>
    list inline take (const list &x, N n) {
        if constexpr (queue<list>) return take_queue (x, n);
        else return reverse (take_stack (x, n));
    }
}


