export module data.tools:valid;

namespace data {

    template <typename X> concept has_valid_method = requires (const X &x) {
        { x.valid () } -> std::same_as<bool>;
    };

    template <typename X> export bool inline valid (const X &x) {
        return true;
    }

    template <typename X> export bool inline valid (const X *x) {
        return x != nullptr;
    }

    template <typename X> export bool inline valid (const ptr<X> x) {
        return x != nullptr;
    }

    template <has_valid_method X> export bool inline valid (const X &x) {
        return x.valid ();
    }

    template <has_valid_method X> export bool inline valid (const X *x) {
        return x == nullptr ? false : x->valid ();
    }

    template <has_valid_method X> export bool inline valid (const ptr<X> x) {
        return x == nullptr ? false : x->valid ();
    }
}

