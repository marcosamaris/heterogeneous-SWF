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
 * @file workspace_s.c
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
 * @generated s Tue Sep 26 20:43:09 2017
 *
 **/
#include "control/common.h"
#include "control/workspace.h"

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgeev - Allocates workspace for MORSE_sgeev or
 *  MORSE_sgeev_Tile routine.
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
int MORSE_Alloc_Workspace_sgeev(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_SGEEV, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgehrd - Allocates workspace for MORSE_sgehrd or
 *  MORSE_sgehrd_Tile routine.
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
int MORSE_Alloc_Workspace_sgehrd(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_SGEHRD, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgebrd - Allocates workspace for MORSE_sgebrd or MORSE_sgebrd_Tile routine.
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
int MORSE_Alloc_Workspace_sgebrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGEBRD, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgels - Allocates workspace for MORSE_sgels or
 *  MORSE_sgels_Tile routine.
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
int MORSE_Alloc_Workspace_sgels(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgels_Tile - Allocates tile workspace for
 *  MORSE_sgels_Tile routine.
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
int MORSE_Alloc_Workspace_sgels_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgeqrf - Allocates workspace for MORSE_sgeqrf or
 *  MORSE_sgeqrf_Tile routine.
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
int MORSE_Alloc_Workspace_sgeqrf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgeqrf_Tile - Allocates tile workspace for
 *  MORSE_sgels_Tile routine.
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
int MORSE_Alloc_Workspace_sgeqrf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgelqf - Allocates workspace for MORSE_sgelqf or
 *  MORSE_sgelqf_Tile routines.
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
int MORSE_Alloc_Workspace_sgelqf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgelqf_Tile - Allocates tile workspace for MORSE_sgels_Tile routine.
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
int MORSE_Alloc_Workspace_sgelqf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGELS, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgesv - Allocates workspace for MORSE_sgesv or
 *  MORSE_sgesv_Tile routines.
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
int MORSE_Alloc_Workspace_sgesv_incpiv(int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(N, N, MORSE_FUNC_SGESV, MorseRealFloat, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgesv_Tile - Allocates workspace for MORSE_sgesv_Tile
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
int MORSE_Alloc_Workspace_sgesv_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_SGESV, MorseRealFloat, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgesvd - Allocates workspace for MORSE_sgesvd or
 *  MORSE_sgesvd_Tile routine.
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
int MORSE_Alloc_Workspace_sgesvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SGESVD, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgetrf_incpiv - Allocates workspace for
 *  MORSE_sgetrf_incpiv or MORSE_sgetrf_incpiv_Tile or
 *  MORSE_sgetrf_incpiv_Tile_Async routines.
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
 * @sa MORSE_sgetrf_incpiv
 * @sa MORSE_sgetrf_incpiv_Tile
 * @sa MORSE_sgetrf_incpiv_Tile_Async
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_sgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(M, N, MORSE_FUNC_SGESV, MorseRealFloat, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_sgetrf_incpiv_Tile - Allocates workspace for
 *  MORSE_sgesv_incpiv_Tile or MORSE_sgesv_incpiv_Tile_Async routines.
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
int MORSE_Alloc_Workspace_sgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_SGESV, MorseRealFloat, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_ssyev - Allocates workspace for MORSE_ssyev or MORSE_ssyev_Tile routine.
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
int MORSE_Alloc_Workspace_ssyev(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SSYEV, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_ssyevd - Allocates workspace for MORSE_ssyevd or MORSE_ssyevd_Tile routine.
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
int MORSE_Alloc_Workspace_ssyevd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SSYEVD, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_shegv - Allocates workspace for MORSE_shegv or MORSE_shegv_Tile routine.
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
int MORSE_Alloc_Workspace_shegv(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_ZHEGV, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_ssygvd - Allocates workspace for MORSE_ssygvd or MORSE_ssygvd_Tile routine.
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
int MORSE_Alloc_Workspace_ssygvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SSYGVD, MorseRealFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_ssytrd - Allocates workspace for MORSE_ssytrd or MORSE_ssytrd_Tile routine.
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
int MORSE_Alloc_Workspace_ssytrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_SSYTRD, MorseRealFloat, descT); }
