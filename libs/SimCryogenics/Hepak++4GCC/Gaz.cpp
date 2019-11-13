//---------------------------------------------------------------------------
#include "Gaz.h"

/*******************************************************************************
long double sign ( long double valeur1, long double valeur2 )

BUT: renvoie le signe de valeur1 * la valeur absolue de valeur2
*******************************************************************************/
long double sign ( long double valeur1, long double valeur2 )
{
	long double s;
    if (valeur2 >= 0) s = 1.0; else s = -1.0;

	return s * fabsl (valeur1);
}

/*******************************************************************************
long double max (long double a, long double b)
int maxe (int a, int b)

But : Renvoyer la valeur maximale de a et b

Rôle des variables :
*******************************************************************************/
long double max (long double a, long double b)
{
	if (a > b) return a;
    else return b;
}

int maxe (int a, int b)
{
	if (a > b) return a;
    else return b;
}

/*******************************************************************************
long double min (long double a, long double b)
int mine (int a, int b)

But : Renvoyer la valeur mimimale de a et b

Rôle des variables :
*******************************************************************************/
long double min (long double a, long double b)
{
	if (a > b) return b;
    else return a;
}

int mine (int a, int b)
{
	if (a > b) return b;
    else return a;
}

/*******************************************************************************
int signe ( long double valeur )

BUT: Cette procŽdure renvoie
		-1 si valeur < 0
		0  si valeur = 0
		1  si valeur > 0
*******************************************************************************/
int signe ( long double valeur )
{
	int sg; // signe de valeur

	if (valeur > 0.0) {sg = 1;}
	else {if (valeur == 0.0) sg = 0; else sg = -1;}
	return sg;
}
//---------------------------------------------------------------------------
//#pragma package(smart_init)
//---------------------------------------------------------------------------

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Replacement for subroutine PRDATA in earlier versions of HEPAK */
/* Sept. 13, 1992 */
/*     COMMON/PRINIT/R,AMW,PCRIT,TCRIT,DCRIT,HCRIT,UCRIT,SCRIT, */
/*    1   PTR,TTR,DTRF,DTRG,HTRF,HTRG,UTRF,UTRG,STRF,STRG,THI,DHI, */
/*    2   HHI,UHI,SHI,CPHI,CVHI,HMAX2P,UMAX2P,PMAX,PMIN,TMAX,TMIN */
/* -----Version 3.23: two lines added (Heprop version #) */
/* -----Version 3.21  HMAX2P and UMAX2P changed to "exact" values */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* This subroutine written by V. Arp. */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* This subroutine written by R.D. McCarty and V. Arp. */
/* Helium I coefficients; version March 14, 1989 */
/* Following line added Sept. 13, 1992 */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* -----Version 3.22  SFTC units corrected */
/* -----Version 3.31  Conversion factor #52 changed 10^13 to 10^10 */


he :: he ()

{

    heprvr = 3.31;


    prinit.rr = 2077.23476;     prinit.amw = 4.0026;        prinit.pcrit =  227462.3;

    prinit.tcrit = 5.1953;      prinit.dcrit = 69.6412374;  prinit.hcrit = 21932.0;

    prinit.ucrit = 18682.0;     prinit.scrit = 5768.6;      prinit.ptr = 5041.8;

    prinit.ttr = 2.1768;        prinit.dtrf = 146.15;       prinit.dtrg = 1.1923727;

    prinit.htrf = 2961.33;      prinit.htrg = 25757.05;     prinit.utrf = 2926.83;

    prinit.utrg = 21528.67;     prinit.strf = 1579.97;      prinit.strg = 11991.95;
    prinit.thi = 300.0;         prinit.dhi = 0.1604;        prinit.hhi = 1573500.0;
    prinit.uhi = 950100.0;      prinit.shi = 31612.0;       prinit.cphi = 5193.0;
    prinit.cvhi = 3117.0;       prinit.hmax2p = 30744.0;    prinit.umax2p = 24724.0;
    prinit.pmax = 2.028e9;      prinit.pmin = 0.1;          prinit.tmax = 1500.0;
    prinit.tmin = 0.8;


    int i;

    struct { long double g[32], r, gm, vp[9], dtp, pcc, ptp, tcc, ttp, tul,	tll,
                     pul, dcc; } mc =
        { {4.558980227431e-5, 0.001260692007853, -0.007139657549318,
	    0.009728903861441, -0.01589302471562, 1.454229259623e-6,
	    -4.708238429298e-5, 0.001132915223587, 0.002410763742104,
	    -5.093547838381e-9, 2.6997269279e-6, -3.954146691114e-5,
	    1.551961438127e-9, 1.050712335785e-8, -5.50115836675e-8,
	    -1.037673478521e-10, 6.446881346448e-13, 3.298960057071e-11,
	    -3.555585738784e-13, -0.00688540136769, 0.009166109232806,
	    -6.544314242937e-6, -3.315398880031e-5, -2.067693644676e-8,
	    3.850153114958e-8, -1.399040626999e-11, -1.888462892389e-12,
	    -4.595138561035e-15, 6.872567403738e-15, -6.097223119177e-19,
	    -7.636186157005e-18, 3.848665703556e-18}, 0.0083143, -0.0033033259,
	    {1.723358273506, 2.355572223663, -0.1899616867304, -0.0614520534873,
	    1.394346356392, 1.5, 2.1768, 5.1953, 0.0050418}, 36.51377, 0.2275,
	    0.0050418, 5.1953, 2.1768, 1500.0, 2.17, 100.0, 17.399 };
    for (i=0; i<32; i++) mc1.g[i] = mc.g[i];
    mc1.r = mc.r;
    mc1.gm = mc.gm;
    for (i=0; i<9; i++) mc1.vp[i] = mc.vp[i];
    mc1.dtp = mc.dtp;
    mc1.pcc = mc.pcc;
    mc1.ptp = mc.ptp;
    mc1.tcc = mc.tcc;
    mc1.ttp = mc.ttp;
    mc1.tul = mc.tul;
    mc1.tll = mc.tll;
    mc1.pul = mc.pul;
    mc1.dcc = mc.dcc;


    long double uc[76] = { 1.0, 1e3, 1e6, 1e5, 101325.0, 6894.757, 0.001, 1e-6, 1e-5,
	    9.86923e-6, 1.45037e-4, 1.0, 0.555555556, 1.0, 1.8, 1.0, 1e3, 4.0026,
	    16.01846, 1.0, 0.001, 0.2498376, 0.0624279, 1.0, 1e3, 249.8376, 4186.8,
	    1.0, 1e3, 249.8376, 2326.0, 1.0, 0.3048, 0.001, 1e-5, 1.0, 8.05765e-5,
	    1., 1.730735, 1e-6, 1e-7, 1.488164, 1., 1e-4, .09290304, 1.0, 0.001,
	    14.5939, 1.0, 1.0, 10.0, 1e10, 1.0, 0.0143593, 0.555555556, 1.0, 1.0, 1.0,
	    227462.3, 5.1953, 69.6412, 1.0, 2077.226, 10791.812, 1.0, 1.0, 1.0,
	    12410.56, 1.0, 1e3, 1e6, 1e5, 1.0, 249.8376, 1e3, 430.4257 };
    for (i=0; i<76; i++) uconvf[i] = uc[i];

    int units[41] = { 1, 57, 12, 16, 20, 1, 69, 28, 24, 28, 28, 28, 28, 60, 24,
	    24, 1, 65, 1, 53, 32, 36, 73, 69, 28, 58, 38, 1, 43, 46, 1, 1, 12,
	    12, 1, 32, 32, 49, 50, 12, 1 };
    for (i=0; i<41; i++) uunits[i] = units[i];


    long double prec[16] = { 0.0, 0.03, 0.01, 0.003, 0.001, 3e-4, 1e-4, 3e-5, 1e-5, 3e-6,

	    1e-6, 3e-7, 1e-7, 3e-8, 1e-8, 3e-9 };
    for (i=0; i<16; i++) precsn[i] = prec[i];

    heprvr = 3.31;

    struct { long double c[82];  // ex 41-2

        long double cl[64]; // ex 8-8
        long double v0, t0; } sub =
        {{ -0.55524231, 0.18333872, -0.042819388, -0.049962336,
	    -0.083818656, -0.14081863, 0.899013, 6.6841845, 9.8899347, 7.3876336,
	     2.0130513, -0.025251119, -1.0649342, -3.5520547, -5.846516,
	    -4.2352097, -1.2206228, 0.016905918, 0.21835833, 0.74548499,
	    1.1932777, 0.86121784, 0.25519882, -0.0013224602, -0.020161157,
	    -0.065799115, -0.10330654, -0.075388298, -0.023788871, 5.2810077e-5,
	    6.6823412e-4, 0.0021297216, 0.0032541554, 0.002442111, 8.2971274e-4,
	    -1.9221178, 1.1203003, -0.16430199, -0.0034805651, 3.63345, -4.325,
	    -1.4629809, 0.76365652, -0.11943389, 0.0030525707, -0.10405828,
	    -0.14748127, -0.96308013, 0.67943869, -0.5527632, 0.019535989,
	    -0.04792884, 0.075410775, -0.08060907, -0.766418, -3.5260824,
	    -5.1006607, -2.0845765, -0.012991643, -0.014392344, 0.72407645,
	    3.5487925, 4.9508203, 2.0014366, 0.0012086022, 0.01089437,
	    -0.21841979, -1.0697343, -1.454107, -0.56844527, -8.2701229e-5,
	    -0.0010295381, 0.02077704, 0.10085164, 0.13267276, 0.04970154,
	    0.95829687, -1.4025436, 0.63551829, -0.055978553, -0.044009, -0.78777},
	    {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
	    1.0, -2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, -3.0, 6.0, -6.0, 0.0, 0.0, 0.0, 0.0,
        1.0, -4.0, 12.0, -24.0, 24.0, 0.0, 0.0, 0.0, 1.0, -5.0, 20.0, -60.0, 120.0,
	    -120.0, 0.0, 0.0, 1.0, -6.0, 30.0, -120.0, 360.0, -720.0, 720.0, 0.0, 1.0,
	    -7.0, 42.0, -210.0, 840.0, -2520.0, 5040.0, -5040.0}, 6.842285, 2.1768 };
    for (i=0; i<82; i++) subhec.c[i] = sub.c[i];
    for (i=0; i<64; i++) subhec.cl[i] = sub.cl[i];
    subhec.v0 = sub.v0;
    subhec.t0 = sub.t0;

    mc8.t0 = 0.0;
    mc8.s0 = 0.0078616;
    mc8.h0 = 0.0611315;

    for (i=0; i<126; i++) prp[i] = 0.0;
}


/* ********************************************************* */
/* ********************************************************* */
/* ********************************************************* */
/* **** Début de la routine de calcul */
/* ********************************************************* */
/* ********************************************************* */
/* ********************************************************* */
/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* -----Version 3.30 */

/* Please update the Heprop version #, in block data HEINIT, as new */
/*     versions are developed! */

/* This subroutine performs all the calculations. */
/* !! See file USER.FOR for properties definitions and locations !! */
/* -------------------------------- AFTER ANY SUCCESSFUL CALL TO CALC */
/* the following properties will have been calculated: */
/*    PRP (0:5) + (if IDID > 1) PRP(6:7) */
/* Additional output is controlled by the 5-digit parameter JOUT. */
/* Each non-zero digit specifies additional parameters. */
/*   If the 10000's digit > 0:   PRP(8:13)  = State Variables */
/*   If the 1000's digit > 0 :   PRP(14:24) = Derivatives */
/*   If the 100's digit > 0  :   PRP(25:26) = Thermal conductivity and */
/*                               Viscosity and (if IDID > 1) PRP(29) = */
/*                               surface tension. */
/*                              Also, if Derivatives have been calculated,*/
/*                               PRP(27:28) = Diffusivity & Prandtl No. */
/*                               will be calculated. */
/*   If the 10's digit > 0   :   PRP(30:31) = Dielectric constant and */
/*                               refractive index. */
/*      Note! PRP(40,0) = wavelength (micrometers) is a required input for*/
/*       the refractive index calculation! */
/*   If the 1's digit > 0    :  PRP(8:24) + PRP(32:39) =  HeII properties*/
/*       State and derivative properties will automatically be calculated*/
/*       when HeII properties are requested. */
/* ------------------------------------------------------ */
/*!! Caution: NIV, NIP, NCF must agree with values in other subroutines !!*/


