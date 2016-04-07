#!/bin/bash
#MSUB -r myjob
#MSUB -n 16
#MSUB -N 16
#MSUB -c 32 
#MSUB -T 600
#MSUB -o out.16x32
#MSUB -e err.16x32
#MSUB -q xlarge
#MSUB -A gen1567

set -x
ccc_mprun uname -a
ccc_mprun ./workdir/ricar/src/example/bin/simple -rsa ./matrix/audi.rsa -t 32 -v 4 
