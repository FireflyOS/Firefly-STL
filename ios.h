#pragma once
#include "cstdlib/cstdint.h"
#include "cstdlib/stdio.h"

namespace firefly::std {
    char* hex(int n) {
        char buff[20];
        return itoa(n, buff, 16);
    }

    char* dec(int n) {
        char buff[20];
        return itoa(n, buff, 10);
    }
} // namespace firefly::std