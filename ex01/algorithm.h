#ifndef FT_ALGORITHM_H
#define FT_ALGORITHM_H

#include <iterator>

namespace ft {

    template<class T>
    void swap(T &a, T &b) {
        T tmp(b);
        b = a;
        a = tmp;
    }

    template<class ForwardIt1, class ForwardIt2>
    void iter_swap(ForwardIt1 a, ForwardIt2 b) {
        swap(*a, *b);
    }

    template<class RandomAccessIterator>
    void reverse_impl(
        RandomAccessIterator first, RandomAccessIterator last,
        std::random_access_iterator_tag /*unused*/) {
        if (first != last) {
            for (; first < --last; first++) {
                ft::iter_swap(first, last);
            }
        }
    }

    template<class BidirectionalIterator>
    void reverse(BidirectionalIterator first, BidirectionalIterator last) {
        reverse_impl(
            first, last, typename BidirectionalIterator::iterator_category());
    }

}

#endif
