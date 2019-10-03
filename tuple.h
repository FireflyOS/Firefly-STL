#pragma once

#include "utility.h"
#include <cstdlib/cstdint.h>

namespace firefly::std {
    // Tuple implementation for actual types.
    template<size_t _index, typename T>
    class _tuple {
    public:
        _tuple (T const &v) {
            val = v;
        }

        _tuple (T &&v) {
            val = move(v);
        }

        T &get() {
            return val;
        }

    private:
        T val;
    };

    // Used when no arguments are specified. Generic tuple.
    template<size_t _index, typename... Types>
    class _tuple_m { };

    //
}