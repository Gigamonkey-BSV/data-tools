module;

#include <random>

export module data.tools:shuffle;

import :sequence;

namespace data {

    export template <typename engine, sequence list>
    list shuffle (engine& e, const list x, size_t n = 1, list q = {}) {
        return empty (x) ? q : shuffle (e, rest (x), n + 1,
            rotate (append (q, first (x)), std::uniform_int_distribution<int> (0, n) (e)));
    }
}

