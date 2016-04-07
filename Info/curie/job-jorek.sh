#!/bin/bash
#MSUB -r IN302        # Nom du job                
#MSUB -N 4            # Nb nodes
#MSUB -n 4            # Nb processus
#MSUB -M 3500
#MSUB -c 16           # Nb thread
#MSUB -x
#MSUB -T 1800            # Limite de temps elapsed
#MSUB -e IN199_4.%J        # Erreur standard
#MSUB -o IN199_4.%J        # Sortie standard
#MSUB -Q test
#MSUB -A gen1567
#MSUB -q standard

ulimit -d unlimited
ulimit -Sa
ulimit -Ha

export OMPI_MCA_coll="^ghc"
#export OMPI_MCA_coll="^ghc,tuned"

set -vx
hostname

#module purge
module unload bullxmpi/1.2.7.2
module load mvapich2/2.0
module load hwloc

#export OMPI_MCA_coll="^ghc"
export OMPI_MCA_coll="^ghc,tuned"

# environment
#------------
ulimit -l unlimited

export OMP_NUM_THREADS=16
export KMP_NUM_THREADS=16
export KMP_AFFINITY="verbose,norespect,compact"
export KMP_STACKSIZE=128m


MODEL=199
PREFIX=res
TG=${PREFIX}${MODEL}
JOREK_HOME=${WORKDIR}/jorek/trunk

# rm -rf ${TG}
# ${JOREK_HOME}/util/nrt_duplicate.sh ae199 ${TG}

cd $JOREK_HOME
export PRERUN='export OMP_NUM_THREADS=16;export KMP_NUM_THREADS=16;export MKL_NUM_THREADS=1;export KMP_AFFINITY="verbose,norespect,compact"'
export MPIRUN="ccc_mprun"
export BASEDIR=${JOREK_HOME}
$PRERUN
util/launch_tests.sh ${TG}

