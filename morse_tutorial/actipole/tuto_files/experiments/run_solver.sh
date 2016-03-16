#!/bin/bash
# Basic solver interface
# params should be: <n_procs> <binary_exe> <driver> <input_file> <matrix_extension> <options>

echo -------------------BEGIN--------------------------
pwd
mpirun -np $@
echo --------------------END---------------------------
