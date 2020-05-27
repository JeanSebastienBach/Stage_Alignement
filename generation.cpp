#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;
string nucleotideHasard(float matriceProba[]){
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
		return "U";
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
		float sequenceU[4] = {0.177,0.239,0.292,0.292};

		if(dernierNucleotide=='A'){
			sequence += nucleotideHasard(sequenceA);
		}
		else if(dernierNucleotide=='C'){
			sequence += nucleotideHasard(sequenceC);
		}
		else if(dernierNucleotide=='G'){
			sequence += nucleotideHasard(sequenceG);
		}
		else if(dernierNucleotide=='U'){
			sequence += nucleotideHasard(sequenceU);
		}
		x++;
	}

	return sequence;
} 

string suppressionNucleotide(string sequence,int position){
	string resultat = sequence.substr(0,position);
	resultat += sequence.substr(position+1,sequence.size());
	return resultat;
}

string duplicationNucleotide(string sequence,int position){
	string resultat = sequence.substr(0,position+1);
	resultat += sequence.substr(position,sequence.size());
	return resultat;
}

vector<string> generationMutation(string s,int nbSeq){
	vector<string> res;
	res.push_back(s);
	
	float probaMutationNucleotide = 0.016;
	float probaDuplicationNucleotide = 0.25;
	float probaSuppressionNucleotide = 0.25;
	float probaChangementNucleotide = 0.50;
	int valeurGenerer = 0;
	int x = 0;
	int nbModifNucleotide = 0;
	char ancienNucleotide;
	string nouvelleSeq="";
	string nouveauNucleotide="";
	int i = 0;
	while (res.size()<nbSeq){
		i = 0;
		while((i<res.size())&&(res.size()<nbSeq)){
			nouvelleSeq=res[i];
			for(int j=0;j<nouvelleSeq.size();j++){
				x++;
				valeurGenerer = rand() % 10001;
				if(valeurGenerer <= probaMutationNucleotide*10000){
					valeurGenerer = rand() % 1001;
					float mutationSequence[4] = {0.3333,0.3333,0.3333,0.3333};
					if(valeurGenerer <= probaDuplicationNucleotide*1000){
						nouvelleSeq = duplicationNucleotide(nouvelleSeq,j);  
					}else if(valeurGenerer <= (probaDuplicationNucleotide + probaSuppressionNucleotide)*1000){
						nouvelleSeq = suppressionNucleotide(nouvelleSeq,j);
					}else {
						ancienNucleotide = nouvelleSeq[j];
						if(ancienNucleotide=='A'){
							mutationSequence[0]=0.000;
							nouveauNucleotide = nucleotideHasard(mutationSequence);
						}else if(ancienNucleotide=='C'){
							mutationSequence[1]=0.000;
							nouveauNucleotide = nucleotideHasard(mutationSequence);
						}else if(ancienNucleotide=='G'){
							mutationSequence[2]=0.000;
							nouveauNucleotide = nucleotideHasard(mutationSequence);
						}else if(ancienNucleotide=='U'){
							mutationSequence[3]=0.000;
							nouveauNucleotide = nucleotideHasard(mutationSequence);
						}
						nouvelleSeq[j] = nouveauNucleotide[0];
					}
					nbModifNucleotide++;
				}
			}
			if(nbModifNucleotide > 0){
				nbModifNucleotide = 0;
				res.push_back(nouvelleSeq);
			}
			i++;
		}
	}
	
	return res;
}

int main(int argc, char** argv,char** env){
	if(argc<4){
		cout<<"La génération nécessite <mode> <taille_des_séquences_à_générer> <nombre_de_séquences_à_générer> "<<endl;
	}else {
		srand(time(NULL));
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