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
 * @file morse_s.h
 *
 *  MORSE header file for float routines
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
#ifndef _MORSE_S_H_
#define _MORSE_S_H_

#undef COMPLEX
#define REAL

#ifdef __cplusplus
extern "C" {
#endif

/** ****************************************************************************
 *  Declarations of math functions (LAPACK layout) - alphabetical order
 **/
//int MORSE_sgebrd(int M, int N, float *A, int LDA, float *D, float *E, MORSE_desc_t *descT);
//int MORSE_sgecon(MORSE_enum norm, int N, float *A, int LDA, float anorm, float *rcond);
//int MORSE_spocon(MORSE_enum uplo, int N, float *A, int LDA, float anorm, float *rcond);
int MORSE_sgelqf(int M, int N, float *A, int LDA, MORSE_desc_t *descT);
int MORSE_sgelqs(int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sgels(MORSE_enum trans, int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sgemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_sgeqrf(int M, int N, float *A, int LDA, MORSE_desc_t *descT);
int MORSE_sgeqrs(int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
//int MORSE_sgesv(int N, int NRHS, float *A, int LDA, int *IPIV, float *B, int LDB);
int MORSE_sgesv_incpiv(int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_sgesv_nopiv(int N, int NRHS, float *A, int LDA, float *B, int LDB);
//int MORSE_sgesvd(MORSE_enum jobu, MORSE_enum jobvt, int M, int N, float *A, int LDA, float *S, float *U, int LDU, float *VT, int LDVT, MORSE_desc_t *descT);
//int MORSE_sgetrf(int M, int N, float *A, int LDA, int *IPIV);
int MORSE_sgetrf_incpiv(int M, int N, float *A, int LDA, MORSE_desc_t *descL, int *IPIV);
int MORSE_sgetrf_nopiv(int M, int N, float *A, int LDA);
//int MORSE_sgetri(int N, float *A, int LDA, int *IPIV);
//int MORSE_sgetrs(MORSE_enum trans, int N, int NRHS, float *A, int LDA, int *IPIV, float *B, int LDB);
int MORSE_sgetrs_incpiv(MORSE_enum trans, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_sgetrs_nopiv(MORSE_enum trans, int N, int NRHS, float *A, int LDA, float *B, int LDB);
#ifdef COMPLEX
int MORSE_ssymm(MORSE_enum side, MORSE_enum uplo, int M, int N, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_ssyrk(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float beta, float *C, int LDC);
int MORSE_ssyr2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
#endif
//int MORSE_ssyev(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_ssyevd(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_shegv(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_ssygvd(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_ssygst(MORSE_enum itype, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB);
//int MORSE_ssytrd(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *D, float *E, MORSE_desc_t *descT, float *Q, int LDQ);
int MORSE_slacpy(MORSE_enum uplo, int M, int N, float *A, int LDA, float *B, int LDB);
float MORSE_slange(MORSE_enum norm, int M, int N, float *A, int LDA);
#ifdef COMPLEX
float MORSE_slansy(MORSE_enum norm, MORSE_enum uplo, int N, float *A, int LDA);
#endif
float MORSE_slansy(MORSE_enum norm, MORSE_enum uplo, int N, float *A, int LDA);
float MORSE_slantr(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, int M, int N, float *A, int LDA);
int MORSE_slaset(MORSE_enum uplo, int M, int N, float alpha, float beta, float *A, int LDA);
//int MORSE_slaswp(int N, float *A, int LDA, int K1, int K2, int *IPIV, int INCX);
//int MORSE_slaswpc(int N, float *A, int LDA, int K1, int K2, int *IPIV, int INCX);
int MORSE_slauum(MORSE_enum uplo, int N, float *A, int LDA);
#ifdef COMPLEX
int MORSE_splgsy( float bump, int N, float *A, int LDA, unsigned long long int seed );
#endif
int MORSE_splgsy( float bump, int N, float *A, int LDA, unsigned long long int seed );
int MORSE_splrnt( int M, int N, float *A, int LDA, unsigned long long int seed );
int MORSE_sposv(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_spotrf(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_ssytrf(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_spotri(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_spotrs(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_ssytrs(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
#endif
int MORSE_ssymm(MORSE_enum side, MORSE_enum uplo, int M, int N, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_ssyrk(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float beta, float *C, int LDC);
int MORSE_ssyr2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_strmm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strsmpl(int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_strsmrv(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strtri(MORSE_enum uplo, MORSE_enum diag, int N, float *A, int LDA);
int MORSE_sorglq(int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sorgqr(int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sormlq(MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sormqr(MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);

//int MORSE_sgecfi(int m, int n, float *A, MORSE_enum fin, int imb, int inb, MORSE_enum fout, int omb, int onb);
//int MORSE_sgetmi(int m, int n, float *A, MORSE_enum fin, int mb,  int nb);

/** ****************************************************************************
 *  Declarations of math functions (tile layout) - alphabetical order
 **/
//int MORSE_sgebrd_Tile(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T);
//int MORSE_sgecon_Tile(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond);
//int MORSE_spocon_Tile(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond);
int MORSE_sgelqf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_sgelqs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sgels_Tile(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sgemm_Tile(MORSE_enum transA, MORSE_enum transB, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_sgeqrf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_sgeqrs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
//int MORSE_sgesv_Tile(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_sgesv_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_sgesv_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
//int MORSE_sgesvd_Tile(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *U, MORSE_desc_t *VT, MORSE_desc_t *T);
//int MORSE_sgetrf_Tile(MORSE_desc_t *A, int *IPIV);
int MORSE_sgetrf_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV);
int MORSE_sgetrf_nopiv_Tile(MORSE_desc_t *A);
//int MORSE_sgetri_Tile(MORSE_desc_t *A, int *IPIV);
//int MORSE_sgetrs_Tile(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_sgetrs_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_sgetrs_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
#ifdef COMPLEX
int MORSE_ssymm_Tile(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_ssyrk_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C);
int MORSE_ssyr2k_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
#endif
//int MORSE_ssyev_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ);
//int MORSE_ssyevd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ);
//int MORSE_shegv_Tile( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_ssygvd_Tile(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_ssygst_Tile(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
//int MORSE_ssytrd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, float *Q, int LDQ);
int MORSE_slacpy_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
float MORSE_slange_Tile(MORSE_enum norm, MORSE_desc_t *A);
#ifdef COMPLEX
float MORSE_slansy_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
#endif
float MORSE_slansy_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
float MORSE_slantr_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_slaset_Tile(MORSE_enum uplo, float alpha, float beta, MORSE_desc_t *A);
//int MORSE_slaswp_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
//int MORSE_slaswpc_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
int MORSE_slauum_Tile(MORSE_enum uplo, MORSE_desc_t *A);
#ifdef COMPLEX
int MORSE_splgsy_Tile(float bump, MORSE_desc_t *A, unsigned long long int seed );
#endif
int MORSE_splgsy_Tile(float bump, MORSE_desc_t *A, unsigned long long int seed );
int MORSE_splrnt_Tile(MORSE_desc_t *A, unsigned long long int seed );
int MORSE_sposv_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_spotrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_ssytrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_spotri_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_spotrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_ssytrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
#endif
int MORSE_ssymm_Tile(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_ssyrk_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C);
int MORSE_ssyr2k_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_strmm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strsm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strsmpl_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_strsmrv_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strtri_Tile(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_sorglq_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sorgqr_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sormlq_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sormqr_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);

/** ****************************************************************************
 *  Declarations of math functions (tile layout, asynchronous execution) - alphabetical order
 **/
//int MORSE_sgebrd_Tile_Async(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgecon_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_spocon_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgels_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgemm_Tile_Async(MORSE_enum transA, MORSE_enum transB, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgesv_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgesv_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgesv_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgesvd_Tile_Async(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *U, MORSE_desc_t *VT, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetrf_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrf_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrf_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetri_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *W, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetrs_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrs_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrs_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_ssymm_Tile_Async(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyrk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyr2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
//int MORSE_ssyev_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssyevd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_shegv_Tile_Async( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssygvd_Tile_Async(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssygst_Tile_Async(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssytrd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, float *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slacpy_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slange_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_slansy_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
int MORSE_slansy_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slantr_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slaset_Tile_Async(MORSE_enum uplo, float alpha, float beta, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_slaswp_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_slaswpc_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slauum_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
#ifdef COMPLEX
int MORSE_splgsy_Tile_Async(float bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
#endif
int MORSE_splgsy_Tile_Async(float bump, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_splrnt_Tile_Async(MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_sposv_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssytrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotri_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#if defined (PRECISION_c) || defined(PRECISION_z)
int MORSE_ssytrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
#endif
int MORSE_ssymm_Tile_Async(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyrk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyr2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strmm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsmpl_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsmrv_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strtri_Tile_Async(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorglq_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorgqr_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormlq_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormqr_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);

//int MORSE_sgecfi_Async(int m, int n, float *A, MORSE_enum f_in, int imb, int inb, MORSE_enum f_out, int omb, int onb, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetmi_Async(int m, int n, float *A, MORSE_enum f_in, int mb,  int inb, MORSE_sequence_t *sequence, MORSE_request_t *request);

/** ****************************************************************************
 *  Declarations of workspace allocation functions (tile layout) - alphabetical order
 **/
int MORSE_Alloc_Workspace_sgesv_incpiv(        int N, MORSE_desc_t **descL, int **IPIV);
int MORSE_Alloc_Workspace_sgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV);

int MORSE_Alloc_Workspace_sgebrd(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgeev( int N,        MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgehrd(int N,        MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgelqf(int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_sgels( int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_sgeqrf(int M, int N, MORSE_desc_t **T);
int MORSE_Alloc_Workspace_sgesvd(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_ssyev( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_ssyevd( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_shegv( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_ssygvd( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_ssytrd(int M, int N, MORSE_desc_t **descT);

/** ****************************************************************************
 *  Declarations of workspace allocation functions (tile layout, asynchronous execution) - alphabetical order
 **/

int MORSE_Alloc_Workspace_sgetri_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *W);

/* Warning: Those functions are deprecated */
int MORSE_Alloc_Workspace_sgelqf_Tile(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgels_Tile( int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgeqrf_Tile(int M, int N, MORSE_desc_t **descT);
int MORSE_Alloc_Workspace_sgesv_incpiv_Tile (int N, MORSE_desc_t **descL, int **IPIV);
int MORSE_Alloc_Workspace_sgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV);

/** ****************************************************************************
 *  Auxiliary function prototypes
 **/
int MORSE_sLapack_to_Tile(float *Af77, int LDA, MORSE_desc_t *A);
int MORSE_sTile_to_Lapack(MORSE_desc_t *A, float *Af77, int LDA);
int MORSE_sLapack_to_Tile_Async(float *Af77, int LDA, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sTile_to_Lapack_Async(MORSE_desc_t *A, float *Af77, int LDA, MORSE_sequence_t *sequence, MORSE_request_t *request);

#ifdef __cplusplus
}
#endif

#undef COMPLEX

#endif
