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
 * @file morse_c.h
 *
 *  MORSE header file for float _Complex routines
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
 * @generated c Tue Sep 26 20:42:59 2017
 *
 **/
#ifndef _MORSE_C_H_
#define _MORSE_C_H_

#undef REAL
#define COMPLEX

#ifdef __cplusplus
extern "C" {
#endif

/** ****************************************************************************
 *  Declarations of math functions (LAPACK layout) - alphabetical order
 **/
//int MORSE_cgebrd(int M, int N, MORSE_Complex32_t *A, int LDA, float *D, float *E, MORSE_desc_t *descT);
//int MORSE_cgecon(MORSE_enum norm, int N, MORSE_Complex32_t *A, int LDA, float anorm, float *rcond);
//int MORSE_cpocon(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, float anorm, float *rcond);
int MORSE_cgelqf(int M, int N, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT);
int MORSE_cgelqs(int M, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
int MORSE_cgels(MORSE_enum trans, int M, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
int MORSE_cgemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC);
int MORSE_cgeqrf(int M, int N, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT);
int MORSE_cgeqrs(int M, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
//int MORSE_cgesv(int N, int NRHS, MORSE_Complex32_t *A, int LDA, int *IPIV, MORSE_Complex32_t *B, int LDB);
int MORSE_cgesv_incpiv(int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descL, int *IPIV, MORSE_Complex32_t *B, int LDB);
int MORSE_cgesv_nopiv(int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
//int MORSE_cgesvd(MORSE_enum jobu, MORSE_enum jobvt, int M, int N, MORSE_Complex32_t *A, int LDA, float *S, MORSE_Complex32_t *U, int LDU, MORSE_Complex32_t *VT, int LDVT, MORSE_desc_t *descT);
//int MORSE_cgetrf(int M, int N, MORSE_Complex32_t *A, int LDA, int *IPIV);
int MORSE_cgetrf_incpiv(int M, int N, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descL, int *IPIV);
int MORSE_cgetrf_nopiv(int M, int N, MORSE_Complex32_t *A, int LDA);
//int MORSE_cgetri(int N, MORSE_Complex32_t *A, int LDA, int *IPIV);
//int MORSE_cgetrs(MORSE_enum trans, int N, int NRHS, MORSE_Complex32_t *A, int LDA, int *IPIV, MORSE_Complex32_t *B, int LDB);
int MORSE_cgetrs_incpiv(MORSE_enum trans, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descL, int *IPIV, MORSE_Complex32_t *B, int LDB);
int MORSE_cgetrs_nopiv(MORSE_enum trans, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
#ifdef COMPLEX
int MORSE_chemm(MORSE_enum side, MORSE_enum uplo, int M, int N, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC);
int MORSE_cherk(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, MORSE_Complex32_t *A, int LDA, float beta, MORSE_Complex32_t *C, int LDC);
int MORSE_cher2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, float beta, MORSE_Complex32_t *C, int LDC);
#endif
//int MORSE_cheev(MORSE_enum jobz, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, float *W, MORSE_desc_t *descT, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_cheevd(MORSE_enum jobz, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, float *W, MORSE_desc_t *descT, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_chegv(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, float *W, MORSE_desc_t *descT, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_chegvd(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, float *W, MORSE_desc_t *descT, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_chegst(MORSE_enum itype, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
//int MORSE_chetrd(MORSE_enum jobz, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA, float *D, float *E, MORSE_desc_t *descT, MORSE_Complex32_t *Q, int LDQ);
int MORSE_clacpy(MORSE_enum uplo, int M, int N, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
float MORSE_clange(MORSE_enum norm, int M, int N, MORSE_Complex32_t *A, int LDA);
#ifdef COMPLEX
float MORSE_clanhe(MORSE_enum norm, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
#endif
float MORSE_clansy(MORSE_enum norm, MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
float MORSE_clantr(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, int M, int N, MORSE_Complex32_t *A, int LDA);
int MORSE_claset(MORSE_enum uplo, int M, int N, MORSE_Complex32_t alpha, MORSE_Complex32_t beta, MORSE_Complex32_t *A, int LDA);
//int MORSE_claswp(int N, MORSE_Complex32_t *A, int LDA, int K1, int K2, int *IPIV, int INCX);
//int MORSE_claswpc(int N, MORSE_Complex32_t *A, int LDA, int K1, int K2, int *IPIV, int INCX);
int MORSE_clauum(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
#ifdef COMPLEX
int MORSE_cplghe( float bump, int N, MORSE_Complex32_t *A, int LDA, unsigned long long int seed );
#endif
int MORSE_cplgsy( MORSE_Complex32_t bump, int N, MORSE_Complex32_t *A, int LDA, unsigned long long int seed );
int MORSE_cplrnt( int M, int N, MORSE_Complex32_t *A, int LDA, unsigned long long int seed );
int MORSE_cposv(MORSE_enum uplo, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
int MORSE_cpotrf(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
int MORSE_csytrf(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
int MORSE_cpotri(MORSE_enum uplo, int N, MORSE_Complex32_t *A, int LDA);
int MORSE_cpotrs(MORSE_enum uplo, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_csytrs(MORSE_enum uplo, int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
#endif
int MORSE_csymm(MORSE_enum side, MORSE_enum uplo, int M, int N, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC);
int MORSE_csyrk(MORSE_enum uplo, MORSE_enum trans, int N, int K, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC);
int MORSE_csyr2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB, MORSE_Complex32_t beta, MORSE_Complex32_t *C, int LDC);
int MORSE_ctrmm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
int MORSE_ctrsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
int MORSE_ctrsmpl(int N, int NRHS, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descL, int *IPIV, MORSE_Complex32_t *B, int LDB);
int MORSE_ctrsmrv(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, MORSE_Complex32_t alpha, MORSE_Complex32_t *A, int LDA, MORSE_Complex32_t *B, int LDB);
int MORSE_ctrtri(MORSE_enum uplo, MORSE_enum diag, int N, MORSE_Complex32_t *A, int LDA);
int MORSE_cunglq(int M, int N, int K, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
int MORSE_cungqr(int M, int N, int K, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
int MORSE_cunmlq(MORSE_enum side, MORSE_enum trans, int M, int N, int K, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);
int MORSE_cunmqr(MORSE_enum side, MORSE_enum trans, int M, int N, int K, MORSE_Complex32_t *A, int LDA, MORSE_desc_t *descT, MORSE_Complex32_t *B, int LDB);

//int MORSE_cgecfi(int m, int n, MORSE_Complex32_t *A, MORSE_enum fin, int imb, int inb, MORSE_enum fout, int omb, int onb);
//int MORSE_cgetmi(int m, int n, MORSE_Complex32_t *A, MORSE_enum fin, int mb,  int nb);

/** ****************************************************************************
 *  Declarations of math functions (tile layout) - alphabetical order
 **/
//int MORSE_cgebrd_Tile(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T);
//int MORSE_cgecon_Tile(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond);
//int MORSE_cpocon_Tile(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond);
int MORSE_cgelqf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_cgelqs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_cgels_Tile(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_cgemm_Tile(MORSE_enum transA, MORSE_enum transB, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C);
int MORSE_cgeqrf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_cgeqrs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
//int MORSE_cgesv_Tile(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_cgesv_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_cgesv_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
//int MORSE_cgesvd_Tile(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *U, MORSE_desc_t *VT, MORSE_desc_t *T);
//int MORSE_cgetrf_Tile(MORSE_desc_t *A, int *IPIV);
int MORSE_cgetrf_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV);
int MORSE_cgetrf_nopiv_Tile(MORSE_desc_t *A);
//int MORSE_cgetri_Tile(MORSE_desc_t *A, int *IPIV);
//int MORSE_cgetrs_Tile(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_cgetrs_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_cgetrs_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
#ifdef COMPLEX
int MORSE_chemm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C);
int MORSE_cherk_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C);
int MORSE_cher2k_Tile(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
#endif
//int MORSE_cheev_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_cheevd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ);
//int MORSE_chegv_Tile( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_chegvd_Tile(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_chegst_Tile(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
//int MORSE_chetrd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ);
int MORSE_clacpy_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
float MORSE_clange_Tile(MORSE_enum norm, MORSE_desc_t *A);
#ifdef COMPLEX
float MORSE_clanhe_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
#endif
float MORSE_clansy_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
float MORSE_clantr_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_claset_Tile(MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_Complex32_t beta, MORSE_desc_t *A);
//int MORSE_claswp_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
//int MORSE_claswpc_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
int MORSE_clauum_Tile(MORSE_enum uplo, MORSE_desc_t *A);
#ifdef COMPLEX
int MORSE_cplghe_Tile(float bump, MORSE_desc_t *A, unsigned long long int seed );
#endif
int MORSE_cplgsy_Tile(MORSE_Complex32_t bump, MORSE_desc_t *A, unsigned long long int seed );
int MORSE_cplrnt_Tile(MORSE_desc_t *A, unsigned long long int seed );
int MORSE_cposv_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_cpotrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_csytrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_cpotri_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_cpotrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_csytrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
#endif
int MORSE_csymm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C);
int MORSE_csyrk_Tile(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_Complex32_t beta, MORSE_desc_t *C);
int MORSE_csyr2k_Tile(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C);
int MORSE_ctrmm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ctrsm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ctrsmpl_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_ctrsmrv_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ctrtri_Tile(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_cunglq_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_cungqr_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_cunmlq_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_cunmqr_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);

/** ****************************************************************************
 *  Declarations of math functions (tile layout, asynchronous execution) - alphabetical order
 **/
//int MORSE_cgebrd_Tile_Async(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgecon_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cpocon_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgelqf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgelqs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgels_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgemm_Tile_Async(MORSE_enum transA, MORSE_enum transB, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgeqrf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgeqrs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgesv_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgesv_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgesv_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgesvd_Tile_Async(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *U, MORSE_desc_t *VT, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgetrf_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgetrf_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgetrf_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgetri_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *W, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgetrs_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgetrs_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cgetrs_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_chemm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cherk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cher2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
//int MORSE_cheev_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cheevd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_chegv_Tile_Async( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_chegvd_Tile_Async(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_chegst_Tile_Async(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_chetrd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, MORSE_Complex32_t *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_clacpy_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_clange_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_clanhe_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
int MORSE_clansy_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_clantr_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_claset_Tile_Async(MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_Complex32_t beta, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_claswp_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_claswpc_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_clauum_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_cplghe_Tile_Async(float bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
#endif
int MORSE_cplgsy_Tile_Async(MORSE_Complex32_t bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_cplrnt_Tile_Async(MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_cposv_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cpotrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_csytrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cpotri_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cpotrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_csytrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
int MORSE_csymm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_csyrk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_Complex32_t beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_csyr2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_Complex32_t beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ctrmm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ctrsm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ctrsmpl_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ctrsmrv_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, MORSE_Complex32_t alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ctrtri_Tile_Async(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cunglq_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cungqr_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cunmlq_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cunmqr_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);

//int MORSE_cgecfi_Async(int m, int n, MORSE_Complex32_t *A, MORSE_enum f_in, int imb, int inb, MORSE_enum f_out, int omb, int onb, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_cgetmi_Async(int m, int n, MORSE_Complex32_t *A, MORSE_enum f_in, int mb,  int inb, MORSE_sequence_t *sequence, MORSE_request_t *request);

/** ****************************************************************************
 *  Declarations of workspace allocation functions (tile layout) - alphabetical order
 **/
int MORSE_Alloc_Workspace_cgesv_incpiv(        int N, MORSE_desc_t **descL, int **IPIV);
int MORSE_Alloc_Workspace_cgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV);

int MORSE_Alloc_Workspace_cgebrd(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgeev( int N,        MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgehrd(int N,        MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgelqf(int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_cgels( int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_cgeqrf(int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_cgesvd(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cheev( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cheevd( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_chegv( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_chegvd( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_chetrd(int M, int N, MORSE_desc_t **descT);

/** ****************************************************************************
 *  Declarations of workspace allocation functions (tile layout, asynchronous execution) - alphabetical order
 **/

int MORSE_Alloc_Workspace_cgetri_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *W);

/* Warning: Those functions are deprecated */
int MORSE_Alloc_Workspace_cgelqf_Tile(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgels_Tile( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgeqrf_Tile(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_cgesv_incpiv_Tile (int N, MORSE_desc_t **descL, int **IPIV);
int MORSE_Alloc_Workspace_cgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV);

/** ****************************************************************************
 *  Auxiliary function prototypes
 **/
int MORSE_cLapack_to_Tile(MORSE_Complex32_t *Af77, int LDA, MORSE_desc_t *A);
int MORSE_cTile_to_Lapack(MORSE_desc_t *A, MORSE_Complex32_t *Af77, int LDA);
int MORSE_cLapack_to_Tile_Async(MORSE_Complex32_t *Af77, int LDA, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_cTile_to_Lapack_Async(MORSE_desc_t *A, MORSE_Complex32_t *Af77, int LDA, MORSE_sequence_t *sequence, MORSE_request_t *request);

#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
