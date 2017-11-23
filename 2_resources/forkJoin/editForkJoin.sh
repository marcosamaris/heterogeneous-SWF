#!/bin/bash


for i in 2 5 10 20 30 40 50; do
    for j in 100 200 300 400 500; do

            rm -rf ./txt/forkjoin-$i-$j.txt
            rm -rf ./str
    
        for p in `seq 0 $(($i * $j + $i))`; do
            cat ./dot/forkjoin-$i-$j.dot | grep " -> $p;" | awk {'print $1'} > Temp
            awk '
                { 
                    for (i=1; i<=NF; i++)  {
                        a[NR,i] = $i
                    }
                }
                NF>p { p = NF }
                END {    
                    for(j=1; j<=p; j++) {
                        str=a[1,j]
                        for(i=2; i<=NR; i++){
                            str=str","a[i,j];
                        }
                        print str > "str"
                    }
                }' Temp

                ind=$(($p/$j))
                ind=$(($ind * $j + $ind))
                task1=$(($ind + 1 ))
                task2=$(($ind + 2 ))
                task3=$(($ind + 3 ))
                task4=$(($ind + 4 ))
                task5=$(($ind + 5 ))

                accel=$[(RANDOM % 100 ) + 1]            
                accel=$(echo "$accel/2" | bc -l)


                if [[ $p -eq $task1 || $p -eq $task2  || $p -eq $task3 || $p -eq $task4   || $p -eq $task5 ]]; then
                    accel=$[(RANDOM % 5 ) + 1]            
                    accel=$(echo "$accel/10" | bc -l)
                fi

                timecpu=$(python ./randomGauss.py $i $(echo "$i/4" | bc -l))
                var=$(echo $timecpu'<'0 | bc -l)
                
                while [ $var -eq 1 ]; do
                    timecpu=$(python ./randomGauss.py $i $(echo "$i/4" | bc -l))
                    var=$(echo $timecpu'<'0 | bc -l)
                done
                
                timegpu=$(echo "$timecpu/$accel" | bc -l)        

                echo "$p $timecpu $timegpu $(cat ./str)" >> ./txt/forkjoin-$i-$j.txt
        done
    done  
done
