/* 

HLIN610 - Stage CMI Informatique : Alignement multiple de séquences, arbre phylogénétique etméthode d’alignement progressif
- Antoine AFFLATET
- Jérémie ROUX      
(L3 GROUPE C)  

Alignement de 2 séquences
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

vector< vector<int> > remplissageMatrice(string mot1, string mot2){
	vector< vector<int> > M(mot1.size(), vector<int>(mot2.size()));
	for(int i=0; i<mot1.size(); i++){
		for(int j=0; j<mot2.size(); j++){
			if(i==0 && j==0){
				M[i][j]=0;
			}
			else if(i==0){
				M[i][j]=-j;
			}
			else if(j==0){
				M[i][j]=-i;
			}
			else{
				M[i][j]=-10;
			}
		}
	}
	return M;
}

void afficherMatrice(vector< vector<int> > M, string mot1, string mot2){
	int ecart=5;
	for(int i=0; i<mot1.size(); i++){
		for(int j=0; j<mot2.size(); j++){
			if(j==-1){

			}
			else if(i==-1){

			}
			else{
				cout<<setw(ecart)<<M[i][j];
			}
		}
		cout<<endl;
	}
	cout<<endl;
}


int main(int argc, char *argv[]){
	if(argc!=3){
		cout<<"Il faut exactement 2 mots à aligner."<<endl;
	}
	else{
		// Récupération des 2 mots
		string mot1 = argv[1];
		string mot2 = argv[2];
		cout<<"MOTS À ALIGNER : "<<endl;
		cout<<"1) "<<mot1<<" (Taille : "<<mot1.size()<<")"<<endl;
		cout<<"2) "<<mot2<<" (Taille : "<<mot2.size()<<")"<<endl<<endl;

		// Scores d'alignement
		//int indel = -1;
		//int mismatch = -2;
		//int match = 2;

		vector< vector<int> > M = remplissageMatrice(mot1,mot2);
		afficherMatrice(M,mot1,mot2);
	}
	
	return 0;
}