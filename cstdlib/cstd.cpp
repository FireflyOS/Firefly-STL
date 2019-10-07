#include "cstdint.h"

extern "C" void* memset(void* dest, int value, size_t count) {
    auto _ptr = reinterpret_cast<char*>(dest);
    for (size_t i = 0; i < count; _ptr[i++] = value)
        ;
    return dest;
}

extern "C" void memcpy(void* dest, const void* src, size_t count) {
    // cast pointers to char*,
    // since void pointers are not suitable for arithmetics
    char* csrc = (char*)src;
    char* cdest = (char*)dest;

    for (size_t i = 0; i < count; i++) {
        cdest[i] = csrc[i];
    }
}