void he :: calc (int& idid, int jout, int j1, long double valu1, int j2, long double valu2, int jprecs, int junits)
{
    /* Initialized data */

    long double dlamh = 179.83;
    long double plamh = 3013400.0;
    long double tlamh = 1.7673;
    bool latch = true;
    int kin[10] = { 1,2,3,4,8,9,11,12,5,33 };

    /* Local variables */
    long double cvfj;
    int j, m;
    long double dlaml, plaml, tlaml;
    long double tmaxa, tminm, tcrit;
    int k1;
    long double waveln;
    int jo1, jo2, jo3, jo4, jo5;
    long double ain[10];
    long double qal, omq;
    char lbl1[1];
    long double dum1, dum2;

	/* -----Initialization of constants: */
    if (latch)
    {
		latch = false;
		sublam.vsave = -1.0;
		tcrit = prinit.tcrit;
		plaml = prinit.ptr;
		tlaml = prinit.ttr;
		dlaml = prinit.dtrf;
    }

	/* Check for valid input parameters */
    if (((j1 - 1) * (j1 - 15) > 0) || ((j2 - 1) * (j2 - 15) > 0))
    {
		idid = -11;
		return;
    }

	/* Check for valid thermodynamic parameter pair */
    m = jm (j1, j2);
    if (m <= 0)
    {
		idid = -21;
		return;
    }

	/* Reset precision and units as needed */
    long double toto = precsn[0];
    if (toto >= 0) toto = fabsl (toto + 0.5); else toto = fabsl (toto - 0.5);
    int n = (int)toto;
    if (jprecs != signe (*precsn) * n) prcis (jprecs);
    if (junits != uunits[40]) unilib (junits);
    // il y a des problème dans la fonction identique de Gaspak
    // Avant d'être réutilisée il faut la vérifier !!!!

	/* Place input values into the array and convert to HEPAK units */
	/* (Note: input temperatures must be K or R, not C or F) */
    if (j1 <= 10)
    {
		ain[j1 - 1] = valu1 * uconvf[uunits[kin[j1 - 1]] - 1];
    }
    if (j2 <= 10)
    {
		ain[j2 - 1] = valu2 * uconvf[uunits[kin[j2 - 1]] - 1];
    }

	/* -----Version 3.21B: Add one line for use by spreadsheets. */
    if (prp[125] != -262144.0)
    {
        /* If Volume was an input parameter, calculate density. */
        if (j1 == 4)
        {
            if (valu1 <= 0.0)
            {
                idid = -170;
                return;
            }
            ain[2] = 1.0 / valu1;
        }
        else    if (j2 == 4)
                {
                    if (valu2 <= 0.0)
                    {
                        idid = -170;
                        return;
                    }
                    ain[2] = 1.0 / valu2;
                }

        /* Set the output array to signify "not a valid answer" */
        /*     Properties 40 & 41 are not used for output (in this version), */
        /*     but may be used for various internal communications, or */
        /*     for input.  Do not erase. */
        for (k1 = 0; k1 <= 39; k1++)
        {
            prp[k1] = 0.0;
            prp[k1 + 42] = 0.0;
            prp[k1 + 84] = 0.0;
        }
        idid = 0;
        /* Obtain temperature, density and quality from input parameters */
        switch (m)
        {
            /* Pressure, temperature input */
            case 1: // modification réalsée le 12/6/2008 pour éviter un bug autour de la
                    // saturation près du point critique
                    // Il est tout à fait possible que dans la zone prise en compte ici
                    // avec des grandeurs d'état différentes on trouve le même bug,
                    // à ce jour cela n'a pas été vérifié.
                    if ((ain[1] < 5.1943) && (ain[2] > 5.0453864))
                    {
                        long double TSaturation = tsatfp (ain[0]);
                        if ((ain[1] > TSaturation) &&
                            (ain[1] < TSaturation - 6.2e-12 * powl (ain[0], 2) + 2.938e-6 * ain[0] - 0.3409))
                        {
                            ain[1] = TSaturation - 6.2e-12 * powl (ain[0], 2) + 2.938e-6 * ain[0] - 0.3409;
                        }
                    }
                    // fin de la modification
                    dfpt (idid, prp[3], prp[0], ain[0], ain[1]);
                    prp[1] = ain[0];
                    prp[2] = ain[1];
                    break;
            /* (D,T) Input */
            case 2: fdt (idid, prp[0], prp[1], prp[48], prp[45], prp[87], ain[2], ain[1]);
                    prp[2] = ain[1];
                    prp[3] = ain[2];
                    break;
            /* Pressure and density input */
            case 3: tfdp (idid, prp[2], prp[0], prp[45], prp[87], ain[2], ain[0]);
                    if (idid == 3) psatft (prp[1], prp[48], prp[2]);
                    prp[3] = ain[2];
                    break;
            /* Pressure and enthalpy input */
            case 4: dtfpx (idid, prp[3], prp[2], prp[0], prp[45], prp[87], dum1, ain[0], ain[5], "PH");
                    if (idid == 3) psatft (prp[1], prp[48], prp[2]);
                    break;
            /* Density and enthalpy input */
            case 5: tfdy (idid, prp[2], prp[0], prp[1], prp[48], prp[45], prp[87], ain[2], ain[5], 'H');
                    prp[3] = ain[2];
                    break;
            /* Pressure and entropy input */
            case 6: dtfpx (idid, prp[3], prp[2], prp[0], prp[45], prp[87], dum1, ain[0], ain[4], "PS");
                    if (idid == 3) psatft (prp[1], prp[48], prp[2]);
                    break;
            /* Temperature and entropy input */
            case 7: dfst (idid, prp[3], prp[0], prp[45], prp[87], prp[1], prp[48], ain[4], ain[1]);
                    prp[2] = ain[1];
                    break;
            /* Density and entropy input */
            case 8: tfdy (idid, prp[2], prp[0], prp[1], prp[48], prp[45], prp[87], ain[2], ain[4], 'S');
                    prp[3] = ain[2];
                    break;
            /* Enthalpy and entropy input */
            case 9: dtfhs (idid, prp[3], prp[2], prp[0], prp[45], prp[87], prp[1], prp[48], ain[5], ain[4]);
                    break;
            /* Pressure and internal energy input */
            case 10: dtfpx (idid, prp[3], prp[2], prp[0], prp[45], prp[87], dum1, ain[0], ain[6], "PU");
                     if (idid == 3) psatft (prp[1], prp[48], prp[2]);
                     break;
            /* Density and internal energy input */
            case 11: tfdy (idid, prp[2], prp[0], prp[1], prp[12], prp[45], prp[87], ain[2], ain[6], 'U');
                     prp[3] = ain[2];
                     break;
            /* Saturation pressure input, possibly quality and pressure */
            case 12: ain[1] = tsatfp (ain[0]);
                     if (ain[1] < 0.0)
                     {
                        idid = -121;
                        break;
                     }
                     prp[2] = ain[1];
                     psatft (prp[1], prp[48], ain[1]);
                     prp[45] = d2lfpt (prp[1], ain[1]);
                     prp[87] = d2vfpt (prp[1], ain[1]);
                     /* If quality has been specified, check that it is between 0 and 1; */
                     /* Else with satL or satV specification, set quality = 0 */
                     /* so that saturated superfluid properties will be calculated correctly.*/
                     if ((j1 == 9) || (j2 == 9))
                     {
                        if ((ain[8] < 0.0) || (ain[8] > 1.0))
                        {
                            idid = -129;
                            break;
                        }
                        idid = 3;
                     }
                     else
                     {
                        ain[8] = 0.0;
                        idid = 2;
                     }
                     prp[3] = 1.0 / ((1.0 - ain[8]) / prp[45] + ain[8] / prp[87]);
                     prp[0] = ain[8];
                     break;
            /* Saturation temperature input, possibly quality and temperature */
            case 13: if ((ain[1] < 0.7999) || (ain[1] > tcrit))
                     {
                        idid = -122;
                        break;
                     }
                     prp[2] = ain[1];
                     psatft (prp[1], prp[48], ain[1]);
                     prp[45] = d2lfpt (prp[1], ain[1]);
                     prp[87] = d2vfpt (prp[1], ain[1]);
                     /* If quality has been specified, check that it is between 0 and 1; */
                     /* Else with satL or satV specification, set quality = 0 */
                     /* so that saturated superfluid properties will be calculated correctly.*/
                     if ((j1 == 9) || (j2 == 9))
                     {
                        if ((ain[8] < 0.0) || (ain[8] > 1.0))
                        {
                            idid = -129;
                            break;
                        }
                        idid = 3;
                     }
                     else
                     {
                        ain[8] = 0.0;
                        idid = 2;
                     }
                     prp[3] = 1.0 / ((1.0 - ain[8]) / prp[45] + ain[8] / prp[87]);
                     prp[0] = ain[8];
                     break;
            /* Saturation S, H, U, or G input */
            case 14: if ((j1 == 5) || (j2 == 5))
                     {
                        lbl1[0] = 'S';
                        dum1 = ain[4];
                     }
                     else if ((j1 == 6) || (j2 == 6))
                     {
                        lbl1[0] = 'H';
                        dum1 = ain[5];
                     }
                     else if ((j1 == 7) || (j2 == 7))
                     {
                        lbl1[0] = 'U';
                        dum1 = ain[6];
                     }
                     else
                     {
                        lbl1[0] = 'G';
                        dum1 = ain[7];
                     }
                     satfy (idid, prp[0], prp[1], prp[48], prp[2], prp[45], prp[87], dum1, lbl1[0]);
                     break;
            /* Saturation density input (double-valued region excluded). */
            case 15: satfd (idid, prp[0], prp[1], prp[48], prp[2], prp[45], prp[87], ain[2]);
                     prp[3] = ain[2];
                     if (idid > 0) idid = 2;
                     break;
            /* Melting pressure input */
            case 16: prp[2] = tmfp (ain[0]);
                     if (prp[2] <= 0.0) idid = -131;
                     else
                     {
                        dfpt (idid, prp[3], dum1, ain[0], prp[2]);
                        prp[0] = -1.0;
                     }
                     break;
            /* Melting temperature input */
            case 17: if ((ain[1] - 0.8) * (ain[1] - 14.05) > 0.0) idid = -132;
                     else
                     {
                        ain[0] = pmft (ain[1]);
                        dfpt (idid, prp[3], dum1, ain[0], ain[1]);
                        prp[1] = ain[0];
                        prp[2] = ain[1];
                        prp[0] = -1.0;
                     }
                     break;
            /* Pressure and Gibbs energy input */
            case 18: dtfpg (idid, prp[3], prp[2], ain[0], ain[7]);
                     prp[0] = -1.0;
                     break;
            /* Temperature and Gibbs energy input */
            case 19: dftg (idid, prp[3], ain[1], ain[7]);
                     prp[2] = ain[1];
                     prp[0] = -1.0;
                     break;
            /* Delta-T to the lambda line at a given density */
            case 20: if (fabsl(ain[9]) >= 0.5) idid = -144;
                     else if ((ain[2] > dlamh) || (ain[2] < 145.56)) idid = -143;
                     else
                     {
                        prp[1] = pressa (ain[2], ain[9]);
                        prp[2] = sublam.tl + ain[9];
                        prp[3] = ain[2];
                        /* Quality will be adjusted following statement 230 */
                        prp[0] = -1.0;
                        idid = 1;
                        /* Possible out-or-range near the saturation line */
                        psatft (dum1, dum2, prp[2]);
                        if (prp[1] < dum1) idid = -145;
                     }
                     break;
            /* Delta-T to the lambda line at a given pressure */
            case 21: if (fabsl(ain[9]) >= 0.5) idid = -144;
                     else if ((ain[0] < 0.0) || (ain[0] > plamh)) idid = -141;
                     else
                     {
                        idid = 1;
                        prp[2] = tlfp (ain[0]) + ain[9];
                        df2pt (idid, prp[3], ain[0], prp[2]);
                        prp[1] = ain[0];
                        prp[0] = -1.0;
                     }
                     break;
            /* LAMBDA line pressure input */
            case 22: if ((ain[0] < plaml - 2.0) || (ain[0] > plamh * 1.0001)) idid = -141;
                     else
                     {
                        prp[1] = ain[0];
                        prp[2] = tlfp (ain[0]);
                        prp[3] = dlft (prp[2]);
                        prp[0] = -2.0;
                        idid = 1;
                     }
                     break;
            /* LAMBDA line temperature input */
            case 23: if ((ain[1] > tlaml + 1.0e-4) || (ain[1] < tlamh - 0.001)) idid = -142;
                     else
                     {
                        prp[1] = plft (ain[1]);
                        prp[2] = ain[1];
                        prp[3] = dlft (ain[1]);
                        prp[0] = -2.0;
                        idid = 1;
                     }
                     break;
            /* LAMBDA line density input */
            case 24: if ((ain[2] < dlaml - 0.1) || (ain[2] > dlamh + 0.1)) idid = -143;
                     else
                     {
                        prp[2] = tlfd (ain[2]);
                        prp[1] = plft (prp[2]);
                        prp[3] = ain[2];
                        prp[0] = -2.0;
                        idid = 1;
                     }
                     break;
            /* Lower LAMBDA point */
            case 25: prp[1] = plaml;
                     prp[2] = tlaml;
                     prp[0] = 0.;
                     idid = 2;
                     prp[45] = dlaml;
                     /* PRP(3,2)= D2VFPT (PRP(1,0), PRP(2,0)) */
                     prp[87] = 1.192378;
                     /* Following point is defined by the T76 temperature scale */
                     prp[12] = 12407.9;
                     break;
            /* Upper LAMBDA point */
            case 26: prp[1] = plamh;
                     prp[2] = tlamh;
                     prp[3] = dlamh;
                     prp[0] = -2.0;
                     idid = 1;
                     break;
            /* delta T to the lambda line along the saturation line */
            case 27: ain[1] = ain[9] + tlaml;
                     /* Saturation temperature input, possibly quality and temperature */
                     if ((ain[1] < 0.7999) || (ain[1] > tcrit))
                     {
                        idid = -122;
                        break;
                     }
                     prp[2] = ain[1];
                     psatft (prp[1], prp[48], ain[1]);
                     prp[45] = d2lfpt (prp[1], ain[1]);
                     prp[87] = d2vfpt (prp[1], ain[1]);
                     /* If quality has been specified, check that it is between 0 and 1; */
                     /* Else with satL or satV specification, set quality = 0 */
                     /* so that saturated superfluid properties will be calculated correctly.*/
                     if ((j1 == 9) || (j2 == 9))
                     {
                        if ((ain[8] < 0.0) || (ain[8] > 1.0))
                        {
                            idid = -129;
                            break;
                        }
                        idid = 3;
                     }
                     else
                     {
                        ain[8] = 0.0;
                        idid = 2;
                     }
                     prp[3] = 1.0 / ((1.0 - ain[8]) / prp[45] + ain[8] / prp[87]);
                     prp[0] = ain[8];
                     break;
        }
    }
	/* All input goes through this point;  check for error. */
	/*     Valid properties at this point are: */
	/*     If IDID=1: density, temperature, and quality */
	/*                = prp(3,0), prp(2,0), prp(0,0) */
	/*                  (In HeII, prp(0,0) will be reset from -1 to -2 later) */
	/*                If M >= 20, pressure = prp(1,0) has been calculated */
	/*     If IDID=3: Mixture, liquid, vapor densities, temperature, */
	/*                saturation pressure, mixture quality */
	/*                = prp(3,0), prp(3,1), prp(3,2), prp(2,0), */
	/*                  prp(1,0), prp(0,0) */
	/*     If IDID=2: Liquid and Vapor densities, temperature, pressure, */
	/*                = prp(3,1), prp(3,2), prp(2,0), prp(1,0) */
	/*                  (note: quality = prp(0,0) will be set = 0) */
    if (idid >= 1)
    {
		if (prp[2] < 0.7999) idid = -161;
		else if (prp[2] > 1500.1) idid = -162;
		else if (m <= 11)
        {
			/* Check for valid density if not already checked */
		    if (prp[3] > denmax (prp[2])) idid = -163;
	    	else
            {
				dum2 = max(prp[3],prp[45]);
				if (dum2 <= 0.0) idid = -164;
		    }
		}
    }
    if (idid == 0) idid = -300;
    if (idid <= 0) return;

	/* Calculate pressure if not already done. */
    if (idid == 1)
    {
		if (m < 20) prp[1] = press (prp[3], prp[2]);
    }
    else
    {
		/* In two-phase or mixture, transfer P and T to 2-phase locations */
		prp[43] = prp[1];
		prp[85] = prp[1];
		prp[44] = prp[2];
		prp[86] = prp[2];
		/* Version 3.23: one line added */
		prp[6] = prp[48];
		prp[90] = prp[48];
		prp[42] = 0.0;
		prp[84] = 1.0;
    }

	/* P, T, RHO, and X have been evaluated. */
	/* Also calculate specific volume, PV/RT, and latent heat if at saturation.*/
    if (idid != 2)
    {
		prp[4] = 1.0 / prp[3];
		prp[5] = prp[1] / (prp[2] * 2077.226 * prp[3]);
    }
    if (idid >= 2)
    {
		prp[47] = prp[43] / (prp[44] * 2077.226 * prp[45]);
		prp[89] = prp[85] / (prp[86] * 2077.226 * prp[87]);
		prp[46] = 1.0 / prp[45];
		prp[88] = 1.0 / prp[87];
		/* -----Version 3.211: */
		/* Clausius-Clapyron value in PRP(7,1) and PRP(7,2);  PRP(7,2) may be */
		/* overwritten later with delH (if delH is calculated). */
		prp[49] = prp[48] * prp[2] * (prp[88] - prp[46]);
		prp[91] = prp[49];
		/* -----Version 3.23: following line */
		prp[7] = prp[49];
    }
    qal = prp[0];
    omq = 1.0 - qal;
	/* Set output mode */
    if (idid == 2)
    {
		if ((j1 == 13) || (j2 == 13)) idid = 4;
		else if ((j1 == 14) || (j2 == 14)) idid = 5;
    }
    jo1 = jout / 10000;
    jo2 = jout % 10000 / 1000;
    jo3 = jout % 1000 / 100;
    jo4 = jout % 100 / 10;
    jo5 = jout % 10;
    if (jo5 >= 1)
    {
		jo1 = 1;
		jo2 = 1;
    }
	/* OUTPUT */
	/* Version 3.23: non-functional numbered CONTINUEs removed below. */
	/* State properties */
    if (jo1 > 0)
    {
		if (idid >= 2)
        {
	    	if (idid != 5) shaug (&prp[43]);
		    if (idid != 4) shaug (&prp[85]);
			/* -----Version 3.23: */
		    if (idid <= 3)
            {
				prp[7] = prp[93] - prp[51];
				prp[91] = prp[7];
		    }
		    prp[8] = qal * prp[92] + omq * prp[50];
		    prp[9] = qal * prp[93] + omq * prp[51];
	    	prp[10] = qal * prp[94] + omq * prp[52];
		    prp[11] = qal * prp[95] + omq * prp[53];
		    prp[12] = qal * prp[96] + omq * prp[54];
		}
        else shaug (&prp[1]);
    }
	/* Derivative properties */
    if (jo2 > 0)
    {
		if (idid >= 2)
        {
	    	if (idid != 5) deriv (&prp[56], prp[45], prp[44]);
		    if (idid != 4) deriv (&prp[98], prp[87], prp[86]);
		}
        else deriv (&prp[14], prp[3], prp[2]);
    }
	/* Transport properties */
    if (jo3 > 0)
    {
		if (idid >= 2)
        {
	    	prp[71] = sten (prp[44]);
		    prp[113] = prp[71];
		    if (idid != 5)
            {
				prp[67] = viscos (prp[45], prp[44]);
				prp[68] = tcon (prp[45], prp[44]);
				if (prp[68] > 0.0) prp[69] = prp[67] * prp[56] / prp[68];
				if (prp[56] > 0.) prp[70] = prp[68] / (prp[45] * prp[56]);
		    }
		    if (idid != 4)
            {
				prp[109] = viscos (prp[87], prp[86]);
				prp[110] = tcon (prp[87], prp[86]);
				if (prp[110] > 0.0) prp[111] = prp[109] * prp[98] / prp[110];
				if (prp[98] > 0.0) prp[112] = prp[110] / (prp[87] * prp[98]);
		    }
		}
        else if (prp[1] < 1.01e8)
        {
			/* The transport functions are not fitted at pressures above 100 MPa. */
		    prp[25] = viscos (prp[3], prp[2]);
		    prp[26] = tcon (prp[3], prp[2]);
	    	if (prp[26] > 0.0) prp[27] = prp[25] * prp[14] / prp[26];
		    if (prp[14] > 0.0) prp[28] = prp[26] / (prp[3] * prp[14]);
		}
    }
	/* Dielectric contant and/or refractive index */
    if (jo4 > 0)
    {
		/* Version 3.23: following IF logic changed. */
		waveln = prp[40];
		if ((idid - 1) * (idid - 3) == 0)
        {
		    prp[30] = dielhe (prp[3]);
		    prp[31] = refr (prp[3], waveln);
		}
		if ((idid - 2) * (idid - 4) <= 0)
        {
	    	prp[72] = dielhe (prp[45]);
		    prp[73] = refr (prp[45], waveln);
		}
		if ((idid - 2) * (idid - 3) * (idid - 5) == 0)
        {
		    prp[114] = dielhe (prp[87]);
		    prp[115] = refr (prp[87], waveln);
		}
    }
	/* Unique superfluid properties */
	/* The array HII(1:5) is evaluated by SUPERF */
	/* Version 3.23: minor change in Fortran; no functional change. */
    if ((jo5 > 0) && (idid < 5))
    {
		j = min(1, idid - 1);
		/* Proceed only if A-equations have been used. */
		amlap (tminm, tmaxa, prp[j * 42 + 3]);
		if (prp[j * 42 + 2] < tmaxa)
        {
			prp[j * 42 + 39] = sublam.tl;
			prp[j * 42 + 33] = prp[j * 42 + 2] - sublam.tl;
			if (fabsl(prp[j * 42 + 33]) < 1e-6) prp[j * 42 + 33] = 0.0;
			prp[j * 42 + 32] = prp[j * 42 + 2] - tlfp (prp[j * 42 + 1]);
			if (fabsl(prp[j * 42 + 32]) < 1e-6) prp[j * 42 + 32] = 0.0;
			if (prp[j * 42 + 33] <= -1e-6)
	        {
		    	prp[j * 42] = -2.0;
				/* Version 3.23: accidently created an index error in following line */
				/* Version 3.24: index error corrected: PRP(2,j) corrected to PRP(1,j)*/
			    superf (&prp[j * 42 + 34], prp[j * 42 + 1], prp[j * 42 + 3], prp[j * 42 + 2],
    	        		prp[j * 42 + 33], prp[j * 42 + 8], &prp[j * 42 + 14]);
			}
		}
    }
	/* Units conversion. */
    if (uunits[40] > 1)
    {
		for (j = 1; j <= 38; ++j)
        {
		    cvfj = uconvf[uunits[j] - 1];
		    prp[j] /= cvfj;
	    	prp[j + 42] /= cvfj;
		    prp[j + 84] /= cvfj;
		}
		/* Note: PRP(39,k), = Tlambda, remains in Kelvin regardless of units.*/
    }
    
    /* Convert to double */
    for (int jj=0 ; jj<126; jj++){
    	//std::cout << jj <<"\n";
    	prpdbl[jj] = (double) prp[jj];
    	}
} /* calc */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Version 3.21, Jan. 5, 1992 */
/* Symmetric matrix of response to input variables */
/*       PP  TT  DD  VV  SS  HH  UU  GG  XX  dt  MM   2  SL  SV  LL */
int he :: jm (int j1, int j2)
{
    /* Initialized data */
    int km[225]	/* was [15][15] */ = { 0,1,3,3,6,4,10,18,12,
	    21,16,12,12,12,22,1,0,2,2,7,0,0,19,13,0,17,13,13,13,23,3,2,0,0,8,
	    5,11,0,0,20,0,15,15,15,24,3,2,0,0,8,5,11,0,0,20,0,15,15,15,24,6,7,
	    8,8,0,9,0,0,0,0,0,14,14,14,0,4,0,5,5,9,0,0,0,0,0,0,14,14,14,0,10,
	    0,11,11,0,0,0,0,0,0,0,14,14,14,0,18,19,0,0,0,0,0,0,0,0,0,14,14,14,
	    0,12,13,0,0,0,0,0,0,0,0,0,0,0,0,0,21,0,20,20,0,0,0,0,0,0,0,27,27,
	    0,0,16,17,0,0,0,0,0,0,0,0,0,0,0,0,26,12,13,15,15,14,14,14,14,0,27,
	    0,0,0,0,25,12,13,15,15,14,14,14,14,0,27,0,0,0,0,25,12,13,15,15,14,
	    14,14,14,0,0,0,0,0,0,0,22,23,24,24,0,0,0,0,0,0,26,25,25,0,0 };

    return km[j1 + j2 * 15 - 16];
} /* jm */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Error messages, when the program returns with IDID < zero */
/* -----Version 3.23 */
/* Input values of IDID: */
/*  -10 TO  -99: external coding errors.  User should investigate. */
/* -100 to -199: input is outside of the valid EOS range. */
/* -200 to -299: unexpected iteration convergence failure.  Probably */
/*               due to input out of range (which should have been */
/*               caught elsewhere) or, possible programming error. */
/*               Cryodata should investigate. */
/* -----Version 3.23 */
/* Note: HEPAK does not assign IDID values of -13, -15, or -20. */
/* However, function HEFUN can return these values. */
void he :: errmsg (char* messag, int idid)
{
    /* Initialized data */
    char line[60*54+1] = "\
 Invalid input parameter(s).                                \
 Invalid combination of input parameters.                   \
 Input Pressure <= zero.                                    \
 Input Pressure too high; out of range.                     \
 Input Temperature < 0.8 K; out of range.                   \
 Input Temperature > 1500 K; out of range.                  \
 Input Density <= zero.                                     \
 Input Density is outside of valid range.                   \
 Solid phase encountered.                                   \
 Entropy out of range.                                      \
 Enthalpy out of range.                                     \
 Internal Energy out of range.                              \
 Input Gibbs energy must be in liquid between 0.8 and 3.0 K.\
 Gibbs energy iteration requires 0.8 <= Temperature <=3.0 K.\
 Pressure out of range for Gibbs energy iteration.          \
 Saturation pressure out of range (1.48 to 226463 Pa).      \
 Saturation temperature out of range (0.8 to 5.1953 K).     \
 Saturation density out of range (0.000888 to 146.16 Kg/m3).\
 Saturation entropy out of range (0.00471 to 23.936 J/g-K). \
 Saturation enthalpy out of range (0.00187 to 30.744 J/g).  \
 Saturation Helmholz E out of range (-.00191 to -11.287 J/g)\
 Saturation energy out of range (0.00186 to 24.724 J/g).    \
 Saturation Gibbs E out of range (-0.00189 to -8.0212 J/g). \
 Saturation quality must be beteen 0 and 1 (inclusive).     \
 Melting pressure out of range (25.328 to 1013.25 bars)     \
 Melting temperature > 14.0 K, pressure exceeds valid range.\
 Lambda pressure out of range (0.050418 to 30.134 bars).    \
 Lambda temperature out of range (2.1768 to 1.7673 K).      \
 Lambda density out of range (146.15 to 179.83 Kg/m3).      \
 On input, absolute value of delta-T must be < 0.5 K        \
 Liquid-vapor mixture state point.                          \
 Calculated temperature < 0.8 K                             \
 Calculated temperature > 1500. K                           \
 Calculated pressure > maximum valid pressure.              \
 Calculated density <= zero.                                \
 Input specific volume <= zero.                             \
 Indeterminant function in compressed liquid.               \
 Iteration failure with (P,T) input.  Out of range?         \
 Iteration failure with (H,S) input.  Out of range?         \
 Iteration failure with (P,G) input.  Out of range?         \
 Iteration failure with (D,P) input; compressed liquid?     \
 Failure with (D,S), (D,H) or (D,U) input.  Out of range?   \
 Failure with (P,S), (P,H) or (P,U) input.  Out of range?   \
 Unexpected iteration failure near the lambda line.         \
 (C) Copyright (1992), Cryodata, Inc.; all rights reserved. \
 Successful calculation: single phase fluid.                \
 Successful calculation: sat. liquid and vapor.             \
 Successful calculation: liquid-vapor mixture.              \
 Successful calculation: sat. liquid only.                  \
 Successful calculation: sat. vapor only.                   \
 Invalid property or units or phase index in HEFUN.         \
 HEPAK has not performed any calculations.                  \
 Calculated state point was not in specified fluid phase.   \
 Cryodata program error: invalid IDID index.			    ";

    int jidid[53] = { -11,-12,-101,-102,-103,-104,-105,-106,-107,
	    -108,-109,-110,-111,-112,-113,-121,-122,-123,-124,-125,-126,-127,
	    -128,-129,-131,-132,-141,-142,-143,-144,-145,-161,-162,-163,-164,
	    -170,-180,-201,-202,-203,-204,-205,-206,-207,0,1,2,3,4,5,-13,-20,
	    -15 };

    /* Local variables */
    int i, j;

    for (j = 0; j < 53; ++j)
    {
		if (jidid[j] == idid)
        {
            for (i=0; i<60; i++) *(messag + i) = line [j*60+i];
	    	return;
		}
    }
    for (i=0; i<60; i++) *(messag + i) = line [3180+i];
} /* errmsg */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Set precision for use in iterative routines. */
void he :: prcis (int j)
{
    /* Initialized data */
    long double a[16] = {0.0,0.03,0.01,0.003,0.001,3.0e-4,1.0e-4,3.0e-5,1.0e-5,
    					 3e-6,1.0e-6,3.0e-7,1.0e-7,3.0e-8,1.0e-8,3.0e-9 };
    long double fact[3] = { 20.0,0.5,0.002 };

    int k, n;
    long double r;

    if (j > 3) n = 3;
    else if (j < 1) n = 1;
    else n = j;
    r = fact[n - 1];
    precsn[0] = 1.0 * n;
    for (k = 1; k <= 15; k++) precsn[k] = r * a[k];
} /* prcis */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output is the array KUNITS in common /UUNITS/ */
/*    the library array KULIB (j,NK) is copied onto KUNITS. */
/* KUNITS is used in subroutine CALC.  Sequence is that of PROP array. */
/* KUNITS may be overwritten in order to customize units. */
/* Note: (j,40) is the set number, equivalent to NK */
/* If NK > NKmax, customized units have been set in an external program:*/
/*     do not overwrite. */
    // il y a des problème dans la fonction identique de Gaspak
    // Avant d'être réutilisée il faut la vérifier !!!!
void he :: unilib (int nk)
{
    /* Initialized data */
    int kulib[164]	/* was [41][4] */ = { 1,57,12,16,20,1,69,28,
	    24,28,28,28,28,60,24,24,1,65,1,53,32,36,73,69,28,58,38,1,43,46,1,
	    1,12,12,1,32,32,49,50,12,1,1,2,12,16,21,1,70,29,25,29,29,29,29,4,
	    25,25,1,65,1,7,32,34,75,70,29,40,38,1,44,47,1,1,12,12,1,32,32,51,
	    52,12,2,1,2,12,18,22,1,70,30,26,30,30,30,30,2,26,26,1,65,1,7,32,
	    34,74,70,30,40,38,1,43,47,1,1,12,12,1,32,32,51,52,12,3,1,6,13,19,
	    23,1,68,31,27,31,31,31,31,6,27,27,1,65,1,11,33,37,76,68,31,42,39,
	    1,45,48,1,1,13,13,1,33,33,49,50,12,4 };

    int j, n;

    if (nk > 4) return;
    n = maxe(1, nk);
    for (j = 0; j <= 40; ++j) uunits[j] = kulib[j + n * 41 - 41];
} /* unilib */

