#pragma once

#include <stddef.h>
#include <stdint.h>

char* itoa(size_t num, char* str, int base);
int atoi(const char* str);
char* strrev(char* str);
int printf(const char* fmt, ...);