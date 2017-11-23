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
 * @file runtime_s.h
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
 * @generated s Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef _RUNTIME_SBLAS_H_
#define _RUNTIME_SBLAS_H_

#define REAL

#ifdef __cplusplus
extern "C" {
#endif


/** ****************************************************************************
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 **/
void MORSE_TASK_sdasum(MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, int M, int N,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_sgeadd(MORSE_option_t *options,
                      int m, int n, float alpha,
                      MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_sbrdalg(MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        MORSE_desc_t *A,
                        MORSE_desc_t *C, int Cm, int Cn,
                        MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_sgelqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sgemm(MORSE_option_t *options,
                      MORSE_enum transA, MORSE_enum transB,
                      int m, int n, int k, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm2( MORSE_option_t *options,
                        MORSE_enum transA, MORSE_enum transB,
                        int m, int n, int k, int nb,
                        float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *B, int Bm, int Bn, int ldb,
                        float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm_f2(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc,
                         MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                         MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_sgemm_p2(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         const float **B, int ldb,
                         float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm_p2f1(MORSE_option_t *options,
                           MORSE_enum transA, MORSE_enum transB,
                           int m, int n, int k, int nb,
                           float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                           const float **B, int ldb,
                           float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc,
                           MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1);
void MORSE_TASK_sgemm_p3(MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         float beta, float **C, int ldc);
void MORSE_TASK_sgeqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sgessm(MORSE_option_t *options,
                       int m, int n, int k, int ib, int nb,
                       int *IPIV,
                       MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       MORSE_desc_t *D, int Dm, int Dn, int ldd,
                       MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_sgessq( MORSE_option_t *options,
                        int m, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn);
void MORSE_TASK_sgetrf(MORSE_option_t *options,
                       int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_sgetrf_incpiv(MORSE_option_t *options,
                              int m, int n, int ib, int nb,
                              MORSE_desc_t *A, int Am, int An, int lda,
                              MORSE_desc_t *L, int Lm, int Ln, int ldl,
                              int *IPIV,
                              MORSE_bool check_info, int iinfo);
void MORSE_TASK_sgetrf_reclap(MORSE_option_t *options,
                              int m, int n, int nb,
                              MORSE_desc_t *A, int Am, int An, int lda,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_sgetrf_rectil(MORSE_option_t *options,
                              MORSE_desc_t A, MORSE_desc_t *Amn, int Amnm, int Amnn, int size,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_sgetrip(MORSE_option_t *options,
                        int m, int n, MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_sgetrip_f1(MORSE_option_t *options,
                           int m, int n, MORSE_desc_t *A, int Am, int An, int szeA,
                           MORSE_desc_t *fake, int fakem, int faken, int szeF, int paramF);
void MORSE_TASK_sgetrip_f2(MORSE_option_t *options,
                           int m, int n, MORSE_desc_t *A, int Am, int An, int szeA,
                           MORSE_desc_t *fake1, int fake1m, int fake1n, int szeF1, int paramF1,
                           MORSE_desc_t *fake2, int fake2m, int fake2n, int szeF2, int paramF2);
void MORSE_TASK_ssymm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssygst(MORSE_option_t *options,
                       int itype, MORSE_enum uplo, int N,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,

                       int iinfo);
void MORSE_TASK_ssyrk(MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyr2k(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyrfb(MORSE_option_t *options,
                       MORSE_enum uplo,
                       int n, int k, int ib, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_slacpy(MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int mb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slange(MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slange_max(MORSE_option_t *options,
                           MORSE_desc_t *A, int Am, int An,
                           MORSE_desc_t *B, int Bm, int Bn);
#ifdef COMPLEX
void MORSE_TASK_ssyssq( MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_slansy(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
#endif
void MORSE_TASK_slansy(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slantr(MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag,
                       int M, int N, int NB,
                       MORSE_desc_t *A, int Am, int An, int LDA,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slaset(MORSE_option_t *options,
                       MORSE_enum uplo, int n1, int n2, float alpha,
                       float beta, MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_slaset2(MORSE_option_t *options,
                        MORSE_enum uplo, int n1, int n2, float alpha,
                        MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_slaswp(MORSE_option_t *options,
                       int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int i1,  int i2, int *ipiv, int inc);
void MORSE_TASK_slaswp_f2(MORSE_option_t *options,
                          int n, MORSE_desc_t *A, int Am, int An, int lda,
                          int i1,  int i2, int *ipiv, int inc,
                          MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                          MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_slaswp_ontile(MORSE_option_t *options,
                              MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                              int i1,  int i2, int *ipiv, int inc, float *fakepanel);
void MORSE_TASK_slaswp_ontile_f2(MORSE_option_t *options,
                                 MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                                 int i1,  int i2, int *ipiv, int inc,
                                 MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                                 MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_slaswpc_ontile(MORSE_option_t *options,
                               MORSE_desc_t descA, MORSE_desc_t *A, int Am, int An,
                               int i1,  int i2, int *ipiv, int inc, float *fakepanel);
void MORSE_TASK_slatro(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int mb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slauum(MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_splgsy(MORSE_option_t *options,
                       float bump, int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_splgsy(MORSE_option_t *options,
                       float bump, int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_splrnt(MORSE_option_t *options,
                       int m, int n, MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_spotrf(MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_sshift( MORSE_option_t *options,
                        int s, int m, int n, int L,
                        float *A);
void MORSE_TASK_sshiftw(MORSE_option_t *options,
                        int s, int cl, int m, int n, int L,
                        MORSE_desc_t *A, int Am, int An, float *W);
void MORSE_TASK_sssssm(MORSE_option_t *options,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *L1, int L1m, int L1n, int ldl1,
                       MORSE_desc_t *L2, int L2m, int L2n, int ldl2,
                       const int *IPIV);
void MORSE_TASK_ssymm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyrk(MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyr2k(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       float beta, MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyssq( MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_sswpab(MORSE_option_t *options,
                       int i, int n1, int n2,
                       MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_sswptr_ontile(MORSE_option_t *options,
                              MORSE_desc_t descA, MORSE_desc_t *Aij, int Aijm, int Aijn,
                              int i1,  int i2, int *ipiv, int inc,
                              MORSE_desc_t *Akk, int Akkm, int Akkn, int ldak);
void MORSE_TASK_strdalg(MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        MORSE_desc_t *A,
                        MORSE_desc_t *C, int Cm, int Cn,
                        MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_strasm(MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_strmm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_strmm_p2(MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                         int m, int n, int nb,
                         float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                         float **B, int ldb);
void MORSE_TASK_strsm(MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      float alpha, MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_strssq( MORSE_option_t *options,
                        MORSE_enum uplo, MORSE_enum diag,
                        int m, int n,
                        MORSE_desc_t *A, int Am, int An, int lda,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_strtri(MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_stslqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmlq_sytra1(MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmlq_corner(MORSE_option_t *options,
                              int m1, int n1, int m2, int n2, int m3, int n3, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *A3, int A3m, int A3n, int lda3,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmqr_sytra1(MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmqr_corner(MORSE_option_t *options,
                              int m1, int n1, int m2, int n2, int m3, int n3, int k, int ib, int nb,
                              MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              MORSE_desc_t *A3, int A3m, int A3n, int lda3,
                              MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ststrf(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *U, int Um, int Un, int ldu,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_sttmqr(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttqrt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttmlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttlqt(MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_spamm(MORSE_option_t *options,
                       int op, MORSE_enum side, MORSE_enum storev,
                       int m, int n, int k, int l,
                       MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       MORSE_desc_t *W, int Wm, int Wn, int ldw);
void MORSE_TASK_splssq( MORSE_option_t *options,
                        MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn,
                        MORSE_desc_t *SCLSSQ,     int SCLSSQm,     int SCLSSQn );
void MORSE_TASK_splssq2( MORSE_option_t *options,
                         MORSE_desc_t *RESULT, int RESULTm, int RESULTn );
void MORSE_TASK_sormlq(MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int ib,  int nb, int k,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sormqr(MORSE_option_t *options,
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
