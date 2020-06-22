/* 

HLIN610 - Stage CMI Informatique : Alignement multiple de séquences, arbre phylogénétique etméthode d’alignement progressif
- Antoine AFFLATET
- Jérémie ROUX      
(L3 GROUPE C)  

Alignement multiple
*/

#include <iostream>
#include <fstream>
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
	int i = mot1.size();
	int j = mot2.size();

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

void affichageTableau(vector<int> T, int taille){
	for(int i=0; i<taille; i++){
		if(i==0){
			cout<<"[";
		}
		cout<<T[i];
		if(i==(taille-1)){
			cout<<"]";
		}
		else{
			cout<<",";
		}
	}
	cout<<endl;
}

int minimumTableau(vector<int> T, int taille){
	int min = T[0];
	for(int i=1; i<taille; i++){
		if(T[i]<min){
			min=T[i];
		}
	}
	return min;
}

int idMinimumTableau(vector<int> T, int taille){
	int min = T[0];
	int idMin = 0;
	for(int i=1; i<taille; i++){
		if(T[i]<min){
			min=T[i];
			idMin=i;
		}
	}
	return idMin;
}

// Mot avec la valeur minimale dont la taille est la plus grande
int motValMinTableau(vector<int> T, int taille, int min, vector<string> mots){
	int result=0;
	int tailleMot=0;
	for(int i=0; i<taille; i++){
		if(T[i]==min && mots[i].size()>tailleMot){
			result=i;
			tailleMot=mots[i].size();
		}
	}
	return result;
}

// Tracer une branche de l'arbre
string branche(string A, string B, int score){
	return "\"" + A + "\" -> \"" + B + "\" [label=\" " + to_string(score) + "\"];";
}

void affichageArguments(){
	
	cout<<endl;
	cout<<endl;
	cout<<"alignementMultiple()		Manuel d'utilisation		alignementMultiple()"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"La fonction alignementMultiple() permet d'aligner une serie de séquence afin de minimiser le score d'alignement global."<<endl;
	cout<<"Un arbre de mutation par comparaison des scores d'alignement est également crée."<<endl;
	cout<<endl;
	cout<<"Options unaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-h/--help 	permet d'afficher le manuel d'utilisation."<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Options binaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-is <valeur> 	permet de donner le nom d'un fichier, au format fasta, contenant des séquences de nucléotide à aligner."<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-o <valeur> 	permet de donner le nom du fichier pour sauvegarder le résultat de l'alignementMultiple sous forme d'abre."<<endl;
	cout<<endl;
	cout<<"Si l'option -is n'est pas présente les séquences peuvent être passées en argument du script."<<endl;
	cout<<"Attention cependant si on veut exécuter le script comme décrit au dessus avec l'option -o les séquences présentent après l'option ne seront pas alignées."<<endl;
	cout<<endl;
	cout<<endl;
}


