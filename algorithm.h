#pragma once
#include "cstdlib/cstdint.h"

namespace firefly::std {
    template <class ForwardIt, class T>
    void fill(ForwardIt first, const ForwardIt last, const T& value) {
        for (; first != last; ++first) {
            *first = value;
        }
    }

    template <class InputIt, class OutputIt>
    OutputIt copy(InputIt first, const InputIt last, OutputIt d_first) {
        while (first != last) {
            *d_first++ = *first++;
        }
        return d_first;
    }

    template <typename InputIt, typename OutputIt, typename UnaryPredicate>
    OutputIt copy_if(InputIt begin, const InputIt end, OutputIt write,
                     UnaryPredicate func) {
        while (begin < end) {
            if (! func(*begin)) {
                begin++;
                continue;
            }
            *(write++) = *(begin++);
        }
        return write;
    }

    template <typename InputIt>
    InputIt max_element(InputIt first, InputIt last) {
        if (first == last)
            return last;

        InputIt largest = first;
        ++first;
        for (; first != last; ++first) {
            if (*largest < *first) {
                largest = first;
            }
        }
        return largest;
    }

    template <typename InputIt, typename UnaryPredicate>
    size_t count_if(InputIt first, const InputIt last, 
        UnaryPredicate func) {
        size_t count = 0;

        for (; first != last; first++) {
            if (func(*first))
                count++;
        }

        return count;
    }

    template <typename InputIt, typename T> size_t count(InputIt first, const InputIt last,
        const T& lval) {
        size_t count = 0;
        
        for (; first != last; first++) {
            if (*first == lval)
                count++;
        }

        return count;
    }

    /*
    template <class RandomIt>
    void sort(RandomIt first, RandomIt last) {
        if (first < last) {
            int partitionIndex = partition(first, last);
            (void) partitionIndex;
        }
    }
     */

    /*
    template <class RandomIt, class Compare>
    void sort(RandomIt first, RandomIt last, Compare comp) {

    }
     */
} // namespace firefly::std
