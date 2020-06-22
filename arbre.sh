#!/bin/bash
# Utilisation : ./arbre.sh -l taille -n nombre_sequence

clear
g++ alignementMultiple.cpp -Wall -o alignementMultiple
g++ generation.cpp -Wall -o generation
nomDeFichier=$(date +%Y%m%d)
./generation $@ -o resultat.txt -f -om arbreMutation.dot > $nomDeFichier
erreurGeneration=$(grep -c 'generation()' $nomDeFichier)
if (($erreurGeneration == 0))
then
	cat $nomDeFichier
	./alignementMultiple -o arbre.dot -is resultat.txt > $nomDeFichier
	erreurAlignement=$(grep -c 'alignement()' $nomDeFichier)
	if (($erreurAlignement == 0))
	then
		cat $nomDeFichier
		dot -Tpng arbre.dot > arbre.png
		dot -Tpng arbreMutation.dot > arbreMutation.png
	else
		echo "arbre.sh			Manuel d'utilisation			arbre.sh()" 
		cat $nomDeFichier
	fi
else
	echo "arbre.sh			Manuel d'utilisation			arbre.sh() "	
	cat $nomDeFichier
fi
rm $nomDeFichier