int main(int argc, char *argv[]){
	
	bool erreurOption = false;	//une erreur dans la saisie des commandes
	bool optionH = false;	//affichage de l'aide
	int optionIs = -1;	//fichier contenant l'arbre des mutations.
	int optionO = -1;	//donner le nom du fichier pour sauvegarder le résultat de l'alignementMultiple sous forme d'abre
	
	unsigned int indice = 0;
	
	string option = "";
	while((indice < argc)&&(!erreurOption)){	
		option = std::string(argv[indice]);
		if(option[0] == '-'){
			if ((option == "-h")||(option == "--help")||(option == "-H")){
				optionH = true;
			}else{
				
				if(((indice+1) < argc)&&(std::string(argv[indice+1])[0] != '-')){
					if((option == "-is")||(option == "-iS")||(option == "-IS")||(option == "-Is")){
						optionIs = indice+1;
					}else if((option == "-o")||(option == "-O")){
						optionO = indice+1;
					}else {
						cout<<"Il y a une erreur dans les options veuillez respecter la syntaxe si dessous : "<<endl;
						erreurOption = true;
					}
				}else{
					string reponse = "";
					cout<<"Il y a une erreur dans les options, l'option "<<argv[indice]<<" n'a pas été pris en compte."<<endl;
					cout<<"Voulez vous poursuivre l'exécution sans cette option, veuillez saisir oui ou non :";
					cin>>reponse;
					if (reponse != "oui"){
						erreurOption = true;
					}
				}
			}
		}
		indice++;
	}
	if((erreurOption)||(optionH)){
		affichageArguments();
	}else {
		// Affichage des mots
		int nbMots = 0;
		int tailleMax = 0;
		cout<<nbMots<<" MOTS À ALIGNER : "<<endl;
		vector<string> mots;
		string mot = "";
		
		if(optionIs != -1){
			string nomFichierDesSequences = argv[optionIs];
			ifstream fichierDesSeq(nomFichierDesSequences);
   			if(fichierDesSeq){
      			string ligne; 
				string resultat=""; 
				
      			while(getline(fichierDesSeq, ligne)){ 
      				if (ligne[0]!='>'){
        				for(int i=0;i<ligne.size();i++){
        					if(ligne[i]!=' '){
        						mot+=ligne[i];
        					}else{
        						cout<<nbMots<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
								mots.push_back(mot);
								if(tailleMax<mot.size()){
									tailleMax=mot.size();
								}
								mot = "";
								nbMots++;
        					}
        				}
        				if(mot != ""){
        					cout<<nbMots<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
							mots.push_back(mot);
							if(tailleMax<mot.size()){
								tailleMax=mot.size();
							}
							mot = "";
							nbMots++;
        				}
        			}
      			}
   			}else{
      			cout << "ERREUR: Impossible d'ouvrir le fichier de lecture des séquences." << endl;
   			}
		}else{
			if (optionO!=-1){
				nbMots = (argc-1)-((argc)-(optionO-1));
			}else{
				nbMots = argc-1;
			}
			for(int i=1; i<(optionO-1); i++){
				mot = argv[i];
				cout<<i-1<<") "<<mot<<" (Taille : "<<mot.size()<<")"<<endl;
				mots.push_back(mot);
				if(tailleMax<mot.size()){
					tailleMax=mot.size();
				}
			}
		}

		vector<string> motsCopie = mots;	
		
		cout<<"Taille Max : "<<tailleMax<<endl<<endl;
		if (nbMots != mots.size()){
			affichageArguments();
		}else{
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
	
			// Détection du mot de score minimum
			vector<int> Score(nbMots+1);
			for(int i=0; i<nbMots; i++){
				for(int j=i+1; j<nbMots; j++){
					Score[i]+=S[i][j];
					Score[j]+=S[i][j];
				}
			}
			S.clear();

			int minTableau = minimumTableau(Score,nbMots);
			int plusGrandMotSelonMin = motValMinTableau(Score,nbMots,minTableau,mots);
	
			bool motChoisiChange=false;
			int a;
			for(int j=0; j<nbMots; j++){
				if(j!=plusGrandMotSelonMin){
					string mot1modif = "";
					string mot2modif = "";
					vector< vector<int> > M((int) mots[plusGrandMotSelonMin].size()+1, vector<int>((int) mots[j].size()+1));
					remplissageMatrice(M,mots[plusGrandMotSelonMin],mots[j],indel,mismatch,match);
					a = alignement(M,mots[plusGrandMotSelonMin],mots[j],mot1modif, mot2modif);
					if(mot1modif.size()>mots[plusGrandMotSelonMin].size()){
						motChoisiChange=true;
						mots[plusGrandMotSelonMin]=mot1modif;
					}
				}
			}
			
			for(int j=0; j<nbMots; j++){
				if(j!=plusGrandMotSelonMin){
					string mot1modif = "";
					string mot2modif = "";
					vector< vector<int> > M((int) mots[plusGrandMotSelonMin].size()+1, vector<int>((int) mots[j].size()+1));
					remplissageMatrice(M,mots[plusGrandMotSelonMin],mots[j],indel,mismatch,match);
					a = alignement(M,mots[plusGrandMotSelonMin],mots[j],mot1modif,mot2modif);
					mots[j] = mot2modif;		
				}
			}
	
			cout<<endl<<"MOTS ALIGNÉS : "<<endl;
			for(int i=0; i<nbMots; i++){
				cout<<mots[i]<<endl;
			}
			cout<<endl;
	
	
			// Matrice de scores finale
			vector< vector<int> > ScoreFinal(nbMots+1, vector<int>(nbMots+1));
			for(int i=0; i<nbMots; i++){
				for(int j=i+1; j<nbMots; j++){
					string mot1modif = "";
					string mot2modif = "";
					vector< vector<int> > M((int) mots[i].size()+1, vector<int>((int) mots[j].size()+1));
					remplissageMatrice(M,mots[i],mots[j],indel,mismatch,match);
					ScoreFinal[i][j] = alignement(M,mots[i],mots[j],mot1modif,mot2modif);
					M.clear();
				}
			}
			afficherMatriceScore(ScoreFinal,nbMots);
	
			vector<int> SommeScore(nbMots+1);
			for(int i=0; i<nbMots; i++){
				for(int j=i+1; j<nbMots; j++){
					SommeScore[i]+=ScoreFinal[i][j];
					SommeScore[j]+=ScoreFinal[i][j];
				}
			}

			int x,y;
			int min = tailleMax;
			minimumMatrice(ScoreFinal,tailleMax,nbMots,min,x,y);
	
			// Arbre
			string nomFichierMutation = "";
	
			if (optionO != -1){
				int indiceVetification = 0;
				string verification = argv[optionO];
				while ((indiceVetification < verification.size())&&(verification[indiceVetification]!='.')){
					indiceVetification++;
				}
				nomFichierMutation = verification.substr(0,indiceVetification);
				nomFichierMutation += ".dot";
				
			
	    		ofstream monFlux(nomFichierMutation);
	
	    		if(monFlux){
		      		monFlux << "digraph mutation {" << endl;
		        	while(min!=tailleMax){
		        		monFlux << branche(mots[x], mots[y], min) << endl;
		        		monFlux << "// " + motsCopie[x] + " " + motsCopie[y] + " " + to_string(min) << endl;
		        		for(int i=0; i<y; i++){
		        			ScoreFinal[i][y]=tailleMax;
		        		}
		        		minimumMatrice(ScoreFinal,tailleMax,nbMots,min,x,y);
		        	}
		        	monFlux << "}" << endl;
		    	}else{
		        	cout << "ERREUR : Impossible d'ouvrir le fichier pour la sauvegarde de l'arbre." << endl;
		    	}
		    }
		}
	}
	
	return 0;
}