#pragma once

#include <complex.h>

#if defined(_MSC_VER) //Windows
    #define complex_t _Dcomplex
#elif defined(__GNUC__) // GCC
    #define complex_t double complex
#endif
