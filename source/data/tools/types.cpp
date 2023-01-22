module;

#include <optional>
#include <variant>
#include <functional>
#include <concepts>
#include <memory>

export module data.tools:types;

namespace data {

    export template <typename X> using ptr = std::shared_ptr<X>;

    export template <typename X> using function = std::function<X>;

    export template <typename X> using maybe = std::optional<X>;

    export template <typename... X> using either = std::variant<X...>;

    export template <typename X> concept ordered = std::totally_ordered<X>;

}

