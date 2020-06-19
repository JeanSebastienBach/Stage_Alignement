#!/bin/bash
# Utilisation : ./alignementMultiple.sh sequence1 sequence2 ... sequenceN

clear
g++ alignementMultiple.cpp -Wall -o alignementMultiple
./alignementMultiple $@
dot -Tpng arbre.dot > arbre.png