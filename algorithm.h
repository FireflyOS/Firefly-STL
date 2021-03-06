#pragma once

namespace firefly::std {
    template<class ForwardIt, class T>
    void fill(ForwardIt first, const ForwardIt last, const T &value) {
        for (; first != last; ++first) {
            *first = value;
        }
    }

    template<class InputIt, class OutputIt>
    OutputIt copy(InputIt first, const InputIt last, OutputIt d_first) {
        while (first != last) {
            *d_first++ = *first++;
        }
        return d_first;
    }

    template<typename InputIt, typename OutputIt, typename UnaryPredicate>
    OutputIt copy_if(InputIt begin, const InputIt end, OutputIt write, UnaryPredicate func) {
        while (begin < end) {
            if (!func(*begin)) {
                continue;
            }
            *(write++) = *(begin++);
        }
        return write;
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
}  // namespace firefly::std
