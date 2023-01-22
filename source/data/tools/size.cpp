export module data.tools:size;

import :limit;
import :sequence;

namespace data {

    template <typename X> concept has_size_method = requires (const X &x) {
        { x.size () } -> std::convertible_to<math::size>;
    };

    template <has_size_method X> export auto inline size (const X &x) {
        return x.size ();
    }

    template <typename list, typename elem> requires sequence<X, elem>
    export bool size (const list &x, size_t n = 0) {
        if (empty (x)) return n;
        return size (rest (x), n + 1);
    }
}
