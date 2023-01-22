export module data.tools:take;

export import :sequence;
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
        if (n <= 0 || empty (x)) return reverse (taken);
        return join_queue (rest (a), prepend (b, first (a)));
    }

    template <pendable list>
    export list inline join (const list &a, const list &b) {
        if constexpr (queue<list>) return join_queue (a, b);
        else return reverse (join_stack (a, reverse (b)));
    }
}
