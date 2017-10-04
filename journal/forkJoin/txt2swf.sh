#!/bin/bash

mkdir -p swf/CPU/
mkdir -p swf/GPU1/
mkdir -p swf/GPU2/

for i in 2 5 10 20 30 40 50; do
    for j in 100 200 300 400 500; do
        inputfile=./txt/forkjoin-$i-$j.txt
        
        CPUoutputfile=./swf/CPU/forkjoin-$i-$j.swf
        GPU1outputfile=./swf/GPU1/forkjoin-$i-$j.swf
	GPU2outputfile=./swf/GPU2/forkjoin-$i-$j.swf
        
	echo $inputfile
        if [ -f $inputfile ];
            then                

            cat $inputfile  | awk '{print $1, -1, -1, $2, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $CPUoutputfile
            cat $inputfile  | awk '{print $1, -1, -1, $3, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $GPU1outputfile        
            cat $inputfile  | awk '{print $1, -1, -1, $4, -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $GPU2outputfile


	fi
        
    done
done

