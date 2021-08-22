#pragma once
#include "cstdint.h"

float sqrt(float arg);

float powf(float base, int exponent);
size_t pow(size_t base, size_t exponent);

double ln(double x);
int log2(uint64_t value);
double log10( double x );

constexpr inline size_t constexpr_log2(size_t n) {
    return ((n < 2) ? 1 : 1 + constexpr_log2(n / 2));
}