/* (C) Copyright (1990, 1992), Cryodata Inc.; all rights reserved. */
/*  This subroutine returns parameters from the two-fluid model */
/*  of superfluidity: */
/*  RSR  = superfluid density fraction                   [-] */
/*  V2S  = velocity of second sound                      [m/s] */
/*  V4S  = velocity of fourth sound                      [m/s] */
/*  GM   = Gorter-Mellink mutual friction parameter      [m-s/kg] */
/*  COND = conductivity parameter                        [(W/m2)3/(m/K)]*/
/*         (The defining equation for COND is that used by */
/*          Srinivasan and Hofmann, Cryogenics 25, 652 (1985), i.e., */
/*          Q**3 = COND * (dT/dX) */
/*                 where Q     = heat flux               [W/m2] */
/*                       dT/dX = temperature gradient    [K/m] */
/*          ! This equation assumes turbulent counterflow. */
/*  VISC = viscosity of the normal fluid component       [kg/(m-s)] */
/* -----INPUT */
/*  P, D, T, S are pressure, density,  temperature & entropy (SI units) */
/*  F(11) is the derivative array (see subroutine DERIV for definitions).*/
/*  DTV is T - Tlambda(V), ie, the isochoric distance from Tlambda */
/*  Version July 12, 1992; for HEPAK v3.2 */
void he :: superf (long double *cheii, long double pi, long double d, long double t,
			 long double dtv, long double s, long double *f)
{
    /* Local variables */
    long double cond, c2, dn, gm, ds, zz;
    long double v2s, v4s, rsr;

	/* Validity very close to the lambda line is unknown. */
    /* Function Body */
    if (dtv < -9.0e-4)
    {
		rsr = rsrfpt (pi, t);
		ds = d * rsr;
		dn = d - ds;
		/*  Maynard's equations (2), (3), and (5); assume small corrections.*/
		c2 = *(f+6) * *(f+6);
		v2s = (d / dn - 1.0) * t * s * s / *f;
		v2s *= *(f+3) * *(f+4) * v2s / (c2 - v2s) + 1.0;
		zz = v2s / c2 * (1.0 - *(f+3) * 2.0 * c2 / (*(f+2) * s * t));
		v4s = c2 * (1.0 - dn / d * (1.0 - zz));
		v2s = sqrtl(v2s);
		v4s = sqrtl(v4s);
		/*  GM is fitted to the data of Srinivasan and Hofmann */
		gm = dn * 10.649 + 383.7;
		/*  Asymtotic form approaching TL is given by Frederking */
		if (gm > (d - 160.0) * 12.4 + 1413.0) gm = 558.9 / rsr;
		cond = s * powl (ds * s * t, 3) / (gm * dn);
		/* Output data */
		*cheii = rsr;
		*(cheii + 1) = v2s;
		*(cheii + 2) = v4s;
		*(cheii + 3) = gm;
		*(cheii + 4) = cond;
   	}
    else
    {
		*cheii = 0;
		*(cheii + 1) = 0;
		*(cheii + 2) = 0;
		*(cheii + 3) = 0;
		*(cheii + 4) = 0;
    }
} /* superf */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/*Rhos/Rho = superfluid density fraction, from Maynard, PR B14, 3868 (1976)*/
/* as a function of P [Pascal] and T [K]. */
/* Maynard's data includes the range T/Tlambda(P) > 0.55 */
long double he :: rsrfpt (long double p, long double t)
{
    /* Initialized data */
    long double a[3] = { -2.08403569,1.760235312,-1.469764627 };

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double x;

    x = 1.0 - t / tlfp(p);
    if (x <= 0.0) ret_val = 0.0;
    else if (x <= 0.45) ret_val = a[0] * x * logl(x) + x * x * (a[1] + x * a[2]);
    else if (x < 1.0) ret_val = 1.0 - powl ((1.0 - x) / 0.55, 6) * 0.02863;
    else ret_val = 1.0;
    return ret_val;
} /* rsrfpt */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* P    = Lambda-line pressure          [Pa] */
/*      = 5041.8 at T=2.1768 */
/* DPDT = dP/dT along the lambda line   [Pa/K] */
/* D    = Density at the lambda line    [kG/M3] */
/*      = 146.15 at T=2.1768 */
/* DDDT = dD/dT along the lambda line   [kG/(M3-K)] */
/* -----INPUT */
/* T    = temperature  (T76 scale)      [K] */
/*        valid range is 2.1768 to 1.7673 */
/* -----REFERENCE */
/*H.A. Kierstead, Phys Rev 162, 153 (1967); constants revised for T76 scale*/
/* Note: Kierstead's density equation disagrees slightly with HEPAK, */
/* and is not used by HEPAK. */
void he :: kierst (long double& p, long double& xdpdt, long double& d,
			 long double& dddt, long double t)
{
    /* Initialized data */
    long double a[7] = {0.42774167,-94.820469,-85.817089,-102.39597,-76.73524,
    					-0.37798315,42.148155 };
    long double b[7] = {0.14841216,-0.15036724,-0.32811465,-0.52635312,-0.37937084,
    					-0.00226216,36.64523 };

    /* Local variables */
    long double x, ex;

    x = t - 2.1768;
    ex = expl(a[6] * x);
    p = (a[0] + x * (a[1] + x * (a[2] + x * (a[3] + x * a[4]))) + a[5] * ex) * 101325.0;
	/* Version 3.301: local variable DPDT renamed XDPDT */
    xdpdt = (a[1] + x * (a[2] * 2.0 + x * (a[3] * 3.0 + x * 4.0 * a[4])) +
    		 a[5] * a[6] * ex) * 101325.;
    ex = expl(b[6] * x);
    d = (b[0] + x * (b[1] + x * (b[2] + x * (b[3] + x * b[4]))) + b[5] * ex) * 1.0e3;
    dddt = (b[1] + x * (b[2] * 2.0 + x * (b[3] * 3.0 + x * 4.0 * b[4])) + b[5] * b[6] * ex) * 1.0e3;
} /* kierst */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Lambda line density as a function of temperature, T76 scale */
/* valid range is 2.1768 to 1.7673 */
long double he :: dlft (long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d, t;
    int jx;

    t = tt;
//    rootaz (d, 146.14, 147.0, 155.0, 182.0, precsn[8], precsn[9], precsn[11], precsn[13], tlfd, t, jx);
    rootaz (d, 146.14, 147.0, 155.0, 182.0, precsn[8], precsn[9],
    		precsn[11], precsn[13], 1, t, jx);
    if (jx <= 0) ret_val = -1.0;
    else ret_val = d;
    return ret_val;
} /* dlft */

/*  lambda line density [kg/m3] as a function of pressure [Pa] */
long double he :: dlfp(long double p)
{
    long double t = tlfp (p);
    return dlft (t);
} /* dlfp */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* P = Lambda-line pressure = 5041.8 Pa    at T = 2.1768 K */
/*                          = 30.134E+5 Pa at T = 1.7673 K */
/* reference: */
/* H.A. Kierstead, Phys Rev 162, 153 (1967) (T58 scale) */
/* refitted to T76 scale. */
long double he :: plft (long double t)
{
    /* Initialized data */
    long double b[7] = {0.42774167,-94.820469,-85.817089,-102.39597,
	    				-76.73524,-0.37798315,42.148155 };

    /* Local variables */
    long double p, x;

    x = t - 2.1768;
    p = b[0] + (b[1] + (b[2] + (b[3] + b[4] * x) * x) * x) * x + b[5]*expl(b[6]*x);
    return p * 101325.0;
} /* plft */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* lambda line temperature as a function of pressure [Pa] */
long double he :: tlfp (long double p)
{
    /* Local variables */
    int jr;
    long double pp, tt;

    pp = p;
	/* T=2.17725 corresponds to P=0 */
//    rootaz (tt, 2.17725, 2.1768, 2.0, 1.7672, precsn[9], 0.0, precsn[2], precsn[11], plft, pp, jr);
    rootaz (tt, 2.17725, 2.1768, 2.0, 1.7672, precsn[9], 0.0, precsn[2], precsn[11], 2, pp, jr);
    return tt;
} /* tlfp */

/* Saturated liquid Temperature [K] as a function of entropy [J/kg-K] */
/* Valid for 4.7128 < SJKG < 5768.4 J/kg-K, corresponding to */
/*           0.8 < T < 5.1953 K */
/* Fitted to HEPAK data, Oct 17, 1992; rms accuracy (+-) 0.035 K */
long double he :: tsatsl (long double sjkg)
{
    /* Initialized data */
    long double c[6] = {2.017414715,-1.192464994,2.441002711,-1.804761829,
    					0.580036035,-0.06892288428 };

    /* Local variables */
    long double s, s2;

    s = max(sjkg * 0.001, 0.0047);
    s2 = sqrtl(s);
    return c[0] * powl(s, 0.1736) + powl (s,4) * (c[1] + s2 * (c[2] + s2 * (c[3] +
    	   s2 * (c[4] + s2 * c[5]))));
} /* tsatsl */

/* Saturated vapor Temperature [K] as a function of entropy [J/kg-K] */
/* Valid for 5768.4 < SJKG < 23936 J/kg-K, corresponding to */
/*           5.1953 > T > 0.8 K */
/* Fitted to HEPAK data, Oct 17, 1992; rms accuracy (+-) 0.035 K */
long double he :: tsatsv (long double sjkg)
{
    /* Initialized data */
    long double c[6] = {-26.21235672,24.31127551,-13.7770157,3.157246354,
    					-0.3331317936,0.01342914271 };

    long double s = powl (sjkg * 0.001, 0.6);
    return c[0] + s * s * (c[1] + s * (c[2] + s * (c[3] + s * (c[4] + s*c[5]))));
} /* tsatsv */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* function used by SATFS */
long double he :: sats (long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d, p, xdpdt;

    psatft (p, xdpdt, t);
    if (subrt.jr == 1) d = d2lfpt (p, t);
    else d = d2vfpt (p, t);
    ret_val = entrop (d, t);
    subrt.r[0] = p;
    subrt.r[1] = xdpdt;
    subrt.r[2] = d;
    return ret_val;
} /* sats */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Quality, saturated pressure, temperature, and densities as a function*/
/* of (saturated) entropy.  SI units.  IDID=2 when successful. */
/*     Range 0.8 to 5.1953 K */
/* -----Version Oct. 17, 1992 */
/* -----Version 3.301: local variable DPDT renamed XDPDT */
void he :: satfs (int& idid, long double& qual, long double& ps, long double& xdpdt,
			long double& ts, long double& dl, long double& dv, long double ss)
{
    /* Initialized data */
    long double sc = 5768.4;
    long double tc = 5.1953;
    long double tmin = 0.8;

    /* Local variables */
    long double s, ta, tb, tt, tx;
    int jx;

    s = ss;
    if (s >= sc)
    {
		subrt.jr = 2;
		tx = tsatsv (s);
    }
    else
    {
		subrt.jr = 1;
		tx = tsatsl (s);
    }
    ta = min (max (tx, 0.81) ,5.12);
    tb = ta + 0.06;
//  rootaz (tt, tmin, ta, tb, tc, precsn[9], 0.0, precsn[5], precsn[8], sats, s, jx);
    rootaz (tt, tmin, ta, tb, tc, precsn[9], 0.0, precsn[5], precsn[8], 3, s, jx);
    if (jx < 0) idid = -124;
    else
    {
		idid = 2;
		ts = tt;
		ps = subrt.r[0];
		/* Version 3.301: local variable DPDT renamed XDPDT */
		xdpdt = subrt.r[1];
		if (subrt.jr == 2)
        {
		    dv = subrt.r[2];
		    dl = d2lfpt (ps, ts);
	    	qual = 1.0;
		}
        else
        {
		    dl = subrt.r[2];
		    dv = d2vfpt (ps, ts);
	    	qual = 0.0;
		}
    }
} /* satfs */

void he :: satfy( int& idid, long double& qual, long double& ps, long double& dpdt,
			long double& ts, long double& dl, long double& dv, long double yy,
            char label)
{
    int iter;
    long double ymin, ymax, t, y, ycrit, tymin;

    y = yy;
    if (label == 'S')
    {
		satfs(idid, qual, ps, dpdt, ts, dl, dv, y);
		return;
    }
    if (label == 'H')
    {
		ymin = 1.8766;
		ycrit = prinit.hcrit;
		ymax = prinit.hmax2p;
		tymin = 4.18;
		subrt.jr = 9;
		idid = -125;
    }
    else if (label == 'U')
    {
		ymin = 1.8665;
		ycrit = prinit.ucrit;
		ymax = prinit.umax2p;
		tymin = 4.21;
		subrt.jr = 11;
		idid = -127;
    }
    else if (label == 'G')
    {
		/* Following Gibbs energies are calculated from HEPAK v3.2 */
		ymax = -8021.2;
		ymin = -1.8963;
		ycrit = ymax;
		subrt.jr = 12;
		idid = -128;
    }
    else
    {
		idid = -299;
		return;
    }
    if ((y - ycrit) * (y - ymin) <= 0.0)
    {
//rootaz (t, prinit.tmin, 2.0, 4.5, prinit.tcrit, precsn[8], 0.0, precsn[11], precsn[9], satly, y, iter);
        rootaz (t, prinit.tmin, 2.0, 4.5, prinit.tcrit, precsn[8], 0.0, precsn[11],
                precsn[9], 4, y, iter);
		if (iter > 0)
        {
		    idid = 2;
		    ps = subrt.r[0];
	    	dpdt = subrt.r[5];
		    ts = t;
		    dl = subrt.r[2];
	    	dv = d2vfpt (subrt.r[0], t);
		    qual = 0.0;
		}
    }
    else if (((y - ycrit) * (y - ymax) <= 0.0) && (subrt.jr != 12))
    {
//rootaz (t, tymin, 4.5, 5.0, prinit.tcrit, precsn[8], 0.0, precsn[11], precsn[9], satvy, y, iter);
		rootaz (t, tymin, 4.5, 5.0, prinit.tcrit, precsn[8],
		 		0.0, precsn[11], precsn[9], 5, y, iter);
		if (iter > 0)
        {
		    idid = 2;
		    ps = subrt.r[0];
	    	dpdt = subrt.r[5];
		    ts = t;
		    dv = subrt.r[2];
	    	dl = d2lfpt (subrt.r[0], t);
		    qual = 1.0;
		}
    }
} /* satfy */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* External function for SATFY; see it for definitions; v 1/5/93 */
long double he :: satly (long double t)
{
    psatft (subrt.r[0], subrt.r[5], t);
    subrt.r[2] = d2lfpt (subrt.r[0], t);
    subrt.r[1] = t;
    shaug (&subrt.r[0]);
    return subrt.r[subrt.jr - 1];
} /* satly */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* External function for SATFY; see it for definitions; v 1/5/93 */
long double he :: satvy (long double t)
{
    psatft (subrt.r[0], subrt.r[5], t);
    subrt.r[2] = d2vfpt (subrt.r[0], t);
    subrt.r[1] = t;
    shaug (&subrt.r[0]);
    return subrt.r[subrt.jr - 1];
} /* satvy */

/* T76 as a function of T58; valid from 0.8 to Tc */
/* RMS fitting error = 66 microdegrees. */
/* constrained for 0 error at T58 = 2.172 and 5.190 */
/*This function is not used by HEPAK.  It is listed here for reference only.*/
/*     DATA A / 0.1498489151E-02, 0.1152508836E-02,  0.1692099224E-03/ */
long double he :: t7658 (long double t58)
{
    /* Initialized data */
    long double a[4] = {-0.001891260993,0.00850893784,-0.004836428596,0.001076075419};
    long double b[3] = {0.007530201452,-0.002681259464,9.78462867e-4 };
    long double c[3] = {0.006115602751,0.001146742367,-2.76784046e-4 };

    /* Local variables */
    long double x;

    if (t58 <= 2.172) return t58 + a[0] + t58 * (a[1] + t58 * (a[2] + t58 * a[3]));
    else if (t58 <= 4.082)
    {
		x = 1.0 / (t58 - 1.7);
		return t58 + b[0] + x * x * (b[1] + x * b[2]);
    }
    else if (t58 <= 4.619) return t58 + 0.00713;
    else if (t58 <= 5.19)
    {
		x = 1.0 / (5.4 - t58);
		return t58 + c[0] + x * (c[1] + x * c[2]);
    } else return -1.0;
} /* t7658 */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* This subroutine iterates for density D [Kg/m3], given P [Pa] and T [K]. */
/* It is valid only in the compressed liquid near the lambda line, where*/
/* it is more precise than subroutine DFPT */
void he :: df2pt (int& idid, long double& d, long double pp, long double tt)
{
    long double deld, delp, p, t;
    int j;

    t = tt;
    p = pp;
    d = d175k (t);
    idid = 1;
    for (j = 1; j <= 5; ++j)
    {
		delp = p - pressa (d, t);
		deld = dpdda (d, t);
		if (fabsl(deld) < 1.0e-8)
        {
	    	idid = -207;
		    return;
		}
		deld = delp / deld;
		d += deld;
		if (fabsl(deld) < 0.001) return;
    }
    idid = -207;
    return;
} /* df2pt */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/*  density given pressure and temperature [SI units]. */
void he :: dfpt (int& idid, long double& d, long double& x, long double p, long double t)
{
    /* Initialized data */
    long double p20 = 2.0e6;

    /* Local variables */
    long double dmin, dmax;
    long double tline, da, db, rho;
    int jx;

    subrt.r[0] = t;
    if (p > prinit.pmax)
    {
		idid = -102;
		return;
    }
    else if (p <= 0.0)
    {
		idid = -101;
		return;
    }
    else if (t < 0.7999)
    {
		idid = -103;
		return;
    }
    tline = p * 1.0e-6 + 11.0;
    if (t > tline)
    {
		/* close to ideal gas */
		if (t > prinit.tmax)
        {
	    	idid = -104;
	    	return;
		}
		rho = rhobb (p, t);
		dmax = denmax(t);
		dmin = 1.0e-8;
		da = min(rho, dmax);
		db = da * 0.9;
    }
	/* check saturation line */
    else if (t < prinit.tcrit)
    {
		if (p >= p20)
        {
	    	dmax = dmft (t) + 0.3;
		    da = 170.0;
		    db = (da + dmax) * 0.5;
	    	dmin = 150.0;
		}
        else if (p < psat (t))
        {
		    da = p / (t * 2200.0);
		    db = dgsat (t);
	    	dmin = 1.0e-8;
		    dmax = db * 1.03;
		}
        else
        {
		    dmin = dfsat (t) * 0.97;
		    db = d175k (p) + 1.0;
	    	da = (db + dmin) * 0.5;
		    dmax = 180.0;
		}
    }
    else if (p < prinit.pcrit)
    {
		da = p / (t * 2077.0);
		dmax = 70.0;
		db = min(dmax, da * 2.0);
		dmin = 1.0e-8;
    }
    else
    {
		dmax = denmax (t);
		dmin = 5.0;
		if (p < p20)
        {
	    	da = 320.0 / t + p * 2.0e-5;
		    db = da * 1.5;
		}
        else
        {
		    da = min(p * 4.0e-7 + 80.0, dmax * 0.7);
		    db = (da + dmax) * 0.5;
		}
    }
//rootaz (rho, dmin, da, db, dmax, precsn[15], precsn[10], precsn[15], precsn[10], dpt, p, jx);
    rootaz (rho, dmin, da, db, dmax, precsn[15], precsn[10], precsn[15], precsn[10], 6, p, jx);
    if (jx <= 0)
    {
		idid = -201;
		if (t < 14.05) idid = -107;
    }
    else
    {
		d = rho;
		idid = 1;
		if (rho > prinit.dcrit) x = -1.0;
		else x = 2.0;
    }
} /* dfpt */

long double he :: dpt (long double d)
{
	/* Function used by DFPT */
    return press (d, subrt.r[0]);
} /* dpt */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/*  density given entropy and temperature [SI units]. */
void he :: dfst (int& idid, long double& rho, long double& x, long double& rf,
		   long double& rg, long double& p, long double& dpdts, long double s,
           long double t)
{
    /* Local variables */
    long double dmin, dmax, xpsat;
    long double da, db, sg, sf;
    int jx;
    long double eya, dum;

    if (s * (s - 6.4e4) >= 0.0)
    {
		idid = -108;
		return;
    }
    if (t < prinit.tmin)
    {
		idid = -103;
		return;
    }
    if (t > prinit.tmax)
    {
		idid = -104;
		return;
    }
    x = 2.0;
    subrt.r[0] = t;
    dmax = denmax (t);
    if (t < prinit.tcrit)
    {
		/* Version 3.301: local variable PSAT renamed XPSAT (2 lines) */
		psatft (xpsat, dum, t);
		rg = d2vfpt (xpsat, t);
		sg = entrop (rg, t);
		if (s >= sg)
        {
	    	dmax = rg * 1.01;
	    	da = rg * expl((sg - s) / prinit.rr);
		    db = sqrtl(da * dmax);
		    dmin = 1.0e-8;
		}
        else
        {
			/* Version 3.301: local variable PSAT renamed XPSAT */
		    rf = d2lfpt (xpsat, t);
		    sf = entrop (rf, t);
	    	if (s > sf)
            {
				x = (s - sf) / (sg - sf);
				rho = rf / (x * (rf / rg - 1.0) + 1.0);
				/* Version 3.301: local variable PSAT renamed XPSAT */
				p = xpsat;
				dpdts = dum;
				idid = 3;
				return;
	    	}
            else
            {
				dmin = rf * 0.99;
				da = dmin * 0.75 + dmax * 0.25;
				db = dmin * 0.25 + dmax * 0.75;
		    }
		}
    }
    else
    {
		da = prinit.dhi * 1.2 * expl((prinit.shi - s +
		prinit.cvhi * logl(t / prinit.thi)) / prinit.rr);
		da = min(da,dmax);
		dmin = 1.0e-8;
		db = max(da * 0.67, dmin);
    }
    eya = prinit.cvhi * precsn[10];
//  rootaz (rho, dmin, da, db, dmax, precsn[15], precsn[10], eya, precsn[10], dst, s, jx);
    rootaz (rho, dmin, da, db, dmax, precsn[15], precsn[10], eya, precsn[10], 7, s, jx);
    if (jx <= 0) idid = -108;
    else
    {
		if (rho > prinit.dcrit) x = -1.0;
		idid = 1;
    }
} /* dfst */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Function used by DFST */
long double he :: dst (long double y)
{
    return entrop (y, subrt.r[0]);
} /* dst */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/*Density, Temperature, and Quality as a function of Enthalpy and Entropy.*/
/*In the two phase region (quality between 0 and 1), saturation densities,*/
/*pressure, and dP/dT are also returned. SI units. Valid from 0.8 to 1500K.*/
/* Following are entropy and temperature when H(sat vap) is maximum */
/* Version August 29, 1992 */
/* Following 2 elements of RR are not modified by the call to ROOT */
void he :: dtfhs (int &idid, long double& d, long double& t, long double& x,
			long double& dl, long double& dv, long double p, long double dpdt,
            long double h, long double s)
{
    /* Initialized data */
    long double shmax2 = 8545.0;
    long double thmax2 = 4.17;

    /* Local variables */
    int i, jx;
    long double d1, t1;
    long double sl, sv;

    subrt.r[3] = s;
    subrt.r[4] = h;
    x = 2.0;
    if (s * (s - 6.4e4) >= 0.0)
    {
		idid = -108;
		return;
    }
    if (h * (h - 8.1e6) >= 0.)
    {
		idid = -109;
		return;
    }
    if (h < prinit.hmax2p)
    {
		/* If in the two-phase region, then we can find T such that H-TS = Gsat(T) */
//rootaz (t1, prinit.tmin, 1.2, 3.6, prinit.tcrit, precsn[8],0.0, precsn[9], precsn[10], dths, 0.0, jx);
		rootaz (t1, prinit.tmin, 1.2, 3.6, prinit.tcrit, precsn[8],
        		0.0, precsn[9], precsn[10], 8, 0.0, jx);
		if (jx > 0)
        {
			/* Two phase */
	    	t = t1;
		    psatft (p, dpdt, t1);
		    dl = d2lfpt (p, t1);
	    	dv = d2vfpt (p, t1);
		    sl = entrop (dl, t1);
		    sv = entrop (dv, t1);
	    	if (sv != sl)
            {
				x = (s - sl) / (sv - sl);
				d = 1.0 / (1.0 / dl * (1.0 - x) + 1.0 / dv * x);
	    	}
            else
            {
				x = 0.5;
				d = prinit.dcrit;
	    	}
		    if (x < 0.0) d1 = dl;
	    	else if (x > 1.0) d1 = dv;
		    else
            {
				idid = 3;
				return;
	    	}
		}
        else if (s <= 0.0)
        {
	    	idid = -108;
	    	return;
		}
        else if (s < prinit.scrit)
        {
			/* Compressed liquid */
	    	t1 = prinit.tmin + s / prinit.scrit * (prinit.tcrit - prinit.tmin);
	    	d1 = dfsat (t1) * 1.005;
		}
        else if (s < shmax2)
        {
			/* Near saturated vapor, T > THMAX2 */
		    t1 = (s - prinit.scrit) / (shmax2 - prinit.scrit);
		    t1 = prinit.tcrit * (1.0 - t1) + thmax2 * t1;
	    	d1 = dgsat (t1) * 0.95;
		} else if (h <= 0.0)
        {
	    	idid = -109;
		    return;
		}
        else
        {
			/* Vapor, T < TCRIT */
			/* Latent heat at T = 0 is about 21000 J/KG */
			/* Computing MAX */
		    t1 = max(prinit.tmin, (h - 2.1e4) * thmax2 / prinit.hmax2p);
		    if (t1 >= prinit.tcrit) t1 = prinit.tcrit - 0.04;
		    d1 = dgsat (t1);
		}
    }
    else
    {
		/* use ideal gas approximation */
		t1 = max (prinit.thi + (h - prinit.hhi) / prinit.cphi, prinit.tcrit + 2.0);
		t1 = min (t1, 1500.0);
		d1 = prinit.dhi * expl((prinit.shi - s - prinit.cvhi * logl(prinit.thi / t1)) / prinit.rr);
		d1 = min (d1, denmax (t1));
		d1 = max (d1, 1.0e-5);
    }
    dtilxy (d1, t1, i, "HS", h, s);
    if (i <= 0) idid = -202;
    else
    {
		d = d1;
		t = t1;
		dl = 0.0;
		dv = 0.0;
		if (d > prinit.dcrit) x = -1.0;
		idid = 1;
    }
} /* dtfhs */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* External function in DTFHS; Version Sept 9, 1989 */
long double he :: dths (long double t)
{
    /* Local variables */
    long double gsat;

    subrt.r[1] = t;
    gsat = subrt.r[4] - subrt.r[1] * subrt.r[3];
    psatft (subrt.r[0], subrt.r[5], subrt.r[1]);
    subrt.r[2] = d2lfpt (subrt.r[0], subrt.r[1]);
    shaug (&subrt.r[0]);
    return gsat - subrt.r[11];
} /* dths */

