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
 * @file runtime_slocality.c
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
#include "runtime/starpu/include/runtime_codelet_s.h"

#ifdef CHAMELEON_USE_CUDA
/* Only codelets with multiple choices are present here */
void RUNTIME_slocality_allrestrict( uint32_t where )
{

    /* Blas 3 */
    cl_sgemm_restrict_where( where );
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_ssymm_restrict_where( where );
    cl_ssyr2k_restrict_where( where );
    cl_ssyrk_restrict_where( where );
    cl_ssytrf_nopiv_restrict_where( where );
#endif
    cl_ssymm_restrict_where( where );
    cl_ssyr2k_restrict_where( where );
    cl_ssyrk_restrict_where( where );
    cl_strmm_restrict_where( where );
    cl_strsm_restrict_where( where );

    /*
     * Lapack
     */
    /* Cholesky */
    cl_spotrf_restrict_where( where );
    cl_slauum_restrict_where( where );
    cl_strtri_restrict_where( where );

    /* LU */
    cl_sgetrf_incpiv_restrict_where( where );
    cl_sgetrf_nopiv_restrict_where( where );
    cl_sgessm_restrict_where( where );
    cl_sssssm_restrict_where( where );
    cl_ststrf_restrict_where( where );

    /* QR */
    cl_sgeqrt_restrict_where( where );
    cl_stsqrt_restrict_where( where );
    cl_sormqr_restrict_where( where );
    cl_stsmqr_restrict_where( where );

    /* QR-RH */
/*     cl_sttqrt_restrict_where( where ); */
/*     cl_sttmqr_restrict_where( where ); */

    /* LQ */
   cl_sgelqt_restrict_where( where );
   cl_stslqt_restrict_where( where );
   cl_sormlq_restrict_where( where );
   cl_stsmlq_restrict_where( where );

    /* LQ-RH */
/*     cl_sttlqt_restrict_where( where ); */
/*     cl_sttmlq_restrict_where( where ); */

}

void RUNTIME_slocality_onerestrict( MORSE_kernel_t kernel, uint32_t where )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_sgemm_restrict_where( where );  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:   cl_ssymm_restrict_where( where );  break;
    case MORSE_SYR2K:  cl_ssyr2k_restrict_where( where ); break;
    case MORSE_SYRK:   cl_ssyrk_restrict_where( where );  break;
    case MORSE_SYTRF_NOPIV: cl_ssytrf_nopiv_restrict_where( where );  break;
#endif
    case MORSE_SYMM:   cl_ssymm_restrict_where( where );  break;
    case MORSE_SYR2K:  cl_ssyr2k_restrict_where( where ); break;
    case MORSE_SYRK:   cl_ssyrk_restrict_where( where );  break;
    case MORSE_TRMM:   cl_strmm_restrict_where( where );  break;
    case MORSE_TRSM:   cl_strsm_restrict_where( where );  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_spotrf_restrict_where( where ); break;
    case MORSE_LAUUM:  cl_slauum_restrict_where( where ); break;
    case MORSE_TRTRI:  cl_strtri_restrict_where( where ); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_sgetrf_incpiv_restrict_where( where ); break;
    case MORSE_GETRF_NOPIV: cl_sgetrf_nopiv_restrict_where( where ); break;
    case MORSE_GESSM:  cl_sgessm_restrict_where( where ); break;
    case MORSE_SSSSM:  cl_sssssm_restrict_where( where ); break;
    case MORSE_TSTRF:  cl_ststrf_restrict_where( where ); break;

    /* QR */
    case MORSE_GEQRT:  cl_sgeqrt_restrict_where( where ); break;
    case MORSE_ORMQR:  cl_sormqr_restrict_where( where ); break;
    case MORSE_TSMQR:  cl_stsmqr_restrict_where( where ); break;
    case MORSE_TSQRT:  cl_stsqrt_restrict_where( where ); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_sttmqr_restrict_where( where ); break; */
/*     case MORSE_TTQRT:  cl_sttqrt_restrict_where( where ); break; */

    /* LQ */
   case MORSE_GELQT:  cl_sgelqt_restrict_where( where ); break;
   case MORSE_ORMLQ:  cl_sormlq_restrict_where( where ); break;
   case MORSE_TSMLQ:  cl_stsmlq_restrict_where( where ); break;
   case MORSE_TSLQT:  cl_stslqt_restrict_where( where ); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_sttmlq_restrict_where( where ); break; */
