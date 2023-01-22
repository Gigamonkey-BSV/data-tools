export module data.tools:values;

import :sequence;
import :container;

namespace data {

    template <typename X, typename element>
    concept has_values_method = requires (X x) {
        { x.values () } -> sequence<element>;
    };

    export template <typename V, typename X, typename E> requires sequence<V, E> && container<X, E>
    V inline values (const X &x) {
        return x.values ();
    }
}
