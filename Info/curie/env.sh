module purge
module load ccc
module load dfldatadir/own
module load c/intel/14.0.3.174
module load fortran/intel/14.0.3.174
module load idb/14.0.3.174
module load bullxmpi/1.2.7.2
module load datadir/own
module load licsrv/intel
module load c++/intel/14.0.3.174
module load mkl/14.0.3.174
module load intel/14.0.3.174
module load cuda/5.5.22
module load cmake/2.8.9
module load hwloc/1.7.1

export CFLAGS="-I$C_INCDIR"
export NVCCFLAGS="-ccbin=icc"
export LD=xild
export CC=icc
export FC=ifort
export CXX=icpc
export STARPU_DIR=/ccc/cont003/home/gen1567/lacoste/work/starpu_svn/trunk-install/
#export STARPU_DIR=$WORKDIR/starpu_svn/branches/starpu-1.1/bullxmpi-intel-install
export PKG_CONFIG_PATH=$STARPU_DIR/lib/pkgconfig/:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$STARPU_DIR/lib/:$LD_LIBRARY_PATH
export INCLUDE=/usr/local/intel-14.0.3.174/14.0.3.174/mkl/include:$STARPU_DIR/include/:$INCLUDE
export PATH=$STARPU_DIR/bin:$PATH
export SCOTCH_HOME=/ccc/work/cont003/gen1567/lacoste/scotch_5.1.12/int64
export HWLOC_PLUGINS_PATH=nimportequoi
