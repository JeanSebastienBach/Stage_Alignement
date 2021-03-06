#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

string getTimeStr(){
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    string s(30, '\0');
    strftime(&s[0], s.size(), "%Y-%m-%d_%H:%M:%S", localtime(&now));
    return s;
}

void affichageArguments(){
	
	cout<<endl;
	cout<<endl;
	cout<<"comparaison()			Manuel d'utilisation			comparaison()"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"La fonction comparaison() permet de produire un score de comparaison entre deux arbres."<<endl;
	cout<<endl;
	cout<<"Options unaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-h/-help 	permet d'afficher le manuel d'utilisation."<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Options binaires : "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"	-am <valeur> 	permet de donner le nom d'un fichier contenant l'arbre des mutations reconstruit."<<endl;
	cout<<endl;
	cout<<"	-ag <valeur>  	permet de donner le nom d'un fichier contenant l'arbre des mutations générées."<<endl;
	cout<<endl;
	cout<<endl;
}

int main(int argc, char** argv,char** env){
	

	bool erreurOption = false;	//une erreur dans la saisie des commandes
	bool optionH = false;	//affichage de l'aide
	int optionAm = -1;	//fichier contenant l'arbre des mutations.
	int optionAg = -1;	//fichier contenant l'arbre généré grâce à la comparaison des mutations. 
	
	unsigned int indice = 0;
	
	string option = "";
	while((indice < argc)&&(!erreurOption)){	
		option = std::string(argv[indice]);
		if(option[0] == '-'){
			if ((option == "-h")||(option == "-help")||(option == "-H")){
				optionH = true;
			}else{
				
				if(((indice+1) < argc)&&(std::string(argv[indice+1])[0] != '-')){
					if((option == "-am")||(option == "-aM")||(option == "-AM")||(option == "-Am")){
						optionAm = indice+1;
					}else if((option == "-ag")||(option == "-aG")||(option == "-AG")||(option == "-Ag")){
						optionAg = indice+1;
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
	if ((optionAm != -1)&&(optionAg != -1)&&(!erreurOption)){
		string nomFichierArbreMutation = argv[optionAm];
		ifstream fichierArbreMutation(nomFichierArbreMutation);
		if(fichierArbreMutation){
      		
   		}else{
      		cout << "ERREUR: Impossible d'ouvrir le fichier de lecture de l'arbre de mutation." << endl;
   		}
		
	}else{
		affichageArguments();
	}
  
	return 0;
}