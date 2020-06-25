#!/bin/bash


clear
HELP="comparaisonBash.sh			Manuel d'utilisation			comparaisonBash.sh \n "
set -e

while [[ $# > 0 ]] 
do

	if  [[ '-' == "${1:0:1}" ]] 
	then
		case "${1}" in
    	    -h|--help)
    	        echo "${HELP}"
    	        exit 0
    	    ;;
    	    -am)
    	    	if [[ $# > 1 ]] 
    	    	then
    	    		shift
    	        	optionAm=${1}
    	        else 
    	        	echo "${HELP}"
    	        	exit 0
    	        fi
    	    ;;
    	    -ag)
    	    	if [[ $# > 1 ]] 
    	    	then
    	    		shift
    	        	optionAg=${1}
    	        else 
    	        	echo "${HELP}"
    	        	exit 0
    	        fi
    	    ;;
    		*)
    	      echo "Invalid \"${1}\" option. See ${0} --help"
    	      exit 1
    	   ;;
    	esac
    fi
    shift
done

old_IFS=$IFS # sauvegarde du séparateur de champ
IFS=$'\n' # nouveau séparateur de champ, le caractère fin de ligne
match=false
difference=0
nbTotal=0
if [[ -f "$optionAg" ]] && [[ -f "$optionAm" ]]
then
	for i in $(cat $optionAg)
	do 
		if [[ "${i:0:2}" == "//" ]]
		then

			chaineUn="${i:2:${#i}-4}"
			nbTotal=$(($nbTotal + 1))
			for j in $(cat $optionAm)
			do	
				if [[ "${j:0:2}" == "//" ]]
				then
					chaineDeux="${j:2:${#i}-4}"
					if [[ $chaineUn == $chaineDeux ]]
					then
						match=true
					fi
				fi
			done
			if [[ $match == true ]]
			then
				match=false
			else
				difference=$(($difference + 1))
			fi
		fi
	done
else
	echo aïe
fi
echo $difference / $nbTotal
IFS=$old_IFS # rétablissement du séparateur de champ par défaut