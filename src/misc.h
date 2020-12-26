/*
 * Copyright (C) 2013  Qiming Sun <osirpt.sun@gmail.com>
 *
 * basic functions
 */

#include <stdint.h>
#include "config.h"
#include "fblas.h"

#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define SQUARE(r)       ((r)[0]*(r)[0] + (r)[1]*(r)[1] + (r)[2]*(r)[2])

void CINTdcmplx_re(const FINT n, complex_t *z, const double *re);
void CINTdcmplx_im(const FINT n, complex_t *z, const double *im);
void CINTdcmplx_pp(const FINT n, complex_t *z, const double *re, const double *im);
void CINTdcmplx_pn(const FINT n, complex_t *z, const double *re, const double *im);
void CINTdcmplx_np(const FINT n, complex_t *z, const double *re, const double *im);
void CINTdcmplx_nn(const FINT n, complex_t *z, const double *re, const double *im);

double CINTsquare_dist(const double *r1, const double *r2);

double CINTgto_norm(FINT n, double a);

#define MALLOC_INSTACK(var, n) \
        var = (void *)cache; \
        cache = (void *)(((uintptr_t)(var + (n)) + 7) & (-(uintptr_t)8));

#ifdef WITH_CINT2_INTERFACE
#define ALL_CINT(NAME) \
FINT c##NAME##_cart(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env, CINTOpt *opt) { \
        return NAME##_cart(out, NULL, shls, atm, natm, bas, nbas, env, opt, NULL); \
} \
void c##NAME##_cart_optimizer(CINTOpt **opt, FINT *atm, FINT natm, \
                         FINT *bas, FINT nbas, double *env) { \
        NAME##_optimizer(opt, atm, natm, bas, nbas, env); \
} \
FINT c##NAME##_sph(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env, CINTOpt *opt) { \
        return NAME##_sph(out, NULL, shls, atm, natm, bas, nbas, env, opt, NULL); \
} \
void c##NAME##_sph_optimizer(CINTOpt **opt, FINT *atm, FINT natm, \
                         FINT *bas, FINT nbas, double *env) { \
        NAME##_optimizer(opt, atm, natm, bas, nbas, env); \
} \
FINT c##NAME(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env, CINTOpt *opt) { \
        return NAME##_spinor((complex_t *)out, NULL, shls, \
                             atm, natm, bas, nbas, env, opt, NULL); \
} \
void c##NAME##_optimizer(CINTOpt **opt, FINT *atm, FINT natm, \
                         FINT *bas, FINT nbas, double *env) { \
        NAME##_optimizer(opt, atm, natm, bas, nbas, env); \
}


#define ALL_CINT1E(NAME) \
FINT c##NAME##_cart(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env) { \
        return NAME##_cart(out, NULL, shls, atm, natm, bas, nbas, env, NULL, NULL); \
} \
FINT c##NAME##_sph(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env) { \
        return NAME##_sph(out, NULL, shls, atm, natm, bas, nbas, env, NULL, NULL); \
} \
FINT c##NAME(double *out, FINT *shls, FINT *atm, FINT natm, \
            FINT *bas, FINT nbas, double *env) { \
        return NAME##_spinor((complex_t *)out, NULL, shls, \
                             atm, natm, bas, nbas, env, NULL, NULL); \
}

#else

#define ALL_CINT(NAME)
#define ALL_CINT1E(NAME)

#endif  // WITH_CINT2_INTERFACE
