/*
 * djdp_cmp.c
 *
 * Code generation for function 'djdp_cmp'
 *
 * C source code generated on: Mon Nov 17 15:43:42 2014
 *
 */

/* Include files */
#include "djdp_cmp.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void djdp_cmp(const real_T H[SIZE_H_MAX*SIZE_H_MAX],
              const real_T h[SIZE_H_MAX], 
              const real_T Gamma[SIZE_H_MAX*SIZE_A_MAX],
              const real_T g[SIZE_A_MAX], 
              const real_T lb[SIZE_H_MAX],
              const real_T ub[SIZE_H_MAX],
              const real_T alpha[SIZE_A_MAX],
              const real_T alpha_min[SIZE_H_MAX],
              const real_T alpha_max[SIZE_H_MAX],
              const real_T z[SIZE_H_MAX],
              real_T der[SIZE_H_MAX])
{
  int16_T ind[SIZE_A_MAX];
  real_T cstp[SIZE_A_MAX];
  real_T cst[SIZE_A_MAX];
  int32_T i;
  int32_T k;
  int32_T j;
  real_T b_u0;
  real_T u0;

  k = 0;
  for (i = 0; i < size_A; i++) {
    ind[i] = 0;
    cstp[i] = 0.0;
    cst[i] = -g[i];
    for (j = 0; j < size_H; j++) {
      cst[i] += Gamma[i + size_A * j] * z[j];
    }

    if (cst[i] > 0.0) {
      cstp[k] = 3.0 * cst[i]*cst[i] * alpha[i];
      ind[k] = (int16_T)(i);
	  k++;
    }
  }

  for (i = 0; i < size_H; i++) {
    der[i] = h[i];
    for (j = 0; j < size_H; j++) {
      der[i] += H[i + size_H * j] * z[j];
    }
  }

  for (i = 0; i < size_H; i++) {
    for (j = 0; j <= k; j++) {
      der[i] += Gamma[(ind[j] + size_A * i)] * cstp[j];
    }

    u0 = z[i] - ub[i];
    if (u0 >= 0.0) {
    } else {
      u0 = 0.0;
    }

    b_u0 = lb[i] - z[i];
    if (b_u0 >= 0.0) {
    } else {
      b_u0 = 0.0;
    }

    der[i] = (der[i] + alpha_max[i] * u0) - alpha_min[i] * b_u0;
  }

  for (i = 0; i < size_H; i++) {
    der[i] = -der[i];
  }
}

void djdp_cmp_initialize(void)
{
}

void djdp_cmp_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (djdp_cmp.c) */
