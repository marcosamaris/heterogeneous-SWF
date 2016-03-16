#!/bin/bash
cd `dirname $4`
echo -------------------BEGIN--------------------------
pwd
mpirun -np $@
echo -------------------VERIF--------------------------
for i in `\ls *_MAIN_*.res`; do
	mpirun -np $1 CalcEps -first $i -second $i.orig
done
if [ -f *_VOLUMIC_*.res ];then 
	for i in `\ls *_VOLUMIC_*.res`; do
		mpirun -np $1 CalcEps -first $i -second $i.orig
	done
fi
echo --------------------END---------------------------
