#ifndef solve_pb_mpc
#define solve_pb_mpc

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int size_A;
int size_H;

#define SIZE_H_MAX 100
#define SIZE_A_MAX 200

void num_pu_fct(double *ppu, double *ppl, double *p, double *Gpu, double dt, double *num_pu);
void num_pl_fct(double *ppl, double *p, double *Gpl, double dt, double *G, double *num_pl);
void saut(double *pp, double *delta_pp);

void denom_cmp(double* H,
	           double* Gamma, 
			   double* g, 
			   double* lb, 
			   double* ub,
			   double* alpha,
			   double* alpha_min,
			   double* alpha_max,
			   double dt, 
			   double* z,
			   double* den);

void djdp_cmp(double* H,
              double* h, 
              double* Gamma,
              double* g, 
              double* lb,
              double* ub,
              double* alpha,
              double* alpha_min,
              double* alpha_max,
              double* z,
              double* der);

int csrt_cmp( double* H,
               double* Gamma,
               double* g, 
               double* lb,
               double* ub,
               double* alpha,
               double* alpha_min,
               double* alpha_max,
               double* z,
			   double* cstp,
			   int* ind);

void lins_perso_cmp(double* A, double* B, double* p);
void solve_pb_mpc_fct( double* H, double* h, double* Gamma, double* g, double* lb, double* ub, double* alpha, double* alpha_min, double* alpha_max, int st, double* z, double* zpu,double* iter, double* lambda, double* norm);

#endif

