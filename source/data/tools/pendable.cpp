module;

#include <concepts>

export module data.tools:pendable;

export import :stack;
export import :queue;

namespace data {

    // pendable means that it's either a stack or a queue.
    export template <typename Q, typename elem = std::remove_reference_t<decltype(std::declval<Q>().first())>>
    concept pendable = stack<Q, elem> || queue<Q, elem>;

}
