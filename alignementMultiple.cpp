/* 

HLIN610 - Stage CMI Informatique : Alignement multiple de séquences, arbre phylogénétique etméthode d’alignement progressif
- Antoine AFFLATET
- Jérémie ROUX      
(L3 GROUPE C)  

Alignement multiple
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int max3(int x, int y, int z){
	return x>=y ? (x>=z ? x : z) : (y>=z ? y : z);
}

int min3(int x, int y, int z){
	return x<=y ? (x<=z ? x : z) : (y=z ? y : z);
}

int matchMismatch(string mot1, string mot2, int i, int j, int mismatch, int match){
	return mot1[i]==mot2[j] ? match : mismatch;
}

vector< vector<int> > remplissageMatrice(string mot1, string mot2, int indel, int mismatch, int match){
	vector< vector<int> > M(mot1.size()+1, vector<int>(mot2.size()+1));
	for(int i=0; i<=mot1.size(); i++){
		for(int j=0; j<=mot2.size(); j++){
			// Initialisation
			if(i==0 && j==0){
				M[i][j]=0;
			}
			else if(i==0){
				M[i][j]=j;
			}
			else if(j==0){
				M[i][j]=i;
			}

			// Remplissage
			else{
				M[i][j]=min3(M[i-1][j-1]+matchMismatch(mot1,mot2,i-1,j-1,mismatch,match), M[i-1][j]+indel, M[i][j-1]+indel);
			}
		}
	}
	return M;
}

void afficherMatrice(vector< vector<int> > M, string mot1, string mot2){
	int ecart=5;
	for(int i=-1; i<=(int) mot1.size(); i++){
		for(int j=-1; j<=(int) mot2.size(); j++){
			if(i==0 && j==0){
				cout<<setw(ecart)<<M[i][j];
			}
			else if(i<=0 && j<=0){
				cout<<setw(ecart)<<" ";
			}
			else if(j==-1){
				cout<<setw(ecart)<<mot1[i-1];
			}
			else if(i==-1){
				cout<<setw(ecart)<<mot2[j-1];
			}
			else{
				cout<<setw(ecart)<<M[i][j];
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

void afficherMatriceScore(vector< vector<int> > S, int nb){
	int ecart=3;
	for(int i=1; i<nb; i++){
		for(int j=1; j<nb; j++){
			cout<<setw(ecart)<<S[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

int alignement(vector< vector<int> > M, string mot1, string mot2){
	int score=0;
	string mot1modif="";
	string mot2modif="";
	int i = mot1.size()+1;
	int j = mot2.size()+1;

	while(i>=0 && j>=0){
		// Match
		if(mot1[i]==mot2[j]){
			mot1modif = mot1[i] + mot1modif;
			mot2modif = mot2[j] + mot2modif;
			i--;
			j--;
		}
		else{
			score++;
			if(M[i+1][j+1]==M[i+1][j]+1){
				mot1modif = "-" + mot1modif;
				mot2modif = mot2[j] + mot2modif;
				j--;
			}
			else if(M[i+1][j+1]==M[i][j+1]+1){
				mot1modif = mot1[i] + mot1modif;
				mot2modif = "-" + mot2modif;
				i--;
			}
			else{
				mot1modif = mot1[i] + mot1modif;
				mot2modif = mot2[j] + mot2modif;
				i--;
				j--;
			}
		}
	}

	if(i==-1){
		while(j!=-1){
			score++;
			mot1modif = "-" + mot1modif;
			mot2modif = mot2[j] + mot2modif;
			j--;
		}
	}
	else if(j==-1){
		while(i!=-1){
			score++;
			mot1modif = mot1[i] + mot1modif;
			mot2modif = "-" + mot2modif;
			i--;
		}
	}

	cout<<mot1modif<<endl;
	cout<<mot2modif<<endl;

	return score;
}


int main(int argc, char *argv[]){
	if(argc<=2){
		cout<<"Il faut 2 mots ou plus à aligner."<<endl;
	}
	else{
		// Affichage des mots
		cout<<"MOTS À ALIGNER : "<<endl;
		for(int i=1; i<argc; i++){
			string mot = argv[i];
			cout<<i<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
		}
		cout<<endl;
		
		// Scores d'alignement
		int indel = 1;
		int mismatch = 1;
		int match = 0;

		// Matrice de scores
		vector< vector<int> > S(argc+1, vector<int>(argc+1));

		for(int i=1; i<argc; i++){
			for(int j=i+1; j<argc; j++){
				string mot1 = argv[i];
				string mot2 = argv[j];
				vector< vector<int> > M = remplissageMatrice(mot1,mot2,indel,mismatch,match);
				S[i][j] = alignement(M,mot1,mot2);
				cout<<S[i][j]<<endl;
			}
		}

		afficherMatriceScore(S, argc);

	}
	
	return 0;
}