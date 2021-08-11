#include "stdio.h"

#include "cstring.h"

#include <stdarg.h>

#ifdef I386
#include <i386/libk++/iostream.h>
#else
#include <x86_64/libk++/iostream.h>
#endif

char itoc(int num) { return '0' + num; }

char itoh(int num, bool upper) {
    if (upper)
        return num - 10 + 'A';
    return num - 10 + 'a';
}

char* strrev(char* src) {
    static char temp;
    int src_string_index = 0;
    int last_char = strlen(src) - 1;

    for (; src_string_index < last_char; src_string_index++) {
        temp = src[src_string_index]; // Save current character
        src[src_string_index] =
            src[last_char];    // Swap out the current char with the last char
        src[last_char] = temp; // Swap out last character with the current character
        last_char--;
    }

    src[strlen(src) - 1 + 1] = '\0';

    return src;
}

char* itoa(size_t num, char* str, int base) {
    size_t buffer_sz = 20;
    size_t counter = 0;
    size_t digit = 0;

    while (num != 0 && counter < buffer_sz) {
        digit = (num % base);
        if (digit > 9) {
            str[counter++] = itoh(digit, false);
        } else {
            str[counter++] = itoc(digit);
        }
        num /= base;
    }

    str[counter] = '\0';
    return strrev(str);
}

char* itoa(size_t num, char* str, int base, bool upper) {
    [[maybe_unused]] size_t buffer_sz = 20;
    [[maybe_unused]] size_t counter = 0;
    [[maybe_unused]] size_t digit = 0;

    if (! upper) {
        return itoa(num, str, base);
    } else {
        while (num != 0 && counter < buffer_sz - 1) {
            digit = (num % base);
            if (digit > 9) {
                str[counter++] = itoh(digit, true);
            } else {
                str[counter++] = itoc(digit);
            }
            num /= base;
        }
    }

    str[counter] = '\0';
    return strrev(str);
}

int atoi(const char* str) {
    int ret = 0;
    int i;

    for (i = 0; str[i]; i++) {
        ret = ret * 10 + str[i] - '0';
    }

    return ret;
}

int printf(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int i = 0;
    int len = strlen(fmt);
    int res = 0;

    for (; i < len; i++) {
        switch (fmt[i]) {
            case '%': {
                switch (fmt[i + 1]) {
                    case 'c': {
                        char arg = va_arg(ap, int);
                        firefly::libkern::print((char)arg);
                        i += 2, ++res;
                        break;
                    }

                    case 's': {
                        char* arg = va_arg(ap, char*);
                        firefly::libkern::print(arg);
                        i += 2, (res += 2 + strlen(arg));
                        break;
                    }

                    case 'i':
                    case 'd': {
                        size_t arg = va_arg(ap, size_t);
                        char buff[20];
                        firefly::libkern::print(itoa(arg, buff, 10));
                        res += digitcount(arg);
                        i += 2;
                        break;
                    }

                    case 'x': {
                        size_t arg = va_arg(ap, size_t);
                        char buff[20];
                        firefly::libkern::print(itoa(arg, buff, 16));
                        res += strlen(buff);
                        i += 2;
                        break;
                    }
                    case 'X': {
                        size_t arg = va_arg(ap, size_t);
                        char buff[20];
                        firefly::libkern::print(itoa(arg, buff, 16, true));
                        res += strlen(buff);
                        i += 2;
                        break;
                    }

                    case 'o': {
                        size_t arg = va_arg(ap, size_t);
                        char buff[20];
                        firefly::libkern::print(itoa(arg, buff, 8));
                        i += 2;
                        break;
                    }
                    default:
                        va_end(ap);
                        break;
                }
            }
            default:
                firefly::libkern::print(fmt[i]);
                va_end(ap);
                res++;
                break;
        }
    }
    return res;
}

void puts(const char *str)
{
    firefly::libkern::print(str);
}

// int sprintf()