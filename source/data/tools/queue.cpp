module;

#include <concepts>

export module data.tools:queue;

export import :sequence;

namespace data {

    template <typename list, typename elem> concept has_append_method = requires (const list &x, const elem &e) {
        { x.append (e) } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_append_method<list, elem>
    auto inline append (const list &x, const elem &e) {
        return x.append (e);
    }

    export template <
        typename list,
        typename elem = std::remove_reference_t<decltype (first (std::declval<list> ()))>
    > concept queue = sequence<list, elem> && std::default_initializable<list> && requires (const list &x) {
        { append (x, first (x)) };
    };
}

