#!/bin/bash

clear
g++ alignementMultiple.cpp -Wall -o alignementMultiple
g++ generation.cpp -Wall -o generation
HELP="écrire l'aide !"
set -e
optionV=false
optionL=false
optionN=false
optionF=false
total=""
while [[ $# > 0 ]] 
do

	if  [[ '-' == "${1:0:1}" ]] 
	then
		case "${1}" in
    	    -h|--help)
    	        echo "${HELP}"
    	        exit 0
    	    ;;
    	    -v)
    	    	shift
    	        optionV=${1}
    	    ;;
    	    -n)
    	    	shift
    	        optionN=${1}
    	    ;;
    	    -l)
    	    	shift
    	        optionL=${1}
    	    ;;
    	    -f)
    	    	shift
    	        optionF=${1}
    	    ;;
    		*)
    	      echo "Invalid \"${1}\" option. See ${0} --help"
    	      exit 1
    	   ;;
    	esac
    fi
    shift
done
if [ "$optionV" != false ] && [ "$optionN" != false ] && [ "$optionL" != false ] && [ "$optionF" != false ]
then
	
	for ((i=0 ; $i<$optionV ; i++))
    do 	
		./generation -l $optionL -n $optionN -o resultat.txt -f -om arbreMutation.dot > /dev/null
		./alignementMultiple -o arbre.dot -is resultat.txt > /dev/null
		./comparaisonBash.sh -am arbre.dot -ag arbreMutation.dot -fs $optionF 
		sleep 1
	done
else
	echo "${HELP}"
fi