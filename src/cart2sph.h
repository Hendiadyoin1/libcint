/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 *
 * Cartisen GTO to spheric or spinor GTO transformation
 */

/*************************************************
 *
 * transform matrix
 *
 *************************************************/
#include "_complex.h"
#include "g1e.h"

void c2s_sph_1e(double *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sph_2e1(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sph_2e2();

void c2s_cart_1e(double *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_cart_2e1(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_cart_2e2();

void c2s_sf_1e(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_1ei(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_si_1e(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_1ei(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_sf_2e1(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_2e1i(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_sf_2e2(complex_t *fijkl, complex_t *opij, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_2e2i(complex_t *fijkl, complex_t *opij, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_si_2e1(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_2e1i(complex_t *opij, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_si_2e2(complex_t *fijkl, complex_t *opij, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_2e2i(complex_t *fijkl, complex_t *opij, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_sph_3c2e1(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_cart_3c2e1(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sph_3c2e1_ssc(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_sf_3c2e1(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_3c2e1i(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_3c2e1(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_3c2e1i(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_3c2e1_ssc(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_sf_3c2e1i_ssc(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_3c2e1_ssc(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_si_3c2e1i_ssc(complex_t *opijk, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_sph_3c1e(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
void c2s_cart_3c1e(double *fijkl, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);

void c2s_dset0(double *out, FINT *dims, FINT *counts);
void c2s_zset0(complex_t *out, FINT *dims, FINT *counts);

/*************************************************
 *
 * transform vectors
 *
 *************************************************/
void c2s_sph_vec(double *sph, double *cart, FINT l, FINT nvec);
