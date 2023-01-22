export module data.tools:limit;

import <concepts>;

namespace data::math {

    template <std::unsigned_integral X> export struct unsigned_limit {
        unsigned_limit (X x);
        static unsigned_limit infinite ();
        bool operator == (unsigned_limit<X>);
        bool operator < (unsigned_limit<X>);
        bool operator > (unsigned_limit<X>);
        bool operator <= (unsigned_limit<X>);
        bool operator >= (unsigned_limit<X>);
        bool operator + (unsigned_limit<X>);
        bool operator - (unsigned_limit<X>);
        bool operator * (unsigned_limit<X>);
        bool operator / (unsigned_limit<X>);
    };

    template <std::signed_integral X> export struct signed_limit {
        signed_limit (X x);
        static signed_limit infinite ();
        bool operator == (signed_limit<X>);
        bool operator < (signed_limit<X>);
        bool operator > (signed_limit<X>);
        bool operator <= (signed_limit<X>);
        bool operator >= (signed_limit<X>);
        bool operator + (signed_limit<X>);
        bool operator - (signed_limit<X>);
        bool operator * (signed_limit<X>);
        bool operator / (signed_limit<X>);
    };

    export size = unsigned_limit<size_t>;

}
