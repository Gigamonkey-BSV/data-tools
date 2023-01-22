export module data.tools:empty;

import :size;

namespace data {

    template <typename X> concept has_empty_method = requires (const X &x) {
        { x.empty () } -> std::same_as<bool>;
    };

    template <has_empty_method X> export bool inline empty (const X &x) {
        return x.empty ();
    }

    template <typename X> requires requires (const X &x) {
        { size (x) };
    } export bool inline empty (const X &x) {
        return size (x) == 0;
    }
}
