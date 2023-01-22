export module data.tools:container;

export import :size;
export import :contains;
export import :remove;

namespace data {

    template <typename X, typename elem> export concept container = requires (const X &x) {
        { size (x) } -> std::convertible_to<math::size>;
    } && requires (const X &x, const elem &e) {
        { contains (x, e) } -> std::same_as<bool>;
        { remove (x, e) } -> std::convertible_to<const X&>;
    }

}
