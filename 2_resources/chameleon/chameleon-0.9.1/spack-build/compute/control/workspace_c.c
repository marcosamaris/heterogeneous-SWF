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
 * @file workspace_c.c
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
 * @generated c Tue Sep 26 20:43:09 2017
 *
 **/
#include "control/common.h"
#include "control/workspace.h"

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgeev - Allocates workspace for MORSE_cgeev or
 *  MORSE_cgeev_Tile routine.
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
int MORSE_Alloc_Workspace_cgeev(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_CGEEV, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgehrd - Allocates workspace for MORSE_cgehrd or
 *  MORSE_cgehrd_Tile routine.
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
int MORSE_Alloc_Workspace_cgehrd(int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(N, N, MORSE_FUNC_CGEHRD, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgebrd - Allocates workspace for MORSE_cgebrd or MORSE_cgebrd_Tile routine.
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
int MORSE_Alloc_Workspace_cgebrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGEBRD, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgels - Allocates workspace for MORSE_cgels or
 *  MORSE_cgels_Tile routine.
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
int MORSE_Alloc_Workspace_cgels(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgels_Tile - Allocates tile workspace for
 *  MORSE_cgels_Tile routine.
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
int MORSE_Alloc_Workspace_cgels_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgeqrf - Allocates workspace for MORSE_cgeqrf or
 *  MORSE_cgeqrf_Tile routine.
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
int MORSE_Alloc_Workspace_cgeqrf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgeqrf_Tile - Allocates tile workspace for
 *  MORSE_cgels_Tile routine.
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
int MORSE_Alloc_Workspace_cgeqrf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgelqf - Allocates workspace for MORSE_cgelqf or
 *  MORSE_cgelqf_Tile routines.
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
int MORSE_Alloc_Workspace_cgelqf(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgelqf_Tile - Allocates tile workspace for MORSE_cgels_Tile routine.
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
int MORSE_Alloc_Workspace_cgelqf_Tile(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGELS, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgesv - Allocates workspace for MORSE_cgesv or
 *  MORSE_cgesv_Tile routines.
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
int MORSE_Alloc_Workspace_cgesv_incpiv(int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(N, N, MORSE_FUNC_CGESV, MorseComplexFloat, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgesv_Tile - Allocates workspace for MORSE_cgesv_Tile
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
int MORSE_Alloc_Workspace_cgesv_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_CGESV, MorseComplexFloat, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgesvd - Allocates workspace for MORSE_cgesvd or
 *  MORSE_cgesvd_Tile routine.
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
int MORSE_Alloc_Workspace_cgesvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CGESVD, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgetrf_incpiv - Allocates workspace for
 *  MORSE_cgetrf_incpiv or MORSE_cgetrf_incpiv_Tile or
 *  MORSE_cgetrf_incpiv_Tile_Async routines.
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
 * @sa MORSE_cgetrf_incpiv
 * @sa MORSE_cgetrf_incpiv_Tile
 * @sa MORSE_cgetrf_incpiv_Tile_Async
 *
 ******************************************************************************/
int MORSE_Alloc_Workspace_cgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV) {
    return morse_alloc_ipiv(M, N, MORSE_FUNC_CGESV, MorseComplexFloat, descL, (void**)IPIV); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cgetrf_incpiv_Tile - Allocates workspace for
 *  MORSE_cgesv_incpiv_Tile or MORSE_cgesv_incpiv_Tile_Async routines.
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
int MORSE_Alloc_Workspace_cgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV)
{
    return morse_alloc_ipiv(N, N, MORSE_FUNC_CGESV, MorseComplexFloat, descL, (void**)IPIV);
}
/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cheev - Allocates workspace for MORSE_cheev or MORSE_cheev_Tile routine.
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
int MORSE_Alloc_Workspace_cheev(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CHEEV, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_cheevd - Allocates workspace for MORSE_cheevd or MORSE_cheevd_Tile routine.
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
int MORSE_Alloc_Workspace_cheevd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CHEEVD, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_chegv - Allocates workspace for MORSE_chegv or MORSE_chegv_Tile routine.
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
int MORSE_Alloc_Workspace_chegv(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_ZHEGV, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_chegvd - Allocates workspace for MORSE_chegvd or MORSE_chegvd_Tile routine.
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
int MORSE_Alloc_Workspace_chegvd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CHEGVD, MorseComplexFloat, descT); }

/** ***************************************************************************
 *
 * @ingroup Workspace
 *
 *  MORSE_Alloc_Workspace_chetrd - Allocates workspace for MORSE_chetrd or MORSE_chetrd_Tile routine.
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
int MORSE_Alloc_Workspace_chetrd(int M, int N, MORSE_desc_t **descT) {
    return morse_alloc_ibnb_tile(M, N, MORSE_FUNC_CHETRD, MorseComplexFloat, descT); }
