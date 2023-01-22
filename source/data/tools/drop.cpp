export module data.tools:drop;

export import :sequence;

namespace data {

    template <sequence list, typename N> export list drop (const list &x, N n) {
        return empty (x) || n == 0 ? x : drop (rest (x), n - 1);
    }

}

