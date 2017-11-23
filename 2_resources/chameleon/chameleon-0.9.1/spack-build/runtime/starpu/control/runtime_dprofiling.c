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
 * @file runtime_dprofiling.c
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
 * @generated d Tue Sep 26 20:42:59 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"

void RUNTIME_ddisplay_allprofile()
{

    /* BLAS 3 */
    profiling_display_dgemm_info();
#if defined(PRECISION_z) || defined(PRECISION_c)
    profiling_display_dsymm_info();
    profiling_display_dsyr2k_info();
    profiling_display_dsyrk_info();
    profiling_display_dsytrf_nopiv_info();
#endif
    profiling_display_dsymm_info();
    profiling_display_dsyr2k_info();
    profiling_display_dsyrk_info();
    profiling_display_dtrmm_info();
    profiling_display_dtrsm_info();

    /* Lapack */
    profiling_display_dgelqt_info();
    profiling_display_dgeqrt_info();
    profiling_display_dgessm_info();
    profiling_display_dgetrf_info();
    profiling_display_dgetrf_incpiv_info();
    profiling_display_dgetrf_nopiv_info();
    profiling_display_dlauum_info();
    profiling_display_dpotrf_info();
    profiling_display_dssssm_info();
    profiling_display_dtrtri_info();
    profiling_display_dtslqt_info();
    profiling_display_dtsmqr_info();
    profiling_display_dtsqrt_info();
    profiling_display_dtstrf_info();
    profiling_display_dttlqt_info();
    profiling_display_dttmlq_info();
    profiling_display_dttmqr_info();
    profiling_display_dttqrt_info();
    profiling_display_dormlq_info();
    profiling_display_dormqr_info();

    profiling_display_dlange_info();
}

void RUNTIME_ddisplay_oneprofile( MORSE_kernel_t kernel )
{
    switch( kernel ) {
        /* Blas 3 */
    case MORSE_GEMM:         profiling_display_dgemm_info();         break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:         profiling_display_dsymm_info();         break;
    case MORSE_SYR2K:        profiling_display_dsyr2k_info();        break;
    case MORSE_SYRK:         profiling_display_dsyrk_info();         break;
    case MORSE_SYTRF_NOPIV:  profiling_display_dsytrf_nopiv_info();  break;
#endif
    case MORSE_SYMM:         profiling_display_dsymm_info();         break;
    case MORSE_SYR2K:        profiling_display_dsyr2k_info();        break;
    case MORSE_SYRK:         profiling_display_dsyrk_info();         break;
    case MORSE_TRMM:         profiling_display_dtrmm_info();         break; 
    case MORSE_TRSM:         profiling_display_dtrsm_info();         break;

        /* Lapack */
    case MORSE_GELQT:        profiling_display_dgelqt_info();        break;
    case MORSE_GEQRT:        profiling_display_dgeqrt_info();        break;
    case MORSE_GESSM:        profiling_display_dgessm_info();        break;
    case MORSE_GETRF:        profiling_display_dgetrf_info();        break;
    case MORSE_GETRF_INCPIV: profiling_display_dgetrf_incpiv_info(); break;
    case MORSE_GETRF_NOPIV:  profiling_display_dgetrf_nopiv_info();  break;
    case MORSE_LAUUM:        profiling_display_dlauum_info();        break;
    case MORSE_POTRF:        profiling_display_dpotrf_info();        break;
    case MORSE_SSSSM:        profiling_display_dssssm_info();        break;
    case MORSE_TRTRI:        profiling_display_dtrtri_info();        break;
    case MORSE_TSLQT:        profiling_display_dtslqt_info();        break;
    case MORSE_TSMQR:        profiling_display_dtsmqr_info();        break;
    case MORSE_TSQRT:        profiling_display_dtsqrt_info();        break;
    case MORSE_TSTRF:        profiling_display_dtstrf_info();        break;
    case MORSE_TTLQT:        profiling_display_dttlqt_info();        break;
    case MORSE_TTMLQ:        profiling_display_dttmlq_info();        break;
    case MORSE_TTMQR:        profiling_display_dttmqr_info();        break;
    case MORSE_TTQRT:        profiling_display_dttqrt_info();        break;
    case MORSE_ORMLQ:        profiling_display_dormlq_info();        break;
    case MORSE_ORMQR:        profiling_display_dormqr_info();        break;

    case MORSE_LANGE:        profiling_display_dlange_info();        break;

    default:
        return;
    }
}

