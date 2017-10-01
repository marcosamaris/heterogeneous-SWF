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
 * @file core_cblas.h
 *
 *  PLASMA auxiliary routines
 *  PLASMA is a software package provided by Univ. of Tennessee,
 *  Univ. of California Berkeley and Univ. of Colorado Denver
 *
 * @version 2.5.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Jakub Kurzak
 * @author Hatem Ltaief
 * @author Azzam Haidar
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated c Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef _MORSE_CORE_CBLAS_H_
#define _MORSE_CORE_CBLAS_H_

#define COMPLEX

#ifdef __cplusplus
extern "C" {
#endif

/** ****************************************************************************
 *  Declarations of serial kernels - alphabetical order
 **/
void CORE_scasum(int storev, MORSE_enum uplo, int M, int N,
                 const MORSE_Complex32_t *A, int lda, float *work);
void CORE_cbrdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, MORSE_Complex32_t *C, MORSE_Complex32_t *S,
                  int i, int j, int m, int grsiz);
int CORE_cgbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
int CORE_cgbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
int CORE_cgblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
int CORE_cgeadd(int M, int N, MORSE_Complex32_t alpha,
                const MORSE_Complex32_t *A, int LDA,
                      MORSE_Complex32_t *B, int LDB);
int  CORE_cgelqt(int M, int N, int IB,
                 MORSE_Complex32_t *A, int LDA,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU,
                 MORSE_Complex32_t *WORK);
void CORE_cgemm(MORSE_enum transA, MORSE_enum transB,
                int M, int N, int K,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                          const MORSE_Complex32_t *B, int LDB,
                MORSE_Complex32_t beta,        MORSE_Complex32_t *C, int LDC);
int  CORE_cgeqrt(int M, int N, int IB,
                 MORSE_Complex32_t *A, int LDA,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU, MORSE_Complex32_t *WORK);
int CORE_cgesplit(MORSE_enum side, MORSE_enum diag,
                  int M, int N,
                  MORSE_Complex32_t *A, int LDA,
                  MORSE_Complex32_t *B, int LDB);
int  CORE_cgessm(int M, int N, int K, int IB,
                 const int *IPIV,
                 const MORSE_Complex32_t *L, int LDL,
                 MORSE_Complex32_t *A, int LDA);
int  CORE_cgessq(int M, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *scale, float *sumsq);
int CORE_cgetf2_nopiv(int M, int N,
                  MORSE_Complex32_t *A, int LDA);
int  CORE_cgetrf(int M, int N,
                 MORSE_Complex32_t *A, int LDA,
                 int *IPIV, int *INFO);
int  CORE_cgetrf_incpiv(int M, int N, int IB,
                        MORSE_Complex32_t *A, int LDA,
                        int *IPIV, int *INFO);
int CORE_cgetrf_nopiv(int M, int N, int IB,
                      MORSE_Complex32_t *A, int LDA,
                      int *INFO);
int  CORE_cgetrf_reclap(int M, int N,
                        MORSE_Complex32_t *A, int LDA,
                        int *IPIV, int *info);
int  CORE_cgetrf_rectil(const MORSE_desc_t A, int *IPIV, int *info);
void CORE_cgetrip(int m, int n, MORSE_Complex32_t *A,
                  MORSE_Complex32_t *work);
int CORE_chbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
int CORE_chblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
int CORE_chbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                int st, int ed, int eltsize);
void CORE_chbtype1cb(int N, int NB,
                     MORSE_Complex32_t *A, int LDA,
                     MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     MORSE_Complex32_t *WORK);
void CORE_chbtype2cb(int N, int NB,
                     MORSE_Complex32_t *A, int LDA,
                     MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     MORSE_Complex32_t *WORK);
void CORE_chbtype3cb(int N, int NB,
                     MORSE_Complex32_t *A, int LDA,
                     const MORSE_Complex32_t *V, const MORSE_Complex32_t *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     MORSE_Complex32_t *WORK);
void CORE_chegst(int itype, MORSE_enum uplo, int N,
                 MORSE_Complex32_t *A, int LDA,
                 MORSE_Complex32_t *B, int LDB, int *INFO);
#ifdef COMPLEX
void CORE_chemm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                          const MORSE_Complex32_t *B, int LDB,
                MORSE_Complex32_t beta,        MORSE_Complex32_t *C, int LDC);
void CORE_cherk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                float alpha, const MORSE_Complex32_t *A, int LDA,
                float beta,        MORSE_Complex32_t *C, int LDC);
void CORE_cher2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                           const MORSE_Complex32_t *B, int LDB,
                 float beta,                    MORSE_Complex32_t *C, int LDC);
