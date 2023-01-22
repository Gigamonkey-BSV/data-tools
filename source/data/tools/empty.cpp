module;

#include <concepts>

export module data.tools:empty;

import :types;

namespace data {

    template <typename X> concept has_empty_method = requires (const X &x) {
        { x.empty () } -> std::same_as<bool>;
    };

    export template <has_empty_method X> bool inline empty (const X &x) {
        return x.empty ();
    }

    export template <typename X> bool inline empty (const X *x) {
        return x != nullptr;
    }

    export template <typename X> bool inline empty (const ptr<X> x) {
        return x != nullptr;
    }
}
