export module data.tools:bi_tree;

namespace data {

    template <typename X> export concept has_root_method = requires (const X &x) {
        { x.root () };
    };

    template <typename X> export concept has_left_method = requires (const X &x) {
        { x.left () } -> std::convertible_to<const X&>;
    };

    template <typename X> export concept has_right_method = requires (const X &x) {
        { x.right () } -> std::convertible_to<const X&>;
    };
}
