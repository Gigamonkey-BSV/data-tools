export module data.tools:rotate;

export import :sequence;

namespace data {

    template <queue list, typename N> export list rotate (const list &x, N n) {
        return empty (x) || n <= 0 ? x : rotate (append (rest (x), first (x)), n - 1);
    }

}

