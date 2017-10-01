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
 * @file workspace_d.c
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
 * @generated d Tue Sep 26 20:43:09 2017
 *
 **/
#include "control/common.h"
#include "control/workspace.h"

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgeev - Allocates workspace for MORSE_dgeev or
 *  MORSE_dgeev_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] N
 *          The order of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors
 *          required by the tile Hessenberg.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgeev(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_DGEEV, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgehrd - Allocates workspace for MORSE_dgehrd or
 *  MORSE_dgehrd_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors
 *          required by the tile Hessenberg.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgehrd(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_DGEHRD, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgebrd - Allocates workspace for MORSE_dgebrd or MORSE_dgebrd_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors
 *          required by the tile BRD.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgebrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGEBRD, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgels - Allocates workspace for MORSE_dgels or
 *  MORSE_dgels_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors
 *          required by the tile QR or the tile LQ factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgels(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgels_Tile - Allocates tile workspace for
 *  MORSE_dgels_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, MORSE_desc_t *on workspace handle for storage of the extra
 *          T factors required by the tile QR or the tile LQ factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgels_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgeqrf - Allocates workspace for MORSE_dgeqrf or
 *  MORSE_dgeqrf_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors
 *          required by the tile QR factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgeqrf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgeqrf_Tile - Allocates tile workspace for
 *  MORSE_dgels_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, MORSE_desc_t *on workspace handle for storage of the extra
 *          T factors required by the tile QR or the tile LQ factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgeqrf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgelqf - Allocates workspace for MORSE_dgelqf or
 *  MORSE_dgelqf_Tile routines.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile LQ
 *          factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgelqf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgelqf_Tile - Allocates tile workspace for MORSE_dgels_Tile routine.
 *
 ******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, MORSE_desc_t *on workspace handle for storage of the extra
 *          T factors required by the tile QR or the tile LQ factorization.
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgelqf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGELS, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgesv - Allocates workspace for MORSE_dgesv or
 *  MORSE_dgesv_Tile routines.
 *
 ******************************************************************************
 *
 * @param[in] N
 *          The number of linear equations, i.e., the order of the matrix A.
 *          N >= 0.
 *
 * @param[out] descL
 *          On exit, workspace handle for storage of the extra L factors
 *          required by the tile LU factorization.
 *
 * @param[out] IPIV
 *          On exit, workspace handle for storage of pivot indexes required
 *          by the tile LU factorization (not equivalent to LAPACK).
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgesv_incpiv(int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(N, N, MORSE_FUNC_DGESV, MorseRealDouble, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgesv_Tile - Allocates workspace for MORSE_dgesv_Tile
 *  routines.
 *
 *******************************************************************************
 *
 * @param[in] N
 *          The number of linear equations, i.e., the order of the matrix A.
 *          N >= 0.
 *
 * @param[out] descL
 *          On exit, MORSE descriptor on workspace handle for storage of the
 *          extra L factors required by the tile LU factorization.
 *
 * @param[out] IPIV
 *          On exit, workspace handle for storage of pivot indexes required by
 *          the tile LU factorization (not equivalent to LAPACK).
 *
 ******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 *****************************************************************************/
int MORSE_Alloc_Workspace_dgesv_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_DGESV, MorseRealDouble, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgesvd - Allocates workspace for MORSE_dgesvd or
 *  MORSE_dgesvd_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile BRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dgesvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DGESVD, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgetrf_incpiv - Allocates workspace for
 *  MORSE_dgetrf_incpiv or MORSE_dgetrf_incpiv_Tile or
 *  MORSE_dgetrf_incpiv_Tile_Async routines.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descL
 *          On exit, workspace handle for storage of the extra L factors required by the tile LU
 *          factorization.
 *
 * @param[out] IPIV
 *          On exit, workspace handle for storage of pivot indexes required by the tile LU
 *          factorization (not equivalent to LAPACK).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************
 *
 * @sa MORSE_dgetrf_incpiv
 * @sa MORSE_dgetrf_incpiv_Tile
 * @sa MORSE_dgetrf_incpiv_Tile_Async
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(M, N, MORSE_FUNC_DGESV, MorseRealDouble, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dgetrf_incpiv_Tile - Allocates workspace for
 *  MORSE_dgesv_incpiv_Tile or MORSE_dgesv_incpiv_Tile_Async routines.
 *
 *******************************************************************************
 *
 * @param[in] N
 *          The number of linear equations, i.e., the order of the matrix A. N >= 0.
 *
 * @param[out] descL
 *          On exit, MORSE descriptor on workspace handle for storage of the extra
 *          L factors required by the tile LU factorization.
 *
 * @param[out] IPIV
 *          On exit, workspace handle for storage of pivot indexes required by the tile LU
 *          factorization (not equivalent to LAPACK).
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_DGESV, MorseRealDouble, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dsyev - Allocates workspace for MORSE_dsyev or MORSE_dsyev_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile TRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dsyev(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DSYEV, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dsyevd - Allocates workspace for MORSE_dsyevd or MORSE_dsyevd_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile TRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dsyevd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DSYEVD, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dhegv - Allocates workspace for MORSE_dhegv or MORSE_dhegv_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile TRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dhegv(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_ZHEGV, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dsygvd - Allocates workspace for MORSE_dsygvd or MORSE_dsygvd_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile TRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dsygvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DSYGVD, MorseRealDouble, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_dsytrd - Allocates workspace for MORSE_dsytrd or MORSE_dsytrd_Tile routine.
 *
 *******************************************************************************
 *
 * @param[in] M
 *          The number of rows of the matrix A. M >= 0.
 *
 * @param[in] N
 *          The number of columns of the matrix A.  N >= 0.
 *
 * @param[out] descT
 *          On exit, workspace handle for storage of the extra T factors required by the tile TRD.
 *
 *******************************************************************************
 *
 * @return
 *          \retval MORSE_SUCCESS successful exit
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_dsytrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_DSYTRD, MorseRealDouble, descT); }
