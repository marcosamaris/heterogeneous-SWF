#!/bin/bash
if [[ $# < 2 ]];then
	echo "Usage: ./read_data.sh <output_folder> <solver>_<method>"
fi
folder=$1
s=`echo $2 | cut -d '_' -f 1`
method=`echo $2 | cut -d '_' -f 2`
echo Method $method

mkdir -p data
datafile="data/${s}_${method}.dat"
echo Writing in $datafile
name=$(echo "cat //solver/methods/method[@id=\"$method\"]/@name" | xmllint --shell $s.xml | awk -F'[="]' '!/>/{print $(NF-1)}' | sed '1d;q')
echo Solver $s
echo Solver $s > $datafile
echo Method Name $name
echo Method $name >> $datafile

echo -e "#\t procs\t size\t facto\t solve\t memory\t nnz\t err" >> ${datafile}
files=""
facto="inf"
Bytes="inf"
nnz="inf"
err="inf"
facto_pattern="Time to factorize|Timer Assemblage|timer LU"
solve_pattern="Time to solve|Timer Solveur|timer Solution"
# memory_pattern="Memory used after factorization"

for file in ./$folder/*_${s}_${method}*;
do
	procs=`echo $file | egrep -o [0-9]+ | sed '1d;q' `
	size=`echo $file | egrep -o [0-9]+ | sed '2d;q'`
	if [ "$procs" == "" ];then procs=1; fi
	line="\t $procs\t $size"

	facto=`cat $file | grep -E "$facto_pattern" | egrep -o '[0-9]+[.]*[0-9]*'`
	solve=`cat $file | grep -E "$solve_pattern" | egrep -o '[0-9]+[.]*[0-9]*'`
	# echo $facto
	if [ "$method" == "pastix" ]; then
		size=`cat $file | grep -E '^[ ]*Memory used after factorization' | tr -s ' ' | cut -d ' ' -f 6`
		unit_str=`cat $file | grep -E '^[ ]*Memory used after factorization' | tr -s ' ' | cut -d ' ' -f 7`
		if [ "$unit_str" == "MB" ]; then
			unit=1000000
		elif [ "$unit_str" == "GB" ]; then
			unit=1000000000
		else
			continue
		fi
		Bytes=$(echo "${size}*${unit}" | bc)
		nnz=`cat $file | grep -E 'Number of nonzeros \(local block structure\)' | tr -s ' ' | cut -d ' ' -f 9`
		nnz=$(echo "${nnz}*2" | bc)
		# echo $nnz
		err=`cat $file | grep 'Precision : ||ax -b||/||b||' | tr -s ' ' | cut -d ' '  -f 6`
		# cat $file  | grep -E '^[ ]*Memory used after factorization' 
	else
		# cat $file | grep '||Ax-b||/||b||' | tr -s ' ' | cut -d ' '  -f 2 
		err=`cat $file | grep '||Ax-b||/||b||' | tr -s ' ' | cut -d ' '  -f 2`
		if [ "$err" == "" ]; then
			err=`cat $file | grep '|| Ax - b || / || b ||' | tr -s ' ' | cut -d ' '  -f 10`
		fi
		if [ "$err" == "" ]; then
			err=`cat $file | grep '^.*relative_L2' | tr -s ' ' | cut -d ' '  -f 2`
		fi

		#search for stored values before and after factorization and non zeros
		before=`cat $file | awk '/Stats 1/,/full Zeros/' | grep '^.*stored values' | tr -s ' ' | cut -d ' '  -f 5`
		Bytes=`cat $file | awk '/Stats 2/,/full Zeros/' | grep 'Memory' | tr -s ' ' | cut -d ' '  -f 3`
		nnz=`cat $file | awk '/Stats 2/,/full Zeros/' | grep '^.*non-zero values' | tr -s ' ' | cut -d ' '  -f 4`
		if [ "$Bytes" == "" ]; then
			after_mem=`cat $file | awk '/Stats 2/,/full Zeros/' | grep '^.*stored values' | tr -s ' ' | cut -d ' '  -f 4`
			# echo $nnz
			if [ "$after_mem" == ":" ]; then
				after_mem=`cat $file | awk '/Stats 2/,/full Zeros/' | grep '^.*stored values' | tr -s ' ' | cut -d ' '  -f 5`
				nnz=`cat $file | awk '/Stats 2/,/full Zeros/' | grep '^.*non-zero values' | tr -s ' ' | cut -d ' '  -f 5`
			fi
			if [ "$after_mem" == "" ]; then
				before=`cat $file | awk '/Stats 1/,/fullRkRatio/' | grep '^.*stored values' | tr -s ' ' | cut -d ' '  -f 5`
				after_mem=`cat $file | awk '/Stats 2/,/fullRkRatio/' | grep '^.*stored values' | tr -s ' ' | cut -d ' '  -f 5`
				nnz=`cat $file | awk '/Stats 2/,/fullRkRatio/' | grep '^.*non-zero values' | tr -s ' ' | cut -d ' '  -f 5`
			fi
			if [ "$after_mem" != "" ]; then
				Bytes=$(echo "${after_mem}*16" | bc)
			fi
		fi
		# echo $Bytes
	fi
	for i in "$facto" "$solve" "$Bytes" "$nnz" "$err";
	do
		if [ "$i" == "" ]; then
			i="inf"
		fi
		line="$line\t $i"
	done
	echo -e $line >> ${datafile}
	# echo $err >> err_${method}.dat
	# echo $facto >> facto_${method}.dat
	files="$files ${datafile}"
done
for file in $files;
do
	sort -snk1,1 -k2,2 $file -o $file
done