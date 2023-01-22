module;

#include <concepts>

export module data.tools:remove;

namespace data {

    template <typename list, typename elem> concept has_remove_method = requires (const list &x, const elem &e) {
        { x.remove () } -> std::convertible_to<const list&>;
    };

    export template <typename list, typename elem> requires has_remove_method<list, elem>
    auto inline remove (const list &x, const elem &e) {
        return x.remove (e);
    }
}
