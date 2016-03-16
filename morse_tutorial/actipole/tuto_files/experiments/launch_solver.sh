#username
WORKDIR=${WORKDIR:-$PWD/`dirname $0`}
echo $WORKDIR
#default values
method=default
s=solver
#directory where matrices are stored
MATRIX_DIR=${MATRIX_DIR:-$WORKDIR/matrices}
if [ ! -d $MATRIX_DIR ]; then
	echo Did not found $MATRIX_DIR
	exit 1
fi
type=size
np=1
opt=" "
var=0

OUTPUTS=${OUTPUTS:-$WORKDIR/outputs}
mkdir -p $OUTPUTS
echo "-- On" `hostname` ": PLAFRIM =" $PLAFRIM "; outputs = $OUTPUTS"
if [ "$BATCH" != "" ];then
	batch=$WORKDIR/${BATCH}_batch
else
	batch=$WORKDIR/slurm_batch
fi

#reading args
while [[ $# > 0 ]]
do
	key="$1"
	case $key in
	-h|--help)
		echo "Options are:"
		echo -e "--<solver>     \t: use like this: --pastix, etc"
		echo -e "-e <extension> \t: matrix extension type (.mtx, .p01 ...)"
		echo -e "-m <matrices>  \t: input matrices"
		echo -e "-o <options>   \t: list of options (put last on command line)"
		echo -e "-p <method>    \t: method used"
		echo -e "-t <test>      \t: matrix test (directory in $MATRIX_DIR)"
		echo -e "-type <type>   \t: type of test (size, err)"
		echo -e "-var <var>     \t: variable name (to use with -in)"
		echo -e "-in <values>   \t: values for <var>"
		exit 0
		;;
	--*)
	    s=`echo $1 | cut -c 3-`
	    ;;
	-p)
	    method="$2"
	    shift;;
	-n)
	    np=$2
	    shift;;
	-type)
	    type="$2"
	    shift;;
	-e)
	    matrix_ext="$2"
	    shift;;
	-t)
	    test="$2"
	    shift;;
	-var)
		varname="-$2"
		shift;;
	-in)
		var=
		while [[ $# > 1 ]] && [[ "$2" != -* ]]
		do
			var="$var $2"
			shift
		done
	    shift;;
	-m)
	    matrices=
	    while [[ $# > 1 ]] && [[ "$2" != -* ]]
	    do
	    	matrices="$matrices $2"
	    	shift
	    done
	    shift;;
	-o)
	    options=
	    while [[ $# > 1 ]]
	    do
    		opt="$opt $2"
    		shift
	    done
	    shift;;
    esac
    shift
done


#read default values from xml
echo Reading $WORKDIR/$s.xml
solver_bin=$(xmllint --xpath '//solver/bin[@id="solver"]/@name' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}')
verif=$(xmllint --xpath '//solver/bin[@id="verif"]/@name' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}')
driver=$(xmllint --xpath '//solver/@driver' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}')
matrix_ext=$(xmllint --xpath '//solver/@extension' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}' )
opt="$opt $(xmllint --xpath '//solver/options/@default' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}' )"

echo bin $solver_bin

if [ "$test" == "" ];then
	# nbTests=$(xmllint --xpath 'count(//solver/test)' $WORKDIR/$s.xml| awk -F'[="]' '!/>/{print $(NF-1)}' )
	# declare -a description=( )

	# for (( i=1; i < $itemsCount; i++ )); do 
	# 	description[$i]="$(xmllint --xpath '//item['$i']/description' /tmp/so.xml)"
	# done
	test=$(xmllint --xpath  '//solver/test/@id' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}')
fi
opt="$opt $(xmllint --xpath '//solver/methods/method[@id="$method"]/@options' $WORKDIR/$s.xml | awk -F'[="]' '!/>/{print $(NF-1)}' )"

cd $OUTPUTS
echo "test_dir " $OUTPUTS/$test
mkdir -p $test
cd $test

dir=$MATRIX_DIR/$test
echo matrix_dir $MATRIX_DIR/$test
files=`\ls $dir | sort -h`
if [ "$matrices" == "" ];then
	matrices=$files # default values
fi

echo Testing: $matrices
#starting jobs
for i in $var
do
	echo At $varname = $i
	for j in $matrices
	do
		echo At matrix $j
		#wait for slots to be free when using jobs
		$QUEUE | grep $USER | wc -l
		while true; do
			if [ `$QUEUE | grep $USER | wc -l` -lt 5  ]; then
				break
			fi
			sleep 1
		done

		if ! [[ $test = ^[0-9]+ ]]; then
			size=$j
		fi

		#walltime
		if [ -d "$batch" ];then
			sed -r -i "s/nodes=[0-9]+/nodes=${np}/g" $batch
			sed -r -i "s/-n [0-9]+/-n ${np}/g" $batch
		fi

		input=$dir/$j/$j$matrix_ext
		out=${OUTPUTS}/${test}/${BATCH}_${s}_${method}_${j}_${np}
		options="$opt"
		date=`date +%Y%m%d_%H%M%S`
		echo Running $s $np $solver_bin $driver $input $varname $i $options
		if [ "$PLAFRIM" == 1 ]; then
			qsub -v s="$s",np="$np",test="$test",input="${input}",out="$out",e="$ext ",o="${options}" -N "${out}" $batch
		elif [ "$PLAFRIM" == 2 ];then
			(set -x; sbatch  -J "${s}_${np}_${method}_${j} ${options}" -o "${out}.o$date" -e "${out}.e$date" $batch $s $np $solver_bin $driver $input "$varname" $i $options)
		else
			(set -x; $WORKDIR/run_$s.sh $np $solver_bin $driver $input "$varname" $i $options > ${out}.o$date)
		fi
	done
done