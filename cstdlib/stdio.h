#pragma once

#include <stddef.h>
#include <stdint.h>

void itoa(size_t num, char *str, int base);
int atoi(const char* str);
char* strrev(char* str);
int printf(const char* fmt, ...);
void puts(const char *str);