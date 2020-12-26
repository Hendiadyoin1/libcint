#pragma once

#include <complex.h>

#if defined(_MSC_VER) //Windows
    #define complex_t _Dcomplex
    #define complex_t(reel, imag) _Dcomplex(reel,imag)
#elif defined(__GNUC__) // GCC
    #define complex_t double complex
    #define complex_t(reel, complex) (reel + complex * _Complex_I)
#endif
