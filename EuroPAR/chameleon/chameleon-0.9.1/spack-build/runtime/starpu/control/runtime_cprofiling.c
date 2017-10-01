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
 * @file runtime_cprofiling.c
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
#include "runtime/starpu/include/morse_starpu.h"

void RUNTIME_cdisplay_allprofile()
{

    /* BLAS 3 */
    profiling_display_cgemm_info();
#if defined(PRECISION_z) || defined(PRECISION_c)
    profiling_display_chemm_info();
    profiling_display_cher2k_info();
    profiling_display_cherk_info();
    profiling_display_csytrf_nopiv_info();
#endif
    profiling_display_csymm_info();
    profiling_display_csyr2k_info();
    profiling_display_csyrk_info();
    profiling_display_ctrmm_info();
    profiling_display_ctrsm_info();

    /* Lapack */
    profiling_display_cgelqt_info();
    profiling_display_cgeqrt_info();
    profiling_display_cgessm_info();
    profiling_display_cgetrf_info();
    profiling_display_cgetrf_incpiv_info();
    profiling_display_cgetrf_nopiv_info();
    profiling_display_clauum_info();
    profiling_display_cpotrf_info();
    profiling_display_cssssm_info();
    profiling_display_ctrtri_info();
    profiling_display_ctslqt_info();
    profiling_display_ctsmqr_info();
    profiling_display_ctsqrt_info();
    profiling_display_ctstrf_info();
    profiling_display_cttlqt_info();
    profiling_display_cttmlq_info();
    profiling_display_cttmqr_info();
    profiling_display_cttqrt_info();
    profiling_display_cunmlq_info();
    profiling_display_cunmqr_info();

    profiling_display_clange_info();
}

void RUNTIME_cdisplay_oneprofile( MORSE_kernel_t kernel )
{
    switch( kernel ) {
        /* Blas 3 */
    case MORSE_GEMM:         profiling_display_cgemm_info();         break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_HEMM:         profiling_display_chemm_info();         break;
    case MORSE_HER2K:        profiling_display_cher2k_info();        break;
    case MORSE_HERK:         profiling_display_cherk_info();         break;
    case MORSE_SYTRF_NOPIV:  profiling_display_csytrf_nopiv_info();  break;
#endif
    case MORSE_SYMM:         profiling_display_csymm_info();         break;
    case MORSE_SYR2K:        profiling_display_csyr2k_info();        break;
    case MORSE_SYRK:         profiling_display_csyrk_info();         break;
    case MORSE_TRMM:         profiling_display_ctrmm_info();         break; 
    case MORSE_TRSM:         profiling_display_ctrsm_info();         break;

        /* Lapack */
    case MORSE_GELQT:        profiling_display_cgelqt_info();        break;
    case MORSE_GEQRT:        profiling_display_cgeqrt_info();        break;
    case MORSE_GESSM:        profiling_display_cgessm_info();        break;
    case MORSE_GETRF:        profiling_display_cgetrf_info();        break;
    case MORSE_GETRF_INCPIV: profiling_display_cgetrf_incpiv_info(); break;
    case MORSE_GETRF_NOPIV:  profiling_display_cgetrf_nopiv_info();  break;
    case MORSE_LAUUM:        profiling_display_clauum_info();        break;
    case MORSE_POTRF:        profiling_display_cpotrf_info();        break;
    case MORSE_SSSSM:        profiling_display_cssssm_info();        break;
    case MORSE_TRTRI:        profiling_display_ctrtri_info();        break;
    case MORSE_TSLQT:        profiling_display_ctslqt_info();        break;
    case MORSE_TSMQR:        profiling_display_ctsmqr_info();        break;
    case MORSE_TSQRT:        profiling_display_ctsqrt_info();        break;
    case MORSE_TSTRF:        profiling_display_ctstrf_info();        break;
    case MORSE_TTLQT:        profiling_display_cttlqt_info();        break;
    case MORSE_TTMLQ:        profiling_display_cttmlq_info();        break;
    case MORSE_TTMQR:        profiling_display_cttmqr_info();        break;
    case MORSE_TTQRT:        profiling_display_cttqrt_info();        break;
    case MORSE_UNMLQ:        profiling_display_cunmlq_info();        break;
    case MORSE_UNMQR:        profiling_display_cunmqr_info();        break;

    case MORSE_LANGE:        profiling_display_clange_info();        break;

    default:
        return;
    }
}

