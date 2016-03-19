#!/bin/bash

declare -a apps=(spotrf sgetrf_nopiv sgeqrf)

for app in "${apps[@]}"; do
    mkdir -p CPUs/${app}
    for TILE in 64 128 256 320 512 640 768 960 ; do
        for i in 1 8 20 50 100; do
            inputfile=../csv/${app}/${app}-${TILE}-${i}.csv
            outputfile=./CPUs/${app}/${app}-${TILE}-${i}.swf            
            if [ -f $inputfile ];
                then                
                grep  M${TILE}x${TILE} $inputfile > Temp
                sed 's/,//g'  Temp > Temp1
                sort -k11 -n Temp1 > Temp
                cat Temp  | awk '{print $11, -1, -1, $6 -1, -1, -1 ,-1 ,-1 ,-1 ,-1 ,-1, -1, -1, -1, -1, -1, -1, -1}' > $outputfile
            fi
            
        done
    done
done
rm Temp Temp1