long double he :: dmfp (long double p)
{
	/* -----melting density as a function of pressure */
    long double t = tmfp (p);
    return dmft (t);
} /* dmfp */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/*  melting pressure as a function of temperature, T76 scale below 5.1953*/
/*  F1 to F3 have been refitted to T58 equations of Grilly and Mills. */
/*  F4 and F5 have been fitted to Grilly and Mills data. */
long double he :: pmft (long double tt)
{
    /* Initialized data */
    long double conv = 98066.5;
    long double con2 = 101325.0;
    long double delt = 0.005;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double t, w;

    t = tt;
	/* Cut off at the upper limit of HEPAK */
    if (t > 14.0104) ret_val = 1.01325e8;
    else if (t >= delt + 5.1953) ret_val = (powl (t, 1.555414) * 17.31457 - 17.8) * conv;
    else if (t > 5.1953 - delt)
    {
		w = (t - 5.1953) / (delt * 2.0) + 0.5;
		ret_val = w * ((powl (t, 1.555414) * 17.31457 - 17.8) * conv) + (1.0 - w)
        * ((t * (t * (t * (t * 0.310795 - 4.91282) + 32.26926) - 45.31231) + 34.2097) * conv);
    }
    else if (t >= delt + 2.0044)
		ret_val = (t*(t*(t*(t * 0.310795 - 4.91282) + 32.26926) - 45.31231) + 34.2097) * conv;
    else if (t > 2.0044 - delt)
    {
		w = (t - 2.0044) / (delt * 2.0) + 0.5;
		ret_val = w * ((t * (t * (t * (t * 0.310795 - 4.91282) + 32.26926) - 45.31231) + 34.2097) * conv)
			+ (1. - w) * ((t * (t * 12.57562 - 15.49444) + 17.8537) * con2);
    }
    else if (t >= delt + 1.766) ret_val = (t * (t * 12.57562 - 15.49444) + 17.8537) * con2;
    else if (t > 1.766 - delt)
    {
		w = (t - 1.766) / (delt * 2.0) + 0.5;
		ret_val = w * ((t * (t * 12.57562 - 15.49444) + 17.8537) * con2)
        + (1.0 - w) * ((t * (t * 35.1175 - 101.4497) + 99.3328) * con2);
    }
    else if (t >= delt + 1.4676) ret_val = (t * (t * 35.1175 - 101.4497) + 99.3328) * con2;
    else if (t > 1.4676 - delt)
    {
		w = (t - 1.4676) / (delt * 2.0) + 0.5;
		ret_val = w * ((t * (t * 35.1175 - 101.4497) + 99.3328) * con2)
        + (1.0 - w) * ((powl (t - 0.725, 4) * 3.3693 + 24.997) * con2);
    }
    else if (t >= 0.8) ret_val = (powl (t - 0.725, 4) * 3.3693 + 24.997) * con2;
    else ret_val = -1.0;
    return ret_val;
} /* pmft */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* melting temperature as a function of pressure [Pa] */
long double he :: tmfp (long double pp)
{
    /* Local variables */
    long double p;
    int jx;
    long double tt;

    p = pp;
//  rootaz (tt, 0.8, 2.0, 8.0, 14.0104, precsn[8], precsn[10], precsn[2], precsn[10], pmft, p, jx);
    rootaz (tt, 0.8, 2.0, 8.0, 14.0104, precsn[8], precsn[10], precsn[2], precsn[10], 9, p, jx);
    if (jx <= 0) return -1.0;
    else return tt;
} /* tmfp */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/*  Beattie-Bridgeman equation used for approximate density */
long double he :: rhobb (long double p, long double t)
{
    /* Initialized data */
    long double a0 = 0.0216;
    long double asm_ = 0.05984;
    long double b0 = 0.014;
    long double bsm = 0.0;
    long double csm = 40.0;
    long double rbb = 0.08206;
    long double amw = 4.0026;

    /* Local variables */
    static long double pi;

    pi = rbb * t * 101325.0 / p;
    return amw / ((pi + b0 * (1.0 - bsm / pi)) * (1.0 - csm /
		    pi * powl (t, -3)) - a0 * (1.0 - asm_ / pi) / (rbb * t));
} /* rhobb */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* This function written by V. Arp. */
/* -----OUTPUT */
/* U3K = Internal Energy [J/kG] at 3 K, for P > P(sat) */
/* -----INPUT */
/* P   = Pressure [Pa] ; fitted to 70 atmospheres */
/* -----ACCURACY */
/* Accuracy about +/- 4.  J/kG for pressures below 2 bars */
/*          about +/- 10. J/kG for pressures above 2 bars */
/* -----Version Sept 18, 1987 */
long double he :: u3k (long double p)
{
    /* Initialized data */
    long double c[5] = {4947.998498,-100.8309679,-106.6139445,29.95380841,-1.53619894};

    /* Local variables */
    long double z;

    if (p <= 0.0) return -1.0;
    else
    {
		z = sqrtl(p * 1.0e-5);
		return c[0] + z * (c[1] + z * (c[2] + z * (c[3] + z * c[4])));
    }
} /* u3k */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* D3K = Density [kG/m3] at 3 K, for P > P(sat) */
/* -----INPUT */
/* P   = Pressure [Pa] ; fitted to 74 bars */
/* -----ACCURACY */
/* Accuracy about +/- 0.1 kG/m3 for pressures below 15 bars */
/*          about +/- 0.3 kG/m3 for pressures above 15 bars */
/* -----Version Sept 18, 1987 */
long double he :: d3k (long double p)
{
    /* Initialized data */
    long double c[5] = { 139.8535389,1.496220385,2.334289084,-0.3419086874,0.0171614572 };

    /* Local variables */
    static long double z;

    if (p <= 0.0) return -1.0;
    else
    {
		z = sqrtl(p * 1.0e-5);
		return c[0] + z * (c[1] + z * (c[2] + z * (c[3] + z * c[4])));
    }
} /* d3k */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output: Density (RHO), Temperature (TT), and Quality (Q) */
/*         If Q is between 0 and 1, the saturation pressure P, its */
/*         derivative dP/dT, and saturation densitites DL and DV */
/*         are also evaluated. SI units. */
/* Input:  Pressure (P) and parameter X, where X can be entropy (S), */
/*         enthalpy (H) or internal energy (U), depending on LABEL. */
/* Range:  valid over the full state equation, including 2-phase region */
/* Version 3.2; indices changed to match PROP array */
void he :: dtfpx( int& idid, long double& rho, long double& tt, long double& q,
		    long double& dl, long double& dv, long double& dpdts, long double p,
            long double x, char label[2])
{
    /* Initialized data */
    long double fhip1[4] = { 2900.0,7.12e5,0.0,2.7e5 };
    long double fhip2[4] = { 17400.0,5.45e6,0.0,1.51e6 };

    /* Local variables */
    long double fder[11];
    long double delt;
    long double spht, d;
    int i;
    long double t;
    long double x3;
    int jf;
    long double fl[13], dm, ta, fv[13], tm, ts;
    long double dum;

    if (p <= 0.0)
    {
    	idid = -101;
		return;
    } else if (p > prinit.pmax)
    {
		idid = -102;
		return;
    } else if (strcmp(label, "PS") == 0)
    {
		idid = -108;
		if (x * (x - 6.4e4) >= 0.) return;
		spht = prinit.cphi;
		jf = 8;
		ta = prinit.thi * expl((x - prinit.shi + prinit.rr * logl(p *
		1.0e-5)) / prinit.cphi);
    } else if (strcmp(label, "PH") == 0)
    {
		idid = -109;
		if (x * (x - 8.1e6) >= 0.) return;
		spht = prinit.cphi;
		jf = 9;
		ta = prinit.thi + (x - prinit.hhi) / prinit.cphi;
    } else if (strcmp(label, "PU") == 0)
    {
		idid = -110;
		if (x * (x - 4.73e6) >= 0.) return;
		spht = prinit.cvhi;
		jf = 11;
		ta = prinit.thi + (x - prinit.uhi) / prinit.cvhi;
    }
    if (x < 1.0) return;
    t = -1.0;
    if ((ta > 15.0) && (p < 1.02e8))
    {
		/* Check for approximate ideal gas */
        d = rhobb (p, ta);
		if ((p < 2.0e6) || (d < prinit.dcrit)) t = ta;
    }
    if (t < 0.0)
    {
		if (p < prinit.pcrit)
        {
	    	if (p < 1.47)
            {
				/* PSAT (0.8) = 1.4752 PA; low pressure vapor */
				t = max(prinit.tmin,ta);
				d = p / (prinit.rr * t);
	    	}
            else
            {
				/* Compare with saturated vapor */
				ts = tsatfp(p);
				dv = d2vfpt (p, ts);
				if (jf == 8)
                {
		    		fv[7] = entrop (dv, ts);
		    		if (x > fv[7]) t = ts * expl((x - fv[7]) / spht);
				}
                else
                {
				    fv[0] = p;
				    fv[1] = ts;
				    fv[2] = dv;
				    shaug (&fv[0]);
				    if (x > fv[jf - 1]) t = ts + (x - fv[jf - 1]) / spht;
				}
				/* Single phase vapor */
				if (t > 0.0) d = dv * ts / t;
				else
                {
					/* Not vapor; compare with saturated liquid */
				    dl = d2lfpt (p, ts);
				    if (jf == 8) fl[7] = entrop (dl, ts);
		    		else
                    {
						fl[0] = p;
						fl[1] = ts;
						fl[2] = dl;
						shaug (&fl[0]);
		    		}
		    		if (x > fl[jf - 1])
                    {
						/* Two phase mixture */
						if (fl[jf - 1] == fv[jf - 1]) q = 0.5;
						else q = roun01 ((x - fl[jf-1]) / (fv[jf-1] - fl[jf-1]));
						psatft (dum, dpdts, ts);
						rho = dl / (q * (dl / dv - 1.0) + 1.0);
						tt = ts;
						idid = 3;
						return;
		    		}
                    else
                    {
						/* Compressed liquid */
						deriv (&fder[0], dl, ts);
						delt = (x - fl[jf - 1]) / fder[0];
						if (jf == 8) delt *= t;
						t = ts + delt;
						if (t < prinit.tmin) t = prinit.tmin;
						d = max(d3k (p), dl);
				    }
				}
	    	}
		}
        else if (p < 2.54e6)
        {
			/* Compressed liquid */
            d = d3k (p);
	    	if (jf == 8)
            {
				x3 = s3k (p);
				if (x > x3)
                {
		    		t = expl((x - x3) / spht) * 3.0;
		    		d = d * 3.0 / t;
				}
                else t = max(prinit.tmin, (x - x3) / spht + 3.0);
	    	}
            else
            {
				if (jf == 9) x3 = h3k (p);
				else x3 = u3k (p);
				t = max(prinit.tmin, (x - x3) / spht + 3.0);
				if (x > x3) d = d * 3.0 / t;
		    }
		}
        else if (p > 1e8)
        {
	    	if ((x - fhip1[jf - 8]) * (x - fhip2[jf - 8]) > 0.0) return;
		    d = p * 1.8e-7 + 150.0;
	    	t = 180.0;
		}
        else
        {
			/* Possible solid */
	    	tm = tmfp (p);
	    	dm = dmfp (p);
	    	fl[0] = p;
		    fl[1] = tm;
		    fl[2] = dm;
	    	shaug (&fl[0]);
		    if (x < fl[jf - 1] * 0.999)
            {
				idid = -107;
				return;
		    }
		    t = tm + (x - fl[jf - 1]) / spht;
	    	if (jf == 8) t = tm * expl((x - fl[jf - 1]) / spht);
	    	d = dm * sqrtl(tm / t);
		}
    }
    dtilxy (d, t, i, label, p, x);
    if (i < 0) idid = -206;
    else
    {
		idid = 1;
		dl = 0.0;
		dv = 0.0;
		if (d > prinit.dcrit) q = -1.0;
		else q = 2.0;
		rho = d;
		tt = t;
    }
} /* dtfpx */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* density [kg/m3] of HeII as a function of P [Pa] at T(58)=1.75 */
/* accuracy probably about 0.2%. */
long double he :: d175k (long double Pa)
{
    /* Initialized data */
    long double c[6] = { -0.8129582813,18.5990126,-6.344068036,
	    				 2.844939685,-0.8216755033,0.1044392629 };
    long double den0 = 146.081;

    /* Local variables */
    long double p;

    p = Pa * 1.0e-6;
    return den0 + c[0] + p*(c[1] + p*(c[2] + p*(c[3] + p*(c[4] + p*c[5]))));
} /* d175k */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* H3K = Enthalpy [J/kG] at 3 K, for P > P(sat) */
/* -----INPUT */
/* P   = Pressure [Pa] ; fitted to 70 atmospheres */
/* -----ACCURACY */
/* Accuracy about +/- 4.  J/kG for pressures below 2 bars */
/*          about +/- 25. J/kG for pressures above 2 bars */
/* -----Version Sept 18, 1987 */
long double he :: h3k (long double p)
{
    /* Initialized data */
    long double c[4] = {4954.376389,-130.2167945,657.1877607,-13.82310121};

    /* Local variables */
    long double z;

    if (p <= 0.0) return -1.0;
    else
    {
		z = sqrtl(p * 1.0e-5);
		return c[0] + z * (c[1] + z * (c[2] + z * c[3]));
    }
} /* h3k */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* S3K = Entropy [J/(kG-K)] at 3 K, for P > P(sat) */
/* -----INPUT */
/* P   = Pressure [Pa] ; fitted to 70 atmospheres */
/* -----ACCURACY */
/* Accuracy about +/- 1. J/(kG-K) for pressures below 2 bars */
/*          about +/- 8. J/(kG-K) for pressures above 2 bars */
/* -----Version Sept 18, 1987 */
long double he :: s3k (long double p)
{
    /* Initialized data */
    long double c[5] = { 2365.990305,-30.12076857,-34.92403215, 5.141720002,-0.261267804 };

    /* Local variables */
    long double z;

    if (p <= 0.0) return -1.0;
    else
    {
		z = sqrtl(p * 1.0e-5);
	    return c[0] + z * (c[1] + z * (c[2] + z * (c[3] + z * c[4])));
    }
} /* s3k */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Density and temperature as a function of pressure and Gibbs energy */
/* This subroutine valid only in the compressed liquid between 0.8 & 3 K*/
void he :: dtfpg (int& idid, long double& dcalc, long double& tcalc, long double p,
			long double g)
{
    long double d, gcalc;
    int j;
    long double pcalc, t;
    long double g3k;
    long double prp[13];

    if ((p < 1.46) || (p > 3.02e6))
    {
		idid = -113;
		return;
    }
    pcalc = p;
    g3k = h3k (pcalc) - s3k (pcalc) * 3.0;
    d = d175k (pcalc);
    t = 0.8;
    prp[0] = pcalc;
    prp[1] = t;
    prp[2] = d;
    shaug (&prp[0]);
    gcalc = prp[11];
    if ((g - gcalc) * (g - g3k) > 0.0)
    {
		idid = -111;
		return;
    }
    t = (g - gcalc) / (g3k - gcalc) * 2.2 + 0.8;
    dtilxy (d, t, j, "PG", p, g);
    if (j <= 0) idid = -203;
    else
    {
		idid = 1;
		dcalc = d;
		tcalc = t;
    }
} /* dtfpg */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* Output: CVM [J/mol-K] = Cv = specific heat at constant volume */
/* Input:  RHO [mol/L]   = density (2-phase region excluded) */
/*         T [K]         = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: cvm (long double rho, long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double cint, d, f, d2, d4, ti, tt, gd1, gd2, gd3, gd4, gg2,
	    		gg3, gg4, gg5, gg6, gd5, gd6, ti2, gmi;

    tt = t;
    d = rho;
    d2 = d * d;
    d4 = d2 * d2;
    ti = 1.0 / tt;
    ti2 = ti * ti;
    f = expl(mc1.gm * d2);
    gmi = 0.5 / mc1.gm;
    gg2 = gmi * -2.0 * gmi;
    gg3 = gg2 * -4.0 * gmi;
    gg4 = gg3 * -6.0 * gmi;
    gg5 = gg4 * -8.0 * gmi;
    gg6 = gg5 * -10.0 * gmi;
    gd1 = f * gmi;
    gd2 = (f * d2 - gd1 * 2.0) * gmi;
    gd3 = (f * d4 - gd2 * 4.0) * gmi;
    gd4 = (f * d4 * d2 - gd3 * 6.0) * gmi;
    gd5 = (f * d4 * d4 - gd4 * 8.0) * gmi;
    gd6 = (f * d4 * d4 * d2 - gd5 * 10.0) * gmi;
    cint = d * (mc1.g[1] * -0.25 / sqrtl(tt) + ti2 * (mc1.g[3] * 2.0 +
	    mc1.g[4] * 6.0 * ti + d * (mc1.g[7] + mc1.g[8] * 3.0 * ti +
	    mc1.g[11] * 2.0/3.0 * d)) + d4 * ti2 * ((((mc1.g[18] * 0.75 * d
        + mc1.g[17] * 0.8571428571428571) * ti + mc1.g[16] * .2857142857142857)
        * d + mc1.g[15] / 3.0) * d + ti * 1.2 * mc1.g[14] + mc1.g[13] * 0.4))
        + ti2 * 6.0 * ti * ((gd1 - gmi) * (mc1.g[19] + ti * 2.0 * mc1.g[20])
        + (gd2 - gg2) * (mc1.g[21] + ti2 * 10.0 / 3.0 * mc1.g[22]) +
	    (gd3 - gg3) * (mc1.g[23] + ti * 2.0 * mc1.g[24]) + (gd4 - gg4)
	    * (mc1.g[25] + ti2 * 10.0 / 3.0 * mc1.g[26]) + (gd5 -
	    gg5) * (mc1.g[27] + ti * 2.0 * mc1.g[28]) + (gd6 - gg6) * (
	    mc1.g[29] + ti * (mc1.g[30] * 2. + ti * 10.0 / 3.0 * mc1.g[31])));
    ret_val = (0.02078575 - (mc1.r + cint)) * 1.0e3;
    return ret_val;
} /* cvm */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Cv as a function of density and temperature [SI units] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: cva (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double f[7];
    int j, k, m;
    long double q[4], t, v, x, t2, ff, dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    t2 = t * t;
    f[0] = x;
    for (j = 1; j <= 4; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 6; ++k)
    {
		ff = f[k - 1] / k;
		for (j = 1; j <= 4; ++j)
        {
		    q[j - 1] += ff * subhec.c[j * 6 + k + 5 + m * 41 - 42];
		}
		f[k] = f[k - 1] * x;
    }
    ret_val = (pvtcsa[3] + t * (q[0] * 2.0 + t2 * (q[1] * 12.0 + t2 * (q[2] *
	    30.0 + t2 * 56.0 * q[3]))) + t * (subhec.c[m * 41 - 6] + t2 * (
	    subhec.c[m * 41 - 5] + t2 * (subhec.c[m * 41 - 4] + t2 *
	    subhec.c[m * 41 - 3])))) * 1.0e3;
    return ret_val;
} /* cva */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Cv [J/(kg-K)] as a function of density [kg/m3] and temperature [K] */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
long double he :: cv (long double d, long double t)
{
    /* Initialized data */
    long double gmwt = 4.0026;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double ca, th, tl, wt;

    amlap (tl, th, d);
    if (t > tl)
    {
		ret_val = cvm (d / gmwt, t) * 1.0e3 / gmwt;
		if (t >= th) return ret_val;
    }
    ca = cva (d, t);
    if (t <= tl) ret_val = ca;
    else
    {
		wt = (t - tl) / (th - tl);
		ret_val = wt * ret_val + (1.0 - wt) * ca;
    }
    return ret_val;
} /* cv */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* F( 1) = Cp    = Specific heat at constant P    [J/(kG-K)] */
/* F( 2) = Cv    = Specific heat at constant V    [J/(kG-K)] */
/* F( 3) = Gamma = Cp/Cv                          [-] */
/* F( 4) = Alpha = (T/V)(dV/dT)  at constant P    [-] */
/* F( 5) = Grun  = (V/Cv)(dP/dT) at constant V    [-] */
/* F( 6) = Kt    = (1/D)(dD/dP)  at constant T    [1/Pa] */
/* F( 7) = C     = velocity of sound              [m/s] */
/* F( 8) = JT    = Joule-Thomson coefficient      [K/Pa] */
/*                 (= dT/dP at constant H) */
/* F( 9) = DPDD  = dP/dD at constant T            [Pa-m3/kG] */
/* F(10) = DPDT  = dP/dT at constant D            [Pa/K] */
/* F(11) = V*(DH/DV) at constant P                [J/kG] */
/* -----INPUT */
/* D     = DI = Density                           [kG/M3] */
/* T     = TI = Temperature                       [K] */
void he :: deriv (long double* f, long double di, long double ti)
{
    /* Initialized data */
    long double d = -10.0;
    long double t = -10.0;

    /* Local variables */
    long double a, b;
    long double ccv;

    /* Function Body */
	/* A, B, CCV, D, and T are local variables (SAVEd from the previous call) */
    if ((di != d) || (ti != t))
    {
		d = di;
		t = ti;
		a = dpdt (d, t);
		b = dpdd (d, t);
		ccv = cv (d, t);
    }
    *(f + 1) = ccv;
    *(f + 5) = 1.0 / (b * d);
    *(f + 3) = t * a * *(f + 5);
    *(f + 4) = a / (d * ccv);
    *(f + 2) = *(f + 3) * *(f + 4) + 1.0;
    *(f + 6) = max(*(f + 2) * b, 1.0);
    *(f + 10) = *(f + 6) / *(f + 4);
    *(f + 6) = sqrtl (*(f + 6));
    *f = *(f + 2) * *(f + 1);
    *(f + 7) = (*(f + 3) - 1.0) / (d * *f);
    *(f + 8) = b;
    *(f + 9) = a;
} /* deriv */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* D = Density     [kG/m3] */
/* T = Temperature [K] */
/* J = Iteration index, which should be a positive number */
/*     If J is negative, it signals convergence failure. */
/* -----INPUT */
/* D = an initial estimate for density */
/* T = an initial estimate for temperature */
/* LABEL = a character variable specifying the pair (X,Y) */
/* X = Thermodynamic variable identified by LABEL */
/* Y = Thermodynamic variable identified by LABEL */
/* ----- Version August 29, 1992 */
void he :: dtilxy (long double& d, long double& t, int& j, char label[2],
			 long double x, long double y)
{
    /* Local variables */
    long double deld, delg, delh, delp, dels, delt, delu, f[11];
    int i;
    long double pcalc, fract;
    long double c2, ompks;
    bool calldr;
    long double ckt, prp[13];

    j = 0;
    fract = 0.3;
    calldr = true;
    for (i = 1; i <= 30; ++i)
    {
		pcalc = press (d, t);
		prp[0] = pcalc;
		prp[1] = t;
		prp[2] = d;
		shaug (&prp[0]);
		if (calldr) deriv (&f[0], d, t);
		c2 = f[6] * f[6];
		if (strcmp(label, "PH") == 0)
        {
			/* X is Pressure, Y is Enthalpy */
	    	delp = x - pcalc;
	    	delh = y - prp[8];
	    	if ((fabsl(delp) < precsn[9] * x + precsn[1])
            	&& (fabsl(delh) < precsn[9] * y + precsn[1])) j = i;
	    	deld = ((f[4] + 1.0) * delp - d * f[4] * delh) / c2;
	    	delt = f[7] * delp + delh / f[0];
		} else if (strcmp(label, "PS") == 0)
        {
			/* X is Pressure, Y is Entropy */
	    	delp = x - pcalc;
	    	dels = y - prp[7];
	    	if ((fabsl(delp / x) < precsn[9])
            	&& (fabsl(t * dels) < precsn[8] * f[0])) j = i;
	    	deld = (delp - f[4] * d * t * dels) / c2;
	    	delt = (f[3] * delp / d + t * dels) / f[0];
		} else if (strcmp(label, "PU") == 0)
        {
			/* X is Pressure, Y is Energy */
	    	delp = x - pcalc;
	    	delu = y - prp[10];
	    	if ((fabsl(delp) < precsn[9] * x + precsn[1])
            	&& fabsl(delu) < precsn[9] * y + precsn[2]) j = i;
	    	ckt = pcalc * f[5];
	    	ompks = 1.0 - f[4] * ckt / f[2];
	    	deld = (delp - f[4] * d * delu) / (c2 * ompks);
	    	delt = ((f[3] - ckt) * delp / d + delu) / (f[0] * ompks);
		} else if (strcmp(label, "PG") == 0)
        {
			/* X is Pressure, Y is Gibbs energy */
	    	delp = x - pcalc;
	    	delg = y - prp[11];
	    	if (((fabsl(delp / x) < precsn[10]) || (fabsl(delp) < precsn[1]))
            	&& (fabsl(delg / prp[7]) < precsn[6])) j = i;
	    	deld = f[3] / prp[7] / t * ((prp[7] / (f[4] * f[1]) - 1.) * delp + d * delg);
		    delt = (delp / d - delg) / prp[7];
		} else if (strcmp(label, "HS") == 0)
        {
			/* X is Enthalpy, Y is Entropy */
            delh = x - prp[8];
	    	dels = y - prp[7];
	    	if ((fabsl(delh) < precsn[10] * fabsl(x) + precsn[2])
            	&& (fabsl(t*dels) < precsn[10] * fabsl(y) + precsn[2])) j = i;
	    	deld = (delh - (f[4] + 1.0) * t * dels) * d / c2;
	    	delt = (f[4] * delh / c2 - d * f[7] * dels) * t;
		}
		/* iteration */
		if ((fabsl(deld / d) + fabsl(delt / t) < 4.0e-4) && (i > 3))
        {
	    	calldr = false;
	    	fract = 0.0;
		}
		/* Limit large steps */
		if (fract > 0.0)
        {
	    	if ((i > 7) && (((i / 4) << 2) == i))
            {
				deld *= 0.5;
				delt *= 0.5;
	    	}
		    deld = sign(min(fabsl(deld), fabsl(fract * d)), deld);
		    delt = sign(min(fabsl(delt), fabsl(fract * t)), delt);
		}
		d += deld;
		t += delt;
		if ((fabsl(deld) < precsn[12] * d)
        	&& (fabsl(delt) < precsn[12] * t)) j = i;
		if (j > 0) return;
    }
    if (fract < 0.01)
    {
		/* Probable oscillation around the true answer */
		d -= deld * 0.5;
		t -= delt * 0.5;
		j = 61;
		return;
    }
    j = -200;
    return;
} /* dtilxy */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Correction of roundoff errors on X in the range 0 to 1 */
long double he :: roun01 (long double x)
{
    /* System generated locals */
    long double ret_val;

    if (x < 3e-5) ret_val = 0.0;
    else if (x > 0.9999) ret_val = 1.0;
    else ret_val = x;
    return ret_val;
} /* roun01 */

