#pragma once
#include "cstdlib/cstddef.h"
#include "utility.h"

template <typename T>
class optional {
    bool _ok;
    T _val;

public:
    constexpr optional()
        : _ok{ false } {
    }

    constexpr optional(nullptr_t)
        : _ok{ false } {
    }

    constexpr optional(const optional<T>& other)
        : _ok{ other._ok }, _val{ other._val } {
    }

    constexpr optional(optional<T>&& other)
        : _ok{ other._ok }, _val{ firefly::std::move(other._val) } {
    }

    template <typename U>
    constexpr optional(const optional<U>& other)
        : _ok{ other._ok }, _val{ other._val } {
    }

    template <typename U>
    constexpr optional(optional<U>&& other)
        : _ok{ other._ok }, _val{ firefly::std::move(other._val) } {
    }

    optional& operator=(optional const&) = default;
    optional& operator=(operator&&) = default;
    ~optional() = default;

    T* operator->() {
        return &_val;
    }

    T& operator*() {
        return _val;
    }

    operator bool() {
        return _ok;
    }

    bool has_value() {
        return _ok;
    }

    T& value() {
        return _val;
    }

    T& value_or(T& val) {
        if (has_value()) {
            return _val;
        }
        return val;
    }

    T value_or(T val) {
        if (has_value()) {
            return _val;
        }
        return val;
    }
};
