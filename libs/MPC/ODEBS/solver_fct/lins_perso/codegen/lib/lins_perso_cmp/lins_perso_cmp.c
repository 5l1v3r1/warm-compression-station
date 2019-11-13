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
void lins_perso_cmp(const real_T A[2500], const real_T B[50], real_T p[50])
{
  real_T C[2500];
  real_T y[50];
  int32_T i;
  real_T temp;
  int32_T k;
  int32_T j;
  int32_T b_j;
  memset(&C[0], 0, 2500U * sizeof(real_T));
  for (i = 0; i < 50; i++) {
    y[i] = 0.0;
    p[i] = 0.0;
  }

  /*  cholesky */
  for (i = 0; i < 50; i++) {
    temp = 0.0;
    for (k = 0; k <= i; k++) {
      temp -= C[k + 50 * i] * C[k + 50 * i];
    }

    C[i + 50 * i] = sqrt(A[i + 50 * i] + temp);
    for (j = 0; j <= 48 - i; j++) {
      b_j = (i + j) + 1;
      temp = 0.0;
      for (k = 0; k <= i; k++) {
        temp -= C[k + 50 * i] * C[k + 50 * b_j];
      }

      C[i + 50 * b_j] = (A[i + 50 * b_j] + temp) / C[i + 50 * i];
    }
  }

  /*  up and down */
  for (i = 0; i < 50; i++) {
    temp = B[i];
    for (j = 0; j <= i; j++) {
      temp -= C[j + 50 * i] * y[j];
    }

    y[i] = temp / C[i + 50 * i];
  }

  for (i = 0; i < 50; i++) {
    temp = y[49 - i];
    for (j = 0; j < 50; j++) {
      temp -= C[(50 * (49 - j) - i) + 49] * p[49 - j];
    }

    p[49 - i] = temp / C[(50 * (49 - i) - i) + 49];
  }
}

void lins_perso_cmp_initialize(void)
{
}

void lins_perso_cmp_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (lins_perso_cmp.c) */
