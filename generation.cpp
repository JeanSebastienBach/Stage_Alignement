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

void modificationTabProbaNucleotides(vector<string> tabSequence,float tabProbaNucleotides[4][4],unsigned int tabNbNucleotideConsiderer[4]){
	string sequence = "";
	char dernierNucleotide;
	char actuelNucleotide;
	cout<<"====================================================="<<endl;
	cout<<"Liste des séquences considérer dans les probabilité : "<<endl;
	cout<<endl;
	for(int i=0;i<tabSequence.size();i++){
		cout<<"S["<<i<<"] = "<<tabSequence[i]<<endl;
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
			
	    	    	case 'U' :
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
			
	    	    	case 'U' :
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
			
	    	    	case 'U' :
	    		        tabProbaNucleotides[2][0] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][0])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][1] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][1])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][2] = ((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][2])/(tabNbNucleotideConsiderer[2]+1));
       		 			tabProbaNucleotides[2][3] = (((tabNbNucleotideConsiderer[2]*tabProbaNucleotides[2][3])+1)/(tabNbNucleotideConsiderer[2]+1));
			            break;
				}
				tabNbNucleotideConsiderer[2]++;
			}
			else if(dernierNucleotide=='U'){
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
			
	    	    	case 'U' :
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
	cout<<"====================================================="<<endl;
} 

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
		else if(dernierNucleotide=='U'){
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
		cout<<"La génération comporte deux mode :"<<endl;
		cout<<"Mode 0 : génération "<<endl;nécessite <mode> <taille_des_séquences_à_générer> <nombre_de_séquences_à_générer> "<<endl;
	}else {
		srand(time(NULL));
		string sequence ="";
		int tailleSeq = stoi(argv[2]);
		int nbSeq = stoi(argv[3]);
		int mode = stoi(argv[1]);
		if (mode==1){
			while(sequence.size()!=tailleSeq){
				
				cout<<"Veuillez saisir une séquence de taille "<<tailleSeq<<" : ";
				cin>>sequence;
			}
		}else {
			vector<string> tabSequence;
			tabSequence.push_back("ACGGUGACACUAACGCGAUGGCUAGCAGCUAGUCAUCGACCCAGUACGCAUG");
			tabSequence.push_back("CAUGACCCGUGCAGCUAGCUACGAAAACUCGAUGAUCGUGCAUCAUGUCAGUCAGUG");
			unsigned int tabNbNucleotideConsiderer[4];
			float tabProbaNucleotides[4][4];
			for (int k=0;k<4;k++){
				tabProbaNucleotides[k][0]=0.0;
				tabProbaNucleotides[k][1]=0.0;
				tabProbaNucleotides[k][2]=0.0;
				tabProbaNucleotides[k][3]=0.0;
				tabNbNucleotideConsiderer[k]=0;
			}
			modificationTabProbaNucleotides(tabSequence,tabProbaNucleotides,tabNbNucleotideConsiderer);
			cout<<"Liste des probabilité d'apparition de chaque nucléotide du nombre de nucléotides considérés : "<<endl;
			cout<<endl;
			for(int i=0;i<4;i++){
				cout<<"Probabilité d'apparition aprés le nucléotide "<< ((i==0) ? "A" : ((i==1) ? "C" : ((i==2) ? "G" : "U"))) <<endl;
				cout<<"A = "<<tabProbaNucleotides[i][0]<<endl;
				cout<<"C = "<<tabProbaNucleotides[i][1]<<endl;
				cout<<"G = "<<tabProbaNucleotides[i][2]<<endl;
				cout<<"U = "<<tabProbaNucleotides[i][3]<<endl;
			}
			cout<<"Nucleotides considérés aprés un : "<<endl;
			cout<<"A = "<<tabNbNucleotideConsiderer[0]<<endl;
			cout<<"C = "<<tabNbNucleotideConsiderer[1]<<endl;
			cout<<"G = "<<tabNbNucleotideConsiderer[2]<<endl;
			cout<<"U = "<<tabNbNucleotideConsiderer[3]<<endl;
			cout<<"====================================================="<<endl;
			cout<<"Génération de la séquence de taille "<<tailleSeq<<" : "<<endl;
			cout<<endl;
			sequence = generation(tailleSeq,tabProbaNucleotides);
			cout<<sequence<<endl;
			cout<<"====================================================="<<endl;
		}
		vector<string> ensembleSeq = generationMutation(sequence,nbSeq);
		cout<<"Liste des mutation générer : "<<endl;
		cout<<endl;
		for(int i=0;i<ensembleSeq.size();i++){
			cout<<"S["<<i<<"]="<<ensembleSeq[i]<<endl;
		}
		cout<<"====================================================="<<endl;
	}
	
	return 0;
}