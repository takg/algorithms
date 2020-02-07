#pragma once

template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    while(first != last) {
        if (!p(*first)) {
            break;
        }
        ++first;
    }

    if (first != last) {
        for (ForwardIt it = std::next(first); it != last; ++it) {
            if (p(*it)) {
                std::iter_swap(it, first);
                ++first;
            }
        }
    }

    return first;
}
