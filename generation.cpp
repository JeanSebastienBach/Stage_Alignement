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
void modificationTabProbaNucleotides(vector<string> tabSequence,float tabProbaNucleotides[4][4],unsigned int tabNbNucleotideConsiderer[4],bool optionF){
	string sequence = "";
	char dernierNucleotide;
	char actuelNucleotide;
	if (!optionF){
		cout<<"====================================================="<<endl;
		cout<<"Liste des séquences considérer dans les probabilités : "<<endl;
		cout<<endl;
	}
	for(int i=0;i<tabSequence.size();i++){
		if (!optionF){
			cout<<"S["<<i<<"] = "<<tabSequence[i]<<endl;
		}
		sequence = tabSequence[i];
		for(int j=1;j<sequence.size();j++){
			dernierNucleotide = sequence[j-1];
			actuelNucleotide = sequence[j];
			if(dernierNucleotide=='A'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[0][0]++;
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[0][1]++;
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[0][2]++;
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[0][3]++;
			            break;
				}
				tabNbNucleotideConsiderer[0]++;
			}
			else if(dernierNucleotide=='C'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[1][0]++;
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[1][1]++;
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[1][2]++;
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[1][3]++;
			            break;
				}
				tabNbNucleotideConsiderer[1]++;
			}
			else if(dernierNucleotide=='G'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[2][0]++;
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[2][1]++;
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[2][2]++;
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[2][3]++;
			            break;
				}
				tabNbNucleotideConsiderer[2]++;
			}
			else if(dernierNucleotide=='T'){
				switch(actuelNucleotide){
       		 		case 'A' :
       		 			tabProbaNucleotides[3][0]++;
            			break;

        			case 'C' :
        	    		tabProbaNucleotides[3][1]++;
        	    		break;
			
			        case 'G' :
    		    	    tabProbaNucleotides[3][2]++;
    			        break;
			
	    	    	case 'T' :
	    		        tabProbaNucleotides[3][3]++;
			            break;
				}
				tabNbNucleotideConsiderer[3]++;
			}
		}
	}
	for(int i = 0;i<4;i++){
		for(int j=0;j<4;j++){
			tabProbaNucleotides[i][j] = tabProbaNucleotides[i][j]/tabNbNucleotideConsiderer[i];
		}
	}
	if (!optionF){
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
vector<string> generationMutation(string s,int nbSeq, string nomFichierArbreMutation){

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
	string nouvelleSeq = "";
	string nouveauNucleotide = "";
	string arbreMutation = "digraph Mutation { \n"; 

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
				res.push_back(nouvelleSeq);
				if (nomFichierArbreMutation != ""){
					arbreMutation += "\"" + res[i] + "\" -> \"" + nouvelleSeq + "\" [label=\" " + to_string(nbModifNucleotide) + "\"];\n";
				}
				nbModifNucleotide = 0;
			}
			
			i++;
		}
	}
	
	
	if (nomFichierArbreMutation != ""){
		ofstream fichierArbre(nomFichierArbreMutation);
		if(fichierArbre){
			fichierArbre<<arbreMutation;
			fichierArbre<<"}"<<endl;
		}else{
			cout<<"ERREUR: Impossible d'ouvrir le fichier pour écrire l'arbre des mutations."<<endl;
		}
	}

	return res;
}

void affichageArguments(){
	
	cout<<endl;
	cout<<endl;
	cout<<"generation()			Manuel d'utilisation			generation()"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"La fonction generation() permet de produire une serie de séquence créer par mutations issues soit d'une séquence générée par un HMM soit d'une séquence passée en option."<<endl;
	cout<<"Les options portant une * sont obligatoires."<<endl;
	cout<<endl;
	cout<<"Options unaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-f		permet de filtrer l'affichage de sortie afin d'afficher seulement les séquences séparées par un espace."<<endl;
	cout<<endl;
	cout<<"	-h/-help 	permet d'afficher le manuel d'utilisation."<<endl;
	cout<<endl;
	cout<<"	-m		permet d'autoriser l'utilisation de parallèlisme pour la génération des mutations. (à préciser avec les données) "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Options binaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	* -l <valeur> 	permet de donner la longueur de la premiére séquence."<<endl;
	cout<<endl;
	cout<<"	* -n <valeur>	permet de donner le nombre de séquence qui doivent être produites."<<endl;
	cout<<endl;
	cout<<"	-s <valeur> 	permet de donner la premiére séquence. Si la séquence est plus grande que la longueur l donné en option seulement les l premiers caractères seront considérées."<<endl;
	cout<<endl;
	cout<<"	-i <valeur> 	permet de donner le nom d'un fichier, au format fasta, contenant une séquence de nucléotide. Elle sera utilisée comme premiére séquence."<<endl;
	cout<<endl;
	cout<<"	-ip <valeur> 	permet de donner le nom d'un fichier, au format fasta, contenant une/des séquence(s) de nucléotide. Elle seront utilisées pour calculer les probabilités du HMM générant la premiére séquence."<<endl;
	cout<<endl;
	cout<<"	-o <valeur> 	permet de donner le nom d'un fichier dans lequel sera écrit l'ensemble des mutations au même format que dans le terminal."<<endl;
	cout<<endl;
	cout<<"	-om <valeur>  	permet de donner le nom d'un fichier dans lequel sera écrit l'arbre de génération de l'ensemble des mutations."<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Attention les séquences considérées ne doivent contenir que les caractères A, C, G ou T !"<<endl;
	cout<<endl;
	cout<<endl;
}

