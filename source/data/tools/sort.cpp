export module data.tools:sort;

import :types;
import :element;
import :sequence;

namespace data {

    export template <sequence list> requires ordered<element_of<list>>
    bool sorted (const list &x) {
        if (empty (x)) return true;

        struct sorted_inner {
            bool operator() (const list &y, const element_of<list> &e) {
                if (empty (y)) return true;
                auto a = first (y);
                if (a < e) return false;
                return sorted_inner {} (rest (y), first (y));
            }
        };

        sorted_inner {} (rest (x), first (x));
    }

    template <queue list> requires ordered<element_of<list>>
    list merge_pendable (
        function<const list (const list &, const element_of<list> &)> pend,
        const list &a, const list &b, const list &n = {}) {
        if (empty (a) && empty (b)) return n;
        if (empty (a)) return merge_pendable (pend, a, rest (b), pend (n, first (b)));
        if (empty (b)) return merge_pendable (pend, rest (a), b, pend (n, first (a)));
        return first (a) < first (b) ?
            merge_queue (pend, rest (a), b, pend (n, first (a))):
            merge_queue (pend, a, rest (b), pend (n, first (b)));
    }

    export template <pendable list>
    list inline merge (const list &a, const list &b) {
        if constexpr (queue<list>) return merge_pendable (append, a, b);
        else return reverse (merge_pendable (prepend, a, b));
    }

    export template <pendable list> requires ordered<element_of<list>>
    list merge_sort(const list &x) {
        auto z = size (x);
        if (z < 2) return x;

        auto half = z / 2;
        return merge (merge_sort (take (x, half)), merge_sort (drop (x, half)));
    }

}
