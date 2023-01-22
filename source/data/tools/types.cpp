export module data.tools:types;

import <optional>;
import <variant>;
import <function>;
import <concepts>;

namespace data {

    template <typename X> export using ptr = std::shared_ptr<X>;

    template <typename X> export using function = std::function<X>;

    template <typename X> export using maybe = std::optional<X>;

    template <typename... X> export using either = std::variant<X...>;

    template <typename X> export concept ordered = std::totally_ordered<X>;

}