int main(int argc, char** argv,char** env){
	
	bool erreurOption = false;	//une erreur dans la saisie des commandes
	bool optionF = false;	//filtrer l'affichage de sortie
	bool optionH = false;	//affichage de l'aide
	//A FAIRE |--------------
	bool optionM = false;	//utilisation du parallélisme
	//A FAIRE |--------------
	int optionL = -1;	//longueur de la séquence
	int optionN = -1;	//nombre de séquence
	int optionS = -1;	//une séquence à faire muter
	int optionI = -1;	//fichier contenant la séquence au format FASTA
	int optionIp = -1;	//fichier contenant la séquence au format FASTA pour générer les probabilités du HMM 
	int optionO = -1;	//donner le nom du fichier pour sauvegarder le résultat de la génération des mutations
	int optionOm = -1;	//donner le nom du fichier pour sauvegarder l'origine des mutations
	unsigned int indice = 0;
	
	
	string option = "";
	while((indice < argc)&&(!erreurOption)){	
		option = std::string(argv[indice]);
		if(option[0] == '-'){
			if ((option == "-f")||(option == "-F")){
				optionF = true;
			}else if ((option == "-h")||(option == "-help")||(option == "-H")){
				optionH = true;
			}else if ((option == "-m")||(option == "-M")){
				optionM = true;
			}else{
				
				if(((indice+1) < argc)&&(std::string(argv[indice+1])[0] != '-')){
					if((option == "-l")||(option == "-L")){
						optionL = indice+1;
					}else if((option == "-n")||(option == "-N")){
						optionN = indice+1;
					}else if((option == "-s")||(option == "-S")){
						optionS = indice+1;
					}else if((option == "-i")||(option == "-I")){
						optionI = indice+1;
					}else if((option == "-ip")||(option == "-Ip")||(option == "-IP")||(option == "-iP")){
						optionIp = indice+1;
					}else if((option == "-o")||(option == "-O")){
						optionO = indice+1;
					}else if((option == "-om")||(option == "-Om")||(option == "-OM")||(option == "-oM")){
						optionOm = indice+1;
					}else{
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
	if((argc<2)||(optionH)||(erreurOption)){
		affichageArguments();
	}else if ((optionN != -1)&(optionL != -1)){
		srand(time(NULL));
		string sequence ="";
		
		int tailleSeq = stoi(argv[optionL]);
		int nbSeq = stoi(argv[optionN]);
		
		if ((optionS != -1)||(optionI != -1)){
			if(optionI != -1){
				string nomFichierSeq = argv[optionI];
				ifstream fichierSeq(nomFichierSeq);
   				if(fichierSeq){
      				string sequenceBrut = ""; 
      				
					int indice = 0;
					while((getline(fichierSeq, sequenceBrut))&&(sequence.size()<tailleSeq)){ 
						indice = 0;
						if (sequenceBrut[0]!='>'){
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
      					}
      				}
   				}else{
      				cout << "ERREUR: Impossible d'ouvrir le fichier de lecture des séquences." << endl;
   				}
			}else {
				sequence = argv[optionS];
			}
		}else {
			vector<string> tabSequence;
			unsigned int tabNbNucleotideConsiderer[4];
			float tabProbaNucleotides[4][4];
			
			if(optionIp != -1){
				string nomFichierDesSequences = argv[optionIp];
				ifstream fichierDesSeq(nomFichierDesSequences);
   				if(fichierDesSeq){
      				string ligne; 
					string resultat=""; 
					
      				while(getline(fichierDesSeq, ligne)){ 
      					if (ligne[0]!='>'){
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
				modificationTabProbaNucleotides(tabSequence,tabProbaNucleotides,tabNbNucleotideConsiderer,optionF);
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
			if(!optionF){
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
		string nomFichierMutation = "";

		if (optionOm != -1){
			int indiceVetification = 0;
			string verification = argv[optionOm];
			while ((indiceVetification < verification.size())&&(verification[indiceVetification]!='.')){
				indiceVetification++;
			}
			nomFichierMutation = verification.substr(0,indiceVetification);
			nomFichierMutation += ".dot";
			
		}

		vector<string> ensembleSeq = generationMutation(sequence,nbSeq,nomFichierMutation);
		if(optionF){
			for(int i=0;i<ensembleSeq.size();i++){
				if (i==0){
					cout<<ensembleSeq[i];
				}else{
					cout<<" "<<ensembleSeq[i];
				}
			}	
			cout<<endl;
		}else {
			if ((optionS != -1)||(optionI != -1)){
				cout<<"====================================================="<<endl;
			}
			cout<<"Liste des mutation générer : "<<endl;
			cout<<endl;
			for(int i=0;i<ensembleSeq.size();i++){
				cout<<"S["<<i<<"]="<<ensembleSeq[i]<<endl;
			}
			cout<<"====================================================="<<endl;
		}
					
		if(optionO != -1){
			string nomFichierResultats = argv[optionO];
   			ofstream fichierSauvegarde(nomFichierResultats);
    		if(fichierSauvegarde){
    			if(optionF){
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