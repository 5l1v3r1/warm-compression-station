/*
 * lins_perso_cmp.h
 *
 * Code generation for function 'lins_perso_cmp'
 *
 * C source code generated on: Mon Nov 17 12:20:36 2014
 *
 */

#ifndef __LINS_PERSO_CMP_H__
#define __LINS_PERSO_CMP_H__
/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "lins_perso_cmp_types.h"

/* Type Definitions */
#define SIZE_H_MAX 1000
#define SIZE_A_MAX 2000

/* Variable Declarations */
int size_A;
int size_H;


/* Variable Definitions */

/* Function Declarations */
extern void lins_perso_cmp(const real_T A[2500], const real_T B[50], real_T p[50]);

#endif
/* End of code generation (lins_perso_cmp.h) */
