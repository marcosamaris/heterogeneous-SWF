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
 * @file core_dblas.h
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
 * @generated d Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef _MORSE_CORE_DBLAS_H_
#define _MORSE_CORE_DBLAS_H_

#define REAL

#ifdef __cplusplus
extern "C" {
#endif

/** ****************************************************************************
 *  Declarations of serial kernels - alphabetical order
 **/
void CORE_dasum(int storev, MORSE_enum uplo, int M, int N,
                 const double *A, int lda, double *work);
void CORE_dbrdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, double *C, double *S,
                  int i, int j, int m, int grsiz);
int CORE_dgbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
int CORE_dgbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
int CORE_dgblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
int CORE_dgeadd(int M, int N, double alpha,
                const double *A, int LDA,
                      double *B, int LDB);
int  CORE_dgelqt(int M, int N, int IB,
                 double *A, int LDA,
                 double *T, int LDT,
                 double *TAU,
                 double *WORK);
void CORE_dgemm(MORSE_enum transA, MORSE_enum transB,
                int M, int N, int K,
                double alpha, const double *A, int LDA,
                                          const double *B, int LDB,
                double beta,        double *C, int LDC);
int  CORE_dgeqrt(int M, int N, int IB,
                 double *A, int LDA,
                 double *T, int LDT,
                 double *TAU, double *WORK);
int CORE_dgesplit(MORSE_enum side, MORSE_enum diag,
                  int M, int N,
                  double *A, int LDA,
                  double *B, int LDB);
int  CORE_dgessm(int M, int N, int K, int IB,
                 const int *IPIV,
                 const double *L, int LDL,
                 double *A, int LDA);
int  CORE_dgessq(int M, int N,
                 const double *A, int LDA,
                 double *scale, double *sumsq);
int CORE_dgetf2_nopiv(int M, int N,
                  double *A, int LDA);
int  CORE_dgetrf(int M, int N,
                 double *A, int LDA,
                 int *IPIV, int *INFO);
int  CORE_dgetrf_incpiv(int M, int N, int IB,
                        double *A, int LDA,
                        int *IPIV, int *INFO);
int CORE_dgetrf_nopiv(int M, int N, int IB,
                      double *A, int LDA,
                      int *INFO);
int  CORE_dgetrf_reclap(int M, int N,
                        double *A, int LDA,
                        int *IPIV, int *info);
int  CORE_dgetrf_rectil(const MORSE_desc_t A, int *IPIV, int *info);
void CORE_dgetrip(int m, int n, double *A,
                  double *work);
int CORE_dhbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
int CORE_dhblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
int CORE_dhbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, double *V, double *TAU,
                int st, int ed, int eltsize);
void CORE_dhbtype1cb(int N, int NB,
                     double *A, int LDA,
                     double *V, double *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     double *WORK);
void CORE_dhbtype2cb(int N, int NB,
                     double *A, int LDA,
                     double *V, double *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     double *WORK);
void CORE_dhbtype3cb(int N, int NB,
                     double *A, int LDA,
                     const double *V, const double *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     double *WORK);
void CORE_dsygst(int itype, MORSE_enum uplo, int N,
                 double *A, int LDA,
                 double *B, int LDB, int *INFO);
#ifdef COMPLEX
void CORE_dsymm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                double alpha, const double *A, int LDA,
                                          const double *B, int LDB,
                double beta,        double *C, int LDC);
void CORE_dsyrk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                double alpha, const double *A, int LDA,
                double beta,        double *C, int LDC);
void CORE_dsyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 double alpha, const double *A, int LDA,
                                           const double *B, int LDB,
                 double beta,                    double *C, int LDC);
int  CORE_dsyssq(MORSE_enum uplo, int N,
                 const double *A, int LDA,
                 double *scale, double *sumsq);
#endif
int  CORE_dsyrfb(MORSE_enum uplo, int N, int K, int IB, int NB,
                 const double *A,    int LDA,
                 const double *T,    int LDT,
                       double *C,    int LDC,
                       double *WORK, int LDWORK);
void CORE_dlacpy(MORSE_enum uplo, int M, int N,
                 const double *A, int LDA,
                       double *B, int LDB);
void CORE_dlange(int norm, int M, int N,
                 const double *A, int LDA,
                 double *work, double *normA);
#ifdef COMPLEX
void CORE_dlansy(int norm, MORSE_enum uplo, int N,
                 const double *A, int LDA,
                 double *work, double *normA);
#endif
void CORE_dlansy(int norm, MORSE_enum uplo, int N,
                 const double *A, int LDA,
                 double *work, double *normA);
void CORE_dlantr(int norm, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                 const double *A, int LDA,
                 double *work, double *normA);
int CORE_dlarfb_gemm(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                     int M, int N, int K,
                     const double *V, int LDV,
                     const double *T, int LDT,
                           double *C, int LDC,
                           double *WORK, int LDWORK);
int CORE_dlarfx2(MORSE_enum side, int N,
                 double V,
                 double TAU,
                 double *C1, int LDC1,
                 double *C2, int LDC2);
int CORE_dlarfx2c(MORSE_enum uplo,
                  double V,
                  double TAU,
                  double *C1,
                  double *C2,
                  double *C3);
int CORE_dlarfx2ce(MORSE_enum uplo,
                   double *V,
                   double *TAU,
                   double *C1,
                   double *C2,
                   double *C3);
void CORE_dlarfy(int N,
                 double *A, int LDA,
                 const double *V,
                 const double *TAU,
                 double *WORK);
