module;

export module data.tools:function;

import :types;

namespace data {

    template <typename n, typename a, typename... args>
    function<n (args...)> inline curry (function<n (a, args...)> f, a va) {
        return [f, va] (args... z) -> n {
            return f (va, z...);
        };
    }

    template <typename n, typename a, typename b, typename... args>
    function<n (args...)> inline curry (function<n (a, b, args...)> f, a va, b vb) {
        return [f, va, vb] (args... z) -> n {
            return f (va, vb, z...);
        };
    }

    template <typename n, typename a, typename b, typename c, typename... args>
    function<n (args...)> inline curry (function<n (a, b, c, args...)> f, a va, b vb, c vc) {
        return [f, va, vb, vc] (args... z) -> n {
            return f (va, vb, vc, z...);
        };
    }

    template <typename n, typename a, typename b, typename c, typename d, typename... args>
    function<n (args...)> inline curry (function<n (a, b, c, d, args...)> f, a va, b vb, c vc, d vd) {
        return [f, va, vb, vc, vd] (args... z) -> n {
            return f (va, vb, vc, vd, z...);
        };
    }

    template <typename n, typename a, typename b, typename c, typename d, typename e, typename... args>
    function<n (args...)> inline curry (function<n (a, b, c, d, e, args...)> f, a va, b vb, c vc, d vd, e ve) {
        return [f, va, vb, vc, vd, ve] (args... z) -> n {
            return f (va, vb, vc, vd, ve, z...);
        };
    }

}
