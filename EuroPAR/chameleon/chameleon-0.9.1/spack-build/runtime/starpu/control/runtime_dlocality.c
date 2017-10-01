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
 * @file runtime_dlocality.c
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
 * @generated d Tue Sep 26 20:43:00 2017
 *
 **/
#include "runtime/starpu/include/morse_starpu.h"
#include "runtime/starpu/include/runtime_codelet_d.h"

#ifdef CHAMELEON_USE_CUDA
/* Only codelets with multiple choices are present here */
void RUNTIME_dlocality_allrestrict( uint32_t where )
{

    /* Blas 3 */
    cl_dgemm_restrict_where( where );
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_dsymm_restrict_where( where );
    cl_dsyr2k_restrict_where( where );
    cl_dsyrk_restrict_where( where );
    cl_dsytrf_nopiv_restrict_where( where );
#endif
    cl_dsymm_restrict_where( where );
    cl_dsyr2k_restrict_where( where );
    cl_dsyrk_restrict_where( where );
    cl_dtrmm_restrict_where( where );
    cl_dtrsm_restrict_where( where );

    /*
     * Lapack
     */
    /* Cholesky */
    cl_dpotrf_restrict_where( where );
    cl_dlauum_restrict_where( where );
    cl_dtrtri_restrict_where( where );

    /* LU */
    cl_dgetrf_incpiv_restrict_where( where );
    cl_dgetrf_nopiv_restrict_where( where );
    cl_dgessm_restrict_where( where );
    cl_dssssm_restrict_where( where );
    cl_dtstrf_restrict_where( where );

    /* QR */
    cl_dgeqrt_restrict_where( where );
    cl_dtsqrt_restrict_where( where );
    cl_dormqr_restrict_where( where );
    cl_dtsmqr_restrict_where( where );

    /* QR-RH */
/*     cl_dttqrt_restrict_where( where ); */
/*     cl_dttmqr_restrict_where( where ); */

    /* LQ */
   cl_dgelqt_restrict_where( where );
   cl_dtslqt_restrict_where( where );
   cl_dormlq_restrict_where( where );
   cl_dtsmlq_restrict_where( where );

    /* LQ-RH */
/*     cl_dttlqt_restrict_where( where ); */
/*     cl_dttmlq_restrict_where( where ); */

}

void RUNTIME_dlocality_onerestrict( MORSE_kernel_t kernel, uint32_t where )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_dgemm_restrict_where( where );  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:   cl_dsymm_restrict_where( where );  break;
    case MORSE_SYR2K:  cl_dsyr2k_restrict_where( where ); break;
    case MORSE_SYRK:   cl_dsyrk_restrict_where( where );  break;
    case MORSE_SYTRF_NOPIV: cl_dsytrf_nopiv_restrict_where( where );  break;
#endif
    case MORSE_SYMM:   cl_dsymm_restrict_where( where );  break;
    case MORSE_SYR2K:  cl_dsyr2k_restrict_where( where ); break;
    case MORSE_SYRK:   cl_dsyrk_restrict_where( where );  break;
    case MORSE_TRMM:   cl_dtrmm_restrict_where( where );  break;
    case MORSE_TRSM:   cl_dtrsm_restrict_where( where );  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_dpotrf_restrict_where( where ); break;
    case MORSE_LAUUM:  cl_dlauum_restrict_where( where ); break;
    case MORSE_TRTRI:  cl_dtrtri_restrict_where( where ); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_dgetrf_incpiv_restrict_where( where ); break;
    case MORSE_GETRF_NOPIV: cl_dgetrf_nopiv_restrict_where( where ); break;
    case MORSE_GESSM:  cl_dgessm_restrict_where( where ); break;
    case MORSE_SSSSM:  cl_dssssm_restrict_where( where ); break;
    case MORSE_TSTRF:  cl_dtstrf_restrict_where( where ); break;

    /* QR */
    case MORSE_GEQRT:  cl_dgeqrt_restrict_where( where ); break;
    case MORSE_ORMQR:  cl_dormqr_restrict_where( where ); break;
    case MORSE_TSMQR:  cl_dtsmqr_restrict_where( where ); break;
    case MORSE_TSQRT:  cl_dtsqrt_restrict_where( where ); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_dttmqr_restrict_where( where ); break; */
/*     case MORSE_TTQRT:  cl_dttqrt_restrict_where( where ); break; */

    /* LQ */
   case MORSE_GELQT:  cl_dgelqt_restrict_where( where ); break;
   case MORSE_ORMLQ:  cl_dormlq_restrict_where( where ); break;
   case MORSE_TSMLQ:  cl_dtsmlq_restrict_where( where ); break;
   case MORSE_TSLQT:  cl_dtslqt_restrict_where( where ); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_dttmlq_restrict_where( where ); break; */
