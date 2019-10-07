#pragma once

#include "cstdint.h"

inline size_t strlen(const char *str) {
    size_t _sz{};
    while (str[_sz++]);
    return _sz;
}

inline size_t strnlen(const char *str) {
    return strlen(str) + 1;
}


void memcpy(void* dest, const void* src, size_t count) {
    // cast pointers to char*,
    // since void pointers are not suitable for arithmetics
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    for (size_t i = 0; i < count; i++) {
        cdest[i] = csrc[i];
    }
}

// inline size_t strlen(const vga_char* str) {
//     size_t _sz{};
//     while (str[_sz++].codepoint);
//     return _sz;
// }

// inline size_t strnlen(const vga_char* str) {
//     return strlen(str) + 1;
// }