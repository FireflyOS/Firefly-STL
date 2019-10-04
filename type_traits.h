#pragma once

namespace firefly::std {
    template<typename T>
    struct is_lvalue_reference {
        constexpr static bool value = false;
    };

    template<typename T>
    struct is_lvalue_reference<T &> {
        constexpr static bool value = true;
    };

    template<typename T>
    using is_lvalue_reference_v = typename is_lvalue_reference<T>::value;

    template<typename T>
    struct remove_reference {
        using type = T;
    };
    template<typename T>
    struct remove_reference<T &> {
        using type = T;
    };
    template<typename T>
    struct remove_reference<T &&> {
        using type = T;
    };

    template<typename T>
    using remove_reference_t = typename remove_reference<T>::type;
}  // namespace firefly::std