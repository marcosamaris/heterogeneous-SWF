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
 * @file core_sblas.h
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
 * @generated s Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef _MORSE_CORE_SBLAS_H_
#define _MORSE_CORE_SBLAS_H_

#define REAL

#ifdef __cplusplus
extern "C" {
#endif

/** ****************************************************************************
 *  Declarations of serial kernels - alphabetical order
 **/
void CORE_sasum(int storev, MORSE_enum uplo, int M, int N,
                 const float *A, int lda, float *work);
void CORE_sbrdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, float *C, float *S,
                  int i, int j, int m, int grsiz);
int CORE_sgbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
int CORE_sgbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
int CORE_sgblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
int CORE_sgeadd(int M, int N, float alpha,
                const float *A, int LDA,
                      float *B, int LDB);
int  CORE_sgelqt(int M, int N, int IB,
                 float *A, int LDA,
                 float *T, int LDT,
                 float *TAU,
                 float *WORK);
void CORE_sgemm(MORSE_enum transA, MORSE_enum transB,
                int M, int N, int K,
                float alpha, const float *A, int LDA,
                                          const float *B, int LDB,
                float beta,        float *C, int LDC);
int  CORE_sgeqrt(int M, int N, int IB,
                 float *A, int LDA,
                 float *T, int LDT,
                 float *TAU, float *WORK);
int CORE_sgesplit(MORSE_enum side, MORSE_enum diag,
                  int M, int N,
                  float *A, int LDA,
                  float *B, int LDB);
int  CORE_sgessm(int M, int N, int K, int IB,
                 const int *IPIV,
                 const float *L, int LDL,
                 float *A, int LDA);
int  CORE_sgessq(int M, int N,
                 const float *A, int LDA,
                 float *scale, float *sumsq);
int CORE_sgetf2_nopiv(int M, int N,
                  float *A, int LDA);
int  CORE_sgetrf(int M, int N,
                 float *A, int LDA,
                 int *IPIV, int *INFO);
int  CORE_sgetrf_incpiv(int M, int N, int IB,
                        float *A, int LDA,
                        int *IPIV, int *INFO);
int CORE_sgetrf_nopiv(int M, int N, int IB,
                      float *A, int LDA,
                      int *INFO);
int  CORE_sgetrf_reclap(int M, int N,
                        float *A, int LDA,
                        int *IPIV, int *info);
int  CORE_sgetrf_rectil(const MORSE_desc_t A, int *IPIV, int *info);
void CORE_sgetrip(int m, int n, float *A,
                  float *work);
int CORE_shbelr(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
int CORE_shblrx(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
int CORE_shbrce(MORSE_enum uplo, int N,
                MORSE_desc_t *A, float *V, float *TAU,
                int st, int ed, int eltsize);
void CORE_shbtype1cb(int N, int NB,
                     float *A, int LDA,
                     float *V, float *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     float *WORK);
void CORE_shbtype2cb(int N, int NB,
                     float *A, int LDA,
                     float *V, float *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     float *WORK);
void CORE_shbtype3cb(int N, int NB,
                     float *A, int LDA,
                     const float *V, const float *TAU,
                     int st, int ed, int sweep, int Vblksiz, int WANTZ,
                     float *WORK);
void CORE_ssygst(int itype, MORSE_enum uplo, int N,
                 float *A, int LDA,
                 float *B, int LDB, int *INFO);
#ifdef COMPLEX
void CORE_ssymm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                float alpha, const float *A, int LDA,
                                          const float *B, int LDB,
                float beta,        float *C, int LDC);
void CORE_ssyrk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                float alpha, const float *A, int LDA,
                float beta,        float *C, int LDC);
void CORE_ssyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 float alpha, const float *A, int LDA,
                                           const float *B, int LDB,
                 float beta,                    float *C, int LDC);
int  CORE_ssyssq(MORSE_enum uplo, int N,
                 const float *A, int LDA,
                 float *scale, float *sumsq);
#endif
int  CORE_ssyrfb(MORSE_enum uplo, int N, int K, int IB, int NB,
                 const float *A,    int LDA,
                 const float *T,    int LDT,
                       float *C,    int LDC,
                       float *WORK, int LDWORK);
