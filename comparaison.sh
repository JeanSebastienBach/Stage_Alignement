#!/bin/bash

clear
HELP="écrire l'aide !"
set -e
optionC=false
while [[ $# > 0 ]] 
do

	if  [[ '-' == "${1:0:1}" ]] 
	then
		case "${1}" in
    	    -h|--help)
    	        echo "${HELP}"
    	        exit 0
    	    ;;
    	    -c)
    	        optionC=true
    	    ;;
    		*)
    	      echo "Invalid \"${1}\" option. See ${0} --help"
    	      exit 1
    	   ;;
    	esac
    fi
    shift
done

if [ "$optionC" = true ]
then
	g++ comparaisonZS.cpp -Wall -o comparaisonZS
	./comparaisonBash.sh -am arbre.dot -ag arbreMutation.dot
	./comparaisonZS -am arbre.dot -ag arbreMutation.dot
else
	./comparaisonBash.sh -am arbre.dot -ag arbreMutation.dot
	./comparaisonZS -am arbre.dot -ag arbreMutation.dot	
fi

