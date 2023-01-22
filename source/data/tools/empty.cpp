module;

#include <concepts>

export module data.tools:empty;

import :size;

namespace data {

    template <typename X> concept has_empty_method = requires (const X &x) {
        { x.empty () } -> std::same_as<bool>;
    };

    export template <has_empty_method X> bool inline empty (const X &x) {
        return x.empty ();
    }

    // if size is defined, then empty can be defined in terms of it.
    export template <typename X> requires requires (const X &x) {
        { size (x) };
    } bool inline empty (const X &x) {
        return size (x) == 0;
    }
}
