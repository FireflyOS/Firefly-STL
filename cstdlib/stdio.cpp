#include "stdio.h"
#include "cstring.h"

#include <stdarg.h>

// #ifdef I386
#include <i386/libk++/iostream.h>
// #elif x86_64
// #include <x86_64/libk++/iostream.h>
// #endif

char itoc(int num) { return '0' + num; }

char itoh(int num) { return num - 10 + 'a'; }

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

char* itoa(int num, char* str, int base) {
    int counter = 0;
    int digit = 0;

    while (num != 0) {
        digit = (num % base);
        if (digit > 9) {
            str[counter++] = itoh(digit);
        } else {
            str[counter++] = itoc(digit);
        }
        num /= base;
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

void printf(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int i = 0;
    int len = strlen(fmt);

    for (; i < len; i++) {
        switch (fmt[i]) {
            case '%': {
                switch (fmt[i + 1]) {
                    case 'c': {
                        char arg = va_arg(ap, int);
                        firefly::libkern::print((char)arg);
                        i += 2;
                        break;
                    }
                }
            }
            default:
                firefly::libkern::print((char)fmt[i]);
                va_end(ap);
                break;
        }
    }
}