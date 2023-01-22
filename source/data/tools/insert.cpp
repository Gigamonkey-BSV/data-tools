export module data.tools:insert;

export import :entry;

namespace data {

    template <typename X, typename E> concept has_insert_method = requires (const X &x, const E &e) {
        { x.insert (e) } -> std::convertible_to<const X&>;
    };

    template <typename X, typename E> requires has_insert_method<X, E>
    export const X insert (const X &x, const E &e) {
        return x.insert (e);
    };

    template <typename X, typename K, typename V> requires requires (const X &x, const entry<K, V> &e) {
        { insert (x, e) };
    } export const X insert (const X &x, const K &e, const V &v) {
        return insert (x, entry {e, v});
    };

}
