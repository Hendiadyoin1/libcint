/*
 * Copyright (C) 2013  Qiming Sun <osirpt.sun@gmail.com>
 *
 * basic functions
 */

#include <math.h>
#include "_complex.h"
#include "cint_const.h"

void CINTdcmplx_re(const FINT n, complex_t *z, const double *re)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(re[i], 0);
        }
}

void CINTdcmplx_im(const FINT n, complex_t *z, const double *im)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(0, im[i]);
        }
}

void CINTdcmplx_pp(const FINT n, complex_t *z,
                   const double *re, const double *im)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(re[i], im[i]);
        }
}
void CINTdcmplx_pn(const FINT n, complex_t *z,
                   const double *re, const double *im)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(re[i], - im[i]);
        }
}
void CINTdcmplx_np(const FINT n, complex_t *z,
                   const double *re, const double *im)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(-re[i], im[i]);
        }
}
void CINTdcmplx_nn(const FINT n, complex_t *z,
                   const double *re, const double *im)
{
        FINT i;
        for (i = 0; i < n; i++) {
                z[i] = Complex_t(-re[i], - im[i]);
        }
}


double CINTsquare_dist(const double *r1, const double *r2)
{
        double r12[3];

        r12[0] = r1[0] - r2[0];
        r12[1] = r1[1] - r2[1];
        r12[2] = r1[2] - r2[2];

        return r12[0] * r12[0] + r12[1] * r12[1] + r12[2] * r12[2];
}

static FINT factorial(FINT n)
{
        FINT i, fact = 1;
        for (i = 1; i <= n; i++) {
                fact *= i;
        }
        return fact;
}
double CINTgto_norm(FINT n, double a)
{
        double nn = pow(2, (2*n+3)) * factorial(n+1) * pow((2*a), (n+1.5)) \
                / (factorial(2*n+2) * sqrt(M_PI));
        return sqrt(nn);
}
double CINTgto_norm_(FINT *n, double *a)
{
        return CINTgto_norm(*n, *a);
}
