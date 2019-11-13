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

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void djdp_cmp(const real_T H[2500], const real_T h[50], const real_T Gamma[5000], const real_T g[100], const real_T lb[50], const real_T ub[50], const real_T alpha[100], const real_T alpha_min[50], const real_T alpha_max[50], const real_T z[50], real_T der[50]);
extern void djdp_cmp_initialize(void);
extern void djdp_cmp_terminate(void);
#endif
/* End of code generation (djdp_cmp.h) */
