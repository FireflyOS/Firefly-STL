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

extern void *memset(void *s, char c, int n);
extern int memcmp(const char *s1, const char *s2, int n);
extern char *strcpy(char *dest, const char *src);
extern int strcmp(const char *s1, const char *s2);
extern char *strchr(const char *str, int c);
extern char *strchrn(const char *str, int c, int n);
extern int toupper(char c);
extern char *strtok(char *s, const char *delimiters);

extern "C" void memcpy(void* dest, const void* src, size_t count);

extern "C" void *memset(void* dest, int value, size_t count);

// inline size_t strlen(const vga_char* str) {
//     size_t _sz{};
//     while (str[_sz++].codepoint);
//     return _sz;
// }

// inline size_t strnlen(const vga_char* str) {
//     return strlen(str) + 1;
// }