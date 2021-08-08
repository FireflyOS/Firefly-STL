#include "cmath.h"

// Method 3
// https://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi
// https://stackoverflow.com/questions/5000109/implement-double-sqrtdouble-x-in-c
float sqrt(float arg) {
    union {
        int i;
        float exp;
    } u;

    u.exp = arg;
    u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
    return u.exp;
}

// https://stackoverflow.com/questions/26860574/pow-implementation-in-cmath-and-efficient-replacement
float powf(float base, int exponent) {
    float temp;
    if (! exponent) {
        return 1;
    }
    temp = powf(base, exponent / 2);
    if ((exponent % 2) == 0) {
        return temp * temp;
    } else {
        if (exponent > 0)
            return base * temp * temp;
        else
            return (temp * temp) / base;
    }
}

double pow(double base, int exponent) {
    double temp;
    if (! exponent) {
        return 1;
    }
    temp = pow(base, exponent / 2);
    if ((exponent % 2) == 0) {
        return temp * temp;
    } else {
        if (exponent > 0)
            return base * temp * temp;
        else
            return (temp * temp) / base;
    }
}