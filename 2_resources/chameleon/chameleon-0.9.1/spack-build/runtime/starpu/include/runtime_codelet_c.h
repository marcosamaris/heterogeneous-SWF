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
 * @file runtime_codelet_c.h
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
 * @generated c Tue Sep 26 20:42:59 2017
 *
 **/

#ifndef _CODELETS_C_H_
#define _CODELETS_C_H_

#include <stdio.h>
#include "runtime/starpu/include/runtime_codelets.h"

/*
 * Management functions
 */
CCODELETS_HEADER(tile_zero)

/*
 * BLAS 1 functions
 */
CCODELETS_HEADER(axpy)

/*
 * BLAS 3 functions
 */
CCODELETS_HEADER(gemm)
CCODELETS_HEADER(hemm)
CCODELETS_HEADER(her2k)
CCODELETS_HEADER(herk)
CCODELETS_HEADER(symm)
CCODELETS_HEADER(syr2k)
CCODELETS_HEADER(syrk)
CCODELETS_HEADER(trmm)
CCODELETS_HEADER(trsm)

/*
 * LAPACK functions
 */
CCODELETS_HEADER(gelqt)
CCODELETS_HEADER(geqrt)
CCODELETS_HEADER(gessm)
CCODELETS_HEADER(gessq)
CCODELETS_HEADER(getrf)
CCODELETS_HEADER(getrf_incpiv)
CCODELETS_HEADER(getrf_nopiv)
CCODELETS_HEADER(lauum)
CCODELETS_HEADER(potrf)
CCODELETS_HEADER(ssssm)
CCODELETS_HEADER(syssq)
CCODELETS_HEADER(trasm)
CCODELETS_HEADER(trssq)
CCODELETS_HEADER(trtri)
CCODELETS_HEADER(tslqt)
CCODELETS_HEADER(tsmlq)
CCODELETS_HEADER(tsmqr)
CCODELETS_HEADER(tsqrt)
CCODELETS_HEADER(tstrf)
CCODELETS_HEADER(ttlqt)
CCODELETS_HEADER(ttmlq)
CCODELETS_HEADER(ttmqr)
CCODELETS_HEADER(ttqrt)
CCODELETS_HEADER(unmlq)
CCODELETS_HEADER(unmqr)

/*
 * Auxiliary functions
 */
CCODELETS_HEADER(geadd)
CCODELETS_HEADER(lacpy)
CCODELETS_HEADER(lange)
CCODELETS_HEADER(lange_max)
CCODELETS_HEADER(lansy)
CCODELETS_HEADER(lantr)
CCODELETS_HEADER(laset)
CCODELETS_HEADER(laset2)
CCODELETS_HEADER(plssq)
CCODELETS_HEADER(plssq2)

/*
 * MIXED PRECISION functions
 */
CCODELETS_HEADER(lag2z)

/*
 * DZ functions
 */
CCODELETS_HEADER(asum)

/*
 * CPU only functions
 */
CCODELETS_HEADER(plrnt)

#if defined(PRECISION_z) || defined(PRECISION_c)
CCODELETS_HEADER(hessq)
CCODELETS_HEADER(lanhe)
CCODELETS_HEADER(plghe)
CCODELETS_HEADER(sytrf_nopiv)
#endif
CCODELETS_HEADER(plgsy)

#endif /* _CODELETS_C_H_ */
