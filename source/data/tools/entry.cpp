module;

#include <concepts>

export module data.tools:entry;

import :valid;

namespace data {

    template <typename K, typename V>
    requires std::totally_ordered<K> && std::default_initializable<K> && std::default_initializable<V>
    struct entry {
        K Key;
        V Value;

        entry (const K k, V v) : Key (k), Value (v) {}

        // an invalid instance must exist for type value.
        entry (const K k) : Key (k), Value {} {}

        bool valid () const {
            return data::valid (Key) && data::valid (Value);
        }

        const K key () const {
            return Key;
        }

        V value () const {
            return Value;
        }

        V operator [] (const K k) {
            if (Key == k) return Value;
            return V{};
        }

        bool operator == (const entry& e) const {
            return Key == e.Key && Value == e.Value;
        }

        bool operator < (const entry& e) const {
            return Key < e.Key;
        }

        bool operator > (const entry& e) const {
            return Key > e.Key;
        }

        bool operator <= (const entry& e) const {
            return Key < e.Key;
        }

        bool operator >= (const entry& e) const {
            return Key >= e.Key;
        }
    };

}
