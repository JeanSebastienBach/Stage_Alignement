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

void remplissageMatrice(vector< vector<int> > &M, string mot1, string mot2, int indel, int mismatch, int match){
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
	for(int i=0; i<nb; i++){
		for(int j=0; j<nb; j++){
			cout<<setw(ecart)<<S[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

int alignement(vector< vector<int> > M, string mot1, string mot2, string &mot1modif, string &mot2modif){
	int score=0;
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

	mot1modif = mot1modif+(char) NULL;
	mot2modif = mot2modif+(char) NULL;

	int id=0;
	string buffer="";
	while(mot1modif[id]!=(char) NULL){
		buffer += mot1modif[id];
		id++;
	}
	mot1modif=buffer;

	id=0;
	buffer="";
	while(mot2modif[id]!=(char) NULL){
		buffer += mot2modif[id];
		id++;
	}
	mot2modif=buffer;

	//cout<<mot1modif<<endl;
	//cout<<mot2modif<<endl;
	//cout<<score<<endl<<endl;

	return score;
}

void minimumMatrice(vector< vector<int> > S, int tailleMax, int nb, int &min, int &x, int &y){
	int result=tailleMax;
	for(int i=0; i<nb; i++){
		for(int j=i+1; j<nb; j++){
			if(S[i][j]<result){
				x=i;
				y=j;
				result=S[i][j];
			}
		}
	}
	min=result;
}


int main(int argc, char *argv[]){
	if(argc<=2){
		cout<<"Il faut 2 mots ou plus à aligner."<<endl;
	}
	else{
		
		// Affichage des mots
		int nbMots = argc-1;
		int tailleMax = 0;
		cout<<nbMots<<" MOTS À ALIGNER : "<<endl;
		vector<string> mots;
		for(int i=1; i<argc; i++){
			string mot = argv[i];
			cout<<i<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
			mots.push_back(mot);
			if(tailleMax<mot.size()){
				tailleMax=mot.size();
			}
		}
		cout<<"Taille Max : "<<tailleMax<<endl;
		
		// Scores d'alignement
		int indel = 1;
		int mismatch = 1;
		int match = 0;

		// Matrice de scores
		vector< vector<int> > S(nbMots+1, vector<int>(nbMots+1));
		for(int i=0; i<nbMots; i++){
			for(int j=i+1; j<nbMots; j++){
				string mot1modif = "";
				string mot2modif = "";
				vector< vector<int> > M((int) mots[i].size()+1, vector<int>((int) mots[j].size()+1));
				remplissageMatrice(M,mots[i],mots[j],indel,mismatch,match);
				S[i][j] = alignement(M,mots[i],mots[j],mot1modif,mot2modif);
				M.clear();
			}
		}
		//afficherMatriceScore(S,nbMots);

		// Détection du score minimum et des mots associés
		int x=0;
		int y=0;
		int a;
		int min = tailleMax;
		minimumMatrice(S,tailleMax,nbMots,min,x,y);
		//cout<<"Minimum : "<<min<<" ("<<x<<","<<y<<")"<<endl;

		while(min<tailleMax){
			string mot1modif = "";
			string mot2modif = "";
			vector< vector<int> > M((int) mots[x].size()+1, vector<int>((int) mots[y].size()+1));
			//cout<<"OUI"<<endl;
			remplissageMatrice(M,mots[x],mots[y],indel,mismatch,match);
			a = alignement(M,mots[x],mots[y],mot1modif,mot2modif);
			M.clear();

			mots[x]=mot1modif;
			mots[y]=mot2modif;

			S[x][y]=tailleMax;
			//afficherMatriceScore(S,nbMots);
			minimumMatrice(S,tailleMax,nbMots,min,x,y);
			//cout<<"Minimum : "<<min<<" ("<<x<<","<<y<<")"<<endl;
		}
		S.clear();

		for(int i=0; i<nbMots; i++){
			int id=0;
			string buffer="";
			while(mots[i][id]!=(char) NULL){
				buffer += mots[i][id];
				id++;
			}
			mots[i]=buffer;
		}

		int tailleMaximum=0;
		for(int i=0; i<nbMots; i++){
			if(tailleMaximum<mots[i].size()){
				tailleMaximum=mots[i].size();
			}
		}

		for(int i=0; i<nbMots; i++){
			int diff=tailleMaximum-mots[i].size();
			if(diff!=0){
				for(int nb=0; nb<diff; nb++){
					mots[i] += "-";
				}
			}
		}

		bool tiret=true;
		while(tiret){
			for(int i=0; i<nbMots; i++){
				if(mots[i][tailleMaximum-1]!='-'){
					tiret=false;
				}
			}
			if(tiret){
				for(int i=0; i<nbMots; i++){
					mots[i]=mots[i].substr(0,tailleMaximum-1);
				}
			}
			tailleMaximum--;
		}

		cout<<endl<<"MOTS ALIGNÉS : "<<endl;
		for(int i=0; i<nbMots; i++){
			cout<<i+1<<") "<<mots[i]<<endl;
		}
		cout<<endl;
		
	}
	
	return 0;
}