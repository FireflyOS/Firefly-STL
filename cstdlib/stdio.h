#pragma once

extern void putchar(char c);
extern void puts(const char *str);
void putsn(const char *str, int n);
// int printf(const char *fmt, ...);
char *itoa(int num, char *str, int base);
int atoi(const char *str);
char *strrev(char *str);
void printf(const char *fmt, ...);