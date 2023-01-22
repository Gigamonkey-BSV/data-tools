module;

#include <concepts>

export module data.tools:stack;

export import :sequence;

namespace data {

    template <typename list, typename elem> concept has_prepend_method = requires (const list &x, const elem &e) {
        { x.prepend (e) } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_prepend_method<list, elem>
    auto inline prepend (const list &x, const elem &e) {
        return x.prepend (e);
    }

    export template <
        typename list,
        typename elem = std::remove_reference_t<decltype (first (std::declval<list> ()))>
    > concept stack = sequence<list, elem> && std::default_initializable<list> && requires (const list &x) {
        { prepend (x, first (x)) };
    };

}