/* -----Version 3.301: local variable DPDT renamed XDPDT */
long double he :: psat (long double t)
{
    /* Local variables */
    long double p, xdpdt, tt;

    tt = t;
    psatft (p, xdpdt, tt);
    return p;
} /* psat */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* saturation temperature as a function of pressure */
long double he :: tsatfp (long double pp)
{
    /* Initialized data */
    long double ta = 0.8;
    long double tz = 5.1953;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double p, t, tb, tc, pl;
    int jr;

    p = max( pp, 1.475154);
    pl = logl(p);
    tb = pl * (pl * (pl * 0.005045477179 - 0.05434555937) + 0.2654401757) +
	     0.6985201046;
    tb = max( ta, tb - 0.04);
    tc = min(tz, tb + 0.08);
//  rootaz (t, ta, tb, tc, tz, precsn[10], precsn[13], precsn[3], precsn[10], psat, p, jr);
    rootaz (t, ta, tb, tc, tz, precsn[10], precsn[13], precsn[3], precsn[10], 10, p, jr);
    if (jr <= 0) ret_val = -1.0;
    else ret_val = t;
    return ret_val;
} /* tsatfp */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* function used by SATFD */
long double he :: satd (long double t)
{
    /* System generated locals */
    long double ret_val;

    psatft (subrt.r[0], subrt.r[1], t);
    if (subrt.jr == 0) ret_val = d2lfpt (subrt.r[0], t);
    else ret_val = d2vfpt (subrt.r[0], t);
    return ret_val;
} /* satd */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* function used by SATFD */
long double he :: satd1 (long double t)
{
    /* System generated locals */
    long double ret_val;

    if (subrt.jr == 0) ret_val = dfsat (t);
    else ret_val = dgsat (t);
    return ret_val;
} /* satd1 */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* This subroutine written by V. Arp. */
/* Output: saturation properties: temperature, pressure, dP/dT, */
/*         liquid and vapor densities (one of these will be a repeat */
/*         of the input parameter, RHO, all SI units) */
/* Input:  RHO = saturated fluid density. */
/* NOTE: The maximum saturated liquid density of 146.1603 occurs at */
/*       T = 2.1852 K, according the HEPAK v3.2.  In the liquid, SATFD */
/*       always returns a temperature T > 2.1852; the saturated superfluid */
/*       branch is not found in the following iteration. */
/* Version August 29, 1992 */
/*          DELT = TB - TNRC;  TNRC is defined in DFSAT and DGSAT */
void he :: satfd (int& idid, long double& qual, long double& psat, long double& dpdt,
			long double& tsat, long double& dl, long double& dv, long double rho)
{
    /* Initialized data */
    long double delt = 0.0893;
    long double dnrcl = 93.3275;
    long double dnrcv = 46.5087;
    long double ta = 0.8;
    long double tz = 5.1953;
    long double dc = 69.6412;

    /* Local variables */
    long double fact, dref;
    long double term;
    long double t;
    long double tb, tc;
    int jx;
    long double ta1, tb1;

    if ((rho > 146.1603) || (rho < 8.88e-4))
    {
		idid = -123;
		return;
    }
    if (rho > dnrcl)
    {
		subrt.jr = 0;
		tb = 2.1852;
		tc = 4.5;
    } else if (rho > dnrcv)
    {
		if (rho >= dc)
        {
	    	dref = dnrcl;
			/* FACT = (DNRCV - DC) / (DNRCL - DC) */
	    	fact = -0.9766194;
	    	qual = 0.0;
		}
        else
        {
	    	dref = dnrcv;
			/* FACT = (DNRCL - DC) / (DREF - DC) */
	    	fact = -1.0239403;
	    	qual = 1.0;
		}
		term = max(fabsl((rho - dc) / (dref - dc)), 1.0e-8);
		tsat = tz - delt * powl (term, 3);
		psatft(psat, dpdt, tsat);
		term = dc + fact * (rho - dc);
		if (qual < 0.5)
        {
	    	dl = rho;
	    	dv = term;
		}
        else
        {
	    	dl = term;
	    	dv = rho;
		}
		idid = 2;
		return;
    }
    else
    {
		subrt.jr = 1;
		tb = ta + rho * 0.06;
		tc = (tb + tz) * 0.5;
    }
//  rootaz (t, ta, tb, tc, tz, 0.03, 0.0, 1.0e-8, 3.0e-4, satd1, rho, jx);
    rootaz (t, ta, tb, tc, tz, 0.03, 0.0, 1.0e-8, 3.0e-4, 11, rho, jx);
    if (jx <= 0) idid = -123;
    else
    {
		ta1 = min (t, tz - 0.005);
		tb1 = min (t + 0.005,tz);
//rootaz (t, ta, ta1, tb1, tz, precsn[8], precsn[10],precsn[15], precsn[9], satd, rho, jx);
		rootaz (t, ta, ta1, tb1, tz, precsn[8], precsn[10],
				precsn[15], precsn[9], 12, rho, jx);
		if (jx < 0)
        {
	    	idid = -180;
	    	return ;
		}
		idid = 2;
		psat = subrt.r[0];
		dpdt = subrt.r[1];
		tsat = t;
		if (subrt.jr == 0)
        {
	    	dl = rho;
	    	dv = d2vfpt (psat, tsat);
	    	qual = 0.0;
        }
		else
        {
	    	dv = rho;
	    	dl = d2lfpt(psat, tsat);
	    	qual = 1.0;
		}
    }
} /* satfd */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output: Temperature, quality, and saturation densities */
/* Input:  Density and pressure  (All SI units) */
/* GRUNCV = Gruneisen parameter * Cv, and is reasonably constant. */
/* Used for integration w.r to P along isochores. */
void he :: tfdp (int& idid, long double& t, long double& x, long double& dl,
		   long double& dv, long double d, long double p)
{
    /* Initialized data */
    long double dc = 69.64;
    long double gruncv = 2078.0;
    long double pmax = 1.0133e8;

    /* Local variables */
    long double dpdt;
    long double tmin, tmax;
    long double ta, tb, pm;
    int jx;
    long double ps, ts, tt, xx;

    x = -1.0;
    idid = 1;
    tmax = 0.0;
    if (d <= 0.0)
    {
		idid = -105;
		return;
    } else if (p <= 0.0)
    {
		idid = -101;
		return;
    } else if (p > pmax)
    {
		idid = -102;
		return;
    }
    if ((p < 1.6e6) || (d < dc))
    {
		ta = min(p / d / 2077.0, 1400.0);
		tmin = 0.8;
		if (ta > 30.0)
        {
	    	tb = ta * 1.05;
	    	tmax = 1500.0;
		} else if ((ta > 6.0) || (p < 1.48))
        {
	    	tb = ta + 3.0;
	    	tmax = 1500.0;
		}
    }
    if (tmax == 0.0)
    {
		if (d < 146.16)
        {
	    	satfd (jx, xx, ps, dpdt, ts, dl, dv, d);
		    if (jx < 0)
            {
				idid = -203;
				return;
	    	}
	    	if (p < ps)
            {
				tt = tsatfp (p);
				dl = d2lfpt (p, tt);
				dv = d2vfpt (p, tt);
				if (dl == dv) x = 0.5;
				else
                {
		    		x = (dl / d - 1.0) / (dl / dv - 1.0);
		    		x = roun01 (x);
				}
				t = tt;
				idid = 3;
				return;
	    	}
            else
            {
				if (d < dc) x = 2.0;
				tmin = ts - 0.001;
				tmax = 1500.0;
				ta = min(ts + (p - ps) * 0.75 / (d * gruncv), 1400.0);
				tb = min(ta * 1.25, tmax);
	    	}
		}
        else
        {
			/* 179.84 = density at upper lambda point, where T = 1.7673 */
	    	if (d < 179.84)
            {
				tmin = tlfd (d) + 0.2;
				jx = -1;
	    	}
            else
            {
				tmin = tmfd (d);
				jx = 0;
	    	}
	    	pm = press (d, tmin);
	    	ta = (p - pm) * 0.75 / (d * gruncv);
	    	if (ta < 0.0)
            {
				if (jx < 0) idid = -180;
				else idid = -107;
				return;
	    	}
	    	ta += tmin;
	    	tb = ta * 1.25;
	    	tmax = 400.0;
		}
    }
    subrt.r[0] = d;
//  rootaz (tt, tmin, ta, tb, tmax, precsn[8], precsn[11], precsn[2], precsn[11], tdp, p, jx);
    rootaz (tt, tmin, ta, tb, tmax, precsn[8], precsn[11], precsn[2], precsn[11], 13, p, jx);
    if (jx < 0) idid = -106;
    else t = tt;
} /* tfdp */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Function used by TFDP */
long double he :: tdp( long double y)
{
    return press(subrt.r[0], y);
} /* tdp */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
long double he :: tmfd (long double dd)
{
    /* Local variables */
    long double d, t, x, ta, tb;
    int jx;

    d = dd;
    x = (d - 171.2) / 136.0;
    ta = max(1.0, x * 13.2 + 0.8);
    tb = min(ta, 12.0) + 2.0;
    ta = tb - 2.0;
//  rootaz (t, 0.8, ta, tb, 14.011, precsn[9], 0.0, precsn[5], precsn[10], dmft, d, jx);
    rootaz (t, 0.8, ta, tb, 14.011, precsn[9], 0.0, precsn[5], precsn[10], 14, d, jx);
    if (jx < 0) t = 0.8;
    return t;
} /* tmfd */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output: Temperature (T) and Quality (Q) */
/*         If Q is between 0 and 1, the saturation pressure P, its */
/*         derivative dP/dT, and saturation densitites DL and DV */
/*         are also evaluated.  SI units. */
/* Input:  Density D and parameter X, where Y can be entropy (S), */
/*         enthalpy (H) or internal energy (U), depending on LABEL. */
/* Range:  valid over the full state equation, including 2-phase region */
/* Version Aug. 5, 1992; for HEPAK v3.2 */
/* -----Version 3.301: local variable DPDT renamed XDPDT */
void he :: tfdy (int& idid, long double& t, long double& q, long double& ps,
		   long double& xdpdt, long double& dl, long double& dv, long double dd,
           long double yy, char label)
{
    /* Initialized data */
    long double tz = 1500.;

    /* Local variables */
    long double d, y;
    long double ta, tb, tc;
    int jx;

    y = yy;
    d = dd;
    if (d * (d - 599.0) >= 0.0)
    {
		idid = -105;
		return;
    }
    if (d > 171.7) ta = tmfd (d);
    else ta = 0.8;
    if (label == 'S')
    {
		idid = -108;
		if (y * (y - 6.4e4) >= 0.) return;
		tb = expl(((y * 0.001 - 10.037) / 2.07723 + logl(d)) / 1.5);
		tb = max(ta,tb);
		subrt.jr = 8;
    } else if (label == 'H')
    {
		idid = -109;
		if (y * (y - 8.1e6) >= 0.) return;
		tb = max(y / 5193.0, ta);
		subrt.jr = 9;
    } else if (label == 'U')
    {
		idid = -110;
		if (y * (y - 4.73e6) >= 0.0) return;
		tb = max(y / 3117.0, ta);
		subrt.jr = 11;
    } else
    {
		idid = -299;
		return;
    }
	tb = max(tb,1.);
    if (tb > 1200.0)
    {
		tb = 1200.0;
		tc = 1400.0;
    }
    else
    {
		tc = tb * 2.0;
		tc = min(tc, tb + 50.0);
    }
    subrt.r[2] = d;
//  rootaz (t, ta, tb, tc, tz, precsn[9], precsn[11], precsn[3], precsn[10], yjfdt, y, jx);
    rootaz (t, ta, tb, tc, tz, precsn[9], precsn[11], precsn[3], precsn[10], 15, y, jx);
    if (jx < 0) return;
    idid = subrt.r[6];
    if (idid == 3)
    {
		q = subrt.r[7];
		ps = subrt.r[0];
		dl = subrt.r[3];
		dv = subrt.r[4];
		/* -----Version 3.301: local variable DPDT renamed XDPDT */
		xdpdt = subrt.r[5];
    }
    else if (d < 69.64) q = 2.0;
    else q = -1.0;
} /* tfdy */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Entropy [J/(kg-K)] as a function of density [kg/m3] and temperature [K] */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
long double he :: entrop (long double d, long double t)
{
    /* Initialized data */
    long double gmwt = 4.0026;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double sa, th, tl, wt;

    amlap (tl, th, d);
    if (t > tl)
    {
		ret_val = entrm (d / gmwt, t) * 1e3 / gmwt;
		if (t >= th) return ret_val;
    }
    sa = entra (d, t);
    if (t <= tl) ret_val = sa;
    else
    {
		wt = (t - tl) / (th - tl);
		ret_val = wt * ret_val + (1.0 - wt) * sa;
    }
    return ret_val;
} /* entrop */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Saturated vapor density, 0.8 to 5.1953 K, T76 scale. */
/* Output is the density such that PRESS(D,T) = PSAT; may differ slightly*/
/* from the density DGSAT, except when T > TNRC. */
/* Valid input of both PSAT and TSAT must be made by the calling program.*/
/* Version Nov. 6, 1990 */
long double he :: d2vfpt (long double psat, long double tsat)
{
    /* Initialized data */
    static long double p0 = 5e3;

    /* Local variables */
    long double delp, d;
    int k;
    long double dv, dpd;

    dv = dgsat (tsat);
    if (tsat < 5.106)
    {
		d = dv;
		dpd = dpdd (d, tsat);
		for (k = 1; k <= 8; ++k)
        {
	    	delp = press (d, tsat) - psat;
		    d -= delp / dpd;
		    if (fabsl(delp / (psat + p0)) < precsn[12]) k = 10;
		}
		if (tsat > 4.804) dv = (d * (5.106 - tsat) + dv * (tsat - 4.804)) / 0.302;
		else dv = d;
    }
    return dv;
} /* d2vfpt */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* Output: PRESSM [MPa] = pressure */
/* Input:  RR [mol/L]   = density (2-phase region excluded) */
/*         TT [K]       = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: pressm (long double rr, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    static long double d, t, d2, ti, ti2;

    t = tt;
    d = rr;
    d2 = d * d;
    ti = 1.0 / tt;
    ti2 = ti * ti;
    ret_val = (((((((((((ti * mc1.g[31] + mc1.g[30]) * ti + mc1.g[29]) *
	     d2 + mc1.g[28] * ti + mc1.g[27]) * d2 + mc1.g[26] * ti2 +
	    mc1.g[25]) * d2 + mc1.g[24] * ti + mc1.g[23]) * d2 +
	    mc1.g[22] * ti2 + mc1.g[21]) * d2 + mc1.g[20] * ti +
	    mc1.g[19]) * expl(mc1.gm * d2) + mc1.g[8]) * ti + mc1.g[7])
	     * ti + mc1.g[6]) * d + ((((((d * mc1.g[18] + mc1.g[17])
	     * ti + mc1.g[16]) * d + mc1.g[15]) * d + ti * mc1.g[14]
	     + mc1.g[13]) * d2 + mc1.g[11]) * ti + d * mc1.g[12] +
	    mc1.g[10]) * d2 + (ti * mc1.g[4] + mc1.g[3]) * ti + sqrtl(t)
	    * mc1.g[1] + ((d * mc1.g[9] + mc1.g[5]) * d + mc1.g[0]
	    ) * t + mc1.g[2]) * d2 + mc1.r * d * t;
    return ret_val;
} /* pressm */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* This function written by V. Arp. */
/* Pressure [Pa] as a function of density [kg/m3] and temperature [K] */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
long double he :: press (long double d, long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double pa, th, tl, wt;

    amlap (tl, th, d);
    if (t > tl)
    {
		/* He I equation (above 2.5 K) */
		ret_val = pressm (d / 4.0026, t) * 1.0e6;
		if (t >= th) return ret_val;
    }
	/* He II and lambda line vicinity */
    pa = pressa (d, t);
    if (t <= tl) ret_val = pa;
    else
    {
    	wt = (t - tl) / (th - tl);
		ret_val = wt * ret_val + (1.0 - wt) * pa;
    }
    return ret_val;
} /* press */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Saturated liquid density, 0.8 to 5.1953 K, T76 scale. */
/* Output is the density such that PRESS(D,T) = PSAT; will differ slightly */
/* from the density DFSAT, except when T > TNRC. */
/* Valid input of both PSAT and TSAT must be made by the calling program.*/
/* Version Nov. 8, 1990 */
long double he :: d2lfpt (long double psat, long double tsat)
{
    /* Initialized data */
    long double p0 = 5e3;

    /* Local variables */
    long double delp, d;
    int k;
    long double dl, dpd;

    dl = dfsat (tsat);
    if (tsat < 5.106)
    {
		d = dl;
		dpd = dpdd (d, tsat);
		for (k = 1; k <= 8; ++k)
        {
	    	delp = press (d, tsat) - psat;
		    d -= delp / dpd;
	    	if (fabsl(delp / (psat + p0)) < precsn[12]) k = 10;
		}
		if (tsat > 4.804) dl = (d * (5.106 - tsat) + dl * (tsat - 4.804)) / 0.302;
		else dl = d;
    }
    return dl;
} /* d2lfpt */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/*  saturation pressure and dP/dT as a function of temperature */
/*  on the T76 scale, from 0.5 to 5.1953 K; Equation is given by */
/*  Durieux and Rusby, Metrologia 19, 67 (1983). */
/* Note: c(11,1) has been corrected in this version, August 19, 1992. */
/* Earlier versions of this routine had c(11,1)=14.5333d0 (missing a "3"); */
/* the corresponding error in pressure is never more than 0.01 pct. */
/* at TL, P=5041.8 and dPdT=12407.9; fixed points on the T76 scale */
/* Note: Durieux and Rusby state Pc=227.46 kPa at 5.1953 K */
/* However, this (corrected) equation gives Pc=227.4623 kPa at 5.1953 K.*/
void he :: psatft (long double& p, long double& dpdts, long double t)
{
    /* Initialized data */
    long double c[22]	/* was [11][2] */ = { -30.93285,392.47361,
	    -2328.04587,8111.30347,-17809.80901,25766.52747,-24601.4,
	    14944.65142,-5240.36518,807.93168,14.53333,-7.41816,5.42128,
	    9.903203,-9.617095,6.804602,-3.0154606,0.7461357,-0.0791791,0.0,0.0,
	    0.0 };
    long double tl = 2.1768;
    long double tc = 5.1953;
    long double tmin = 0.5;

    /* Local variables */
    int j, m;
    long double x, y, q0, q1, tn;
    int mx;

    if ((t > tc + 1.0e-5) || (t < tmin))
    {
		p = -1.0;
		dpdts = -1.0;
		return;
    }
    else if (t > tl)
    {
		/* Computing MIN */
		x = min(t / tc,1.0);
		m = 1;
		mx = 10;
    }
    else
    {
		x = t;
		m = 2;
		mx = 8;
    }
    q0 = c[m * 11 - 11] / x + c[m * 11 - 10];
    q1 = -c[m * 11 - 11] / (x * x);
    tn = 1.0;
    for (j = 3; j <= mx; ++j)
    {
		q1 += c[j + m * 11 - 12] * tn * (j - 2);
		tn *= x;
		q0 += c[j + m * 11 - 12] * tn;
    }
    x = 1.0 - x;
    if ((m == 1) && (x > 0.0))
    {
		y = powl (x, 0.9);
		q0 += x * c[m * 11 - 1] * y;
		q1 -= c[m * 11 - 1] * 1.9 * y;
    }
    p = expl(q0);
    dpdts = p * q1;
    if (m == 1) dpdts /= tc;
    return;
} /* psatft */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Saturated vapor density, 0.8 < T < 5.1953. */
/* This is the best independent estimate of saturation density; */
/* Theoretical form above TNRC, fitted for continuity at TNRC. */
/* Version Nov. 8, 1990 */
long double he :: dgsat (long double t)
{
    /* Initialized data */
    long double a[8] = { -561.8978079,3.300736785,-60.31200561,
	    612.990156,-2718.577178,1285.18502,-440.6873907,71.63145577 };
    long double c[8] = { -7.41816,5.42128,9.903203,-9.617095,6.804602,
	    -3.0154606,0.7461357,-0.0791791 };
    long double ttp = 2.1768;
    long double tcc = 5.1953;
    long double dcc = 17.399;
    long double dtpv = 0.294058864;
    long double tnrc = 5.106;
    long double dnrc = 46.5087;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d;
    int j;
    long double p, x, y, z;

    if (t > ttp)
    {
		if (t > tnrc)
        {
			/* Computing MAX */
	    	p = powl (max (1.0e-20,(tcc - t) / (tcc - tnrc)), 1.0/3.0);
		    d = dcc + p * (dnrc / 4.0026 - dcc);
		}
        else
        {
	    	x = (t - tcc) / (ttp - tcc);
		    y = powl (x, 1.0/3.0);
		    z = 1.0 / x;
	    	p = a[0] * logl(x);
		    for (j = 2; j <= 8; ++j)
            {
				p += a[j - 1] * (1.0 - z);
				if (j == 4) z = y;
				else z *= y;
		    }
		    d = dcc + expl(p) * (dtpv - dcc);
		}
		ret_val = d * 4.0026;
	}
    else if (t > 0.799)
    {
		p = c[0] / t + c[1];
		y = 1.0;
		for (j = 3; j <= 8; ++j)
        {
	    	y *= t;
		    p += c[j - 1] * y;
		}
		d = expl(p) / (t * 2077.2258);
		z = (0.0537 - 0.514 / t) / 4.0026;
		/* Computing 3rd power */
		ret_val = d / (z * d + 1.0) + powl (d,3) * 0.00164;
    }
    else ret_val = -1.0;
    return ret_val;
} /* dgsat */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* DENMAX = Density [kG/m3] ; maximum density for which */
/*          the equations are valid (melting pressure to 14 K; */
/*          1000 atmos to 75 K, 20000 bars to 300 K, 1000 atmos to 1500 K) */
/* -----INPUT */
/* T  = Temperature [K] ; 0.8 < T < 1500. */
/* Accuracy of fit: better than 0.3 kg/m3 for all T */
/* ----- */
long double he :: denmax (long double t)
{
    /* Initialized data */
    long double a[4] = { -16.70040531,485.7565167,-258.5274317, 51.61716546 };
    long double b[4] = { 292.4157352,1202.25329,-1859.861872, 1060.045153 };
    long double c[3] = { .9714767056,474.5050407,-302.8968312 };

    /* Local variables */
    static long double d, x;

    if (t < 14.05) d = dmft (t);
    else
    {
		x = 100.0 / (t + 50.0);
		if (t < 74.99) d = a[0] + x * (a[1] + x * (a[2] + x * a[3]));
		else if (t < 300.01)d = b[0] + x * (b[1] + x * (b[2] + x * b[3]));
		else d = c[0] + x * (c[1] + x * c[2]);
    }
	/* Add a little for error tolerance. */
    return d + 0.5;
} /* denmax */