void CORE_dlaset(MORSE_enum uplo, int n1, int n2,
                 double alpha, double beta,
                 double *tileA, int ldtilea);
void CORE_dlaset2(MORSE_enum uplo, int n1, int n2, double alpha,
                  double *tileA, int ldtilea);
void CORE_dlaswp(int N, double *A, int LDA,
                 int I1,  int I2, const int *IPIV, int INC);
int  CORE_dlaswp_ontile( MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_dlaswpc_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_dlatro(MORSE_enum uplo, MORSE_enum trans,
                 int M, int N,
                 const double *A, int LDA,
                       double *B, int LDB);
void CORE_dlauum(MORSE_enum uplo, int N, double *A, int LDA);
int CORE_dpamm(int op, MORSE_enum side, MORSE_enum storev,
               int M, int N, int K, int L,
               const double *A1, int LDA1,
                     double *A2, int LDA2,
               const double *V, int LDV,
                     double *W, int LDW);
int  CORE_dparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                 int M1, int N1, int M2, int N2, int K, int L,
                       double *A1, int LDA1,
                       double *A2, int LDA2,
                 const double *V, int LDV,
                 const double *T, int LDT,
                       double *WORK, int LDWORK);
int CORE_dpemv(MORSE_enum trans, MORSE_enum storev,
               int M, int N, int L,
               double ALPHA,
               const double *A, int LDA,
               const double *X, int INCX,
               double BETA,
               double *Y, int INCY,
               double *WORK);
void CORE_dplgsy(double bump, int m, int n, double *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_dplgsy(double bump, int m, int n, double *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_dplrnt(int m, int n, double *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_dpotrf(MORSE_enum uplo, int N, double *A, int LDA, int *INFO);
void CORE_dshift(int s, int m, int n, int L,
                 double *A);
void CORE_dshiftw(int s, int cl, int m, int n, int L,
                  double *A, double *W);
int  CORE_dssssm(int M1, int N1, int M2, int N2, int K, int IB,
                       double *A1, int LDA1,
                       double *A2, int LDA2,
                 const double *L1, int LDL1,
                 const double *L2, int LDL2,
                 const int *IPIV);
void CORE_dsymm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                double alpha, const double *A, int LDA,
                                          const double *B, int LDB,
                double beta,        double *C, int LDC);
void CORE_dsyrk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                double alpha, const double *A, int LDA,
                double beta,        double *C, int LDC);
void CORE_dsyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 double alpha, const double *A, int LDA,
                                           const double *B, int LDB,
                 double beta,        double *C, int LDC);
int  CORE_dsyssq(MORSE_enum uplo, int N,
                 const double *A, int LDA,
                 double *scale, double *sumsq);
int CORE_dsytf2_nopiv(MORSE_enum uplo, int n, double *A, int lda);
void CORE_dswpab(int i, int n1, int n2,
                 double *A, double *work);
int  CORE_dswptr_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc,
                        const double *Akk, int ldak);
void CORE_dtrdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, double *V, double *TAU,
                  int i, int j, int m, int grsiz);
void CORE_dtrmm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                double alpha, const double *A, int LDA,
                                                double *B, int LDB);
void CORE_dtrsm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                double alpha, const double *A, int LDA,
                                                double *B, int LDB);
void CORE_dtrtri(MORSE_enum uplo, MORSE_enum diag, int N,
                 double *A, int LDA, int *info);
int  CORE_dtslqt(int M, int N, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 double *T, int LDT,
                 double *TAU, double *WORK);
int  CORE_dtsmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *WORK, int LDWORK);
int CORE_dtsmlq_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        double *A1, int lda1,
                        double *A2, int lda2,
                        double *A3, int lda3,
                        const double *V, int ldv,
                        const double *T, int ldt,
                        double *WORK, int ldwork);
int CORE_dtsmlq_sytra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        double *A1, int lda1,
                        double *A2, int lda2,
                        const double *V, int ldv,
                        const double *T, int ldt,
                        double *WORK, int ldwork);
int  CORE_dtsmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *WORK, int LDWORK);
int CORE_dtsmqr_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        double *A1, int lda1,
                        double *A2, int lda2,
                        double *A3, int lda3,
                        const double *V, int ldv,
                        const double *T, int ldt,
                        double *WORK, int ldwork);
int CORE_dtsmqr_sytra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        double *A1, int lda1,
                        double *A2, int lda2,
                        const double *V, int ldv,
                        const double *T, int ldt,
                        double *WORK, int ldwork);
int  CORE_dtsqrt(int M, int N, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 double *T, int LDT,
                 double *TAU, double *WORK);
int  CORE_dtstrf(int M, int N, int IB, int NB,
                 double *U, int LDU,
                 double *A, int LDA,
                 double *L, int LDL,
                 int *IPIV, double *WORK,
                 int LDWORK, int *INFO);
int  CORE_dttmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *WORK, int LDWORK);
int  CORE_dttqrt(int M, int N, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 double *T, int LDT,
                 double *TAU,
                 double *WORK);
int  CORE_dttmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *WORK, int LDWORK);
int  CORE_dttlqt(int M, int N, int IB,
                 double *A1, int LDA1,
                 double *A2, int LDA2,
                 double *T, int LDT,
                 double *TAU,
                 double *WORK);
int  CORE_dormlq(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int IB, int K,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *C, int LDC,
                 double *WORK, int LDWORK);
int  CORE_dormqr(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int K, int IB,
                 const double *V, int LDV,
                 const double *T, int LDT,
                 double *C, int LDC,
                 double *WORK, int LDWORK);




#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
