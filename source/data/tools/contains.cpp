export module data.tools:contains;

export import :sequence;

namespace data {

    template <typename X, typename elem> concept has_contains_method = requires (const X &x, const elem &e) {
        { x.contains (e) } -> std::convertible_to<bool>;
    };

    template <typename list, typename elem> requires has_contains_method<X, elem>
    export bool inline contains (const list &x, const elem &e) {
        return x.contains (e);
    }

    template <typename list, typename elem> requires sequence<X, elem>
    export bool contains (const list &x, const elem &e) {
        if (empty (x)) return false;
        if (first (x) == e) return true;
        return contains (rest (x), e);
    }

}

