/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Thu Dec 10 07:05:57 EST 2020 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -compact -variables 4 -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 4 -dit -name hf2_4 -include rdft/scalar/hf.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 21 stack variables, 0 constants, and 16 memory accesses
 */
#include "rdft/scalar/hf.h"

static void hf2_4(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(8, rs)) {
	       E T2, T6, T3, T5, T7, Tb, T4, Ta;
	       T2 = W[0];
	       T6 = W[3];
	       T3 = W[2];
	       T4 = T2 * T3;
	       Ta = T2 * T6;
	       T5 = W[1];
	       T7 = FMA(T5, T6, T4);
	       Tb = FNMS(T5, T3, Ta);
	       {
		    E T1, Tx, Td, Tw, Ti, Tq, Tm, Ts;
		    T1 = cr[0];
		    Tx = ci[0];
		    {
			 E T8, T9, Tc, Tv;
			 T8 = cr[WS(rs, 2)];
			 T9 = T7 * T8;
			 Tc = ci[WS(rs, 2)];
			 Tv = T7 * Tc;
			 Td = FMA(Tb, Tc, T9);
			 Tw = FNMS(Tb, T8, Tv);
		    }
		    {
			 E Tf, Tg, Th, Tp;
			 Tf = cr[WS(rs, 1)];
			 Tg = T2 * Tf;
			 Th = ci[WS(rs, 1)];
			 Tp = T2 * Th;
			 Ti = FMA(T5, Th, Tg);
			 Tq = FNMS(T5, Tf, Tp);
		    }
		    {
			 E Tj, Tk, Tl, Tr;
			 Tj = cr[WS(rs, 3)];
			 Tk = T3 * Tj;
			 Tl = ci[WS(rs, 3)];
			 Tr = T3 * Tl;
			 Tm = FMA(T6, Tl, Tk);
			 Ts = FNMS(T6, Tj, Tr);
		    }
		    {
			 E Te, Tn, To, Tt;
			 Te = T1 + Td;
			 Tn = Ti + Tm;
			 ci[WS(rs, 1)] = Te - Tn;
			 cr[0] = Te + Tn;
			 To = T1 - Td;
			 Tt = Tq - Ts;
			 ci[0] = To - Tt;
			 cr[WS(rs, 1)] = To + Tt;
		    }
		    {
			 E Tu, Ty, Tz, TA;
			 Tu = Tq + Ts;
			 Ty = Tw + Tx;
			 cr[WS(rs, 2)] = Tu - Ty;
			 ci[WS(rs, 3)] = Tu + Ty;
			 Tz = Tm - Ti;
			 TA = Tx - Tw;
			 cr[WS(rs, 3)] = Tz - TA;
			 ci[WS(rs, 2)] = Tz + TA;
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 4, "hf2_4", twinstr, &GENUS, { 16, 8, 8, 0 } };

void X(codelet_hf2_4) (planner *p) {
     X(khc2hc_register) (p, hf2_4, &desc);
}
#else

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 4 -dit -name hf2_4 -include rdft/scalar/hf.h */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 21 stack variables, 0 constants, and 16 memory accesses
 */
#include "rdft/scalar/hf.h"

static void hf2_4(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(8, rs)) {
	       E T2, T4, T3, T5, T6, T8;
	       T2 = W[0];
	       T4 = W[1];
	       T3 = W[2];
	       T5 = W[3];
	       T6 = FMA(T2, T3, T4 * T5);
	       T8 = FNMS(T4, T3, T2 * T5);
	       {
		    E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
		    T1 = cr[0];
		    Tp = ci[0];
		    T7 = cr[WS(rs, 2)];
		    T9 = ci[WS(rs, 2)];
		    Ta = FMA(T6, T7, T8 * T9);
		    To = FNMS(T8, T7, T6 * T9);
		    {
			 E Tc, Td, Tf, Tg;
			 Tc = cr[WS(rs, 1)];
			 Td = ci[WS(rs, 1)];
			 Te = FMA(T2, Tc, T4 * Td);
			 Tk = FNMS(T4, Tc, T2 * Td);
			 Tf = cr[WS(rs, 3)];
			 Tg = ci[WS(rs, 3)];
			 Th = FMA(T3, Tf, T5 * Tg);
			 Tl = FNMS(T5, Tf, T3 * Tg);
		    }
		    {
			 E Tb, Ti, Tj, Tm;
			 Tb = T1 + Ta;
			 Ti = Te + Th;
			 ci[WS(rs, 1)] = Tb - Ti;
			 cr[0] = Tb + Ti;
			 Tj = T1 - Ta;
			 Tm = Tk - Tl;
			 ci[0] = Tj - Tm;
			 cr[WS(rs, 1)] = Tj + Tm;
		    }
		    {
			 E Tn, Tq, Tr, Ts;
			 Tn = Tk + Tl;
			 Tq = To + Tp;
			 cr[WS(rs, 2)] = Tn - Tq;
			 ci[WS(rs, 3)] = Tn + Tq;
			 Tr = Th - Te;
			 Ts = Tp - To;
			 cr[WS(rs, 3)] = Tr - Ts;
			 ci[WS(rs, 2)] = Tr + Ts;
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 4, "hf2_4", twinstr, &GENUS, { 16, 8, 8, 0 } };

void X(codelet_hf2_4) (planner *p) {
     X(khc2hc_register) (p, hf2_4, &desc);
}
#endif
