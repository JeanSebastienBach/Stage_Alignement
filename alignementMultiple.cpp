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

	return score;
}

int minimumMatrice(vector< vector<int> > S, int nb, int min, int &x, int &y){
	int result=min;
	for(int i=1; i<nb; i++){
		for(int j=i+1; j<nb; j++){
			if(S[i][j]<result){
				x=i;
				y=j;
				result=S[i][j];
			}
		}
	}

	return result;
}


int main(int argc, char *argv[]){
	if(argc<=2){
		cout<<"Il faut 2 mots ou plus à aligner."<<endl;
	}
	else{
		// Affichage des mots
		cout<<"MOTS À ALIGNER : "<<endl;
		vector<string> mots(argc);
		int tailleMax = 0;
		for(int i=1; i<argc; i++){
			string mot = argv[i];
			cout<<i<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
			if(tailleMax<mot.size()){
				tailleMax=mot.size();
			}
			mots[i]=mot;
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
				string mot1 = mots[i];
				string mot2 = mots[j];
				string mot1modif = "";
				string mot2modif = "";
				vector< vector<int> > M = remplissageMatrice(mot1,mot2,indel,mismatch,match);
				S[i][j] = alignement(M,mot1,mot2,mot1modif,mot2modif);
			}
		}

		//cout<<"MATRICE : "<<endl;
		//afficherMatriceScore(S, argc);

		int min = tailleMax;
		int x=0;
		int y=0;
		min = minimumMatrice(S,argc,min,x,y);

		while(min<tailleMax){
			//cout<<"Minimum : "<<min<<" x="<<x<<" y="<<y<<endl<<endl;
			string mot1modif = "";
			string mot2modif = "";
			vector< vector<int> > M = remplissageMatrice(mots[x],mots[y],indel,mismatch,match);
			int a;
			a= alignement(M,mots[x],mots[y],mot1modif,mot2modif);
			//cout<<S[x][y]<<endl;
			//cout<<mot1modif<<endl;
			//cout<<mot2modif<<endl<<endl;
			S[x][y] = tailleMax;
			//afficherMatriceScore(S, argc);
			mots[x] = mot1modif;
			mots[y] = mot2modif;
			if(mots[y].size()<mot2modif.size()){
				//cout<<"MODIFICATION EN CASCADE"<<endl;
				for(int j=y+1; j<argc; j++){
					mot1modif = "";
					mot2modif = "";
					//cout<<mots[y]<<endl;
					//cout<<mots[j]<<endl<<endl;
					vector< vector<int> > M = remplissageMatrice(mots[y],mots[j],indel,mismatch,match);
					S[y][j] = alignement(M,mots[y],mots[j],mot1modif,mot2modif);
					//cout<<S[y][j]<<endl;
					//cout<<mot1modif<<endl;
					//cout<<mot2modif<<endl<<endl;
				}
				//afficherMatriceScore(S, argc);
			}
			if(mots[x].size()<mot2modif.size()){
				//cout<<"MODIFICATION EN CASCADE"<<endl;
				for(int i=x+1; i<argc; i++){
					mot1modif = "";
					mot2modif = "";
					//cout<<mots[y]<<endl;
					//cout<<mots[j]<<endl<<endl;
					vector< vector<int> > M = remplissageMatrice(mots[i],mots[x],indel,mismatch,match);
					S[i][x] = alignement(M,mots[i],mots[x],mot1modif,mot2modif);
					//cout<<S[y][j]<<endl;
					//cout<<mot1modif<<endl;
					//cout<<mot2modif<<endl<<endl;
				}
				//afficherMatriceScore(S, argc);
			}

			min = minimumMatrice(S,argc,tailleMax,x,y);

			/*cout<<"MOTS ALIGNÉS : "<<endl;
			for(int i=1; i<argc; i++){
				cout<<mots[i]<<endl;
			}*/
		}

		for(int i=1; i<argc; i++){
			int id=0;
			string buffer="";
			while(mots[i][id]!=(char) NULL){
				buffer += mots[i][id];
				id++;
			}
			mots[i]=buffer;
		}

		int tailleMaximum=0;
		for(int i=1; i<argc; i++){
			if(tailleMaximum<mots[i].size()){
				tailleMaximum=mots[i].size();
			}
		}

		for(int i=1; i<argc; i++){
			int diff=tailleMaximum-mots[i].size();
			if(diff!=0){
				for(int nb=0; nb<diff; nb++){
					mots[i] += "-";
				}
			}
		}

		bool tiret=true;
		while(tiret){
			for(int i=1; i<argc; i++){
				if(mots[i][tailleMaximum-1]!='-'){
					tiret=false;
				}
			}
			if(tiret){
				for(int i=1; i<argc; i++){
					mots[i]=mots[i].substr(0,tailleMaximum-1);
				}
			}
			tailleMaximum--;
		}

		cout<<"MOTS ALIGNÉS : "<<endl;
		for(int i=1; i<argc; i++){
			cout<<i<<") "<<mots[i]<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}