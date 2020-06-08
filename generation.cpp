#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;
//Explication
string nucleotideHasard(float matriceProba[]){
	int nbPseudoAleatoire = rand() % 1001;
	string resultat = "";
	if(nbPseudoAleatoire<=matriceProba[0]*1000){
		resultat = "A";
	}
	else if(nbPseudoAleatoire<=(matriceProba[0]+matriceProba[1])*1000){
		resultat = "C";
	}
	else if(nbPseudoAleatoire<=(matriceProba[0]+matriceProba[1]+matriceProba[2])*1000){
		resultat = "G";
	}
	else{
		resultat = "T";
	}
	return resultat;
}
//Renommer variables + vérifier que le code est propre + Explication
void modificationTabProbaNucleotides(vector<string> tabSequence,float tabProbaNucleotides[4][4],unsigned int tabNbNucleotideConsiderer[4],bool optionM){
	string sequence = "";
	char dernierNucleotide;
	char actuelNucleotide;
	if (!optionM){
		cout<<"====================================================="<<endl;
		cout<<"Liste des séquences considérer dans les probabilité : "<<endl;
		cout<<endl;
	}
	for(int i=0;i<tabSequence.size();i++){
		if (!optionM){
			cout<<"S["<<i<<"] = "<<tabSequence[i]<<endl;
		}
		sequence = tabSequence[i];
		for(int j=1;j<sequence.size();j++){
			dernierNucleotide = sequence[j-1];
			actuelNucleotide = sequence[j];
			if(dernierNucleotide=='A'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[0][0] = (((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][0])+1)/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][1] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][1])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][2] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][2])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][3] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][3])/(tabNbNucleotideConsiderer[0]+1));
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[0][0] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][0])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][1] = (((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][1])+1)/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][2] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][2])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][3] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][3])/(tabNbNucleotideConsiderer[0]+1));
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[0][0] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][0])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][1] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][1])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][2] = (((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][2])+1)/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][3] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][3])/(tabNbNucleotideConsiderer[0]+1));
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[0][0] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][0])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][1] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][1])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][2] = ((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][2])/(tabNbNucleotideConsiderer[0]+1));
       		 			tabProbaNucleotides[0][3] = (((tabNbNucleotideConsiderer[0]*tabProbaNucleotides[0][3])+1)/(tabNbNucleotideConsiderer[0]+1));
			            break;
				}
				tabNbNucleotideConsiderer[0]++;
			}
			else if(dernierNucleotide=='C'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[1][0] = (((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][0])+1)/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][1] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][1])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][2] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][2])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][3] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][3])/(tabNbNucleotideConsiderer[1]+1));
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[1][0] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][0])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][1] = (((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][1])+1)/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][2] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][2])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][3] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][3])/(tabNbNucleotideConsiderer[1]+1));
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[1][0] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][0])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][1] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][1])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][2] = (((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][2])+1)/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][3] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][3])/(tabNbNucleotideConsiderer[1]+1));
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[1][0] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][0])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][1] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][1])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][2] = ((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][2])/(tabNbNucleotideConsiderer[1]+1));
       		 			tabProbaNucleotides[1][3] = (((tabNbNucleotideConsiderer[1]*tabProbaNucleotides[1][3])+1)/(tabNbNucleotideConsiderer[1]+1));
			            break;
				}
				tabNbNucleotideConsiderer[1]++;
			}
			else if(dernierNucleotide=='G'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[2][0] = (((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][0])+1)/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][1] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][1])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][2] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][2])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][3] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][3])/(tabNbNucleotideConsiderer[2]+1));
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[2][0] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][0])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][1] = (((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][1])+1)/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][2] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][2])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][3] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][3])/(tabNbNucleotideConsiderer[2]+1));
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[2][0] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][0])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][1] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][1])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][2] = (((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][2])+1)/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][3] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][3])/(tabNbNucleotideConsiderer[2]+1));
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[2][0] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][0])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][1] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][1])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][2] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][2])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][3] = (((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][3])+1)/(tabNbNucleotideConsiderer[2]+1));
			            break;
				}
				tabNbNucleotideConsiderer[2]++;
			}
			else if(dernierNucleotide=='T'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[3][0] = (((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][0])+1)/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][1] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][1])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][2] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][2])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][3] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][3])/(tabNbNucleotideConsiderer[3]+1));
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[3][0] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][0])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][1] = (((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][1])+1)/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][2] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][2])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][3] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][3])/(tabNbNucleotideConsiderer[3]+1));
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[3][0] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][0])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][1] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][1])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][2] = (((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][2])+1)/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][3] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][3])/(tabNbNucleotideConsiderer[3]+1));
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[3][0] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][0])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][1] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][1])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][2] = ((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][2])/(tabNbNucleotideConsiderer[3]+1));
       		 			tabProbaNucleotides[3][3] = (((tabNbNucleotideConsiderer[3]*tabProbaNucleotides[3][3])+1)/(tabNbNucleotideConsiderer[3]+1));
			            break;
				}
				tabNbNucleotideConsiderer[3]++;
			}
		}
	}
	if (!optionM){
		cout<<"====================================================="<<endl;
	}
} 
//Explication
string generation(int tailleSequenceAGenerer,float tabProbaNucleotides[4][4]){
	string sequence = "";
	int indice=0;

	if(tailleSequenceAGenerer>1){
		// Nucléotide de départ 
		float teteSequence[4] = {0.250,0.250,0.250,0.250};
		sequence += nucleotideHasard(teteSequence);
		indice++;
	}

	while(tailleSequenceAGenerer>indice){
		char dernierNucleotide = sequence.back();

		if(dernierNucleotide=='A'){
			sequence += nucleotideHasard(tabProbaNucleotides[0]);
		}
		else if(dernierNucleotide=='C'){
			sequence += nucleotideHasard(tabProbaNucleotides[1]);
		}
		else if(dernierNucleotide=='G'){
			sequence += nucleotideHasard(tabProbaNucleotides[2]);
		}
		else if(dernierNucleotide=='T'){
			sequence += nucleotideHasard(tabProbaNucleotides[3]);
		}
		indice++;
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
//Renommer variables + vérifier que le code est propre + Explication
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
						}else if(ancienNucleotide=='T'){
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
void affichageArguments(){
	cout<<"La génération comporte deux modes :"<<endl;
	cout<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Mode 0 : génération d'une séquence de taille <taille_des_séquences_à_générer> par un HMM et de <nombre_de_séquences_à_générer> mutations de cette séquence."<<endl;
	cout<<"Le mode permet d'écrire dans un fichier <*nom_du_fichier_résultat> l'ensemble des mutations générées."<<endl;
	cout<<"Il permet également de recalculer les probabilités du HMM depuis un fichier <*nom_du_fichier_paramétrage_HMM>(attention il faut également un <*nom_du_fichier_résultat> pour ce faire)"<<endl;
	cout<<endl;
	cout<<"Pour utilisé ce mode veuillez entré la commande suivante (les arguments comportant une * sont facultatifs):"<<endl;
	cout<<"./generation 0 <taille_des_séquences_à_générer> <nombre_de_séquences_à_générer> <*nom_du_fichier_résultat> <*nom_du_fichier_paramétrage_HMM>"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"Mode 1 : une séquence de taille <taille_des_séquences_à_générer> vous sera demandé par la suite afin de générer les <nombre_de_séquences_à_générer> mutations de cette séquence."<<endl;
	cout<<"Le mode permet d'écrire dans un fichier <*nom_du_fichier_résultat> l'ensemble des mutations générées."<<endl;
	cout<<"Il permet également de lire la séquence à faire muter depuis un fichier <*nom_du_fichier_sequence>(attention il faut également un <*nom_du_fichier_résultat> pour ce faire)"<<endl;
	cout<<endl;
	cout<<"Pour utilisé ce mode veuillez entré la commande suivante (les arguments comportant une * sont facultatifs):"<<endl;
	cout<<"./generation 1 <taille_des_séquences_à_générer> <nombre_de_séquences_à_générer> <*nom_du_fichier_résultat> <*nom_du_fichier_sequence>"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"Attention les séquences considérées ne doivent contenir que les caractères A, C, G ou U !"<<endl;
	cout<<"Pour n'afficher que les mutations générées en les séparant par un espace il faut ajouter un -m en argument."<<endl;
	cout<<"Pour revoir ces informations ajouter un -help ou -h en argument."<<endl;
}

int main(int argc, char** argv,char** env){
	unsigned int nbOption = 0;
	int premiereOption = -1;
	unsigned int indice = 0;
	bool optionM = false;
	bool optionH = false;
	string option = "";
	while(indice < argc){	
		if((std::string(argv[indice])=="-m")||(std::string(argv[indice])=="-h")||(std::string(argv[indice])=="-help")){
			nbOption++;
			if (premiereOption == -1){
				premiereOption = indice;
			}
			if (std::string(argv[indice])=="-m"){
				optionM = true;
			}else{
				optionH = true;
			}
		}
		indice++;
	}
	if((argc<2)||(optionH)||(premiereOption < argc-nbOption)){
		affichageArguments();
	}else if (((stoi(argv[1])==1)||(stoi(argv[1])==0))&&((argc-nbOption)>3)){
		srand(time(NULL));
		string sequence ="";
		
		int tailleSeq = stoi(argv[2]);
		int nbSeq = stoi(argv[3]);
		
		if (stoi(argv[1])==1){
			if((argc-nbOption)==6){
				string nomFichierSeq = argv[5];
				ifstream fichierSeq(nomFichierSeq);
   				if(fichierSeq){
      				string sequenceBrut = ""; 
					getline(fichierSeq, sequenceBrut); 
					int indice = 0;
        			while((indice<sequenceBrut.size())&&(sequence.size()<tailleSeq)){
        				if ((sequenceBrut[indice]=='a')||(sequenceBrut[indice]=='A')){
							sequence+='A';
						}else if ((sequenceBrut[indice]=='c')||(sequenceBrut[indice]=='C')){
							sequence+='C';
						}else if ((sequenceBrut[indice]=='g')||(sequenceBrut[indice]=='G')){
							sequence+='G';
						}else if ((sequenceBrut[indice]=='t')||(sequenceBrut[indice]=='T')){
							sequence+='T';
						}
						indice++;
      				}
      				
   				}else{
      				cout << "ERREUR: Impossible d'ouvrir le fichier de lecture des séquences." << endl;
   				}
			}else {
				while(sequence.size()!=tailleSeq){
					cout<<"Veuillez saisir une séquence de taille "<<tailleSeq<<" : ";
					cin>>sequence;
				}
			}
		}else {
			vector<string> tabSequence;
			unsigned int tabNbNucleotideConsiderer[4];
			float tabProbaNucleotides[4][4];
			
			if((argc-nbOption)==6){
				string nomFichierDesSequences = argv[5];
				ifstream fichierDesSeq(nomFichierDesSequences);
   				if(fichierDesSeq){
      				string ligne; 
					string resultat=""; 
      				while(getline(fichierDesSeq, ligne)){ 
        				for(int i=0;i<ligne.size();i++){
        					if ((ligne[i]=='a')||(ligne[i]=='A')){
								resultat+='A';
							}else if ((ligne[i]=='c')||(ligne[i]=='C')){
								resultat+='C';
							}else if ((ligne[i]=='g')||(ligne[i]=='G')){
								resultat+='G';
							}else if ((ligne[i]=='t')||(ligne[i]=='T')){
								resultat+='T';
							}
        				}
      				}
      				tabSequence.push_back(resultat);
   				}else{
      				cout << "ERREUR: Impossible d'ouvrir le fichier de lecture des séquences." << endl;
   				}
   				
				for (int k=0;k<4;k++){
					tabProbaNucleotides[k][0]=0.0;
					tabProbaNucleotides[k][1]=0.0;
					tabProbaNucleotides[k][2]=0.0;
					tabProbaNucleotides[k][3]=0.0;
					tabNbNucleotideConsiderer[k]=0;
				}	
				modificationTabProbaNucleotides(tabSequence,tabProbaNucleotides,tabNbNucleotideConsiderer,optionM);
			}else {
				tabProbaNucleotides[0][0]=0.32168;
				tabProbaNucleotides[0][1]=0.225958;
				tabProbaNucleotides[0][2]=0.194572;
				tabProbaNucleotides[0][3]=0.25779;
				tabNbNucleotideConsiderer[0]=8953;	
								
				tabProbaNucleotides[1][0]=0.379461;
				tabProbaNucleotides[1][1]=0.16169;
				tabProbaNucleotides[1][2]=0.0799346;
				tabProbaNucleotides[1][3]=0.378915;
				tabNbNucleotideConsiderer[1]=5492;
									
				tabProbaNucleotides[2][0]=0.274944;
				tabProbaNucleotides[2][1]=0.199215;
				tabProbaNucleotides[2][2]=0.186424;
				tabProbaNucleotides[2][3]=0.339417;
				tabNbNucleotideConsiderer[2]=5863;
				
				tabProbaNucleotides[3][0]=0.247759;
				tabProbaNucleotides[3][1]=0.14728;
				tabProbaNucleotides[3][2]=0.269856;
				tabProbaNucleotides[3][3]=0.335105;
				tabNbNucleotideConsiderer[3]=9594;
			}
			sequence = generation(tailleSeq,tabProbaNucleotides);
			if(!optionM){
				cout<<"Liste des probabilité d'apparition de chaque nucléotide du nombre de nucléotides considérés : "<<endl;
				cout<<endl;
				for(int i=0;i<4;i++){
					cout<<"Probabilité d'apparition aprés le nucléotide "<< ((i==0) ? "A" : ((i==1) ? "C" : ((i==2) ? "G" : "T"))) <<endl;
					cout<<"A = "<<tabProbaNucleotides[i][0]<<endl;
					cout<<"C = "<<tabProbaNucleotides[i][1]<<endl;
					cout<<"G = "<<tabProbaNucleotides[i][2]<<endl;
					cout<<"T = "<<tabProbaNucleotides[i][3]<<endl;
				}
				cout<<"Nucleotides considérés aprés un : "<<endl;
				cout<<"A = "<<tabNbNucleotideConsiderer[0]<<endl;
				cout<<"C = "<<tabNbNucleotideConsiderer[1]<<endl;
				cout<<"G = "<<tabNbNucleotideConsiderer[2]<<endl;
				cout<<"T = "<<tabNbNucleotideConsiderer[3]<<endl;
				cout<<"====================================================="<<endl;
				cout<<"Génération de la séquence de taille "<<tailleSeq<<" : "<<endl;
				cout<<endl;
				cout<<sequence<<endl;
				cout<<"====================================================="<<endl;
			}
		}
		vector<string> ensembleSeq = generationMutation(sequence,nbSeq);
		if(optionM){
			for(int i=0;i<ensembleSeq.size();i++){
				if (i==0){
					cout<<ensembleSeq[i];
				}else{
					cout<<" "<<ensembleSeq[i];
				}
			}	
			cout<<endl;
		}else {
			if (stoi(argv[1])==1){
				cout<<"====================================================="<<endl;
			}
			cout<<"Liste des mutation générer : "<<endl;
			cout<<endl;
			for(int i=0;i<ensembleSeq.size();i++){
				cout<<"S["<<i<<"]="<<ensembleSeq[i]<<endl;
			}
			cout<<"====================================================="<<endl;
		}
					
		if((argc-nbOption)>=5){
			string nomFichierResultats = argv[4];
   			ofstream fichierSauvegarde(nomFichierResultats);
    		if(fichierSauvegarde){
    			if(optionM){
					for(int i=0;i<ensembleSeq.size();i++){
						if (i==0){
							fichierSauvegarde<<ensembleSeq[i];
						}else{
							fichierSauvegarde<<" "<<ensembleSeq[i];
						}
					}	
					fichierSauvegarde<<endl;
				}else {
					fichierSauvegarde<<"====================================================="<<endl;
					fichierSauvegarde<<"Liste des mutation générées : "<<endl;
					fichierSauvegarde<<endl;
					for(int i=0;i<ensembleSeq.size();i++){
						fichierSauvegarde<<"S["<<i<<"]="<<ensembleSeq[i]<<endl;
					}
					fichierSauvegarde<<endl<<"====================================================="<<endl;
				}
        	}else{
        		cout << "ERREUR: Impossible d'ouvrir le fichier pour l'écriture du résultat." << endl;
    		}
		}
	}else{
		affichageArguments();
	}		
	return 0;
}