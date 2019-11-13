/*
 * lins_perso_cmp.c
 *
 * Code generation for function 'lins_perso_cmp'
 *
 * C source code generated on: Mon Nov 17 12:20:36 2014
 *
 */

/* Include files */
#include "lins_perso_cmp.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void lins_perso_cmp(const real_T A[SIZE_H_MAX*SIZE_H_MAX],
	                const real_T B[SIZE_H_MAX],
					real_T p[SIZE_H_MAX])
{
  real_T C[SIZE_H_MAX*SIZE_H_MAX];
  real_T y[SIZE_H_MAX];
  int32_T i;
  real_T temp;
  int32_T k;
  int32_T j;
  int32_T b_j;
  memset(&C[0], 0, size_H*size_H * sizeof(real_T));
  for (i = 0; i < size_H; i++) {
    y[i] = 0.0;
    p[i] = 0.0;
  }

  /*  cholesky */
  for (i = 0; i < size_H; i++) {
    temp = 0.0;
    for (k = 0; k <= i; k++) {
      temp -= C[k + size_H * i] * C[k + size_H * i];
    }

    C[i + size_H * i] = sqrt(A[i + size_H * i] + temp);
    for (j = 0; j <= size_H - 2 - i; j++) {
      b_j = (i + j) + 1;
      temp = 0.0;
      for (k = 0; k <= i; k++) {
        temp -= C[k + size_H * i] * C[k + size_H * b_j];
      }

      C[i + size_H * b_j] = (A[i + size_H * b_j] + temp) / C[i + size_H * i];
    }
  }

  /*  up and down */
  for (i = 0; i < size_H; i++) {
    temp = B[i];
    for (j = 0; j <= i; j++) {
      temp -= C[j + size_H * i] * y[j];
    }

    y[i] = temp / C[i + size_H * i];
  }

  for (i = 0; i < size_H; i++) {
    temp = y[size_H - 1 - i];
    for (j = 0; j < size_H; j++) {
      temp -= C[(size_H * (size_H - 1 - j) - i) + size_H - 1] * p[size_H - 1 - j];
    }

    p[size_H - 1 - i] = temp / C[(size_H * (size_H - 1 - i) - i) + size_H - 1];
  }
}

/* End of code generation (lins_perso_cmp.c) */
