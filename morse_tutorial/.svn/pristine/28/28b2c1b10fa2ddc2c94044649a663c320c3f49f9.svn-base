#!/bin/bash
config_file=config_tests.in
while [[ $# > 0 ]]
do
	key="$1"
	case $key in
	-h|--help)
		echo "Script to define new tests campaign to plot"
		echo "Options are:"
		echo "-t  : Campaign name"
		echo "-m  : Methods to test (default: default)"
		exit 0;;
	-t|--test)
		TESTS_FOLDER="$2"
	    shift;;
	-m|--method)
		while [[ $# > 1 ]] && [[ "$2" != -* ]]
		do
			METHODS="$METHODS $2"
			shift
		done
	    shift;;
	-p|--params)
		while [[ $# > 1 ]] && [[ "$2" != -* ]]
		do
			PARAMS="$PARAMS $2"
			shift
		done
	    shift;;
	esac
    shift
done

if [ ! -f ${config_file} ];then
	TESTS_FOLDER=${TESTS_FOLDER:-outputs/`ls -t outputs/ | head -1`}
	echo -e "TESTS_FOLDER=${TESTS_FOLDER}" 	>  ${config_file}
	METHODS=${METHODS:-default}
	echo -e "METHODS=$METHODS" >>  ${config_file}
	PARAMS=${PARAMS:-default}
	echo -e "PARAMS=$PARAMS" >>  ${config_file}
	exit 0
fi
if [ "$TESTS_FOLDER" != "" ];then
	sed -i "/TESTS_FOLDER=/c\TESTS_FOLDER=${TESTS_FOLDER}"  ${config_file}
fi
if [ "$METHODS" != "" ];then
	sed -i "/METHODS/c\METHODS=$METHODS"  ${config_file}
fi
if [ "$PARAMS" != "" ];then
	sed -i "/PARAMS/c\PARAMS=$PARAMS"  ${config_file}
fi
