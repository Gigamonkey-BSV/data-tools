export module data.tools:take;

export import :sequence;
import :pendable;

namespace data {

    template <stack list>
    const list reverse_stack (const list &x, const list &reversed = {}) {
        if (empty (x)) return reversed;
        return reverse_stack (rest (x), prepend (reversed, first (x)));
    }

    template <queue list>
    const list reverse_queue (const list &x) {
        if (empty (x)) return x;
        return append (reverse_queue (rest (x)), first (x));
    }

    template <pendable list>
    export list inline reverse (const list &x) {
        if constexpr (queue<list>) return reverse_queue (x);
        else return reverse_stack (x);
    }
}

