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
 * @file runtime_clocality.c
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
#include "runtime/starpu/include/runtime_codelet_c.h"

#ifdef CHAMELEON_USE_CUDA
/* Only codelets with multiple choices are present here */
void RUNTIME_clocality_allrestrict( uint32_t where )
{

    /* Blas 3 */
    cl_cgemm_restrict_where( where );
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_chemm_restrict_where( where );
    cl_cher2k_restrict_where( where );
    cl_cherk_restrict_where( where );
    cl_csytrf_nopiv_restrict_where( where );
#endif
    cl_csymm_restrict_where( where );
    cl_csyr2k_restrict_where( where );
    cl_csyrk_restrict_where( where );
    cl_ctrmm_restrict_where( where );
    cl_ctrsm_restrict_where( where );

    /*
     * Lapack
     */
    /* Cholesky */
    cl_cpotrf_restrict_where( where );
    cl_clauum_restrict_where( where );
    cl_ctrtri_restrict_where( where );

    /* LU */
    cl_cgetrf_incpiv_restrict_where( where );
    cl_cgetrf_nopiv_restrict_where( where );
    cl_cgessm_restrict_where( where );
    cl_cssssm_restrict_where( where );
    cl_ctstrf_restrict_where( where );

    /* QR */
    cl_cgeqrt_restrict_where( where );
    cl_ctsqrt_restrict_where( where );
    cl_cunmqr_restrict_where( where );
    cl_ctsmqr_restrict_where( where );

    /* QR-RH */
/*     cl_cttqrt_restrict_where( where ); */
/*     cl_cttmqr_restrict_where( where ); */

    /* LQ */
   cl_cgelqt_restrict_where( where );
   cl_ctslqt_restrict_where( where );
   cl_cunmlq_restrict_where( where );
   cl_ctsmlq_restrict_where( where );

    /* LQ-RH */
/*     cl_cttlqt_restrict_where( where ); */
/*     cl_cttmlq_restrict_where( where ); */

}

void RUNTIME_clocality_onerestrict( MORSE_kernel_t kernel, uint32_t where )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_cgemm_restrict_where( where );  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_HEMM:   cl_chemm_restrict_where( where );  break;
    case MORSE_HER2K:  cl_cher2k_restrict_where( where ); break;
    case MORSE_HERK:   cl_cherk_restrict_where( where );  break;
    case MORSE_SYTRF_NOPIV: cl_csytrf_nopiv_restrict_where( where );  break;
#endif
    case MORSE_SYMM:   cl_chemm_restrict_where( where );  break;
    case MORSE_SYR2K:  cl_cher2k_restrict_where( where ); break;
    case MORSE_SYRK:   cl_cherk_restrict_where( where );  break;
    case MORSE_TRMM:   cl_ctrmm_restrict_where( where );  break;
    case MORSE_TRSM:   cl_ctrsm_restrict_where( where );  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_cpotrf_restrict_where( where ); break;
    case MORSE_LAUUM:  cl_clauum_restrict_where( where ); break;
    case MORSE_TRTRI:  cl_ctrtri_restrict_where( where ); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_cgetrf_incpiv_restrict_where( where ); break;
    case MORSE_GETRF_NOPIV: cl_cgetrf_nopiv_restrict_where( where ); break;
    case MORSE_GESSM:  cl_cgessm_restrict_where( where ); break;
    case MORSE_SSSSM:  cl_cssssm_restrict_where( where ); break;
    case MORSE_TSTRF:  cl_ctstrf_restrict_where( where ); break;

    /* QR */
    case MORSE_GEQRT:  cl_cgeqrt_restrict_where( where ); break;
    case MORSE_UNMQR:  cl_cunmqr_restrict_where( where ); break;
    case MORSE_TSMQR:  cl_ctsmqr_restrict_where( where ); break;
    case MORSE_TSQRT:  cl_ctsqrt_restrict_where( where ); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_cttmqr_restrict_where( where ); break; */
/*     case MORSE_TTQRT:  cl_cttqrt_restrict_where( where ); break; */

    /* LQ */
   case MORSE_GELQT:  cl_cgelqt_restrict_where( where ); break;
   case MORSE_UNMLQ:  cl_cunmlq_restrict_where( where ); break;
   case MORSE_TSMLQ:  cl_ctsmlq_restrict_where( where ); break;
   case MORSE_TSLQT:  cl_ctslqt_restrict_where( where ); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_cttmlq_restrict_where( where ); break; */
/*     case MORSE_TTLQT:  cl_cttlqt_restrict_where( where ); break; */

    default:
      return;
    }
}

