export module data.tools:rotate;

export import :queue;

namespace data {

    export template <queue list, typename N> list rotate (const list &x, N n) {
        return empty (x) || n <= 0 ? x : rotate (append (rest (x), first (x)), n - 1);
    }

}

