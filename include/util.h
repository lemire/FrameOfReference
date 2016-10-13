#ifndef FRAMEOFREFERENCE_INCLUDE_UTIL_H
#define FRAMEOFREFERENCE_INCLUDE_UTIL_H
#include <iso646.h> // mostly for Microsoft compilers
#include <stdint.h> // part of Visual Studio 2010 and better

// integer logarithm function
static inline uint32_t bits(const uint32_t v) {
    return v == 0 ? 0 : 32 - __builtin_clz(v); // todo: make portable (Visual studio)
}


#endif // FRAMEOFREFERENCE_INCLUDE_UTIL_H
