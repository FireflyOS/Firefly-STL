#pragma once

#include "type_traits.h"

namespace firefly::std {
    template<typename T>
    constexpr remove_reference_t<T> &&move(T &&value) noexcept {
        return static_cast<
                remove_reference_t<T> &&>(value);
    };

    template<typename T>
    constexpr T &&forward(typename remove_reference<T>::type &__t) noexcept {
        return static_cast<T &&>(__t);
    }

    template<typename T>
    constexpr T &&forward(typename remove_reference<T>::type &&__t) noexcept {
        return static_cast<T &&>(__t);
    }

    // Pair implementation.
    template<typename T1, class T2>
    struct pair {
        constexpr pair() {};

        constexpr pair(T1 const &f, T2 const &s)
                : first{f}, second{s} {};

        constexpr pair(T1 &&f, T2 &&s)
                : first{f}, second{s} {};

        constexpr pair &operator=(const pair &other) {
            first = other.first;
            second = other.second;
        }

        template<typename U1, class U2>
        constexpr pair &operator=(const pair<U1, U2> &other) {
            first = other.first;
            second = other.second;
        }

        constexpr pair &operator=(pair &&other) = default;

        template<typename U1, class U2>
        constexpr pair &operator=(pair<U1, U2> &&other) {
            first = forward<U1>(other.first);
            second = forward<U2>(other.second);
        }

        template<typename T>
        void swap(T &one, T &two) {
            auto temp = one;
            one = two;
            two = temp;
        }

        T1 first;
        T2 second;
    };
}  // namespace firefly::std