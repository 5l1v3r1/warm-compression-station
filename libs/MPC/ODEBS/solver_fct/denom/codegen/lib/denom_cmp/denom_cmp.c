/*
 * denom_cmp.c
 *
 * Code generation for function 'denom_cmp'
 *
 * C source code generated on: Mon Nov 17 16:15:30 2014
 *
 */

/* Include files */
#include "denom_cmp.h"

/* Type Definitions */

/* Named Constants */
#define b_lambda__                     (5.0)

/* Variable Declarations */

/* Variable Definitions */
static real_T lambda__;
static uint32_T lambda___dirty;

/* Function Declarations */

/* Function Definitions */
void denom_cmp(const real_T H[2500], const real_T Gamma[5000], const real_T g
               [100], const real_T lb[50], const real_T ub[50], const real_T
               alpha[100], const real_T alpha_min[50], const real_T alpha_max[50],
               real_T dt, const real_T z[50], real_T den[2500])
{
  int8_T ind[100];
  real_T cstp[100];
  real_T cst[100];
  int32_T i;
  int32_T k;
  int32_T j;
  real_T a;
  real_T hmm[50];
  real_T u0;
  real_T b_u0;
  int32_T l;
  for (i = 0; i < 100; i++) {
    ind[i] = 0;
    cstp[i] = 0.0;
    cst[i] = -g[i];
  }

  memset(&den[0], 0, 2500U * sizeof(real_T));
  k = -1;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 50; j++) {
      cst[i] += Gamma[i + 100 * j] * z[j];
    }

    if (cst[i] > 0.0) {
      k++;
      cstp[k] = dt / 2.0 * lambda__ * 6.0 * alpha[i] * cst[i];
      ind[k] = (int8_T)(1 + i);
    }
  }

  a = dt * lambda__ / 2.0;
  for (i = 0; i < 50; i++) {
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

    hmm[i] = a * (alpha_max[i] * u0 + alpha_min[i] * b_u0);
  }

  for (i = 0; i < 50; i++) {
    for (l = 0; l <= i; l++) {
      den[l + 50 * i] = a * H[i + 50 * l];
      for (j = 0; j <= k; j++) {
        den[l + 50 * i] += Gamma[(ind[j] + 100 * l) - 1] * cstp[j] * Gamma
          [(ind[j] + 100 * i) - 1];
        den[i + 50 * l] = den[l + 50 * i];
      }
    }

    den[i + 50 * i] = (den[i + 50 * i] + hmm[i]) + 1.0;
  }
}

void denom_cmp_initialize(void)
{
  lambda___dirty = 0U;
  lambda__ = b_lambda__;
}

void denom_cmp_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (denom_cmp.c) */
