module;

#include <iterator>

export module data.tools:sequence_iterator;

import :sequence;
import :element;
import :iterable;

namespace data {

    // iterator capable of iterating through a sequence.
    export template <typename L>
    struct sequence_iterator {
        const L *Sequence;
        L Next;
        int Index;

        sequence_iterator (const L &s, L n, int i) : Sequence {&s}, Next {n}, Index {i} {}

        // we need this constructor in order to satisfy some
        // std concepts but it's not really good for anything.
        sequence_iterator () : Sequence {}, Next {}, Index {0} {}

        sequence_iterator &operator = (const sequence_iterator&);

        sequence_iterator operator ++ (int);
        sequence_iterator &operator ++ ();

        const element_of<L> &operator * () const;

        bool operator == (const sentinel<L> i) const;
        bool operator != (const sentinel<L> i) const;
        bool operator == (const sequence_iterator i) const;

        int operator - (const sequence_iterator& i) const;

        sequence_iterator (const L &s) : Sequence {&s}, Next {s}, Index {0} {}
    };
}

namespace std {
    export template <typename list>
    struct iterator_traits<data::sequence_iterator<list>> {
        using value_type = remove_const_t<data::element_of<list>>;
        using difference_type = int;
        using pointer = const remove_reference_t<data::element_of<list>>*;
        using reference = const data::element_of<list>&;
        using iterator_concept = input_iterator_tag;
    };
}

namespace data {

    export template <sequence L>
    inline sequence_iterator<L> &sequence_iterator<L>::operator = (const sequence_iterator& i) {
        Sequence = i.Sequence;
        Next = i.Next;
        Index = i.Index;
        return *this;
    }

    export template <sequence L>
    inline sequence_iterator<L> &sequence_iterator<L>::operator ++ () { // Prefix
        if (Sequence == nullptr || data::empty(Next)) return *this;
        return *this = sequence_iterator {*Sequence, data::rest(Next), Index + 1};
    }

    export template <sequence L>
    inline sequence_iterator<L> sequence_iterator<L>::operator ++ (int) { // Postfix
        sequence_iterator n = *this;
        ++(*this);
        return n;
    }

    export template <sequence L>
    const element_of<L> inline &sequence_iterator<L>::operator * () const {
        return data::first (Next);
    }

    export template <sequence L>
    bool inline sequence_iterator<L>::operator == (const sequence_iterator i) const {
        return Sequence == i.Sequence && Index == i.Index;
    }

    export template <sequence L>
    bool inline sequence_iterator<L>::operator == (const sentinel<L> i) const {
        return Sequence == i.Structure && Index == data::size(*Sequence);
    }

    export template <sequence L>
    bool inline sequence_iterator<L>::operator != (const sentinel<L> i) const {
        return !(*this == i);
    }

    export template <sequence L>
    int inline sequence_iterator<L>::operator - (const sequence_iterator& i) const {
        if (Sequence != i.Sequence) return 0;
        return static_cast<int> (Index) - i.Index;
    }

}