int  CORE_chessq(MORSE_enum uplo, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *scale, float *sumsq);
#endif
int  CORE_cherfb(MORSE_enum uplo, int N, int K, int IB, int NB,
                 const MORSE_Complex32_t *A,    int LDA,
                 const MORSE_Complex32_t *T,    int LDT,
                       MORSE_Complex32_t *C,    int LDC,
                       MORSE_Complex32_t *WORK, int LDWORK);
void CORE_clacpy(MORSE_enum uplo, int M, int N,
                 const MORSE_Complex32_t *A, int LDA,
                       MORSE_Complex32_t *B, int LDB);
void CORE_clange(int norm, int M, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *work, float *normA);
#ifdef COMPLEX
void CORE_clanhe(int norm, MORSE_enum uplo, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *work, float *normA);
#endif
void CORE_clansy(int norm, MORSE_enum uplo, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *work, float *normA);
void CORE_clantr(int norm, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *work, float *normA);
int CORE_clarfb_gemm(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                     int M, int N, int K,
                     const MORSE_Complex32_t *V, int LDV,
                     const MORSE_Complex32_t *T, int LDT,
                           MORSE_Complex32_t *C, int LDC,
                           MORSE_Complex32_t *WORK, int LDWORK);
int CORE_clarfx2(MORSE_enum side, int N,
                 MORSE_Complex32_t V,
                 MORSE_Complex32_t TAU,
                 MORSE_Complex32_t *C1, int LDC1,
                 MORSE_Complex32_t *C2, int LDC2);
int CORE_clarfx2c(MORSE_enum uplo,
                  MORSE_Complex32_t V,
                  MORSE_Complex32_t TAU,
                  MORSE_Complex32_t *C1,
                  MORSE_Complex32_t *C2,
                  MORSE_Complex32_t *C3);
int CORE_clarfx2ce(MORSE_enum uplo,
                   MORSE_Complex32_t *V,
                   MORSE_Complex32_t *TAU,
                   MORSE_Complex32_t *C1,
                   MORSE_Complex32_t *C2,
                   MORSE_Complex32_t *C3);
void CORE_clarfy(int N,
                 MORSE_Complex32_t *A, int LDA,
                 const MORSE_Complex32_t *V,
                 const MORSE_Complex32_t *TAU,
                 MORSE_Complex32_t *WORK);
void CORE_claset(MORSE_enum uplo, int n1, int n2,
                 MORSE_Complex32_t alpha, MORSE_Complex32_t beta,
                 MORSE_Complex32_t *tileA, int ldtilea);
void CORE_claset2(MORSE_enum uplo, int n1, int n2, MORSE_Complex32_t alpha,
                  MORSE_Complex32_t *tileA, int ldtilea);
void CORE_claswp(int N, MORSE_Complex32_t *A, int LDA,
                 int I1,  int I2, const int *IPIV, int INC);
int  CORE_claswp_ontile( MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_claswpc_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_clatro(MORSE_enum uplo, MORSE_enum trans,
                 int M, int N,
                 const MORSE_Complex32_t *A, int LDA,
                       MORSE_Complex32_t *B, int LDB);
void CORE_clauum(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
int CORE_cpamm(int op, MORSE_enum side, MORSE_enum storev,
               int M, int N, int K, int L,
               const MORSE_Complex32_t *A1, int LDA1,
                     MORSE_Complex32_t *A2, int LDA2,
               const MORSE_Complex32_t *V, int LDV,
                     MORSE_Complex32_t *W, int LDW);
int  CORE_cparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                 int M1, int N1, int M2, int N2, int K, int L,
                       MORSE_Complex32_t *A1, int LDA1,
                       MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                       MORSE_Complex32_t *WORK, int LDWORK);
int CORE_cpemv(MORSE_enum trans, MORSE_enum storev,
               int M, int N, int L,
               MORSE_Complex32_t ALPHA,
               const MORSE_Complex32_t *A, int LDA,
               const MORSE_Complex32_t *X, int INCX,
               MORSE_Complex32_t BETA,
               MORSE_Complex32_t *Y, int INCY,
               MORSE_Complex32_t *WORK);
void CORE_cplghe(float bump, int m, int n, MORSE_Complex32_t *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_cplgsy(MORSE_Complex32_t bump, int m, int n, MORSE_Complex32_t *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_cplrnt(int m, int n, MORSE_Complex32_t *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_cpotrf(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, int *INFO);
void CORE_cshift(int s, int m, int n, int L,
                 MORSE_Complex32_t *A);
void CORE_cshiftw(int s, int cl, int m, int n, int L,
                  MORSE_Complex32_t *A, MORSE_Complex32_t *W);
int  CORE_cssssm(int M1, int N1, int M2, int N2, int K, int IB,
                       MORSE_Complex32_t *A1, int LDA1,
                       MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *L1, int LDL1,
                 const MORSE_Complex32_t *L2, int LDL2,
                 const int *IPIV);
void CORE_csymm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                          const MORSE_Complex32_t *B, int LDB,
                MORSE_Complex32_t beta,        MORSE_Complex32_t *C, int LDC);
void CORE_csyrk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                MORSE_Complex32_t beta,        MORSE_Complex32_t *C, int LDC);
void CORE_csyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                           const MORSE_Complex32_t *B, int LDB,
                 MORSE_Complex32_t beta,        MORSE_Complex32_t *C, int LDC);
int  CORE_csyssq(MORSE_enum uplo, int N,
                 const MORSE_Complex32_t *A, int LDA,
                 float *scale, float *sumsq);
int CORE_csytf2_nopiv(MORSE_enum uplo, int n, MORSE_Complex32_t *A, int lda);
void CORE_cswpab(int i, int n1, int n2,
                 MORSE_Complex32_t *A, MORSE_Complex32_t *work);
int  CORE_cswptr_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc,
                        const MORSE_Complex32_t *Akk, int ldak);
