module;

#include <concepts>

export module data.tools:container;

export import :size;
export import :contains;
export import :remove;

namespace data {

    export template <typename X, typename elem> concept container = requires (const X &x) {
        { size (x) } -> std::convertible_to<size_t>;
    } && requires (const X &x, const elem &e) {
        { contains (x, e) } -> std::same_as<bool>;
        { remove (x, e) } -> std::convertible_to<const X&>;
    };

}
