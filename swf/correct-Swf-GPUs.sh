#!/bin/bash

declare -a apps=( sgetrf_nopiv sgetrs_nopiv slange sposv spotrf spotri spotrs )

for app in "${apps[@]}"; do
    mkdir -p GPUs/${app}
    for TILE in 64 128 256 320 512 640 768 960 ; do
        for i in 1 5 10 20 50 100; do
            diffInputfile=../diff/CPU-GPU/${app}/${app}-${TILE}-${i}.csv
            swfInputfile=./GPUs/${app}/${app}-${TILE}-${i}.swf
            outputfile=./GPUs/${app}/${app}-${TILE}-${i}.swf                        

            cat $diffInputfile | awk '{print $9 }' >  TempDiff
            cat $swfInputfile  | awk '{print $1, $4}' > TempSwf
            paste TempDiff TempSwf > Temp
            cat Temp  | awk '{print $2 - $1, -1, -1, $3 -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $outputfile

            
        done
    done
done
rm TempDiff TempSwf Temp