void CORE_slacpy(MORSE_enum uplo, int M, int N,
                 const float *A, int LDA,
                       float *B, int LDB);
void CORE_slange(int norm, int M, int N,
                 const float *A, int LDA,
                 float *work, float *normA);
#ifdef COMPLEX
void CORE_slansy(int norm, MORSE_enum uplo, int N,
                 const float *A, int LDA,
                 float *work, float *normA);
#endif
void CORE_slansy(int norm, MORSE_enum uplo, int N,
                 const float *A, int LDA,
                 float *work, float *normA);
void CORE_slantr(int norm, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                 const float *A, int LDA,
                 float *work, float *normA);
int CORE_slarfb_gemm(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                     int M, int N, int K,
                     const float *V, int LDV,
                     const float *T, int LDT,
                           float *C, int LDC,
                           float *WORK, int LDWORK);
int CORE_slarfx2(MORSE_enum side, int N,
                 float V,
                 float TAU,
                 float *C1, int LDC1,
                 float *C2, int LDC2);
int CORE_slarfx2c(MORSE_enum uplo,
                  float V,
                  float TAU,
                  float *C1,
                  float *C2,
                  float *C3);
int CORE_slarfx2ce(MORSE_enum uplo,
                   float *V,
                   float *TAU,
                   float *C1,
                   float *C2,
                   float *C3);
void CORE_slarfy(int N,
                 float *A, int LDA,
                 const float *V,
                 const float *TAU,
                 float *WORK);
void CORE_slaset(MORSE_enum uplo, int n1, int n2,
                 float alpha, float beta,
                 float *tileA, int ldtilea);
void CORE_slaset2(MORSE_enum uplo, int n1, int n2, float alpha,
                  float *tileA, int ldtilea);
void CORE_slaswp(int N, float *A, int LDA,
                 int I1,  int I2, const int *IPIV, int INC);
int  CORE_slaswp_ontile( MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_slaswpc_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc);
int  CORE_slatro(MORSE_enum uplo, MORSE_enum trans,
                 int M, int N,
                 const float *A, int LDA,
                       float *B, int LDB);
void CORE_slauum(MORSE_enum uplo, int N, float *A, int LDA);
int CORE_spamm(int op, MORSE_enum side, MORSE_enum storev,
               int M, int N, int K, int L,
               const float *A1, int LDA1,
                     float *A2, int LDA2,
               const float *V, int LDV,
                     float *W, int LDW);
int  CORE_sparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev,
                 int M1, int N1, int M2, int N2, int K, int L,
                       float *A1, int LDA1,
                       float *A2, int LDA2,
                 const float *V, int LDV,
                 const float *T, int LDT,
                       float *WORK, int LDWORK);
int CORE_spemv(MORSE_enum trans, MORSE_enum storev,
               int M, int N, int L,
               float ALPHA,
               const float *A, int LDA,
               const float *X, int INCX,
               float BETA,
               float *Y, int INCY,
               float *WORK);