void RUNTIME_clocality_allrestore( )
{
    /* Blas 3 */
    cl_cgemm_restore_where();
#if defined(PRECISION_z) || defined(PRECISION_c)
    cl_chemm_restore_where();
    cl_cher2k_restore_where();
    cl_cherk_restore_where();
    cl_csytrf_nopiv_restore_where();
#endif
    cl_csymm_restore_where();
    cl_csyr2k_restore_where();
    cl_csyrk_restore_where();
    cl_ctrmm_restore_where();
    cl_ctrsm_restore_where();

    /*
     * Lapack
     */
    /* Cholesky */
    cl_cpotrf_restore_where();
    cl_clauum_restore_where();
    cl_ctrtri_restore_where();

    /* LU incpiv */
    cl_cgetrf_incpiv_restore_where();
    cl_cgessm_restore_where();
    cl_cssssm_restore_where();
    cl_ctstrf_restore_where();

    /* QR */
    cl_cgeqrt_restore_where();
    cl_ctsqrt_restore_where();
    cl_cunmqr_restore_where();
    cl_ctsmqr_restore_where();

    /* QR-RH */
/*     cl_cttqrt_restore_where(); */
/*     cl_cttmqr_restore_where(); */

    /* LQ */
   cl_cgelqt_restore_where();
   cl_ctslqt_restore_where();
   cl_cunmlq_restore_where();
   cl_ctsmlq_restore_where();

    /* LQ-RH */
/*     cl_cttlqt_restore_where(); */
/*     cl_cttmlq_restore_where(); */

}

void RUNTIME_clocality_onerestore( MORSE_kernel_t kernel )
{
    switch( kernel ) {
    /* Blas 3 */
    case MORSE_GEMM:   cl_cgemm_restore_where();  break;
#if defined(PRECISION_z) || defined(PRECISION_c)
    case MORSE_HEMM:   cl_chemm_restore_where();  break;
    case MORSE_HER2K:  cl_cher2k_restore_where(); break;
    case MORSE_HERK:   cl_cherk_restore_where();  break;
    case MORSE_SYTRF_NOPIV: cl_csytrf_nopiv_restore_where();  break;
#endif
    case MORSE_SYMM:   cl_chemm_restore_where();  break;
    case MORSE_SYR2K:  cl_cher2k_restore_where(); break;
    case MORSE_SYRK:   cl_cherk_restore_where();  break;
    case MORSE_TRMM:   cl_ctrmm_restore_where();  break;
    case MORSE_TRSM:   cl_ctrsm_restore_where();  break;

    /*
     * Lapack
     */
    /* Cholesky */
    case MORSE_POTRF:  cl_cpotrf_restore_where(); break;
    case MORSE_LAUUM:  cl_clauum_restore_where(); break;
    case MORSE_TRTRI:  cl_ctrtri_restore_where(); break;

    /* LU */
    case MORSE_GETRF_INCPIV: cl_cgetrf_incpiv_restore_where(); break;
    case MORSE_GETRF_NOPIV: cl_cgetrf_nopiv_restore_where(); break;
    case MORSE_GESSM:  cl_cgessm_restore_where(); break;
    case MORSE_SSSSM:  cl_cssssm_restore_where(); break;
    case MORSE_TSTRF:  cl_ctstrf_restore_where(); break;

    /* QR */
    case MORSE_GEQRT:  cl_cgeqrt_restore_where(); break;
    case MORSE_UNMQR:  cl_cunmqr_restore_where(); break;
    case MORSE_TSMQR:  cl_ctsmqr_restore_where(); break;
    case MORSE_TSQRT:  cl_ctsqrt_restore_where(); break;

    /* QR-RH */
/*     case MORSE_TTMQR:  cl_cttmqr_restore_where(); break; */
/*     case MORSE_TTQRT:  cl_cttqrt_restore_where(); break; */

    /* LQ */
   case MORSE_GELQT:  cl_cgelqt_restore_where(); break;
   case MORSE_UNMLQ:  cl_cunmlq_restore_where(); break;
   case MORSE_TSMLQ:  cl_ctsmlq_restore_where(); break;
   case MORSE_TSLQT:  cl_ctslqt_restore_where(); break;

    /* LQ-RH */
/*     case MORSE_TTMLQ:  cl_cttmlq_restore_where(); break; */
/*     case MORSE_TTLQT:  cl_cttlqt_restore_where(); break; */

    default:
      return;
    }
}
#else
void RUNTIME_clocality_allrestrict( uint32_t where ) {}
void RUNTIME_clocality_onerestrict( MORSE_kernel_t kernel, uint32_t where ) {}
void RUNTIME_clocality_allrestore( ) {}
void RUNTIME_clocality_onerestore( MORSE_kernel_t kernel ) {}
#endif
