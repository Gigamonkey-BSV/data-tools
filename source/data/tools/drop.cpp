export module data.tools:drop;

export import :sequence;

namespace data {

    export template <sequence list, typename N> list drop (const list &x, N n) {
        return empty (x) || n == 0 ? x : drop (rest (x), n - 1);
    }

}

