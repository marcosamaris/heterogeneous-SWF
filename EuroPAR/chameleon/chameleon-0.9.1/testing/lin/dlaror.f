!!!
!
! -- Inria
! -- (C) Copyright 2012
!
! This software is a computer program whose purpose is to process
! Matrices Over Runtime Systems @ Exascale (MORSE). More information
! can be found on the following website: http://www.inria.fr/en/teams/morse.
! 
! This software is governed by the CeCILL-B license under French law and
! abiding by the rules of distribution of free software.  You can  use, 
! modify and/ or redistribute the software under the terms of the CeCILL-B
! license as circulated by CEA, CNRS and INRIA at the following URL
! "http://www.cecill.info". 
! 
! As a counterpart to the access to the source code and  rights to copy,
! modify and redistribute granted by the license, users are provided only
! with a limited warranty  and the software's author,  the holder of the
! economic rights,  and the successive licensors  have only  limited
! liability. 
! 
! In this respect, the user's attention is drawn to the risks associated
! with loading,  using,  modifying and/or developing or reproducing the
! software by the user in light of its specific status of free software,
! that may mean  that it is complicated to manipulate,  and  that  also
! therefore means  that it is reserved for developers  and  experienced
! professionals having in-depth computer knowledge. Users are therefore
! encouraged to load and test the software's suitability as regards their
! requirements in conditions enabling the security of their systems and/or 
! data to be ensured and,  more generally, to use and operate it in the 
! same conditions as regards security. 
! 
! The fact that you are presently reading this means that you have had
! knowledge of the CeCILL-B license and that you accept its terms.
!
!!!

      SUBROUTINE DLAROR( SIDE, INIT, M, N, A, LDA, ISEED, X, INFO )
*
*  -- LAPACK auxiliary test routine (version 3.1) --
*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd..
*     November 2006
*
*     .. Scalar Arguments ..
      CHARACTER          INIT, SIDE
      INTEGER            INFO, LDA, M, N
*     ..
*     .. Array Arguments ..
      INTEGER            ISEED( 4 )
      DOUBLE PRECISION   A( LDA, * ), X( * )
*     ..
*
*  Purpose
*  =======
*
*  DLAROR pre- or post-multiplies an M by N matrix A by a random
*  orthogonal matrix U, overwriting A.  A may optionally be initialized
*  to the identity matrix before multiplying by U.  U is generated using
*  the method of G.W. Stewart (SIAM J. Numer. Anal. 17, 1980, 403-409).
*
*  Arguments
*  =========
*
*  SIDE    (input) CHARACTER*1
*          Specifies whether A is multiplied on the left or right by U.
*          = 'L':         Multiply A on the left (premultiply) by U
*          = 'R':         Multiply A on the right (postmultiply) by U'
*          = 'C' or 'T':  Multiply A on the left by U and the right
*                          by U' (Here, U' means U-transpose.)
*
*  INIT    (input) CHARACTER*1
*          Specifies whether or not A should be initialized to the
*          identity matrix.
*          = 'I':  Initialize A to (a section of) the identity matrix
*                   before applying U.
*          = 'N':  No initialization.  Apply U to the input matrix A.
*
*          INIT = 'I' may be used to generate square or rectangular
*          orthogonal matrices:
*
*          For M = N and SIDE = 'L' or 'R', the rows will be orthogonal
*          to each other, as will the columns.
*
*          If M < N, SIDE = 'R' produces a dense matrix whose rows are
*          orthogonal and whose columns are not, while SIDE = 'L'
*          produces a matrix whose rows are orthogonal, and whose first
*          M columns are orthogonal, and whose remaining columns are
*          zero.
*
*          If M > N, SIDE = 'L' produces a dense matrix whose columns
*          are orthogonal and whose rows are not, while SIDE = 'R'
*          produces a matrix whose columns are orthogonal, and whose
*          first M rows are orthogonal, and whose remaining rows are
*          zero.
*
*  M       (input) INTEGER
*          The number of rows of A.
*
*  N       (input) INTEGER
*          The number of columns of A.
*
*  A       (input/output) DOUBLE PRECISION array, dimension (LDA, N)
*          On entry, the array A.
*          On exit, overwritten by U A ( if SIDE = 'L' ),
*           or by A U ( if SIDE = 'R' ),
*           or by U A U' ( if SIDE = 'C' or 'T').
*
*  LDA     (input) INTEGER
*          The leading dimension of the array A.  LDA >= max(1,M).
*
*  ISEED   (input/output) INTEGER array, dimension (4)
*          On entry ISEED specifies the seed of the random number
*          generator. The array elements should be between 0 and 4095;
*          if not they will be reduced mod 4096.  Also, ISEED(4) must
*          be odd.  The random number generator uses a linear
*          congruential sequence limited to small integers, and so
*          should produce machine independent random numbers. The
*          values of ISEED are changed on exit, and can be used in the
*          next call to DLAROR to continue the same random number
*          sequence.
*
*  X       (workspace) DOUBLE PRECISION array, dimension (3*MAX( M, N ))
*          Workspace of length
*              2*M + N if SIDE = 'L',
*              2*N + M if SIDE = 'R',
*              3*N     if SIDE = 'C' or 'T'.
*
*  INFO    (output) INTEGER
*          An error flag.  It is set to:
*          = 0:  normal return
*          < 0:  if INFO = -k, the k-th argument had an illegal value
*          = 1:  if the random numbers generated by DLARND are bad.
*
*  =====================================================================
*
*     .. Parameters ..
      DOUBLE PRECISION   ZERO, ONE, TOOSML
      PARAMETER          ( ZERO = 0.0D+0, ONE = 1.0D+0,
     $                   TOOSML = 1.0D-20 )
