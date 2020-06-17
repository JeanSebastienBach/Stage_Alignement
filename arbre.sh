# Utilisation : ./arbre.sh -l taille -n nombre_sequence

clear
g++ alignementMultiple.cpp -Wall -o alignementMultiple
g++ generation.cpp -Wall -o generation
g++ comparaisonMast.cpp -Wall -o comparaisonMast
g++ comparaisonZS.cpp -Wall -o comparaisonZS
./generation $@ -o resultat.txt -f -om arbreMutation.dot
./alignementMultiple -o arbre.dot -is resultat.txt
dot -Tpng arbre.dot > arbre.png
dot -Tpng arbreMutation.dot > arbreMutation.png
./comparaisonZS -am arbre.dot -ag arbreMutation.dot