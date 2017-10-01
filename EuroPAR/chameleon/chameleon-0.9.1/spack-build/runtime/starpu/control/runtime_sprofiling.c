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
 * @file runtime_sprofiling.c
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
#include "runtime/starpu/include/morse_starpu.h"

void RUNTIME_sdisplay_allprofile()
{

    /* BLAS 3 */
    profiling_display_sgemm_info();
#if defined(PRECISION_z) || defined(PRECISION_c)
    profiling_display_ssymm_info();
    profiling_display_ssyr2k_info();
    profiling_display_ssyrk_info();
    profiling_display_ssytrf_nopiv_info();
#endif
    profiling_display_ssymm_info();
    profiling_display_ssyr2k_info();
    profiling_display_ssyrk_info();
    profiling_display_strmm_info();
    profiling_display_strsm_info();

    /* Lapack */
    profiling_display_sgelqt_info();
    profiling_display_sgeqrt_info();
    profiling_display_sgessm_info();
    profiling_display_sgetrf_info();
    profiling_display_sgetrf_incpiv_info();
    profiling_display_sgetrf_nopiv_info();
    profiling_display_slauum_info();
    profiling_display_spotrf_info();
    profiling_display_sssssm_info();
    profiling_display_strtri_info();
    profiling_display_stslqt_info();
    profiling_display_stsmqr_info();
    profiling_display_stsqrt_info();
    profiling_display_ststrf_info();
    profiling_display_sttlqt_info();
    profiling_display_sttmlq_info();
    profiling_display_sttmqr_info();
    profiling_display_sttqrt_info();
    profiling_display_sormlq_info();
    profiling_display_sormqr_info();

    profiling_display_slange_info();
}

void RUNTIME_sdisplay_oneprofile( MORSE_kernel_t kernel )
{
    switch( kernel ) {
        /* Blas 3 */
    case MORSE_GEMM:         profiling_display_sgemm_info();         break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:         profiling_display_ssymm_info();         break;
    case MORSE_SYR2K:        profiling_display_ssyr2k_info();        break;
    case MORSE_SYRK:         profiling_display_ssyrk_info();         break;
    case MORSE_SYTRF_NOPIV:  profiling_display_ssytrf_nopiv_info();  break;
#endif
    case MORSE_SYMM:         profiling_display_ssymm_info();         break;
    case MORSE_SYR2K:        profiling_display_ssyr2k_info();        break;
    case MORSE_SYRK:         profiling_display_ssyrk_info();         break;
    case MORSE_TRMM:         profiling_display_strmm_info();         break; 
    case MORSE_TRSM:         profiling_display_strsm_info();         break;

        /* Lapack */
    case MORSE_GELQT:        profiling_display_sgelqt_info();        break;
    case MORSE_GEQRT:        profiling_display_sgeqrt_info();        break;
    case MORSE_GESSM:        profiling_display_sgessm_info();        break;
    case MORSE_GETRF:        profiling_display_sgetrf_info();        break;
    case MORSE_GETRF_INCPIV: profiling_display_sgetrf_incpiv_info(); break;
    case MORSE_GETRF_NOPIV:  profiling_display_sgetrf_nopiv_info();  break;
    case MORSE_LAUUM:        profiling_display_slauum_info();        break;
    case MORSE_POTRF:        profiling_display_spotrf_info();        break;
    case MORSE_SSSSM:        profiling_display_sssssm_info();        break;
    case MORSE_TRTRI:        profiling_display_strtri_info();        break;
    case MORSE_TSLQT:        profiling_display_stslqt_info();        break;
    case MORSE_TSMQR:        profiling_display_stsmqr_info();        break;
    case MORSE_TSQRT:        profiling_display_stsqrt_info();        break;
    case MORSE_TSTRF:        profiling_display_ststrf_info();        break;
    case MORSE_TTLQT:        profiling_display_sttlqt_info();        break;
    case MORSE_TTMLQ:        profiling_display_sttmlq_info();        break;
    case MORSE_TTMQR:        profiling_display_sttmqr_info();        break;
    case MORSE_TTQRT:        profiling_display_sttqrt_info();        break;
    case MORSE_ORMLQ:        profiling_display_sormlq_info();        break;
    case MORSE_ORMQR:        profiling_display_sormqr_info();        break;

    case MORSE_LANGE:        profiling_display_slange_info();        break;

    default:
        return;
    }
}