void CORE_splgsy(float bump, int m, int n, float *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_splgsy(float bump, int m, int n, float *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_splrnt(int m, int n, float *A, int lda,
                 int bigM, int m0, int n0, unsigned long long int seed );
void CORE_spotrf(MORSE_enum uplo, int N, float *A, int LDA, int *INFO);
void CORE_sshift(int s, int m, int n, int L,
                 float *A);
void CORE_sshiftw(int s, int cl, int m, int n, int L,
                  float *A, float *W);
int  CORE_sssssm(int M1, int N1, int M2, int N2, int K, int IB,
                       float *A1, int LDA1,
                       float *A2, int LDA2,
                 const float *L1, int LDL1,
                 const float *L2, int LDL2,
                 const int *IPIV);
void CORE_ssymm(MORSE_enum side, MORSE_enum uplo,
                int M, int N,
                float alpha, const float *A, int LDA,
                                          const float *B, int LDB,
                float beta,        float *C, int LDC);
void CORE_ssyrk(MORSE_enum uplo, MORSE_enum trans,
                int N, int K,
                float alpha, const float *A, int LDA,
                float beta,        float *C, int LDC);
void CORE_ssyr2k(MORSE_enum uplo, MORSE_enum trans,
                 int N, int K,
                 float alpha, const float *A, int LDA,
                                           const float *B, int LDB,
                 float beta,        float *C, int LDC);
int  CORE_ssyssq(MORSE_enum uplo, int N,
                 const float *A, int LDA,
                 float *scale, float *sumsq);
int CORE_ssytf2_nopiv(MORSE_enum uplo, int n, float *A, int lda);
void CORE_sswpab(int i, int n1, int n2,
                 float *A, float *work);
int  CORE_sswptr_ontile(MORSE_desc_t descA, int i1, int i2, const int *ipiv, int inc,
                        const float *Akk, int ldak);
void CORE_strdalg(MORSE_enum uplo, int N, int NB,
                  const MORSE_desc_t *pA, float *V, float *TAU,
                  int i, int j, int m, int grsiz);
void CORE_strmm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                float alpha, const float *A, int LDA,
                                                float *B, int LDB);
void CORE_strsm(MORSE_enum side, MORSE_enum uplo,
                MORSE_enum transA, MORSE_enum diag,
                int M, int N,
                float alpha, const float *A, int LDA,
                                                float *B, int LDB);
void CORE_strtri(MORSE_enum uplo, MORSE_enum diag, int N,
                 float *A, int LDA, int *info);
int  CORE_stslqt(int M, int N, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 float *T, int LDT,
                 float *TAU, float *WORK);
int  CORE_stsmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *WORK, int LDWORK);
int CORE_stsmlq_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        float *A1, int lda1,
                        float *A2, int lda2,
                        float *A3, int lda3,
                        const float *V, int ldv,
                        const float *T, int ldt,
                        float *WORK, int ldwork);
int CORE_stsmlq_sytra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        float *A1, int lda1,
                        float *A2, int lda2,
                        const float *V, int ldv,
                        const float *T, int ldt,
                        float *WORK, int ldwork);
int  CORE_stsmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *WORK, int LDWORK);
int CORE_stsmqr_corner( int m1, int n1, int m2, int n2, int m3, int n3,
                        int k, int ib, int nb,
                        float *A1, int lda1,
                        float *A2, int lda2,
                        float *A3, int lda3,
                        const float *V, int ldv,
                        const float *T, int ldt,
                        float *WORK, int ldwork);
int CORE_stsmqr_sytra1( MORSE_enum side, MORSE_enum trans,
                        int m1, int n1, int m2, int n2,
                        int k, int ib,
                        float *A1, int lda1,
                        float *A2, int lda2,
                        const float *V, int ldv,
                        const float *T, int ldt,
                        float *WORK, int ldwork);
int  CORE_stsqrt(int M, int N, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 float *T, int LDT,
                 float *TAU, float *WORK);
int  CORE_ststrf(int M, int N, int IB, int NB,
                 float *U, int LDU,
                 float *A, int LDA,
                 float *L, int LDL,
                 int *IPIV, float *WORK,
                 int LDWORK, int *INFO);
int  CORE_sttmqr(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *WORK, int LDWORK);
int  CORE_sttqrt(int M, int N, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 float *T, int LDT,
                 float *TAU,
                 float *WORK);
int  CORE_sttmlq(MORSE_enum side, MORSE_enum trans,
                 int M1, int N1, int M2, int N2, int K, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *WORK, int LDWORK);
int  CORE_sttlqt(int M, int N, int IB,
                 float *A1, int LDA1,
                 float *A2, int LDA2,
                 float *T, int LDT,
                 float *TAU,
                 float *WORK);
int  CORE_sormlq(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int IB, int K,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *C, int LDC,
                 float *WORK, int LDWORK);
int  CORE_sormqr(MORSE_enum side, MORSE_enum trans,
                 int M, int N, int K, int IB,
                 const float *V, int LDV,
                 const float *T, int LDT,
                 float *C, int LDC,
                 float *WORK, int LDWORK);




#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
