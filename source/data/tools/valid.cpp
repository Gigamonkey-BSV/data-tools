module;

#include <concepts>

export module data.tools:valid;

import :types;

namespace data {

    template <typename X> concept has_valid_method = requires (const X &x) {
        { x.valid () } -> std::same_as<bool>;
    };

    export template <typename X> bool inline valid (const X &x) {
        return true;
    }

    export template <typename X> bool inline valid (const X *x) {
        return x != nullptr;
    }

    export template <typename X> bool inline valid (const ptr<X> x) {
        return x != nullptr;
    }

    export template <has_valid_method X> bool inline valid (const X &x) {
        return x.valid ();
    }

    export template <has_valid_method X> bool inline valid (const X *x) {
        return x == nullptr ? false : x->valid ();
    }

    export template <has_valid_method X> bool inline valid (const ptr<X> x) {
        return x == nullptr ? false : x->valid ();
    }
}

