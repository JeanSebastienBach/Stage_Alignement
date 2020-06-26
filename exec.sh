#!/bin/bash

clear
HELP="écrire l'aide !"
set -e
tailleMax=false
tailleMin=false
nbMax=false
nbMin=false

while [[ $# > 0 ]] 
do

	if  [[ '-' == "${1:0:1}" ]] 
	then
		case "${1}" in
    	    -h|--help)
    	        echo "${HELP}"
    	        exit 0
    	    ;;
    	    -tma)
    	    	shift
    	        tailleMax=${1}
    	    ;;
    	    -tmi)
    	    	shift
    	        tailleMin=${1}
    	    ;;
    	    -nma)
    	    	shift
    	        nbMax=${1}
    	    ;;
    	    -nmi)
    	    	shift
    	        nbMin=${1}
    	    ;;
    		*)
    	      echo "Invalid \"${1}\" option. See ${0} --help"
    	      exit 1
    	   ;;
    	esac
    fi
    shift
done
if [ "$nbMax" != false ] && [ "$nbMin" != false ] && [ "$tailleMax" != false ] && [ "$tailleMin" != false ]
then
	for ((i=$tailleMin ; $i<=$tailleMax ; i++))
	do 
		echo "\\addplot " >> t-$i.txt
		echo "table[row sep=\\\,y index=0] { " >> t-$i.txt
		./stat.sh -l $i -n 35 -v 50 -f t-$i.txt
		echo "};" >> t-$i.txt
	done
	
	for ((j=$nbMin ; $j<=$nbMax ; j++))
	do 
		echo "\\addplot " >> nb-$j.txt 
		echo "table[row sep=\\\,y index=0] { " >> nb-$j.txt
		./stat.sh -l 65 -n $j -v 50 -f nb-$j.txt
		echo "};" >> nb-$j.txt
	done
else
	echo "${HELP}"
fi
