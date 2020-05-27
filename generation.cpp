#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;
string nucleotideHasard(float matriceProba[]){
	srand(time(NULL));
	int p = rand() % 1001;
	if(p<=matriceProba[0]*1000){
		return "A";
	}
	else if(p<=(matriceProba[0]+matriceProba[1])*1000){
		return "C";
	}
	else if(p<=(matriceProba[0]+matriceProba[1]+matriceProba[2])*1000){
		return "G";
	}
	else{
		return "T";
	}
}

string generation(int t){
	string sequence = "";
	int x=0;

	if(t>1){
		// Nucléotide de départ 
		float teteSequence[4] = {0.250,0.250,0.250,0.250};
		sequence += nucleotideHasard(teteSequence);
		x++;
	}

	while(t>x){
		char dernierNucleotide = sequence.back();
		float sequenceA[4] = {0.300,0.205,0.285,0.210};
		float sequenceC[4] = {0.322,0.298,0.078,0.302};
		float sequenceG[4] = {0.248,0.246,0.298,0.208};
		float sequenceT[4] = {0.177,0.239,0.292,0.292};

		if(dernierNucleotide=='A'){
			sequence += nucleotideHasard(sequenceA);
		}
		else if(dernierNucleotide=='C'){
			sequence += nucleotideHasard(sequenceC);
		}
		else if(dernierNucleotide=='G'){
			sequence += nucleotideHasard(sequenceG);
		}
		else if(dernierNucleotide=='T'){
			sequence += nucleotideHasard(sequenceT);
		}
		x++;
	}

	return sequence;
} 

vector<string> generationMutation(string s,int nbSeq){
	vector<string> res;
	res.push_back(s);
	
	float probaMutationNucleo = 0.016;
	int valeurGenerer = 0;
	int x = 0;
	int nbModifNucleotide = 0;
	char ancienNucleotide ="";
	while (res.size()<nbSeq){
		string nouvelleSeq="";
		for(int i=0;i<res.size();i++){
			nouvelleSeq=res[i];
			nbModifNucleotide = 0;
			for(int j=0;j<nouvelleSeq.size();j++){
				srand(time(NULL)+x);
				x++;
				valeurGenerer = rand() % 10001;
				if(valeurGenerer <= probaMutationNucleo*10000){
					ancienNucleotide = nouvelleSeq[j];
					nbModifNucleotide++;
				}
				
			}
		}
	}
	
	return res;
}

int main(int argc, char** argv,char** env){
	if(argc<4){
		cout<<"La génération nécessite <mode> <taille_des_séquences_à_générer> <nombre_de_séquences_à_générer> "<<endl;
	}else {
		string s ="";
		int tailleSeq = stoi(argv[2]);
		int nbSeq = stoi(argv[3]);
		if (stoi(argv[1])==1){
			while(s.size()!=tailleSeq){
				
				cout<<"Veuillez saisir une séquence de taille "<<tailleSeq<<" : ";
				cin>>s;
			}
		}else{
			
			s = generation(tailleSeq);
			cout<<s<<endl;
		}
		vector<string> ensembleSeq = generationMutation(s,nbSeq);
		for(int i=0;i<ensembleSeq.size();i++){
			cout<<"S["<<i<<"]="<<ensembleSeq[i]<<endl;
		}
	}
	
	return 0;
}