/* -----Version 3.301: local variable DPDT renamed XDPDT */
/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Check of (density, tmeperature) input variables for out-of-range */
/* or liquid-vapor mixtures. */
void he :: fdt (int& idid, long double& q, long double& ps, long double& xdpdt,
		  long double& dl, long double& dv, long double dd, long double tt)
{
    /* Initialized data */
    long double tcc = 5.1953;
    long double dsatm = 146.16;
    long double d, t;
    long double xdl, xdv;

    d = dd;
    t = tt;
    idid = 1;
    if (t < 0.8) idid = -103;
    else if (t > 1501.0) idid = -104;
    	 else if (d <= 0.0) idid = -105;
    		  else if (d > denmax (t)) idid = -106;
    if (idid < 0) return;
    if (d > 69.64) q = -1.0;
    else q = 2.0;
    if ((t < tcc) && (d < dsatm))
    {
		xdl = dfsat (t);
		if (d < xdl * 1.05)
        {
	    	xdv = dgsat (t);
		    if (d > xdv * 0.95)
            {
				/* Close to or within 2-phase region */
				/* -----Version 3.301: local variable DPDT renamed XDPDT */
				psatft (ps, xdpdt, t);
				dl = d2lfpt (ps, t);
				if (d < dl)
                {
		    		dv = d2vfpt (ps, t);
		   			if (d > dv)
                    {
						idid = 3;
						if (dl == dv) q = 0.5;
						else q = (dl / d - 1.0) / (dl / dv - 1.0);

		    		}
				}
	    	}
		}
    }
    return;
} /* fdt */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* External function in TFDY. */
/* Output: */
/*     YJFDT = entropy, enthlpy, or energy [SI units] */
/*     (if IDID = 3) saturation properties P, DPDT, Q, DL, DV, via /SUBRT/ */
/* Input:  T = temperature (called from ROOTAZ) */
/*         D = density, from TFDY via common /SUBRT/ */
/* Version Sept 13, 1992 */
long double he :: yjfdt ( long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    int idid;
    long double d, f[13], q;
    long double xdpdt;
    long double dl, dv, ps;

    d = subrt.r[2];
	/* -----Version 3.301: local variable DPDT renamed XDPDT */
    fdt (idid, q, ps, xdpdt, dl, dv, d, t);
    subrt.r[6] = idid;
    if (idid < 0) idid = 1;
    if (idid == 1)
    {
		dl = d;
		ps = press (d, t);
    }
    if (subrt.jr == 8) ret_val = entrop (dl, t);
    else
    {
		f[0] = ps;
		f[1] = t;
		f[2] = dl;
		shaug (&f[0]);
		ret_val = f[subrt.jr - 1];
    }
    if (idid == 3)
    {
		if (subrt.jr == 8) ret_val = q * entrop (dv, t) + (1.0 - q) * ret_val;
		else
        {
	    	f[2] = dv;
		    shaug (&f[0]);
		    ret_val = q * f[subrt.jr - 1] + (1.0 - q) * ret_val;
		}
		subrt.r[7] = q;
		subrt.r[0] = ps;
		subrt.r[3] = dl;
		subrt.r[4] = dv;
		/* -----Version 3.301: local variable DPDT renamed XDPDT */
		subrt.r[5] = xdpdt;
    }
    return ret_val;
} /* yjfdt */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Liquid density at the melting line [kg/m3] as a function of T [K] */
/* Range 0.8 to 14.0 K; accuracy generally better than 0.3 kg/m3 */
/* Version March 22, 1989. */
long double he :: dmft (long double t)
{
    /* Initialized data */
    long double cl[3] = { 167.9361577,6.728283584,-10.18218341 };
    long double cm[3] = { 146.9940814,18.58136626,-1.497696476 };
    long double ch[4] = { 154.2809083,18.90207406,-0.8746341757, 0.02235656147 };
    long double t1 = 1.7673;
    long double t2 = 3.53;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double z;

    if (t > t2) ret_val = ch[0] + t * (ch[1] + t * (ch[2] + t * ch[3]));
    else
    {
		z = t - t1;
		if (fabsl(z) < 1e-4) ret_val = 0.0;
		else ret_val = z * logl((fabsl(z)));
		if (z >= 0.0) ret_val = cm[2] * ret_val + cm[0] + t * cm[1];
		else ret_val = cl[2] * ret_val + cl[0] + t * cl[1];
    }
    return ret_val;
} /* dmft */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Density of saturated liquid [kg/m3]; 0.8 < T < 5.1953; T76 scale. */
/* This is the best independent estimate of saturation density; */
/* However, it is not exactly consistent with function D2LFPT. */
/* HeI range above TNRC:  theoretical form, fitted for continuity at TNRC*/
/* HeI range above 3.2 K: R.D.McCarty equation May 4, 1988. */
/* HeI range below 3.2 K: Van Degrift' s equation, quoted by Barenghi */
/*     Lucas and Donnelly, J. Low Temp. Physics 44, 491 (1981), */
/*     shifted to the T76 temperature scale. */
/* HeII range: V.Arp equation Dec 16, 1987. */
/* Version Nov. 8, 1990 */
long double he :: dfsat (long double t)
{
    /* Initialized data */
    long double ttp = 2.1768;
    long double tbb = 3.1853;
    long double tcc = 5.1953;
    long double dcc = 17.399;
    long double dtpl = 36.514;
    long double den0 = 145.188;
    long double denl = 146.15;
    long double tnrc = 5.106;
    long double dnrc = 93.3275;
    long double a[6] = { -34.34500882,0.4501470666,-6.89546017,
	    54.42223002,-97.16273774,17.85061367 };
    long double b[4] = { -1.29782247,-4.911239491,1.021276082,
	    -2.626058542 };
    long double c[5] = { -243.3560558,1814.476908,2425.346403,
	    -460.4869802,245.3561962 };

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d;
    int j;
    long double p, x, y, z;

    if (t >= tbb)
    {
		if (t > tnrc)
        {
			/* Computing MAX */
		    p = powl (max (1.0e-20, (tcc - t) / (tcc - tnrc)), 1.0/3.0);
	    	d = dcc + p * (dnrc / 4.0026 - dcc);
		}
    	else
    	{
	    	x = (t - tcc) / (ttp - tcc);
		    y = powl (x, 1.0/3.0);
		    z = 1.0 / x;
	    	p = a[0] * logl(x);
		    for (j = 2; j <= 6; ++j)
    	    {
				p += a[j - 1] * (1.0 - z);
				if (j == 4) z = y;
				else z *= y;
		    }
	    	d = dcc + expl(p) * (dtpl - dcc);
		}
		ret_val = d * 4.0026;
    }
    else
    {
		z = t - ttp;
		if (z >= 0.0)
        {
	    	ret_val = denl + z * (b[1] + z * (b[2] + z * b[3]));
		    if (z != 0.0) ret_val += b[0] * z * logl(z);
        }
	    else
        {
		    y = z * (logl(-z) - 1.0);
	    	p = t * t;
		    ret_val = ((p * p * (c[0] * y + c[1] * z + c[2] + c[3] *p)
            		  + c[4] * p) * 1.0e-6 + 1.0) * den0;
		}
   	}
    return ret_val;
} /* dfsat */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Density as a function of Temperature and Gibbs Energy (all SI units).*/
/* This function operates only in the compressed liquid between 0.8 and */
/* 3 K (applicable to the fountain effect in superfluid). */
void he :: dftg (int& idid, long double& d, long double t, long double g)
{
    long double dmin, dmax;
    long double d1, d2;
    int jx;

    if (t < 0.8)
    {
    	idid = -103;
		return;
    }
    else if (t > 3.0)
    	{
			idid = -112;
			return;
    	}
    subrt.r[1] = t;
    dmin = dfsat (t) * 0.995;
    dmax = dmft (t);
    d1 = dmin * 0.9 + dmax * 0.1;
    d2 = (dmin + dmax) * 0.5;
//  rootaz (d, dmin, d1, d2, dmax, precsn[7], precsn[11], precsn[6], precsn[11], dtg, g, jx);
    rootaz (d, dmin, d1, d2, dmax, precsn[7], precsn[11], precsn[6], precsn[11], 16, g, jx);
    if (jx < 0) idid = -111;
    else idid = 1;
} /* dftg */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* "background" Helmholtz energy [J/gm] as a function of V-V0 [cm3/gm] */
/*  and T [K]. */
/* M specifies HeI or HeII.  V0 is the volume at the lower lambda point.*/
/* Called from HELMA. */
long double he :: helma2 (long double x, long double t, int m)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double f[7];
    int j, k;
    long double q[5], t2, t4, ff;

    t2 = t * t;
    t4 = t2 * t2;
    f[0] = x;
    for (j = 1; j <= 5; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 6; ++k)
    {
		ff = f[k - 1] / k;
		for (j = 1; j <= 5; ++j)
		    q[j - 1] += ff * subhec.c[j * 6 + k - 1 + m * 41 - 42];
		f[k] = f[k - 1] * x;
    }
    ret_val = q[0] + t2 * (q[1] + t2 * (q[2] + t2 * (q[3] + t2 * q[4]))) +
	    subhec.c[m * 41 - 6] * t2 / 2.0 + subhec.c[m * 41 - 5] *
	    t4 / 12.0 + subhec.c[m * 41 - 4] * t4 * t2 / 30.0 +
	    subhec.c[m * 41 - 3] * t4 * t4 / 56.0 + subhec.c[m * 41
	    - 2] * t + subhec.c[m * 41 - 1];
    return ret_val;
} /* helma2 */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Helmholtz energy as a function of density and temperature [SI units] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: helma (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    int m;
    long double t, v, x;
    long double dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    ret_val = (pvtcsa[5] + helma2 (x, t, m)) * -1.0e3;
    return ret_val;
} /* helma */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/*"background" entropy [J/gm-K] as a function of V-V0 [cm3/gm], and T [K].*/
/* M specifies HeI or HeII.  V0 is the volume at the lower lambda point.*/
/* Called from ENTRA. */
long double he :: entra2 ( long double x, long double t, int m)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double f[7];
    int j, k;
    long double q[4], t2, t5, ff;

    t2 = t * t;
    t5 = t2 * t2 * t;
    f[0] = x;
    for (j = 1; j <= 4; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 6; ++k)
    {
		ff = f[k - 1] / k;
		for (j = 1; j <= 4; ++j)
		    q[j - 1] += ff * subhec.c[j * 6 + k + 5 + m * 41 - 42];
		f[k] = f[k - 1] * x;
    }
    ret_val = t * (q[0] * 2.0 + t2 * (q[1] * 4.0 + t2 * (q[2] * 6.0 + t2 * 8.0 *
	    q[3]))) + subhec.c[m * 41 - 6] * t + subhec.c[m * 41 - 5]
        * t2 * t / 3.0 + subhec.c[m * 41 - 4] * t5 / 5.0 +
	    subhec.c[m * 41 - 3] * t5 * t2 / 7.0 + subhec.c[m * 41 - 2];
    return ret_val;
} /* entra2 */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Entropy as a function of density and temperature [SI units] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: entra (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    int m;
    long double t, v, x;
    long double dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    ret_val = (pvtcsa[4] + entra2 (x, t, m)) * 1.0e3;
    return ret_val;
} /* entra */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/*  Output: ENERM [J/mol] = Internal energy */
/*  Input:  RR [mol/L]    = density (2-phase region excluded) */
/*          TT [K]        = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: enerm (long double rr, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    static long double d, e, f, t, d2, d3, d4, ti, gd1, gd2, gd3, gd4, gg2,
	    gg3, gg4, gg5, gg6, gd5, gd6, ti2, gmi;

    t = tt;
    ti = 1.0 / tt;
    ti2 = ti * ti;
    d = rr;
    d2 = d * d;
    d3 = d2 * d;
    d4 = d3 * d;
    f = expl (mc1.gm * d2);
    gmi = 0.5 / mc1.gm;
    gg2 = gmi * -2.0 * gmi;
    gg3 = gg2 * -4.0 * gmi;
    gg4 = gg3 * -6.0 * gmi;
    gg5 = gg4 * -8.0 * gmi;
    gg6 = gg5 * -10.0 * gmi;
    gd1 = f * gmi;
    gd2 = (f * d2 - gd1 * 2.0) * gmi;
    gd3 = (f * d4 - gd2 * 4.0) * gmi;
    gd4 = (f * d4 * d2 - gd3 * 6.0) * gmi;
    gd5 = (f * d4 * d4 - gd4 * 8.0) * gmi;
    gd6 = (f * d4 * d4 * d2 - gd5 * 10.0) * gmi;
    e = mc1.r * 2.5 * t + d * (mc1.g[1] * 0.5 * sqrtl(t) + mc1.g[2] +
	    ti * (mc1.g[3] * 2.0 + ti * mc1.g[4] * 3.0) + d * (
	    mc1.g[6] * 0.5 + ti * (mc1.g[7] + ti * mc1.g[8] * 1.5) + d
	    * (mc1.g[10] / 3.0 + ti * mc1.g[11] * 2.0 / 3.0
	    + d * (mc1.g[12] * 0.25 + d * ti * (
	    mc1.g[13] * 0.4 + ti * mc1.g[14] * 0.6 + d * (mc1.g[15] / 3.0
	    + d * (mc1.g[16] * 0.2857142857142857 + ti *
	     (mc1.g[17] * 0.42857142857142855 + d * mc1.g[18] * .375)))))
	    ))) + ti2 * ((gd1 - gmi) * (mc1.g[19] * 3.0 + ti * 4.0 * mc1.g[
	    20]) + (gd2 - gg2) * (mc1.g[21] * 3.0 + ti2 * 5.0 * mc1.g[22])
	    + (gd3 - gg3) * (mc1.g[23] * 3.0 + ti * 4.0 * mc1.g[24]) + (gd4
	    - gg4) * (mc1.g[25] * 3.0 + ti2 * 5.0 * mc1.g[26]) + (gd5 - gg5)
	     * (mc1.g[27] * 3.0 + ti * 4.0 * mc1.g[28]) + (gd6 - gg6) * (
	    mc1.g[29] * 3.0 + ti * (mc1.g[30] * 4.0 + ti * 5.0 * mc1.g[31])
	    ));
    ret_val = (e - mc1.r * t + mc8.h0) * 1.0e3;
    return ret_val;
} /* enerm */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* Output: ENTRM [J/mol-K] = entropy */
/* Input:  RR [mol/L]      = density (2-phase region excluded) */
/*         TT [K]          = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: entrm (long double rr, long double tt)
{
    /* Initialized data */
    long double p0 = 0.101325;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double sint, d, f, t, d2, d4, ti, gd1, gd2, gd3, gg1, gg2,
	    gg3, gg4, gg5, gg6, gd4, gd5, gd6, ti2;

    t = tt;
    ti = 1.0 / t;
    ti2 = ti * ti;
    d = rr;
    d2 = d * d;
    d4 = d2 * d2;
    f = expl(mc1.gm * d2);
    gg1 = 0.5 / mc1.gm;
    gg2 = gg1 * -2.0 * gg1;
    gg3 = gg2 * -4.0 * gg1;
    gg4 = gg3 * -6.0 * gg1;
    gg5 = gg4 * -8.0 * gg1;
    gg6 = gg5 * -10.0 * gg1;
    gd1 = f * gg1;
    gd2 = (f * d2 - gd1 * 2.0) * gg1;
    gd3 = (f * d4 - gd2 * 4.0) * gg1;
    gd4 = (f * d4 * d2 - gd3 * 6.0) * gg1;
    gd5 = (f * d4 * d4 - gd4 * 8.0) * gg1;
    gd6 = (f * d4 * d4 * d2 - gd5 * 10.0) * gg1;
	/* vda  Z(4) = 2.5 */
    sint = mc1.r * 2.5 * logl(t) + d * (-mc1.g[0] - mc1.g[1] * 0.5 / sqrtl(t)
    	- d * (mc1.g[5] * 0.5 + d / 3.0 * mc1.g[9]) + ti2 * (mc1.g[3] + d * (
	    mc1.g[7] * 0.5 + d * (mc1.g[11] / 3.0
	    + d2 * (mc1.g[13] * 0.2 + d * (mc1.g[15] / 6.0
	    + d * 0.14285714285714285 * mc1.g[16])))) +
	    ti * (mc1.g[4] * 2.0 + d * (mc1.g[8] + d2 * d * (mc1.g[
	    14] * 0.4 + d2 * (mc1.g[17] * .2857142857142857 + d * 0.25 *
	    mc1.g[18])))))) + ti2 * 2.0 * ti * ((f - 1.0) * gg1 * (mc1.g[19]
	     + mc1.g[20] * ti * 1.5) + (gd2 - gg2) * (mc1.g[21] + mc1.g[
	    22] * ti2 * 2.0) + (gd3 - gg3) * (mc1.g[23] + mc1.g[24] * ti *
	    1.5) + (gd4 - gg4) * (mc1.g[25] + mc1.g[26] * ti2 * 2.0) + (
	    gd5 - gg5) * (mc1.g[27] + mc1.g[28] * ti * 1.5) + (gd6 - gg6)
	    * (mc1.g[29] + mc1.g[30] * ti * 1.5 + mc1.g[31] * ti2 * 2.0))
	    ;
    ret_val = (sint + mc8.s0 - mc1.r * logl(d * mc1.r * tt / p0))
	    * 1e3;
    return ret_val;
} /* entrm */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output: S, H, A, U, G;  Input: P, D, T ; all SI units */
/*    PRP: 1=P, 2=T, 3=D, 8=S, 9=H, 10=A, 11=U, 12=G, 13=Fugacity */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
/* Note: the first index is 1, not 0 */
void he :: shaug (long double* prp)
{
    /* Initialized data */
    long double gmwt = 4.0026;

    /* Local variables */
    long double omwt;
    long double aa, ga, ha, sa, ua, th, tl, pv, wt;

    /* Function Body */
    amlap (tl, th, *(prp+2));
    pv = *prp / *(prp+2);
    if (*(prp+1) > tl)
    {
		*(prp+7) = entrm (*(prp+2) / gmwt, *(prp+1)) * 1.0e3 / gmwt;
		*(prp+10) = enerm (*(prp+2) / gmwt, *(prp+1)) * 1.0e3 / gmwt;
		*(prp+8) = *(prp+10) + pv;
		*(prp+9) = *(prp+10) - *(prp+1) * *(prp+7);
		*(prp+11) = *(prp+9) + pv;
		if (*(prp+1) >= th) return;
    }
    sa = entra (*(prp+2), *(prp+1));
    aa = helma (*(prp+2), *(prp+1));
    ua = aa + *(prp+1) * sa;
    ha = ua + pv;
    ga = aa + pv;
    if (*(prp+1) <= tl)
    {
		*(prp+7) = sa;
		*(prp+8) = ha;
		*(prp+9) = aa;
		*(prp+10) = ua;
		*(prp+11) = ga;
    }
    else
    {
		wt = (*(prp+1) - tl) / (th - tl);
		omwt = 1.0 - wt;
		*(prp+7) = wt * *(prp+7) + omwt * sa;
		*(prp+8) = wt * *(prp+8) + omwt * ha;
		*(prp+9) = wt * *(prp+9) + omwt * aa;
		*(prp+10) = wt * *(prp+10) + omwt * ua;
		*(prp+11) = wt * *(prp+11) + omwt * ga;
    }
} /* shaug */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* "background" pressure [MPa] as a function of V-V0 [cm3/gm], and T [K].*/
/* M specifies HeI or HeII.  V0 is the volume at the lower lambda point.*/
/* Called from PRESSA. */
long double he :: presa2 (long double x, long double t, int m)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double f[7];
    int j, k;
    long double q[5], t2;

    t2 = t * t;
    f[0] = 1.0;
    for (j = 1; j <= 5; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 6; ++k)
    {
		for (j = 1; j <= 5; ++j)
		    q[j - 1] += f[k - 1] * subhec.c[j * 6 + k - 1 + m * 41 - 42];
		f[k] = f[k - 1] * x;
    }
    ret_val = q[0] + t2 * (q[1] + t2 * (q[2] + t2 * (q[3] + t2 * q[4])));
    return ret_val;
} /* presa2 */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Pressure [Pa] as a function of density [kg/m3] and temperature [K] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: pressa (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    int m;
    long double t, v, x;
    long double dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    ret_val = (pvtcsa[0] + presa2 (x, t, m)) * 1.0e6;
    return ret_val;
} /* pressa */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Gibbs energy as a function of density and (from /SUBRT/) T. */
/* This is an external function to subroutine DFTG. */
long double he :: dtg (long double d)
{
    /* System generated locals */
    long double ret_val;

    subrt.r[2] = d;
    subrt.r[0] = pressa (subrt.r[2], subrt.r[1]);
    shaug (&subrt.r[0]);
    ret_val = subrt.r[11];
    return ret_val;
} /* dtg */

