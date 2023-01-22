export module data.tools:take;

export import :sequence;
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
        if (n <= 0 || empty (x)) return reverse (taken);
        return take_stack (rest (x), n - 1, prepend (taken, first (n)));
    }

    template <pendable list, typename N>
    export list inline take (const list &x, const elem &e) {
        if constexpr (queue<list, elem>) return take_queue (x);
        else return take_stack (x);
    }
}


