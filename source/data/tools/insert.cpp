module;

#include <concepts>

export module data.tools:insert;

import :entry;

namespace data {

    template <typename X, typename E> concept has_insert_method = requires (const X &x, const E &e) {
        { x.insert (e) } -> std::convertible_to<const X&>;
    };

    export template <typename X, typename E> requires has_insert_method<X, E>
    const X insert (const X &x, const E &e) {
        return x.insert (e);
    };

    export template <typename X, typename K, typename V> requires requires (const X &x, const entry<K, V> &e) {
        { insert (x, e) };
    } const X insert (const X &x, const K &e, const V &v) {
        return insert (x, entry {e, v});
    };

}
