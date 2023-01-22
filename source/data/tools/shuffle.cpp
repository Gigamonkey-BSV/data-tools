export module data.tools:shuffle;

export import :sequence;
import :rotate;

namespace data {

    template <typename engine, sequence L>
    export L shuffle (engine& e, const L x, size_t n = 1, L q = {}) {
        return empty (x) ? q : shuffle (e, rest (x), n + 1,
            rotate (append (q, first (x)), std::uniform_int_distribution<int> (0, n) (e));
    }
}

