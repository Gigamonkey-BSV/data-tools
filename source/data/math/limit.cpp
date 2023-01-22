module;

#include <concepts>

export module data.tools:limit;

namespace data::math {

    export template <std::unsigned_integral X> struct unsigned_limit {
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

    export template <std::signed_integral X> struct signed_limit {
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
}
