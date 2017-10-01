/**
 *
 * @copyright (c) 2009-2014 The University of Tennessee and The University
 *                          of Tennessee Research Foundation.
 *                          All rights reserved.
 * @copyright (c) 2012-2014 Inria. All rights reserved.
 * @copyright (c) 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria, Univ. Bordeaux. All rights reserved.
 *
 **/

/**
 *
 * @file runtime_codelet_s.h
 *
 *  MORSE codelets kernel
 *  MORSE is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver,
 *  and INRIA Bordeaux Sud-Ouest
 *
 * @version 0.9.0
 * @author Cedric Augonnet
 * @author Mathieu Faverge
 * @author Cedric Castagnede
 * @date 2011-06-01
 * @generated s Tue Sep 26 20:42:59 2017
 *
 **/

#ifndef _CODELETS_S_H_
#define _CODELETS_S_H_

#include <stdio.h>
#include "runtime/starpu/include/runtime_codelets.h"

/*
 * Management functions
 */
SCODELETS_HEADER(tile_zero)

/*
 * BLAS 1 functions
 */
SCODELETS_HEADER(axpy)

/*
 * BLAS 3 functions
 */
SCODELETS_HEADER(gemm)
SCODELETS_HEADER(symm)
SCODELETS_HEADER(syr2k)
SCODELETS_HEADER(syrk)
SCODELETS_HEADER(symm)
SCODELETS_HEADER(syr2k)
SCODELETS_HEADER(syrk)
SCODELETS_HEADER(trmm)
SCODELETS_HEADER(trsm)

/*
 * LAPACK functions
 */
SCODELETS_HEADER(gelqt)
SCODELETS_HEADER(geqrt)
SCODELETS_HEADER(gessm)
SCODELETS_HEADER(gessq)
SCODELETS_HEADER(getrf)
SCODELETS_HEADER(getrf_incpiv)
SCODELETS_HEADER(getrf_nopiv)
SCODELETS_HEADER(lauum)
SCODELETS_HEADER(potrf)
SCODELETS_HEADER(ssssm)
SCODELETS_HEADER(syssq)
SCODELETS_HEADER(trasm)
SCODELETS_HEADER(trssq)
SCODELETS_HEADER(trtri)
SCODELETS_HEADER(tslqt)
SCODELETS_HEADER(tsmlq)
SCODELETS_HEADER(tsmqr)
SCODELETS_HEADER(tsqrt)
SCODELETS_HEADER(tstrf)
SCODELETS_HEADER(ttlqt)
SCODELETS_HEADER(ttmlq)
SCODELETS_HEADER(ttmqr)
SCODELETS_HEADER(ttqrt)
SCODELETS_HEADER(ormlq)
SCODELETS_HEADER(ormqr)

/*
 * Auxiliary functions
 */
SCODELETS_HEADER(geadd)
SCODELETS_HEADER(lacpy)
SCODELETS_HEADER(lange)
SCODELETS_HEADER(lange_max)
SCODELETS_HEADER(lansy)
SCODELETS_HEADER(lantr)
SCODELETS_HEADER(laset)
SCODELETS_HEADER(laset2)
SCODELETS_HEADER(plssq)
SCODELETS_HEADER(plssq2)

/*
 * MIXED PRECISION functions
 */
SCODELETS_HEADER(lag2d)

/*
 * DZ functions
 */
SCODELETS_HEADER(asum)

/*
 * CPU only functions
 */
SCODELETS_HEADER(plrnt)

#if defined(PRECISION_z) || defined(PRECISION_c)
SCODELETS_HEADER(syssq)
SCODELETS_HEADER(lansy)
SCODELETS_HEADER(plgsy)
SCODELETS_HEADER(sytrf_nopiv)
#endif
SCODELETS_HEADER(plgsy)

#endif /* _CODELETS_S_H_ */