*     ..
*     .. Local Scalars ..
      INTEGER            IROW, ITYPE, IXFRM, J, JCOL, KBEG, NXFRM
      DOUBLE PRECISION   FACTOR, XNORM, XNORMS
*     ..
*     .. External Functions ..
      LOGICAL            LSAME
      DOUBLE PRECISION   DLARND, DNRM2
      EXTERNAL           LSAME, DLARND, DNRM2
*     ..
*     .. External Subroutines ..
      EXTERNAL           DGEMV, DGER, DLASET, DSCAL, XERBLA
*     ..
*     .. Intrinsic Functions ..
      INTRINSIC          ABS, SIGN
*     ..
*     .. Executable Statements ..
*
      IF( N.EQ.0 .OR. M.EQ.0 )
     $   RETURN
*
      ITYPE = 0
      IF( LSAME( SIDE, 'L' ) ) THEN
         ITYPE = 1
      ELSE IF( LSAME( SIDE, 'R' ) ) THEN
         ITYPE = 2
      ELSE IF( LSAME( SIDE, 'C' ) .OR. LSAME( SIDE, 'T' ) ) THEN
         ITYPE = 3
      END IF
*
*     Check for argument errors.
*
      INFO = 0
      IF( ITYPE.EQ.0 ) THEN
         INFO = -1
      ELSE IF( M.LT.0 ) THEN
         INFO = -3
      ELSE IF( N.LT.0 .OR. ( ITYPE.EQ.3 .AND. N.NE.M ) ) THEN
         INFO = -4
      ELSE IF( LDA.LT.M ) THEN
         INFO = -6
      END IF
      IF( INFO.NE.0 ) THEN
         CALL XERBLA( 'DLAROR', -INFO )
         RETURN
      END IF
*
      IF( ITYPE.EQ.1 ) THEN
         NXFRM = M
      ELSE
         NXFRM = N
      END IF
*
*     Initialize A to the identity matrix if desired
*
      IF( LSAME( INIT, 'I' ) )
     $   CALL DLASET( 'Full', M, N, ZERO, ONE, A, LDA )
*
*     If no rotation possible, multiply by random +/-1
*
*     Compute rotation by computing Householder transformations
*     H(2), H(3), ..., H(nhouse)
*
      DO 10 J = 1, NXFRM
         X( J ) = ZERO
   10 CONTINUE
*
      DO 30 IXFRM = 2, NXFRM
         KBEG = NXFRM - IXFRM + 1
*
*        Generate independent normal( 0, 1 ) random numbers
*
         DO 20 J = KBEG, NXFRM
            X( J ) = DLARND( 3, ISEED )
   20    CONTINUE
*
*        Generate a Householder transformation from the random vector X
*
         XNORM = DNRM2( IXFRM, X( KBEG ), 1 )
         XNORMS = SIGN( XNORM, X( KBEG ) )
         X( KBEG+NXFRM ) = SIGN( ONE, -X( KBEG ) )
         FACTOR = XNORMS*( XNORMS+X( KBEG ) )
         IF( ABS( FACTOR ).LT.TOOSML ) THEN
            INFO = 1
            CALL XERBLA( 'DLAROR', INFO )
            RETURN
         ELSE
            FACTOR = ONE / FACTOR
         END IF
         X( KBEG ) = X( KBEG ) + XNORMS
*
*        Apply Householder transformation to A
*
         IF( ITYPE.EQ.1 .OR. ITYPE.EQ.3 ) THEN
*
*           Apply H(k) from the left.
*
            CALL DGEMV( 'T', IXFRM, N, ONE, A( KBEG, 1 ), LDA,
     $                  X( KBEG ), 1, ZERO, X( 2*NXFRM+1 ), 1 )
            CALL DGER( IXFRM, N, -FACTOR, X( KBEG ), 1, X( 2*NXFRM+1 ),
     $                 1, A( KBEG, 1 ), LDA )
*
         END IF
*
         IF( ITYPE.EQ.2 .OR. ITYPE.EQ.3 ) THEN
*
*           Apply H(k) from the right.
*
            CALL DGEMV( 'N', M, IXFRM, ONE, A( 1, KBEG ), LDA,
     $                  X( KBEG ), 1, ZERO, X( 2*NXFRM+1 ), 1 )
            CALL DGER( M, IXFRM, -FACTOR, X( 2*NXFRM+1 ), 1, X( KBEG ),
     $                 1, A( 1, KBEG ), LDA )
*
         END IF
   30 CONTINUE
*
      X( 2*NXFRM ) = SIGN( ONE, DLARND( 3, ISEED ) )
*
*     Scale the matrix A by D.
*
      IF( ITYPE.EQ.1 .OR. ITYPE.EQ.3 ) THEN
         DO 40 IROW = 1, M
            CALL DSCAL( N, X( NXFRM+IROW ), A( IROW, 1 ), LDA )
   40    CONTINUE
      END IF
*
      IF( ITYPE.EQ.2 .OR. ITYPE.EQ.3 ) THEN
         DO 50 JCOL = 1, N
            CALL DSCAL( M, X( NXFRM+JCOL ), A( 1, JCOL ), 1 )
   50    CONTINUE
      END IF
      RETURN
*
*     End of DLAROR
*
      END
