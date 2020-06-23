#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

struct Arbre
{
    string nom;
    vector<Arbre> fils;
};

void afficherArbre(Arbre a){
	cout<<a.nom;
	cout<<" [ ";
	for(int i=0; i<a.fils.size(); i++){
		afficherArbre(a.fils[i]);
		cout<<" ";
	}
	cout<<"] ";
}

// Pour fusionner a1 et a2 si a2 est un noeud de a1
Arbre fusionArbre(Arbre a1, Arbre a2){
	if(a1.nom == a2.nom){
		a1.fils.insert(a1.fils.end(), a2.fils.begin(), a2.fils.end());
		return a1;
	}
	if(a1.fils.size()==0){
		Arbre arbreVide;
		arbreVide.nom="NULL";
		return arbreVide;
	}
	int i=0;
	bool trouve=false;
	Arbre temp;
	while(i<=a1.fils.size()-1 && !trouve){
		temp = fusionArbre(a1.fils[i],a2);
		if(temp.nom!="NULL"){
			trouve=true;
		}
		i++;
	}
	if(!trouve){
		Arbre arbreVide;
		arbreVide.nom="NULL";
		return arbreVide;
	}
	else{
		a1.fils[i-1]=temp;
		return a1;
	}
}

Arbre generationArbre(vector<string> branchesArbre){
	vector<Arbre> arbres;

	// Initialisation
	int i = 0;
	int nb = branchesArbre.size()/2;
	while(i<=nb){
		Arbre a = Arbre();
		a.nom = branchesArbre[i*2];
		Arbre b = Arbre();
		b.nom = branchesArbre[(i*2)+1];
		a.fils.push_back(b);
		arbres.push_back(a);
		i++;
	}

	// Deux arbres ont la même racine, on fusionne leurs sous-arbres
	int trouve=true;
	while(trouve){
		int x=0;
		trouve=false;
		while(x<arbres.size()-2 && !trouve){
			int y=x+1;
			while(y<arbres.size()-1 && !trouve){
				if(arbres[x].nom==arbres[y].nom){
					trouve=true;
					arbres[x].fils.insert(arbres[x].fils.end(), arbres[y].fils.begin(), arbres[y].fils.end());
					arbres.erase(arbres.begin()+ y);
				}
				y++;
			}
			x++;
		}
	}
	
	// Un arbre est sous-arbre de l'autre
	trouve=true;
	while(trouve){
		int x=0;
		trouve=false;
		while(x<arbres.size()-2 && !trouve){
			int y=x+1;
			while(y<arbres.size()-1 && !trouve){
				int id=0;
				while(id<arbres[x].fils.size() && !trouve){
					if(arbres[x].fils[id].nom==arbres[y].nom){
						trouve=true;
						arbres[x].fils[id]=arbres[y];
						arbres.erase(arbres.begin()+ y);
					}
					id++;
				}
				id=0;
				while(id<arbres[y].fils.size()-1 && !trouve){
					if(arbres[y].fils[id].nom==arbres[x].nom){
						trouve=true;
						arbres[y].fils[id]=arbres[x];
						arbres.erase(arbres.begin()+ x);
					}
					id++;
				}
				y++;
			}
			x++;
		}
	}

	cout<<endl;

	// Mettre tous les sous-arbres dans le premier
	while(arbres.size()>2){
		
		Arbre temp = fusionArbre(arbres[0], arbres[1]);
		if(temp.nom!="NULL"){
			arbres[0]=temp;
			arbres.erase(arbres.begin()+ 1);
		}
		else{
			temp = fusionArbre(arbres[1], arbres[0]);
			arbres[1]=temp;
			arbres.erase(arbres.begin()+ 0);
		}
	}

	return arbres[0];
}

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
	cout<<"	-h/--help 	permet d'afficher le manuel d'utilisation."<<endl;
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
			if ((option == "-h")||(option == "--help")||(option == "-H")){
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

		//cout<< "ARBRE" << endl;
		
		string nomFichierArbreMutation = argv[optionAm];
		ifstream fichierArbreMutation(nomFichierArbreMutation);
		vector<string> branchesArbre;
		if(fichierArbreMutation){
			string ligne;
  			while(getline(fichierArbreMutation, ligne)){
  				if(ligne[0]=='/'){
  					vector<string> motLigne;
					string s = "";
					for(int c=0; c<ligne.size(); c++){
						if(ligne[c]==' '){
							motLigne.push_back(s);
							s = "";
						}
						else{
							s += ligne[c];
						}
					}
					branchesArbre.push_back(motLigne[1]);
					branchesArbre.push_back(motLigne[2]);
  					//cout << "'" << motLigne[1] << "' -> '" << motLigne[2] << "'" << endl;
  				}
			}

			Arbre A = generationArbre(branchesArbre);
			//afficherArbre(A);

			//cout << endl << "ARBRE 2" << endl;

			string nomFichierArbreMutation2 = argv[optionAg];
			ifstream fichierArbreMutation2(nomFichierArbreMutation2);
			vector<string> branchesArbre2;
			if(fichierArbreMutation2){
      			string ligne2;
      			while(getline(fichierArbreMutation2, ligne2)){
      				if(ligne2[0]=='/'){
      					vector<string> motLigne2;
						string s2 = "";
						for(int c=0; c<ligne2.size(); c++){
							if(ligne2[c]==' '){
								motLigne2.push_back(s2);
								s2 = "";
							}
							else{
								s2 += ligne2[c];
							}
						}
						branchesArbre2.push_back(motLigne2[1]);
						branchesArbre2.push_back(motLigne2[2]);
      					//cout << "'" << motLigne2[1] << "' -> '" << motLigne2[2] << "'" << endl;
      				}
				}

				Arbre A2 = generationArbre(branchesArbre2);

				cout<<"A : ";
				afficherArbre(A);
				cout<<endl<<"A2 : ";
				afficherArbre(A2);
				cout<<endl;

	   		}
	   		else{
	      		cout << "ERREUR: Impossible d'ouvrir le fichier de lecture de l'arbre de mutation générées." << endl;
	   		}
      		
   		}
   		else{
      		cout << "ERREUR: Impossible d'ouvrir le fichier de lecture de l'arbre de mutation." << endl;
   		}
		
	}
	else{
		affichageArguments();
	}
  
	return 0;
}