/*     case MORSE_TTLQT:  cl_sttlqt_restrict_where( where ); break; */

    default:
      return;
    }
}

void RUNTIME_slocality_allrestore( )
{
    /* Blas 3 */
    cl_sgemm_restore_where();
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_ssymm_restore_where();
    cl_ssyr2k_restore_where();
    cl_ssyrk_restore_where();
    cl_ssytrf_nopiv_restore_where();
#endif
    cl_ssymm_restore_where();
    cl_ssyr2k_restore_where();
    cl_ssyrk_restore_where();
    cl_strmm_restore_where();
    cl_strsm_restore_where();

    /*
     * Lapack
     */
    /* Cholesky */
    cl_spotrf_restore_where();
    cl_slauum_restore_where();
    cl_strtri_restore_where();

    /* LU incpiv */
    cl_sgetrf_incpiv_restore_where();
    cl_sgessm_restore_where();
    cl_sssssm_restore_where();
    cl_ststrf_restore_where();

    /* QR */
    cl_sgeqrt_restore_where();
    cl_stsqrt_restore_where();
    cl_sormqr_restore_where();
    cl_stsmqr_restore_where();

    /* QR-RH */
/*     cl_sttqrt_restore_where(); */
/*     cl_sttmqr_restore_where(); */

    /* LQ */
   cl_sgelqt_restore_where();
   cl_stslqt_restore_where();
   cl_sormlq_restore_where();
   cl_stsmlq_restore_where();

    /* LQ-RH */
/*     cl_sttlqt_restore_where(); */
/*     cl_sttmlq_restore_where(); */

}

void RUNTIME_slocality_onerestore( MORSE_kernel_t kernel )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_sgemm_restore_where();  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_SYMM:   cl_ssymm_restore_where();  break;
    case MORSE_SYR2K:  cl_ssyr2k_restore_where(); break;
    case MORSE_SYRK:   cl_ssyrk_restore_where();  break;
    case MORSE_SYTRF_NOPIV: cl_ssytrf_nopiv_restore_where();  break;
#endif
    case MORSE_SYMM:   cl_ssymm_restore_where();  break;
    case MORSE_SYR2K:  cl_ssyr2k_restore_where(); break;
    case MORSE_SYRK:   cl_ssyrk_restore_where();  break;
    case MORSE_TRMM:   cl_strmm_restore_where();  break;
    case MORSE_TRSM:   cl_strsm_restore_where();  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_spotrf_restore_where(); break;
    case MORSE_LAUUM:  cl_slauum_restore_where(); break;
    case MORSE_TRTRI:  cl_strtri_restore_where(); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_sgetrf_incpiv_restore_where(); break;
    case MORSE_GETRF_NOPIV: cl_sgetrf_nopiv_restore_where(); break;
    case MORSE_GESSM:  cl_sgessm_restore_where(); break;
    case MORSE_SSSSM:  cl_sssssm_restore_where(); break;
    case MORSE_TSTRF:  cl_ststrf_restore_where(); break;

    /* QR */
    case MORSE_GEQRT:  cl_sgeqrt_restore_where(); break;
    case MORSE_ORMQR:  cl_sormqr_restore_where(); break;
    case MORSE_TSMQR:  cl_stsmqr_restore_where(); break;
    case MORSE_TSQRT:  cl_stsqrt_restore_where(); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_sttmqr_restore_where(); break; */
/*     case MORSE_TTQRT:  cl_sttqrt_restore_where(); break; */

    /* LQ */
   case MORSE_GELQT:  cl_sgelqt_restore_where(); break;
   case MORSE_ORMLQ:  cl_sormlq_restore_where(); break;
   case MORSE_TSMLQ:  cl_stsmlq_restore_where(); break;
   case MORSE_TSLQT:  cl_stslqt_restore_where(); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_sttmlq_restore_where(); break; */
/*     case MORSE_TTLQT:  cl_sttlqt_restore_where(); break; */

    default:
      return;
    }
}
#else
void RUNTIME_slocality_allrestrict( uint32_t where ) {}
void RUNTIME_slocality_onerestrict( MORSE_kernel_t kernel, uint32_t where ) {}
void RUNTIME_slocality_allrestore( ) {}
void RUNTIME_slocality_onerestore( MORSE_kernel_t kernel ) {}
#endif
