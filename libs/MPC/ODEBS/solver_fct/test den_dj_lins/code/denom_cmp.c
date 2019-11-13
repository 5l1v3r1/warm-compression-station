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
#define lambda__  (0.585786437626905)

/* Variable Declarations */


/* Function Definitions */
void denom_cmp(const real_T H[SIZE_H_MAX*SIZE_H_MAX],
	           const real_T Gamma[SIZE_H_MAX*SIZE_A_MAX], 
			   const real_T g[SIZE_A_MAX], 
			   const real_T lb[SIZE_H_MAX], 
			   const real_T ub[SIZE_H_MAX],
			   const real_T alpha[SIZE_A_MAX],
			   const real_T alpha_min[SIZE_H_MAX],
			   const real_T alpha_max[SIZE_H_MAX],
			   real_T dt, const real_T z[SIZE_H_MAX],
			   real_T den[SIZE_H_MAX*SIZE_H_MAX])
{
  int16_T ind[SIZE_A_MAX];
  real_T cstp[SIZE_A_MAX];
  real_T cst[SIZE_A_MAX];
  int32_T i;
  int32_T k;
  int32_T j;
  real_T a;
  real_T hmm[SIZE_H_MAX];
  real_T u0;
  real_T b_u0;
  int32_T l;
  for (i = 0; i < size_A; i++) {
    ind[i] = 0;
    cstp[i] = 0.0;
    cst[i] = -g[i];
  }

  memset(&den[0], 0, size_H*size_H * sizeof(real_T));
  k = -1;
  for (i = 0; i < size_A; i++) {
    for (j = 0; j < size_H; j++) {
      cst[i] += Gamma[i + size_A * j] * z[j];
    }

    if (cst[i] > 0.0) {
      k++;
      cstp[k] = dt / 2.0 * lambda__ * 6.0 * alpha[i] * cst[i];
      ind[k] = (int16_T)(1 + i);
    }
  }

  a = dt * lambda__ / 2.0;
  for (i = 0; i < size_H; i++) {
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

  for (i = 0; i < size_H; i++) {
    for (l = 0; l <= i; l++) {
      den[l + size_H * i] = a * H[i + size_H * l];
      for (j = 0; j <= k; j++) {
        den[l + size_H * i] += Gamma[(ind[j] + size_A * l) - 1] * cstp[j] * Gamma
          [(ind[j] + size_A * i) - 1];
      }
    }

    den[i + size_H * i] = (den[i + size_H * i] + hmm[i]) + 1.0;
  }
}

