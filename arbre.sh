# Utilisation : ./alignementMultiple.sh sequence1 sequence2 ... sequenceN

clear
g++ alignementMultiple.cpp -Wall -o alignementMultiple
g++ generation.cpp -Wall -o generation
g++ comparaison.cpp -Wall -o comparaison
./generation $@ -o resultat.txt -f -om arbreMutation.dot
./alignementMultiple -o arbre.dot -is resultat.txt
dot -Tpng arbre.dot > arbre.png
dot -Tpng arbreMutation.dot > arbreMutation.png