/*    (Dielectric constant - 1.0) as a function of density [Kg/m3]. */
/* -----Version 3.23: Output changed to (Dielectric constant - 1.0) */
/*                   instead of just the dielectric constant. */
/*    Equation from D. Friend, NIST, 12/20/90.  Includes values from Gugan */
/*    and Michel,  Metrologia 1980, 1984 with 1986 CODATA constants; */
/*    temperature dependence of B is eliminated. */
long double he :: dielhe (long double rho)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double p;

    p = (0.123493 - rho * 5.86e-6) * 1.046516792;
    ret_val = (p * 2.0 * rho + 1.0e3) / (1.0e3 - p * rho) - 1.0;
    return ret_val;
} /* dielhe */

/*    (Refractive index -1.0) as a function of density and wavelength [um].*/
/* -----Version 3.23: Output changed to (refr. index - 1.0) */
/*                   instead of just the refractive index. */
/*     Uses new dielectric constant correlation for infinite wavelength.*/
/*    Uses Sellmeier fit from Peck (App. Opt. 22, 2906, 1983) for dispersion*/
/*     between 0.09 and 2 micrometer [= um] wavelength. */
/*    For larger wavelengths, linearly interpolates between 2 um value and*/
/*    dielectric constant value.  The dispersion at 298.15 k, 0.101325 mpa*/
/*     is assumed to be unchanged at other state points. */
/*     Equation from D. Friend (NIST), Jan 3 1991. */
long double he :: refr (long double rho, long double w)
{
    /* Initialized data */
    long double rinf = 3.1704e-5;
    long double r2min = 3.464e-5;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double rdisp;
    long double rininf, w2i;

    if (w <= 0.) w2i = 1.0;
    else w2i = 1.0 / (w * w);
    rininf = sqrtl (dielhe(rho) + 1.0);
    if (w2i < 0.25) rdisp = w2i * (r2min - rinf) / 0.25;
    else rdisp = 0.0092797 / (339.82 - w2i) + 7.3123e-6 - rinf;
    ret_val = rininf + rdisp - 1.0;
    return ret_val;
} /* refr */

/*  Surface tension [N/m] as a function of temperature [K]. */
/*  Equation from D. Friend, NIST, Jan 8, 1991.  Fit of data from */
/*  Iino, Suzuki, Ikushima, JLTP 61, 155 (1985). */
long double he :: sten (long double t)
{
    /* Initialized data */

    static long double tc = 5.1953;
    static long double a1 = 3.89057e-4;
    static long double a2 = 5.2141e-4;
    static long double a3 = -5.79737e-4;

    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double tstr;

    if (t >= tc) ret_val = 0.0;
    else tstr = (tc - t) / tc;
	ret_val = tstr * (a1 + tstr * (a2 + tstr * a3));

    return ret_val;
} /* sten */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* dP/dT as a function of density and temperature [SI units] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: dpdta (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double f[7];
    int j, k, m;
    long double q[4], t, v, x, t2, dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    t2 = t * t;
    f[0] = 1.0;
    for (j = 1; j <= 4; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 6; ++k)
    {
		for (j = 1; j <= 4; ++j)
        {
		    q[j - 1] += f[k - 1] * subhec.c[j * 6 + k + 5 + m * 41 - 42];
		}
		f[k] = f[k - 1] * x;
    }
    ret_val = (pvtcsa[2] + t * (q[0] * 2.0 + t2 * (q[1] * 4.0 + t2 * (q[2] * 6.0
	    + t2 * 8.0 * q[3])))) * 1.0e6;
    return ret_val;
} /* dpdta */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* Output: DPDTM [MPa/K] = dPressure/dTemperature at constant density */
/* Input:  RR [mol/L]    = density (2-phase region excluded) */
/*         TT [K]        = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: dpdtm (long double rr, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d, t, d2, ti, ti2;

    d = rr;
    t = tt;
    d2 = d * d;
    ti = 1.0 / t;
    ti2 = ti * ti;

    ret_val = mc1.g[23] * 2.0
        + ti * 3.0 * mc1.g[24] + d2 * (mc1.g[25] * 2.0 + ti2 * 4.0 * mc1.g[26]
        + d2 * (mc1.g[27] * 2.0
        + ti * 3.0 * mc1.g[28] + d2 * (mc1.g[29] * 2.0 + ti * 3.0 *  mc1.g[30]
        + ti2 * 4.0 * mc1.g[31])));
    ret_val = mc1.g[7]
	    + ti * (mc1.g[8] * 2.0 + expl(mc1.gm * d2) * (mc1.g[19] * 2.0
	    + ti * 3.0 * mc1.g[20] + d2 * (mc1.g[21] * 2.0 + ti2 * 4.0 * mc1.g[22]
        + d2 * ret_val)));
    ret_val = d2 * (mc1.g[0] + mc1.g[1] * 0.5 / sqrtl(t) - ti2 * (mc1.g[3]
	    + ti * 2.0 * mc1.g[4]) + d * (mc1.g[5] - ti2 * ret_val + d * (mc1.g[9]
	    - ti2 * mc1.g[11] - d2 * ti2 * (mc1.g[13] + ti * 2.0 * mc1.g[14]
        + d * mc1.g[15] + d2 * (mc1.g[16] + ti * 2.0 * (mc1.g[17]
        + d * mc1.g[18])))))) + mc1.r * d;
    return ret_val;
} /* dpdtm */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* dP/dT [kG/K] at constant V as a function of density [kg/m3] */
/* and temperature [K] */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
long double he :: dpdt (long double d, long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double da, th, tl, wt;

    amlap (tl, th, d);
    if (t > tl)
    {
		ret_val = dpdtm(d / 4.0026, t) * 1.0e6;
		if (t >= th) return ret_val;
    }
    da = dpdta (d, t);
    if (t <= tl) ret_val = da;
    else
    {
		wt = (t - tl) / (th - tl);
		ret_val = wt * ret_val + (1.0 - wt) * da;
    }
    return ret_val;
} /* dpdt */

void he :: logfun (long double *pvtcsa, long double tt, long double dtt, int m)
/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* quasi-logarithmic thermodynamic functions */
/* Output: */
/* PVTCSA(1) = pressure [MPa] */
/* PVTCSA(2) = dP/dV [MPa-kg/m3] */
/* PVTCSA(3) = dP/dT [Mpa/K] */
/* PVTCSA(4) = Cv [J/kg -K] */
/* PVTCSA(5) = entropy [J/kg-K] */
/* PVTCSA(6) = Helmholz energy [J/kg] */
/* Input: */
/* T  = Temperature */
/* DT = T - Tlambda = isochoric distance to the lambda line */
/*(Note: parameters in common SUBLAM must have evaluated prior to this call*/
/*  to LOGFUN, by a call to subroutine LAMDER.) */
{
    /* Initialized data */
    long double zero = 0.0;
    long double dtsave = 98765.432;
    long double tsave = 98765.432;
    long double cl5[5] = { 1.0,-4.0,12.0,-24.0,24.0 };

    /* Local variables */
    long double fact, e;
    int i, j;
    long double r, t, y[9], z, r0, t2, aa, ac, ad, ej, ap, as, at,
			    dt, xa, xd, xp, xs, xt, ckm;

    /* Function Body */
    t = tt;
    dt = dtt;
    if ((dt != dtsave) || (t != tsave))
    {
		/* Calculation is skipped if input parameters are unchanged */
		dtsave = dt;
		tsave = t;

		/* Y(1) = quasi-logarithmic singularity */
		/* Y(i), i>1, = successive indefinite integrals */

		if (dt == zero)
        {
	    	y[0] = -100.0;
	    	for (i = 2; i <= 9; ++i) y[i - 1] = zero;
		}
        else
        {
	    	z = fabsl(dt);
	    	y[0] = logl(z);
		    fact = 1.0;
	    	for (i = 2; i <= 9; ++i)
            {
				if ((fabsl (y[i - 2]) < 1e-25) && (i > 2))
                    y[i - 1] = zero;
				else
                    y[i-1] = (dt * y[i-2] - powl (dt, i-1) / fact) / (i-1);
        		fact *= 1.0*i;
			}
	    }

/* Thermodynamic function evaluation */
/* -----Version 3.3; function rewritten for greater efficiency */

		t2 = t * t;
		r0 = t2 * t2;
		ap = subhec.c[m * 41 - 41] * y[1] + subhec.c[m * 41 - 40] *
			 (t2 * y[1] - t * 4.0 * y[2] + y[3] * 6.0);
		at = subhec.c[m * 41 - 41] * y[0] + subhec.c[m * 41 - 40] *
			 (t2 * y[0] - t * 2.0 * y[1] + y[2] * 2.0);
		ad = subhec.c[m * 41 - 41] * y[0] + subhec.c[m * 41 - 40] *
			 (t2 * y[0] - t * 4.0 * y[1] + y[2] * 6.0);
		ac = subhec.c[m * 41 - 41] * t * y[0] + subhec.c[m * 41 -
			 40] * t2 * t * y[0];
		as = subhec.c[m * 41 - 41] * y[1] + subhec.c[m * 41 - 40] *
			 (t2 * y[1] - t * 2.0 * y[2] + y[3] * 2.0);
		aa = subhec.c[m * 41 - 41] * y[2] + subhec.c[m * 41 - 40] *
			 (t2 * y[2] - t * 4.0 * y[3] + y[4] * 6.0);
		for (i=1; i <= 3; ++i)
    	{
			ckm = subhec.c[i + 2 + m * 41 - 42];
		    xp = r0 * y[i];
		    xt = r0 * y[i - 1];
	    	xd = r0 * y[i - 1];
		    xs = r0 * y[i];
		    xa = r0 * y[i + 1];
	    	r = r0 / t;
		    for (j = 2; j <= 5; ++j)
    	    {
				e = cl5[j - 1] * r;
				ej = e * j;
				xp += ej * y[i + j - 1];
				xt += e * y[i + j - 2];
				xd += ej * y[i + j - 2];
				xs += e * y[i + j - 1];
				xa += ej * y[i + j];
				r /= t;
		    }
		    ap += ckm * xp;
	    	at += ckm * xt;
		    ad += ckm * xd;
		    ac += ckm * t * r0 * y[i - 1];
	    	as += ckm * xs;
		    aa += ckm * xa;
		}
		ad = sublam.dtldv * sublam.dtldv * ad - sublam.d2tdv2 * ap;
		ap = -sublam.dtldv * ap;
		at = -sublam.dtldv * at;
    }
	/* Output */
    *pvtcsa = ap;
    *(pvtcsa + 1) = ad;
    *(pvtcsa + 2) = at;
    *(pvtcsa + 3) = ac;
    *(pvtcsa + 4) = as;
    *(pvtcsa + 5) = aa;
} /* logfun */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* dP/dD as a function of density and temperature [SI units] */
/* Valid in compressed liquid from 0.8 to about 3 K. */
/* If TT is less than 0.8 K, TT is assumed to be the isochoric distance */
/*    to the lambda line (negative in HeII, positive in HeI). */
long double he :: dpdda (long double d, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double dpdv, f[6];
    int j, k, m;
    long double q[5], t, v, x, t2, ff, dt;
    long double pvtcsa[6];

    v = 1.0e3 / d;
    x = v - subhec.v0;
    if (v != sublam.vsave) lamder (v);
    if (tt > 0.7999)
    {
		t = tt;
		dt = t - sublam.tl;
    }
    else
    {
		dt = tt;
		t = sublam.tl + dt;
    }
    if (dt > 0.0) m = 1;
    else m = 2;
    logfun (&pvtcsa[0], t, dt, m);
    t2 = t * t;
    f[0] = 1.0;
	/* L40: */
    for (j = 1; j <= 5; ++j) q[j - 1] = 0.0;
    for (k = 1; k <= 5; ++k)
    {
		ff = f[k - 1] * k;
		/* L50: */
		for (j = 1; j <= 5; ++j)
		    q[j - 1] += ff * subhec.c[j * 6 + k + m * 41 - 42];
		/* L60: */
		f[k] = f[k - 1] * x;
    }
    dpdv = pvtcsa[1] + q[0] + t2 * (q[1] + t2 * (q[2] + t2 * (q[3] + t2 * q[4])));
    ret_val = dpdv * -1e9 / (d * d);
    return ret_val;
} /* dpdda */

/* (C) Copyright (1994), Cryodata Inc.; all rights reserved. */
/* Output: DPDDM [MPa-L/mol] = dPressure/dDensity at constant temperature*/
/* Input:  RR [mol/L]        = density (2-phase region excluded) */
/*         TT [K]            = temperature, range 2 to 1500 K */
/* -----Version 3.3; function rewritten for greater efficiency */
long double he :: dpddm (long double rr, long double tt)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d, f, t, d2, f1, ti, fy, fz, ti2;

    d = rr;
    t = tt;
    d2 = d * d;
    ti = 1.0 / tt;
    ti2 = ti * ti;
    f = expl(mc1.gm * d2);
    f1 = f * 2.0 * mc1.gm * d;
    fz = f1 * d2 * d;
    fy = f * 3.0 * d2;

    ret_val = (t * mc1.g[9] + mc1.g[10] + ti * mc1.g[11] + d * 1.25 *
	    mc1.g[12]) * 4.0 + d2 * ti * ((mc1.g[13] + ti * mc1.g[14]) *
	    6.0 + d * 7.0 * mc1.g[15] + d2 * ((mc1.g[16] + ti * mc1.g[
	    17]) * 8. + ti * 9. * d * mc1.g[18]));
    ret_val = (mc1.g[2] + mc1.g[1] * sqrtl(t) + mc1.g[0] * t + ti
	    * (mc1.g[3] + ti * mc1.g[4])) * 2.0 + d * ((t * mc1.g[5] +
	    mc1.g[6] + ti * (mc1.g[7] + ti * mc1.g[8])) * 3. + d * ret_val);
    ret_val = d * ret_val + ti2 * ((fy + fz) *
	    (mc1.g[19] + ti * mc1.g[20]) + d2 * ((fy * 5.0 / 3.0
	    + fz) * (mc1.g[21] + ti2 * mc1.g[22]) + d2 * ((fy *
	    7.0 / 3.0 + fz) * (mc1.g[23] + ti * mc1.g[24]) + d2 *
	    ((fy * 3. + fz) * (mc1.g[25] + ti2 * mc1.g[26]) + d2 * ((fy *
	     11.0 / 3.0 + fz) * (mc1.g[27] + ti * mc1.g[28]) + d2
	    * ((fy * 13.0 / 3.0 + fz) * (mc1.g[29] + ti * mc1.g[30]
	    + ti2 * mc1.g[31]))))))) + mc1.r * t;
    return ret_val;
} /* dpddm */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* Computes the overlap temperatures between Arp and McCarty equations */
/* as a function of density [kg/m3]. */
/* TMINM is the minimum temperature for McCarty (in compressed liquid). */
/* TMAXA is the maximum temperature for Arp */
void he :: amlap (long double& tminm, long double& tmaxa, long double d)
{
    /* Initialized data */

    long double tm = 2.53;
    long double ta = 2.98;
    long double dmin = 140.0;
    long double dmax = 190.0;

    long double dt;

    if (d < dmin || d > dmax)
    {
		tminm = 0.0;
		tmaxa = 0.1;
    }
    else
    {
		/* Note: -0.28 [K] / (DMAX-DMIN) = -0.0056 = slope of boundary line */
		dt = -0.0056 * (d - dmin);
		tminm = tm + dt;
		tmaxa = ta + dt;
		if (d > 180.0)
        {
	    	dt = -0.035 * (d - 180.0);
	    	tminm += dt;
	    	tmaxa += dt;
		}
    }
} /* amlap */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* dP/dD [Pa-m3/kg] at constant T as a function of density [kg/m3] */
/* and temperature [K] */
/* Valid for temperatures 0.8 to 1500 K, but excluding the 2-phase region. */
long double he :: dpdd (long double d, long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double da, th, tl, wt;

    amlap (tl, th, d);
    if (t > tl)
    {
		ret_val = dpddm (d/4.0026, t) * 249837.6;
		if (t >= th) return ret_val;
    }
    if (t >= th) return ret_val;
    da = dpdda (d, t);
    if (t <= tl) ret_val = da;
    else
    {
    	wt = (t - tl) / (th - tl);
		ret_val = wt * ret_val + (1.0 - wt) * da;
    }
    return ret_val;
} /* dpdd */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* This function written by B.A. Hands. */
/*  thermal conductivity as a function of density and temperature */
long double he :: tcon (long double rho, long double t)
{
    /* Initialized data */

    long double f[12] = { 3.726229668,1.86297053e-4,-7.275964435e-7,
	    -1.427549651e-4,3.290833592e-5,-5.213335363e-8,4.492659933e-8,
	    -5.924416513e-9,7.087321137e-6,-6.013335678e-6,8.067145814e-7,
	    3.995125013e-7 };
    long double x0 = 0.392;
    long double e1 = 2.8461;
    long double e2 = 0.27156;
    long double beta = 0.3554;
    long double gamma = 1.1743;
    long double delta = 4.304;
    long double dc = 69.58;
    long double tc = 5.18992;
    long double pc = 227460.;
    long double const_ = -5.882788298;
    long double con = 3.4685233e-17;
    long double c[5] = { 0.7034007057,3.739232544,-26.20316969,
	    59.82252246,-49.26397634 };

    /* Local variables */
    long double deld;
    long double dhdx, delt;
    long double xx2be, a, d, h;
    int i;
    long double w, kcrit, d2, d3, k0, r2, t1, t2, x1, dl, kt, tt;
    long double kt1, pdt, d2kt, xx2b;

    d = rho;
    if (t < 3.5)
    {
		if (d < dc) return conlpt (rho, t);
        else return 0.0;
    }
    t1 = powl (t, 1.0/3.0);
    t2 = t1 * t1;
    d2 = rho * rho;
    d3 = rho * d2;
    if (rho < 1.0e-8) dl = 0.0;
    else dl = d2 * logl(rho / 69.64);

    /* Calculate critical enhancement */
    if ((t > 12.0) || (t < 3.5)) kcrit = 0.0;
    else
    {
		/* Calculate compressibility */
    	kt = 1.0 / dpdd (rho, t) / rho;
    	deld = fabsl ((rho - dc) / dc);
    	delt = fabsl ((t - tc) / tc);
	    r2 = delt * delt / 0.04 + deld * deld / 0.0625;
    	if (r2 < 1.0)
        {
		    w = delt / powl (deld, 1.0 / beta);
		    x1 = (w + x0) / x0;
		    xx2b = powl (x1, 2.0*beta);
		    xx2be = powl (e2 * xx2b + 1.0, (gamma - 1.0) / 2.0 / beta);
		    h = e1 * x1 * xx2be;
		    dhdx = e1 * xx2be / x0 + e1 * e2 / x0 * xx2b * xx2be / (e2 * xx2b + 1.0) * (gamma - 1.0);
		    d2kt = (delta * h - w * dhdx / beta) * powl(deld, delta - 1.0);
		    kt1 = dc * dc / d2 / d2kt / pc;
		    kt = r2 * kt + (1.0- r2) * kt1;
	    }
	    pdt = dpdt (rho, t);
    	kcrit = t*t * sqrtl(kt) / rho / viscos (rho, t) * pdt * pdt *
		        expl(-18.66 * delt * delt - 4.25 * powl (deld, 4));
	    kcrit *= con;
    }
    a = 0.0;
    tt = t;
    for (i = 2; i <= 5; ++i)
    {
		a = c[i - 1] / tt + a;
		tt *= t;
    }
    k0 = powl(t, c[0]) * expl(a + const_);
    dl = d2 * logl(rho / 68.0);
    return k0 + f[0] * kcrit + rho * (f[1] + f[2] * t + f[3] * t1 + f[4]
	    * t2) + d3 * (f[5] + f[6] * t1 + f[7] * t2) + dl * (f[8] + f[9] *
	    t1 + f[10] * t2 + f[11] / t);
} /* tcon */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Conductivity of vapor, T < 3.5 K; extrapolation of HEPAK v3.0 data. */
/* The accuracy of this extrapolation is unknown.  Existing data from */
/* 3.5 to 20 K suggests anomalous behavior in the low T limit. */
/* The assigned lower limit of 1.2 K is arbitrary. */
/* Units: CONLPT [W/m-K], Density [Kg/m3], Temperature [K] */
/* V. Arp; August, 1992 */
long double he :: conlpt (long double d, long double t)
{
    /* Initialized data */

    long double a = 0.001916377113;
    long double b = 4.654575892e-5;

    /* System generated locals */
    long double ret_val;

    if (t > 1.1999999)	ret_val = a * t + b * d;
    else ret_val = 0.0;

    return ret_val;
} /* conlpt */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Output: Viscosity [SI units = Pa-s] */
/*Input:  Density [Kg/m3] (single phase region only!), and Temperature [K]*/
/* -----Version 3.2; 7/2/92 */
long double he :: viscos (long double dkgm3, long double tk)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double d, t, w, vx;

    d = dkgm3;
    t = tk;
    if (t > 3.5)
    {
		ret_val = vischi (d, t);
		if (t >= 3.75) return ret_val;
    }
	/* Param(5) is the critical density */
    if (d > prinit.dcrit) vx = vislam (d, t);
    else vx = vislpt (d, t);

    if (t <= 3.5) return vx;

    w = (t - 3.5) / 0.25;
    ret_val = w * ret_val + (1.0 - w) * vx;
    return ret_val;
} /* viscos */

