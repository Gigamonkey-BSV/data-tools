module;

#include <concepts>

export module data.tools:bi_tree;

import :types;
import :empty;
import :container;

namespace data {

    template <typename X> concept has_root_method = requires (const X &x) {
        { x.root () };
    };

    template <typename X> concept has_left_method = requires (const X &x) {
        { x.left () } -> std::convertible_to<const X&>;
    };

    template <typename X> concept has_right_method = requires (const X &x) {
        { x.right () } -> std::convertible_to<const X&>;
    };

    export template <has_root_method X> auto inline root (const X &x) {
        return x.root ();
    }

    export template <has_left_method X> const auto inline left (const X &x) {
        return x.left ();
    }

    export template <has_right_method X> const auto inline right (const X &x) {
        return x.right ();
    }

    template <typename tree, typename element>
    concept has_bi_tree_constructor = requires (element e, tree r, tree l) {
        { tree {e, r, l} };
    } && requires (element e) {
        { tree {e} };
    };

    export template <typename tree, typename element = unreference<decltype (std::declval<const tree> ().root ())>>
    concept bi_tree = container<tree, element> && has_bi_tree_constructor<tree, element> && requires (const tree &tr) {
        { root (tr) } -> std::convertible_to<const element&>;
        { left (tr) } -> std::convertible_to<const tree&>;
        { right (tr) } -> std::convertible_to<const tree&>;
    };

    // there are two ways of ordering the elements of a tree
    // depending on the type of data structure we want. The
    // root may go between the two branches, which we call
    // the infix ordering, or it may be before both branches,
    // which we call the prefix ordering.
    template <typename tree, typename P>
    void for_each_tree_infix (const tree &t, P f) {
        if (empty(t)) return;
        for_each_infix (left (t), f);
        f (root (t));
        for_each_infix (right (t), f);
    }

    template <typename tree, typename P>
    void for_each_tree_prefix (const tree &t, P f) {
        if (empty (t)) return;
        f (root (t));
        for_each_prefix (left (t), f);
        for_each_prefix (right (t), f);
    }

    // a node that could be used to make a tree.
    template <typename value, typename tree>
    struct tree_node final {
        value Value;
        tree Left;
        tree Right;
        tree_node(const value& v, tree l, tree r) : Value {v}, Left {l}, Right {r} {}
    };

}
