module;

#include <concepts>

export module data.tools:bi_tree_sequence;

import :empty;
import :bi_tree;
import :sequence;

namespace data {

    template <typename Tree, typename Stack>
    requires bi_tree<Tree> && stack<Stack, Tree>
    struct bi_tree_sequence {
        Stack Prev;

        bi_tree_sequence () : Prev {} {}
        bi_tree_sequence (const Tree &t) : Prev {t} {}

        auto first () const {
            return root (data::first (Prev));
        }

        bi_tree_sequence (const Stack p) : Prev {p} {}
    };

    export template <typename Tree, typename Stack>
    struct bi_tree_sequence_infix final : bi_tree_sequence<Tree, Stack> {
        bi_tree_sequence_infix (const Tree &t) : bi_tree_sequence<Tree, Stack> {t} {
            go_left ();
        }

        bi_tree_sequence_infix rest () const {
            if (empty (this->Prev) || empty (first (this->Prev)) || empty (right (first (this->Prev)))) return *this;

            return {go_left (prepend (data::rest (this->Prev), right (first (this->Prev))))};
        }

        static Stack go_left (const Stack p) {
            if (empty (p) || empty (first (p)) || empty (left (first (p)))) return p;
            return go_left (prepend (p, left (first (p))));
        }

    private:
        bi_tree_sequence_infix (const Stack p) : bi_tree_sequence<Tree, Stack> {p} {}
    };

    export template <typename Tree, typename Stack>
    struct bi_tree_sequence_prefix final : bi_tree_sequence<Tree, Stack> {
        bi_tree_sequence_prefix (const Tree &t) : bi_tree_sequence<Tree, Stack> {t} {}

        static Stack go_right (const Stack p) {
            if (empty (p)) return p;

            auto t = first (p);
            if (empty (t)) return go_right (data::rest (p));

            if (empty (left (t))) {
                if (empty (right (t))) return go_right (data::rest (p));
                else return prepend (data::rest (p), right (t));
            }

            if (empty (right (t))) return prepend (data::rest (p), left (t));

            return prepend (prepend (data::rest (p), right (t)), left (t));
        }

        bi_tree_sequence_prefix rest () const {
            return {go_right (this->Prev)};
        }

    private:
        bi_tree_sequence_prefix (const Stack p) : bi_tree_sequence<Tree, Stack> {p} {}
    };


}
