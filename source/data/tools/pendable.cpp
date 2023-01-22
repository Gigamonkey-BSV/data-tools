export module data.tools:pendable;

import :sequence;

namespace data {

    template <typename Q, typename elem = std::remove_reference_t<decltype(std::declval<Q>().first())>>
    export concept pendable = stack<Q, elem> || queue<Q, elem>;

}
