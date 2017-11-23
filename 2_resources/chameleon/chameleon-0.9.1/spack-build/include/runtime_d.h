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
 * @file runtime_d.h
 *
 *  MORSE auxiliary routines
 *  MORSE is a software package provided by Univ. of Tennessee,
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
#ifndef _RUNTIME_DBLAS_H_
#define _RUNTIME_DBLAS_H_

#define REAL

#ifdef __cplusplus
extern "C" {
#endif


/** ****************************************************************************
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 **/
void MORSE_TASK_ddasum(MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, int M, int N,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dgeadd(MORSE_option_t *options,
                      int m, int n, double alpha,
                      MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dbrdalg(MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        MORSE_desc_t *A,
                        MORSE_desc_t *C, int Cm, int Cn,
                        MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_dgelqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dgemm(MORSE_option_t *options,
                      MORSE_enum transA, MORSE_enum transB,
                      int m, int n, int k, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm2( MORSE_option_t *options,
                        MORSE_enum transA, MORSE_enum transB,
                        int m, int n, int k, int nb,
                        double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *B, int Bm, int Bn, int ldb,
                        double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm_f2(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc,
                         MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                         MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dgemm_p2(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         const double **B, int ldb,
                         double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm_p2f1(MORSE_option_t *options,
                           MORSE_enum transA, MORSE_enum transB,
                           int m, int n, int k, int nb,
                           double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                           const double **B, int ldb,
                           double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc,
                           MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1);
void MORSE_TASK_dgemm_p3(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         double beta, double **C, int ldc);
void MORSE_TASK_dgeqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dgessm(MORSE_option_t *options,
                       int m, int n, int k, int ib, int nb,
                       int *IPIV,
                       MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       MORSE_desc_t *D, int Dm, int Dn, int ldd,
                       MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_dgessq( MORSE_option_t *options,
                        int m, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn);
void MORSE_TASK_dgetrf(MORSE_option_t *options,
                       int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_dgetrf_incpiv(MORSE_option_t *options,
                              int m, int n, int ib, int nb,
                              MORSE_desc_t *A, int Am, int An, int lda,
                              MORSE_desc_t *L, int Lm, int Ln, int ldl,
                              int *IPIV,
                              MORSE_bool check_info, int iinfo);
void MORSE_TASK_dgetrf_reclap(MORSE_option_t *options,
                              int m, int n, int nb,
                              MORSE_desc_t *A, int Am, int An, int lda,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_dgetrf_rectil(MORSE_option_t *options,
                              MORSE_desc_t A, MORSE_desc_t *Amn, int Amnm, int Amnn, int size,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_dgetrip(MORSE_option_t *options,
                        int m, int n, MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_dgetrip_f1(MORSE_option_t *options,
                           int m, int n, MORSE_desc_t *A, int Am, int An, int szeA,
                           MORSE_desc_t *fake, int fakem, int faken, int szeF, int paramF);
void MORSE_TASK_dgetrip_f2(MORSE_option_t *options,
                           int m, int n, MORSE_desc_t *A, int Am, int An, int szeA,
                           MORSE_desc_t *fake1, int fake1m, int fake1n, int szeF1, int paramF1,
                           MORSE_desc_t *fake2, int fake2m, int fake2n, int szeF2, int paramF2);
void MORSE_TASK_dsymm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsygst(MORSE_option_t *options,
                       int itype, MORSE_enum uplo, int N,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,

                       int iinfo);
void MORSE_TASK_dsyrk(MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyr2k(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyrfb(MORSE_option_t *options,
                       MORSE_enum uplo,
                       int n, int k, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dlacpy(MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int mb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlange(MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlange_max(MORSE_option_t *options,
                           MORSE_desc_t *A, int Am, int An,
                           MORSE_desc_t *B, int Bm, int Bn);
#ifdef COMPLEX
void MORSE_TASK_dsyssq( MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dlansy(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
#endif
void MORSE_TASK_dlansy(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlantr(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag,
                       int M, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlaset(MORSE_option_t *options,
                       MORSE_enum uplo, int n1, int n2, double alpha,
                       double beta, MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_dlaset2(MORSE_option_t *options,
                        MORSE_enum uplo, int n1, int n2, double alpha,
                        MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_dlaswp(MORSE_option_t *options,
                       int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int i1,  int i2, int *ipiv, int inc);
void MORSE_TASK_dlaswp_f2(MORSE_option_t *options,
                          int n, MORSE_desc_t *A, int Am, int An, int lda,
                          int i1,  int i2, int *ipiv, int inc,
                          MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                          MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dlaswp_ontile(MORSE_option_t *options,
                              MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                              int i1,  int i2, int *ipiv, int inc, double *fakepanel);
void MORSE_TASK_dlaswp_ontile_f2(MORSE_option_t *options,
                                 MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                                 int i1,  int i2, int *ipiv, int inc,
                                 MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                                 MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dlaswpc_ontile(MORSE_option_t *options,
                               MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                               int i1,  int i2, int *ipiv, int inc, double *fakepanel);
void MORSE_TASK_dlatro(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int mb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlauum(MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_dplgsy(MORSE_option_t *options,
                       double bump, int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dplgsy(MORSE_option_t *options,
                       double bump, int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dplrnt(MORSE_option_t *options,
                       int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dpotrf(MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_dshift( MORSE_option_t *options,
                        int s, int m, int n, int L,
                        double *A);
void MORSE_TASK_dshiftw(MORSE_option_t *options,
                        int s, int cl, int m, int n, int L,
                        MORSE_desc_t *A, int Am, int An, double *W);
void MORSE_TASK_dssssm(MORSE_option_t *options,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *L1, int L1m, int L1n, int ldl1,
                       MORSE_desc_t *L2, int L2m, int L2n, int ldl2,
                       const int *IPIV);
void MORSE_TASK_dsymm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyrk(MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyr2k(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       double beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyssq( MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dswpab(MORSE_option_t *options,
                       int i, int n1, int n2,
                       MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_dswptr_ontile(MORSE_option_t *options,
                              MORSE_desc_t descA, MORSE_desc_t *Aij, int Aijm, int Aijn,
                              int i1,  int i2, int *ipiv, int inc,
                              MORSE_desc_t *Akk, int Akkm, int Akkn, int ldak);
void MORSE_TASK_dtrdalg(MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        MORSE_desc_t *A,
                        MORSE_desc_t *C, int Cm, int Cn,
                        MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_dtrasm(MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dtrmm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dtrmm_p2(MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                         int m, int n, int nb,
                         double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         double **B, int ldb);
void MORSE_TASK_dtrsm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      double alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dtrssq( MORSE_option_t *options,
                        MORSE_enum uplo, MORSE_enum diag,
                        int m, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dtrtri(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_dtslqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmlq_sytra1(MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmlq_corner(MORSE_option_t *options,
                              int m1, int n1, int m2, int n2, int m3, int n3, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *A3, int A3m, int A3n, int lda3,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmqr_sytra1(MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmqr_corner(MORSE_option_t *options,
                              int m1, int n1, int m2, int n2, int m3, int n3, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *A3, int A3m, int A3n, int lda3,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtstrf(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *U, int Um, int Un, int ldu,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_dttmqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttmlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttlqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dpamm(MORSE_option_t *options,
                       int op, MORSE_enum side, MORSE_enum storev,
                       int m, int n, int k, int l,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *W, int Wm, int Wn, int ldw);
void MORSE_TASK_dplssq( MORSE_option_t *options,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn,
                        MORSE_desc_t *SCLSSQ,     int SCLSSQm,     int SCLSSQn );
void MORSE_TASK_dplssq2( MORSE_option_t *options,
                         MORSE_desc_t *RESULT, int RESULTm, int RESULTn );
void MORSE_TASK_dormlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int ib,  int nb, int k,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dormqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int k, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc);



#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
