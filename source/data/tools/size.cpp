module;

#include <concepts>

export module data.tools:size;

import :limit;

namespace data {

    export using size_t = math::unsigned_limit<std::size_t>;

    template <typename X> concept has_size_method = requires (const X &x) {
        { x.size () } -> std::convertible_to<size_t>;
    };

    export template <has_size_method X> auto inline size (const X &x) {
        return x.size ();
    }
}
