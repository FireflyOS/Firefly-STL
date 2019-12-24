#pragma once
#include "cstdlib/cstdint.h"

namespace firefly::std {
    template <typename Key>
    struct hash;

    template <>
    struct hash<bool> {
        size_t operator()(bool _val) const noexcept {
            return static_cast<size_t>(_val);
        }
    };

    template <>
    struct hash<char>;

    template <>
    struct hash<signed char>;

    template <>
    struct hash<unsigned char>;
    
    template <>
    struct hash<char8_t>;

    template <>
    struct hash<char16_t>;

    template <>
    struct hash<char32_t>;

    template <>
    struct hash<wchar_t>;

    template <>
    struct hash<short>;

    template <>
    struct hash<unsigned short>;

    template <>
    struct hash<int>;

    template <>
    struct hash<unsigned int>;

    template <>
    struct hash<long>;

    template <>
    struct hash<long long>;

    template <>
    struct hash<unsigned long>;

    template <>
    struct hash<unsigned long long>;

    template <>
    struct hash<float>;

    template <>
    struct hash<double>;

    template <>
    struct hash<long double>;

    template <class T>
    struct hash<T*>;
} // namespace firefly::std