void CORE_ctrdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, MORSE_Complex32_t *V, MORSE_Complex32_t *TAU,
                  int i, int j, int m, int grsiz);
void CORE_ctrmm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                                MORSE_Complex32_t *B, int LDB);
void CORE_ctrsm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                MORSE_Complex32_t alpha, const MORSE_Complex32_t *A, int LDA,
                                                MORSE_Complex32_t *B, int LDB);
void CORE_ctrtri(MORSE_enum uplo, MORSE_enum diag, int N,
                 MORSE_Complex32_t *A, int LDA, int *info);
int  CORE_ctslqt(int M, int N, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU, MORSE_Complex32_t *WORK);
int  CORE_ctsmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *WORK, int LDWORK);
int CORE_ctsmlq_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        MORSE_Complex32_t *A1, int lda1,
                        MORSE_Complex32_t *A2, int lda2,
                        MORSE_Complex32_t *A3, int lda3,
                        const MORSE_Complex32_t *V, int ldv,
                        const MORSE_Complex32_t *T, int ldt,
                        MORSE_Complex32_t *WORK, int ldwork);
int CORE_ctsmlq_hetra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        MORSE_Complex32_t *A1, int lda1,
                        MORSE_Complex32_t *A2, int lda2,
                        const MORSE_Complex32_t *V, int ldv,
                        const MORSE_Complex32_t *T, int ldt,
                        MORSE_Complex32_t *WORK, int ldwork);
int  CORE_ctsmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *WORK, int LDWORK);
int CORE_ctsmqr_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        MORSE_Complex32_t *A1, int lda1,
                        MORSE_Complex32_t *A2, int lda2,
                        MORSE_Complex32_t *A3, int lda3,
                        const MORSE_Complex32_t *V, int ldv,
                        const MORSE_Complex32_t *T, int ldt,
                        MORSE_Complex32_t *WORK, int ldwork);
int CORE_ctsmqr_hetra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        MORSE_Complex32_t *A1, int lda1,
                        MORSE_Complex32_t *A2, int lda2,
                        const MORSE_Complex32_t *V, int ldv,
                        const MORSE_Complex32_t *T, int ldt,
                        MORSE_Complex32_t *WORK, int ldwork);
int  CORE_ctsqrt(int M, int N, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU, MORSE_Complex32_t *WORK);
int  CORE_ctstrf(int M, int N, int IB, int NB,
                 MORSE_Complex32_t *U, int LDU,
                 MORSE_Complex32_t *A, int LDA,
                 MORSE_Complex32_t *L, int LDL,
                 int *IPIV, MORSE_Complex32_t *WORK,
                 int LDWORK, int *INFO);
int  CORE_cttmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *WORK, int LDWORK);
int  CORE_cttqrt(int M, int N, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU,
                 MORSE_Complex32_t *WORK);
int  CORE_cttmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *WORK, int LDWORK);
int  CORE_cttlqt(int M, int N, int IB,
                 MORSE_Complex32_t *A1, int LDA1,
                 MORSE_Complex32_t *A2, int LDA2,
                 MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *TAU,
                 MORSE_Complex32_t *WORK);
int  CORE_cunmlq(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int IB, int K,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *C, int LDC,
                 MORSE_Complex32_t *WORK, int LDWORK);
int  CORE_cunmqr(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int K, int IB,
                 const MORSE_Complex32_t *V, int LDV,
                 const MORSE_Complex32_t *T, int LDT,
                 MORSE_Complex32_t *C, int LDC,
                 MORSE_Complex32_t *WORK, int LDWORK);




#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
