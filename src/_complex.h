#pragma once

#include <complex.h>

#if defined(_MSC_VER) //Windows
    #define complex_t _Dcomplex

    complex_t operator *(const complex_t& a, const complex_t& b){
        return _Cmulcc(a,b);
    }
    complex_t operator *(const complex_t& a, const double& b){
        return _Cmulcr(a,b);
    }
    complex_t operator *(const double& b, const complex_t& a,){
        return _Cmulcr(a,b);
    }

#elif defined(__GNUC__) // GCC
    #define complex_t double complex
#endif
