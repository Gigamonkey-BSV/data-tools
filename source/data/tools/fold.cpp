export module data.tools:fold;

export import :sequence;

namespace data {

    export template <typename x, typename f, sequence l>
    x fold (f fun, x init, l ls) {
        if (empty (ls)) return init;
        return fold (fun, fun (init, first (ls)), rest (ls));
    }

    export template <typename x, typename f, typename N>
    x nest (f fun, N rounds, x init) {
        if (rounds == 0) return init;
        return nest (fun, fun (init), rounds - 1);
    }

    export template <typename x, typename f, sequence l>
    x reduce (f fun, l ls) {
        if (empty (ls)) return x {};
        return fun (first (ls), reduce<x> (fun, rest (ls)));
    }

}

