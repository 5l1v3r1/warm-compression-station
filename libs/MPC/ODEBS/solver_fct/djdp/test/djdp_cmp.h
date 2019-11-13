/*
 * djdp_cmp.h
 *
 * Code generation for function 'djdp_cmp'
 *
 * C source code generated on: Mon Nov 17 15:43:42 2014
 *
 */

#ifndef __DJDP_CMP_H__
#define __DJDP_CMP_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#include "rtwtypes.h"
#include "djdp_cmp_types.h"

/* Type Definitions */

/* Named Constants */
#define SIZE_H_MAX 1000
#define SIZE_A_MAX 2000

/* Variable Declarations */
int size_A;
int size_H;

/* Variable Definitions */

/* Function Declarations */
extern void djdp_cmp(const real_T H[SIZE_H_MAX*SIZE_H_MAX], const real_T h[SIZE_H_MAX], const real_T Gamma[SIZE_H_MAX*SIZE_A_MAX], const real_T g[SIZE_A_MAX], const real_T lb[SIZE_H_MAX], const real_T ub[SIZE_H_MAX], const real_T alpha[SIZE_A_MAX], const real_T alpha_min[SIZE_H_MAX], const real_T alpha_max[SIZE_H_MAX], const real_T z[SIZE_H_MAX], real_T der[SIZE_H_MAX]);
extern void djdp_cmp_initialize(void);
extern void djdp_cmp_terminate(void);
#endif
/* End of code generation (djdp_cmp.h) */