/*     case MORSE_TTLQT:  cl_dttlqt_restrict_where( where ); break; */

    default:
      return;
    }
}

void RUNTIME_dlocality_allrestore( )
{
    /* Blas 3 */
    cl_dgemm_restore_where();
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_dsymm_restore_where();
    cl_dsyr2k_restore_where();
    cl_dsyrk_restore_where();
    cl_dsytrf_nopiv_restore_where();
#endif
    cl_dsymm_restore_where();
    cl_dsyr2k_restore_where();
    cl_dsyrk_restore_where();
    cl_dtrmm_restore_where();
    cl_dtrsm_restore_where();

    /*
     * Lapack
     */
    /* Cholesky */
    cl_dpotrf_restore_where();
    cl_dlauum_restore_where();
    cl_dtrtri_restore_where();

    /* LU incpiv */
    cl_dgetrf_incpiv_restore_where();
    cl_dgessm_restore_where();
    cl_dssssm_restore_where();
    cl_dtstrf_restore_where();

    /* QR */
    cl_dgeqrt_restore_where();
    cl_dtsqrt_restore_where();
    cl_dormqr_restore_where();
    cl_dtsmqr_restore_where();

    /* QR-RH */
/*     cl_dttqrt_restore_where(); */
/*     cl_dttmqr_restore_where(); */

    /* LQ */
   cl_dgelqt_restore_where();
   cl_dtslqt_restore_where();
   cl_dormlq_restore_where();
   cl_dtsmlq_restore_where();

    /* LQ-RH */
/*     cl_dttlqt_restore_where(); */
/*     cl_dttmlq_restore_where(); */

}

void RUNTIME_dlocality_onerestore( MORSE_kernel_t kernel )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_dgemm_restore_where();  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:   cl_dsymm_restore_where();  break;
    case MORSE_SYR2K:  cl_dsyr2k_restore_where(); break;
    case MORSE_SYRK:   cl_dsyrk_restore_where();  break;
    case MORSE_SYTRF_NOPIV: cl_dsytrf_nopiv_restore_where();  break;
#endif
    case MORSE_SYMM:   cl_dsymm_restore_where();  break;
    case MORSE_SYR2K:  cl_dsyr2k_restore_where(); break;
    case MORSE_SYRK:   cl_dsyrk_restore_where();  break;
    case MORSE_TRMM:   cl_dtrmm_restore_where();  break;
    case MORSE_TRSM:   cl_dtrsm_restore_where();  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_dpotrf_restore_where(); break;
    case MORSE_LAUUM:  cl_dlauum_restore_where(); break;
    case MORSE_TRTRI:  cl_dtrtri_restore_where(); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_dgetrf_incpiv_restore_where(); break;
    case MORSE_GETRF_NOPIV: cl_dgetrf_nopiv_restore_where(); break;
    case MORSE_GESSM:  cl_dgessm_restore_where(); break;
    case MORSE_SSSSM:  cl_dssssm_restore_where(); break;
    case MORSE_TSTRF:  cl_dtstrf_restore_where(); break;

    /* QR */
    case MORSE_GEQRT:  cl_dgeqrt_restore_where(); break;
    case MORSE_ORMQR:  cl_dormqr_restore_where(); break;
    case MORSE_TSMQR:  cl_dtsmqr_restore_where(); break;
    case MORSE_TSQRT:  cl_dtsqrt_restore_where(); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_dttmqr_restore_where(); break; */
/*     case MORSE_TTQRT:  cl_dttqrt_restore_where(); break; */

    /* LQ */
   case MORSE_GELQT:  cl_dgelqt_restore_where(); break;
   case MORSE_ORMLQ:  cl_dormlq_restore_where(); break;
   case MORSE_TSMLQ:  cl_dtsmlq_restore_where(); break;
   case MORSE_TSLQT:  cl_dtslqt_restore_where(); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_dttmlq_restore_where(); break; */
/*     case MORSE_TTLQT:  cl_dttlqt_restore_where(); break; */

    default:
      return;
    }
}
#else
void RUNTIME_dlocality_allrestrict( uint32_t where ) {}
void RUNTIME_dlocality_onerestrict( MORSE_kernel_t kernel, uint32_t where ) {}
void RUNTIME_dlocality_allrestore( ) {}
void RUNTIME_dlocality_onerestore( MORSE_kernel_t kernel ) {}
#endif
