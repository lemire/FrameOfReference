#ifndef FRAMEOFREFERENCE_INCLUDE_UTIL_H
#define FRAMEOFREFERENCE_INCLUDE_UTIL_H
#include <iso646.h> // mostly for Microsoft 
#ifdef _MSC_VER
/* Microsoft C/C++-compatible compiler */
#include <intrin.h>

#ifndef __clang__ // if one compiles with MSVC *with* clang, then these intrinsics are defined!!!
// sadly there is no way to check whether we are missing these intrinsics specifically.

/* wrappers for Visual Studio built-ins that look like gcc built-ins */
/* result might be undefined when input_num is zero */
static inline int __builtin_ctzll(unsigned long long input_num) {
	unsigned long index;
#ifdef _WIN64 // highly recommended!!!
	_BitScanForward64(&index, input_num);
#else // if we must support 32-bit Windows
	if ((uint32_t)input_num != 0) {
		_BitScanForward(&index, (uint32_t)input_num);
	}
	else {
		_BitScanForward(&index, (uint32_t)(input_num >> 32));
		index += 32;
	}
#endif
	return index;
}

/* result might be undefined when input_num is zero */
static inline int __builtin_clzll(unsigned long long input_num) {
	unsigned long index;
#ifdef _WIN64 // highly recommended!!!
	_BitScanReverse64(&index, input_num);
#else // if we must support 32-bit Windows
	if (input_num > 0xFFFFFFF) {
		_BitScanReverse(&index, (uint32_t)(input_num >> 32));
	}
	else {
		_BitScanReverse(&index, (uint32_t)(input_num));
		index += 32;
	}
#endif
	return 63 - index;
}

/* result might be undefined when input_num is zero */
static inline int __builtin_clz(int input_num) {
	unsigned long index;
	_BitScanReverse(&index, input_num);
	return 31 - index;
}

/* result might be undefined when input_num is zero */
static inline int __builtin_popcountll(unsigned long long input_num) {
#ifdef _WIN64 // highly recommended!!!
	return (int)__popcnt64(input_num);
#else // if we must support 32-bit Windows
	return (int)(__popcnt((uint32_t)input_num) + __popcnt((uint32_t)(input_num >> 32)));
#endif
}

static inline void __builtin_unreachable() {
	__assume(0);
}
#endif
#endif


#include <stdint.h> // part of Visual Studio 2010 and better

// integer logarithm function
static inline uint32_t bits(const uint32_t v) {
    return v == 0 ? 0 : 32 - __builtin_clz(v); // todo: make portable (Visual studio)
}



// integer logarithm function
static inline uint32_t bits64(const uint64_t v) {
    return v == 0 ? 0 : 64 - __builtin_clzll(v); // todo: make portable (Visual studio)
}

#endif // FRAMEOFREFERENCE_INCLUDE_UTIL_H
