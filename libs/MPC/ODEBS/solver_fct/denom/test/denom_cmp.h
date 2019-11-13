/*
 * denom_cmp.h
 *
 * Code generation for function 'denom_cmp'
 *
 * C source code generated on: Mon Nov 17 16:15:30 2014
 *
 */

#ifndef __DENOM_CMP_H__
#define __DENOM_CMP_H__
/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "denom_cmp_types.h"

/* Type Definitions */

/* Named Constants */
#define SIZE_H_MAX 1000
#define SIZE_A_MAX 2000

/* Variable Declarations */
int size_A;
int size_H;

/* Variable Definitions */

/* Function Declarations */
extern void denom_cmp(const real_T H[2500], const real_T Gamma[5000], const real_T g[100], const real_T lb[50], const real_T ub[50], const real_T alpha[100], const real_T alpha_min[50], const real_T alpha_max[50], real_T dt, const real_T z[50], real_T den[2500]);
#endif
/* End of code generation (denom_cmp.h) */
