//---------------------------------------------------------------------------
#ifndef GazH
#define GazH
//#include "calcul.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
//#include "general.h"
//---------------------------------------------------------------------------
int signe ( long double valeur );
long double max (long double a, long double b);
int maxe (int a, int b);
long double min (long double a, long double b);
int mine (int a, int b);
long double sign ( long double valeur1, long double valeur2 );
//---------------------------------------------------------------------------
// hepak en C++
class he
{
public :
    // propriétés du fluide
    long double prp[126];
    double prpdbl[126];


    struct { long double tl, dtldv, d2tdv2, vsave; } sublam;

    struct { long double r[13]; int jr; } subrt;

    /* */ struct { long double rr, amw, pcrit, tcrit, dcrit, hcrit, ucrit,
		             scrit, ptr, ttr, dtrf, dtrg, htrf, htrg, utrf,
                     utrg, strf, strg, thi, dhi, hhi, uhi, shi, cphi,
                     cvhi, hmax2p, umax2p, pmax, pmin, tmax, tmin; } prinit;

    /* */ struct { long double g[32], r, gm, vp[9], dtp, pcc, ptp, tcc, ttp, tul,	tll,
                     pul, dcc; } mc1;

    /* */ long double uconvf[76];

    /* */ int uunits[41];

    /* */ long double precsn[16];

    long double heprvr;

    /* */ struct { long double c[82];  // ex 41-2
             long double cl[64]; // ex 8-8
             long double v0, t0; } subhec;

    /* */ struct { long double t0, s0, h0; } mc8;

//---------------------------------------------------------------------------
    he ();
    long double tlfd (long double d);	// common
    long double vislam (long double dd, long double tt);
    long double vislpt (long double d, long double t);


    void calc (int& idid, int jout, int j1, long double valu1,
	    	   int j2, long double valu2, int jprecs, int junits);
    int jm (int j1, int j2);
    void errmsg (char* messag, int idid);
    void prcis (int j);
    void unilib (int nk);
    void superf (long double *cheii, long double pi, long double d, long double t,
                 long double dtv, long double s, long double *f);
    long double rsrfpt (long double p, long double t);
    void kierst (long double& p, long double& xdpdt, long double& d,
                 long double& dddt, long double t);
    long double dlft (long double tt);
    long double dlfp(long double p);
    long double plft (long double t);
    long double tlfp (long double p);
    long double tsatsl (long double sjkg);
    long double tsatsv (long double sjkg);
    long double sats (long double t);
    long double dielhe (long double rho);
    void satfs (int& idid, long double& qual, long double& ps, long double& xdpdt,
                long double& ts, long double& dl, long double& dv, long double ss);
    void satfy( int& idid, long double& qual, long double& ps, long double& dpdt,
                long double& ts, long double& dl, long double& dv, long double yy,
                char label);
    void satfd (int& idid, long double& qual, long double& psat, long double& dpdt,
                long double& tsat, long double& dl, long double& dv, long double rho);
    long double satly (long double t);
    long double satvy (long double t);
    long double t7658 (long double t58);
    void df2pt (int& idid, long double& d, long double pp, long double tt);
    void dfpt (int& idid, long double& d, long double& x, long double p, long double t);
    long double dpt (long double d);
    long double dst (long double y);
    void dtfhs (int &idid, long double& d, long double& t, long double& x,
                long double& dl, long double& dv, long double p, long double dpdt,
                long double h, long double s);
    void dfst (int& idid, long double& rho, long double& x, long double& rf,
               long double& rg, long double& p, long double& dpdts, long double s,
               long double t);
    long double dths (long double t);
    long double dmfp (long double p);
    long double pmft (long double tt);
    long double tmfp (long double pp);
    long double rhobb (long double p, long double t);
    long double u3k (long double p);
    long double d3k (long double p);
    void dtfpx( int& idid, long double& rho, long double& tt, long double& q,
                long double& dl, long double& dv, long double& dpdts, long double p,
                long double x, char label[2]);
    long double d175k (long double Pa);
    long double h3k (long double p);
    long double s3k (long double p);
    void dtfpg (int& idid, long double& dcalc, long double& tcalc, long double p,
                long double g);
    long double cva (long double d, long double tt);
    long double cvm (long double rho, long double t);
    long double cv (long double d, long double t);
    void deriv (long double* f, long double di, long double ti);
    void dtilxy (long double& d, long double& t, int& j, char label[2],
                 long double x, long double y);
    long double roun01 (long double x);
    long double psat (long double t);
    long double tsatfp (long double pp);
    long double dpdta (long double d, long double tt);
    long double satd (long double t);
    long double satd1 (long double t);
    void tfdp (int& idid, long double& t, long double& x, long double& dl,
               long double& dv, long double d, long double p);
    long double tdp( long double y);
    long double tmfd (long double dd);
    void tfdy (int& idid, long double& t, long double& q, long double& ps,
               long double& xdpdt, long double& dl, long double& dv, long double dd,
               long double yy, char label);
    long double entrop (long double d, long double t);
    long double d2vfpt (long double psat, long double tsat);
    long double pressm (long double rr, long double tt);
    long double press (long double d, long double t);
    long double d2lfpt (long double psat, long double tsat);
    void shaug (long double *prp);
    void psatft (long double& p, long double& dpdts, long double t);
    long double dgsat (long double t);
    long double denmax (long double t);
    void fdt (int& idid, long double& q, long double& ps, long double& xdpdt,
              long double& dl, long double& dv, long double dd, long double tt);
    long double yjfdt ( long double t);
    long double dmft (long double t);
    long double dfsat (long double t);
    void dftg (int& idid, long double& d, long double t, long double g);
    long double helma2 (long double x, long double t, int m);
    long double helma (long double d, long double tt);
    long double entra2 ( long double x, long double t, int m);
    long double entra (long double d, long double tt);
    long double enerm (long double rr, long double tt);
    long double entrm (long double rr, long double tt);
    long double presa2 (long double x, long double t, int m);
    long double pressa (long double d, long double tt);
    long double dtg (long double d);
    long double refr (long double rho, long double w);
    long double sten (long double t);
    long double dpdtm (long double rr, long double tt);
    long double dpdt (long double d, long double t);
    void logfun (long double* pvtcsa, long double tt, long double dtt, int m);
    long double dpdda (long double d, long double tt);
    long double dpddm (long double rr, long double tt);
    void amlap (long double& tminm, long double& tmaxa, long double d);
    long double dpdd (long double d, long double t);
    long double tcon (long double rho, long double t);
    long double conlpt (long double d, long double t);
    long double viscos (long double dkgm3, long double tk);
    long double vischi (long double dkgm3, long double t);
    void lamder (long double v);
    void rootaz ( long double& r, long double a, long double b, long double c,
                  long double z, long double exa, long double exr, long double eya,
                  long double eyr, int i,
                  long double f0, int& jx);

    long double f (int i, long double x);
    //int affiche (long double *tab, int dep, int fin);
};


#endif