/* Output: Viscosity [SI units = Pa-s] */
/* Input:  Density [Kg/m3], and Temperature [K] (valid only for T>3.5K) */

/* This is consistent with NIST's viscosity function, January, 1991, */
/* by D.G.Friend, V. Arp and R.D. McCarty. */
long double he :: vischi (long double dkgm3, long double t)
{
    /* System generated locals */
    long double ret_val;

    /* Local variables */
    long double visc0, b, c, d, r, visch, viscl, tl;

    if (t <= 300.0)	tl = logl(t);
    else tl = 5.7037825;		/* TL = logl(300) */
    viscl = expl(-0.135311743 / tl + 1.00347841 + tl * (tl * (tl * 0.0125208416
	    - 0.149564551) + 1.20654649));
    visc0 = viscl;
    if (t > 100.0)
    {
		visch = powl (t, 0.71938) * 196.0 * expl((12.451 - 295.67 / t) / t - 4.1249);
		if (t < 110.) visc0 = viscl + (visch - viscl) * (t - 100.0) / 10.0;
	 	else visc0 = visch;
    }
    r = dkgm3 * 0.001;
    b = -47.5295259 / tl + 87.6799309 + tl * (tl * (8.33128289 - tl * 0.589252385) - 42.0741589);
    c = 547.309267 / tl - 904.870586 + tl * (tl * (tl * 5.37008433 - 81.4504854) + 431.404928);
    d = -1684.39324 / tl + 3331.0863 + tl * (tl * (308.804413 - tl * 20.2936367) - 1632.19172);
    ret_val = (visc0 + viscl * (expl(r * (b + r * (c + r * d))) - 1.0)) * 1e-7;
    return ret_val;
} /* vischi */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* -----OUTPUT */
/* T      = Lambda temperature [K] [T76 scale] */
/* DTDV   = dT/dV              [(K-gm)/cm3] */
/* D2TDV2 = d2T/dV2            [(K-gm2)/cm6] */
/* -----INPUT */
/* V = Specific volume [cm3/gm] */
void he :: lamder (long double v)
{
    /* Initialized data */
    long double a[5] = { 0.091672438,-0.082840336,0.071832749,0.04839517,0.039159012 };

    long double x;

    x = v - subhec.v0;
    sublam.tl = subhec.t0 + x*(a[0] + x*(a[1] + x*(a[2] + x*(a[3] + x*a[4]))));
    sublam.dtldv = a[0] + x*(a[1]*2.0 + x*(a[2]*3.0 + x*(a[3]*4.0 + x*5.0*a[4])));
    sublam.d2tdv2 = a[1]*2.0 + x*(a[2]*6.0 + x*(a[3]*12.0 + x*20.0*a[4]));
} /* lamder */

/* (C) Copyright (1990), Cryodata Inc.; all rights reserved. */
/* lambda line temperature as a function of density */
long double he :: tlfd (long double d)
{
    /* Local variables */
    long double vcgs;

    vcgs = 1.0e3 / d;
    lamder (vcgs);

    return sublam.tl;
} /* tlfd */

/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Liquid helium viscosity, 1.2 to 3.8 K */
/*     Fitted to HMeyer's data along the saturation line. */
/*    Extended to higher densities by using Hoffman's (Brewer and Edwards)*/
/*     data, shifted by 6.2 pct; joined smoothly to Steward's data */
/*     at T = 3.6 to 3.8 K. */
/*     The calling program must make certain that the input density */
/*     is within the liquid range (nominally 132 to 180+ Kg/m3). */
/* Units: VISLAM [Pa-s], DD [Kg/m3], TT [K] */
long double he :: vislam (long double dd, long double tt)
{
    /* Initialized data */

    long double e0[2] = { 1.8,-4.79 };
    long double a[3] = { 2.505885162,0.5230553382,0.5607799718 };
    long double b[8] = { -112.7424846,209.5894826,-128.6503418,
	    -79.51538104,201.5521019,-123.1199069,-64.60724357,54.24829902 };
    long double c[8] = { 877.2148954,-2515.234338,2679.676294,
	    346.9587682,-1509.946785,2056.348276,288.6724375,-383.1832082 };

    /* Local variables */
    long double dens;
    long double d, e;
    int j;
    long double t, v, x, tl;

    dens = dd;
    tl = tlfd (dens);
    t = tt;
    if (t < 1.1999999) return 0.0;

    x = fabsl (1.0 - t / tl);
    d = (dens / 146.15 - 1.0) * 10.0;
    if (t <= tl)
    {
		j = 1;
		v = x * x * (c[0] + x * (c[1] + x * c[2]) + d * (c[3] + x *
			(c[4] + x * c[5]) + d * x * (c[6] + x * c[7])));
    }
    else
    {
		j = 0;
		v = x * x * (b[0] + x * (b[1] + x * b[2]) + d * (b[3] + x * (b[4] +
			x * b[5]) + d * (b[6] + x * b[7])));
    }
    e = 10.0 * (1.0 + e0[j] * powl(x+1e-8, 0.84));
    v += e * (a[0] + d * (a[1] + d * a[2]));
    return v * 1e-7;
} /* vislam */


/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* Viscosity of vapor, T < 3.5 K; extrapolation of HEPAK v3.0 data. */
/* The accuracy of this extrapolation is unknown.  Existing data from */
/* 3.5 to 20 K suggests anomalous behavior in the low T limit. */
/* The assigned lower limit of 1.2 K is arbitrary. */

/* Units: VISLPT [Pa-s], Density [Kg/m3], Temperature [K] */
long double he :: vislpt (long double d, long double t)
{
    /* Initialized data */

    long double a = 0.2539133848;
    long double b = 0.01024277783;

    if (t > 1.1999999) return (a*t + b*d) * 1.0e-6;
    else return 0.0;
} /* vislpt */


/* (C) Copyright (1992), Cryodata Inc.; all rights reserved. */
/* -----DESCRIPTION */
/* This subroutine finds the root, R, such that F(R) = F0, */
/* where F is an external function, and F0 is a specified constant. */
/* -----EXTERNAL VARIABLES */
/* This version of ROOTAZ assumes that all external floating-point */
/* variables are DOUBLE PRECISION */
/* OUTPUT VARIABLES */
/*   R           = the desired root,     if JX is positive; */
/*               = an approximate root,  if JX is zero; */
/*               = an invalid root,      if JX is negative. */
/*   JX          = number of calls to F, if ROOTAZ was successful. */
/*                 If JX=0, input error tolerances may be invalid. */
/*                 If JX = JMAX+4 = 54, iteration has been terminated without*/
/*                 satisfying any convergence criterion. */
/*               = -1 if input values of A, B, C, and Z are invalid */
/*               = -2 if input values of EXA, EXR, EYA, or EYR are invalid. */
/*               = -3 if extrapolation beyond [B, C] is indeterminant. */
/*               = -4 if extrapolation beyond A or Z was attempted. */
/*               = -5 if extrapolation of a non-monotonic function */
/*                     was attempted. */
/* INPUT VARIABLES */
/*   A and Z     = limiting values of the independent variable which must */
/*                 bracket the root R.  A must not equal Z.  ROOTAZ will */
/*                 not extrapolate beyond these limits. */
/*   B and C     = Initial guesses for the root R.  B must not equal C, */
/*                 and both must be within or at the limits of the */
/*                 range [A, Z]. */
/*   EXA and EXR = absolute and relative tolerances on the independent */
/*                 variable.  R is accepted as the root if it is */
/*                 bracketed within the range EXA + EXR*R */
/*                 EXA must be > zero.  EXR must be >= zero. */
/*   EYA and EYR = absolute and relative tolerances on the dependent */
/*                 variable.  R is accepted as the root if the absolute */
/*                 value of F(R) - F0 is less than EYA + EYR*F0 */
/*                 EYA must be > zero.  EYR must be >= zero. */
/*   F0          = the specified value of the function F */
/* Note:  ROOTAZ does not modify any of these input variables */
/*   F           = the external function.  It must be named in an EXTERNAL */
/*                statement in the calling program.  It can be non-monotonic*/
/*                 if B and C bracket R, but must be monotonic if */
/*                 extrapolation is required.. */
/* -----INTERNAL VARIABLES */
/* All internal floating point variables are DOUBLE PRECISION */
/* X(1)...X(4)     are successive approximations to R. */
/* Y(1)...Y(4)     are successive values of F(X(i)) - F0. */
/*ESYS            specifies the machine precision of the external variables.*/
/*                It must be larger than the smallest number EPS such that */
/*                1 + EPS is not equal to 1 in double precision arithmetic.*/
/* JMAX            should be chosen such that 2**JMAX > (1/ESYS)**2 */
/*                 in order to assure convergence for any F. */
/* Other variables are used in intermediate steps. */

/* -----VERSION Sept. 13, 1992;  V. Arp */
/* Statement function */
/* fonction */
/*void he :: rootaz ( long double& r, long double a, long double b, long double c,
              long double z, long double exa, long double exr, long double eya,
              long double eyr, long double (*f) (long double),
              long double f0, int& jx)*/
void he :: rootaz ( long double& r, long double a, long double b, long double c,
              long double z, long double exa, long double exr, long double eya,
              long double eyr, int i,
              long double f0, int& jx)
{
    /* System generated locals */
    long double esys = 1.0e-8;
    long double ome = 1.0-esys;
    int jmax = 50;

    /* Local variables */
    long double xlim, step, w, x[4], y[4];
    bool limit;
    int jd, jf, jg, jj, jo, js;
    long double r21, r32;
    long double ey, xe;
    long double xi, xjd, yjd, xjo, xjs;

	long double res1, res2;

	// Check for valid parameters
    if ((a == z) || (b == c) || ((b-a)*(b-z) > 0.0) || ((c-a)*(c-z) > 0.0))
    {
		jx = -1;
		return;
    }
    if ((exa <= 0.0) || (exr < 0.0) || (eya <= 0.0) || (eyr < 0.0))
    {
		jx = -2;
		return;
    }
    limit = false;
    ey = eya + (eyr + 1e-8) * fabsl(f0);

	// First guess
//  y[0] = (*f)(b) - f0;
    y[0] = f (i, b) - f0;
    if (fabsl(y[0]) < ey)
    {
		jx = 1;
		r = b;
		return;
    }

	/* Second guess */
//  y[1] = (*f)(c) - f0;
    y[1] = f (i, c) - f0;
    if (fabsl(y[1]) < ey)
    {
		jx = 2;
		r = c;
		return;
    }
    r21 = y[1] / y[0];

	/* Order such that Y(2) is smaller than Y(1).  This is required for */
	/* extrapolation, where monotonic F(x) is assumed. */
	/* If extrapolation is not required, F(x) can be non-monotonic. */

    if (fabsl(r21) > 1.0+esys)
    {
		r32 = y[1];
		y[1] = y[0];
		y[0] = r32;
		x[0] = c;
		x[1] = b;
    }
    else if (r21 < ome)
    {
		x[0] = b;
		x[1] = c;
    }
    else
    {
		/* Failure: Constant function F; indeterminant extrapolation. */
		jx = -3;
		return;
    }

	/* Third try: linear interpolation or extrapolation */

    step = x[1] - x[0];
    x[2] = y[1] * step / (y[0] - y[1]) + x[1];
	res2 = exa + (exr+esys) * fabsl(x[0]) + (exr+esys) * fabsl(x[1]);
    if (r21 > 0.0)
    {

		/* Extrapolation; check limits. */
		/* First, find which limit applies. */

		if ((a - x[1]) / step >= 0.0) xlim = a;
		else xlim = z;

  		res1 = exa + (exr+esys) * fabsl(x[1]) + (exr+esys) * fabsl(x[1]);
		if (fabsl (x[1] - xlim) < 0.5*res1)
    	{
			/* Failure: A=B or A=C or Z=B or Z=C; extrapolation is not permitted. */
	    	jx = -4;
	    	return;
		}
		/* Do not extrapolate beyond XLIM. */
		if ((x[2] - xlim) * (x[2] - x[0]) >= 0.0)
    	{
	    	x[2] = xlim;
	    	limit = true;
		}
    }
    else if (fabsl(step) <= res2)
    {
		/* B and C straddle the root. */
		/* Return if their separation is is less than the minimum acceptable*/
		/* separation specified by EXA, EXR, and ESYS.   User should check for */
		/* input error. */
		jx = 0;
		r = x[2];
		return;
    }

//  y[2] = (*f)(x[2]) - f0;
    y[2] = f (i, x[2]) - f0;
    if (fabsl(y[2]) < ey)
    {
		r = x[2];
		jx = 3;
		return;
    }
    jf = 0;
    jg = 0;

	/* -----Do loop */

    for (jj = 0; jj <= jmax; ++jj)
    {
		r21 = y[1] / y[0];
		r32 = y[2] / y[1];
		if ((r32 > 0.0) && (r21 > 0.0))
    	{

			/* Root not bracketed; extrapolation still required. */

	    	if (limit)
            {
				/* Failure; further extrpolation is prohibited. */
				jx = -4;
				return;
	    	}
	    	if (r32 >= ome)
            {
				/* Extrapolation failure: constant or non-monotonic function. */
				jx = -5;
				return;
	    	}
	    	xi = y[2] * (x[2] - x[1]) / (y[1] - y[2]);
	    	if (r21 > r32)
            {
				/* Use inverse quadratic extrapolation if fabsl(slope) is decreasing. */
				xe = y[2] * (x[2] - x[0]) / (y[0] - y[2]);
				w = y[0] / (y[0] - y[1]);
				xi = w * xi + (1.0 - w) * xe;
	    	}
	    	x[3] = xi + x[2];
	    	if (r32 > 0.1)
            {
				/* If extrapolation convergence is slow, give an artificial boost. */
				if (jj >= 2) x[3] += (jj - 1.0) * step;
                else x[3] += (jj + 1.0) * (x[2] - x[1]);
		    }
			/* But do not extrapolate beyond the limit. */
	    	if ((x[3] - xlim) * (x[3] - x[0]) > 0.0)
            {
				x[3] = xlim;
				limit = true;
	    	}
	    	jf = 0;
	    	js = 2;
		}
        else
        {

			/* Root has been bracketed. */
			/*    Define the geometry. */
	    	if (r32 < 0.0)
            {
				jo = 1;
				jf = 0;
				if (r21 < 0.0)
                {
		    		js = 2;
		    		jd = 3;
		    		++jg;
				}
                else
                {
		    		js = 3;
                    jd = 2;
		    		jg = 0;
				}
	    	}
            else
            {
				js = 1;
				jd = 3;
				jo = 2;
				++jf;
				jg = 0;
	    	}
	    	xjd = x[jd - 1];
	    	xjs = x[js - 1];
	    	xjo = x[jo - 1];
	    	yjd = y[jd - 1];
			/* Exit if the bracket width is less than EX */
	  		res1 = exa + (exr+esys) * fabsl(x[js-1]) + (exr+esys) * fabsl(x[jd-1]);
	    	if (fabsl (xjs-xjd) <= res1)
            {
				jx = jj + 3;
				r = x[2];
				return;
	    	}
	    	if ((fabsl(r32) >= ome) || (jg >= 2) && (r32 < -0.7))
            {
				/* Not converging: bisect. */
				x[3] = (xjs + xjd) * 0.5;
				jf = 0;
	    	}
            else
            {
				/* The following approximates quadratic interpolation when converging */
				/* nicely.  Otherwise it can accelerate the search when large changes */
				/* in slope and/or slow movement toward a distant root are found. */

				xi = yjd * (xjd - xjs) / (y[js - 1] - yjd) + xjd;
				if (fabsl(y[jo - 1] - yjd) < ey) xe = xjs;
				else
                {
		    		xe = yjd * (xjd - xjo) / (y[jo - 1] - yjd) + xjd;
		    		if ((xe - xjs) * (xe - xjd) > 0.0) xe = xjs;
				}
				w = (xjd - xjo) / (xjs - xjo);
				if (jf >= 2 && w < 0.3 && r32 > 0.25)
                	x[3] = x[2] + (x[0] - x[2]) * sqrtl(w);
                else
				    x[3] = w * xi + (1.0 - w) * xe;
	    	}
		}
		/* X(4), Y(4) are the new estimate. */
//		y[3] = (*f)(x[3]) - f0;
		y[3] = f (i, x[3]) - f0;
		if (fabsl(y[3]) < ey)
        {
	    	jx = jj + 4;
	    	r = x[3];
	    	return;
		}
		/* Update indices. */
		if (js >= 2)
        {
	    	x[0] = x[1];
	    	y[0] = y[1];
		}
		x[1] = x[2];
		x[2] = x[3];
		y[1] = y[2];
		y[2] = y[3];

    } /* L480: */

	/* This statement should never be reached */
    r = x[3];
    jx = jmax + 4;
    return;
} /* rootaz */

long double he :: f (int i, long double x)
{
    long double y;
    switch (i)
    {
        case 1 : y = tlfd (x); break;
        case 2 : y = plft (x); break;
        case 3 : y = sats (x); break;
        case 4 : y = satly (x); break;
        case 5 : y = satvy (x); break;
        case 6 : y = dpt (x); break;
        case 7 : y = dst (x); break;
        case 8 : y = dths (x); break;
        case 9 : y = pmft (x); break;
        case 10 : y = psat (x); break;
        case 11 : y = satd1 (x); break;
        case 12 : y = satd (x); break;
        case 13 : y = tdp (x); break;
        case 14 : y = dmft (x); break;
        case 15 : y = yjfdt (x); break;
        case 16 : y = dtg (x); break;
    }
    return y;
}

/*int he :: affiche (long double *tab, int dep, int fin)
{
    FILE *f, *g;
    f = new (FILE);
    g = new (FILE);
    f = fopen ("d:\\programmes\\codes\\gaz\\tempoh.txt", "wt");
    g = fopen ("D:\\fortran\\Tempoh.txt", "rt");
    int i, j;
    AnsiString ligne;
    long double a, b;
    Formatage F(16);

    j = 0;
    for (i=dep; i<=fin; i++)
    {
        ligne = lit_f_esp (g);
        a = AS2LD (lit_f_esp (g));
        if (fabsl(a) > 1e-14) b = (a - *(tab + i)) / a;
        else b = a - *(tab + i);
        if (fabsl(b) < 6e-6) b = 0;
        else
        {
            j++;
            if (j == 1) fprintf (f, "N°               C++           fortran            erreur\n");
            fprintf (f, "%2i  %s", i, F.f(*(tab + i)));
            fprintf (f, "  %s", F.f(a));
            fprintf (f, "  %s\n", F.f(b));
        }
    }
    if (j == 0) fprintf (f, "Pas de problème");

    fclose (f);
    delete (f);
    fclose (g);
    delete (g);
    return j;
}*/
