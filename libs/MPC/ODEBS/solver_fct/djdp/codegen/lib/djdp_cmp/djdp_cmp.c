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
void djdp_cmp(const real_T H[2500], const real_T h[50], const real_T Gamma[5000],
              const real_T g[100], const real_T lb[50], const real_T ub[50],
              const real_T alpha[100], const real_T alpha_min[50], const real_T
              alpha_max[50], const real_T z[50], real_T der[50])
{
  int8_T ind[100];
  real_T cstp[100];
  real_T cst[100];
  int32_T i;
  int32_T k;
  int32_T j;
  real_T u0;
  real_T b_u0;
  for (i = 0; i < 100; i++) {
    ind[i] = 0;
    cstp[i] = 0.0;
    cst[i] = -g[i];
  }

  k = -1;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 50; j++) {
      cst[i] += Gamma[i + 100 * j] * z[j];
    }

    if (cst[i] > 0.0) {
      k++;
      u0 = cst[i];
      u0 = pow(u0, 2.0);
      cstp[k] = 3.0 * u0 * alpha[i];
      ind[k] = (int8_T)(1 + i);
    }
  }

  for (i = 0; i < 50; i++) {
    der[i] = h[i];
    for (j = 0; j < 50; j++) {
      der[i] += H[i + 50 * j] * z[j];
    }
  }

  for (i = 0; i < 50; i++) {
    for (j = 0; j <= k; j++) {
      der[i] += Gamma[(ind[j] + 100 * i) - 1] * cstp[j];
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

  for (i = 0; i < 50; i++) {
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
