
#include <iostream>
#include "Voiture.h"
#include "Camion.h"
#include <vector>

using namespace std;

/*
* Déclaration de fonction 
*/
void afficherCamions(vector<Camion *> Camions); // Affichage des voitures et de leurs roues
void saisirInformationVoiture(Voiture& tempVoiture); // Saisie des informations de la voiture et de ses roues

int main()
{
	vector<Camion*> camions;
	string interString;
	// vector<Voiture *> voitures; // Sera ajouter lors des notions de polymorphisme
	string wait;
	do {
		do {
			cout << "Voulez vous ajouter une voiture ou un camion ? (V/C) : ";
			cin >> interString;
			if (interString == "c" || interString == "C") {
				Camion* tempCamion = new Camion();
				saisirInformationVoiture(*tempCamion);
				camions.push_back(tempCamion);
				break;
			}
			else {
				cout << "Veuillez entrer V pour voiture ou C pour camion." << endl;
				break;
			}
		} while (true);		
		


		//cout << "Nombre de voitures : " << voitures.size() << endl;
		//cout << "Nombre de roues : " << voitures[0].roues.size() << endl;
		cout << "Voulez-vous ajouter une autre voiture ? (O/N) : ";
		cin >> interString;
		if (interString != "O" && interString != "o") {
			break;
		}

	} while (true);

	system("cls"); // Nettoyage de la console
	afficherCamions(camions); // Affichage des voitures et de leurs roues

	for (int x = 0; x < camions.size(); x++) {
		delete camions[x]; // Libération de la mémoire allouée pour les voitures
	}
	camions.clear(); // Nettoyage du vecteur de voitures

	cin >> wait;

	return 0;
}
/*
* Cette fonction permet d'afficher les informations des voitures et de leurs roues.
*/
void afficherCamions(vector<Camion *> camions) {
	for (int x = 0; x < camions.size(); x++) {
		cout << "Voiture numero " << x + 1 << " : " << endl;
		cout << "\tNumero de serie : " << camions[x]->getNumero_serie() << endl;
		cout << "\tMarque : " << camions[x]->getMarque() << endl;
		cout << "Moteur : " << endl;
		cout << "\tNumero de serie : " << camions[x]->moteur.getNumero_serie() << endl;
		cout << "\tModel : " << camions[x]->moteur.getModel() << endl;
		cout << "\tPuissance : " << camions[x]->moteur.puissance << endl;
		cout << "\tCylindree : " << camions[x]->moteur.cylindree << endl;
		for (int y = 0; y < camions[x]->roues.size(); y++) {
			cout << "Roues numero " << y + 1 << " : " << endl;
			cout << "\tNumero de serie : " << camions[x]->roues[y].getNumeruo_serie() << endl;
			cout << "\tMarque : " << camions[x]->roues[y].getMarque() << endl;
			cout << "\tLargeur : " << camions[x]->roues[y].largeur << endl;
			cout << "\tHauteur : " << camions[x]->roues[y].hauteur << endl;
			cout << "\tRadial : " << camions[x]->roues[y].radial << endl;
			cout << "\tDiametre : " << camions[x]->roues[y].diametre << endl;
			cout << "\tIndice de charge : " << camions[x]->roues[y].indiceCharge << endl;
			cout << "\tIndice de vitesse : " << camions[x]->roues[y].indiceVitesse << endl;
		}

	}
}

void saisirInformationVoiture(Voiture& tempCamion) {
	int interInt;
	string interString;
	do {
		// Numero série voiture
		cout << "Entrez le numero de serie de la voiture : ";
		cin >> interInt;
		tempCamion.setNumero_serie(interInt);

		// Marque voiture
		cout << "Entrez la marque de la voiture : ";
		cin >> interString;
		tempCamion.setMarque(interString);

		// Moteur de la voiture
		cout << "Entrez les informations du moteur de la voiture : " << endl;
		cout << "Numero de serie : ";
		cin >> interInt;
		tempCamion.moteur.setNumero_serie(interInt);
		cout << "Model : ";
		cin >> interString;
		tempCamion.moteur.setModel(interString);

		cout << "Puissance : ";
		cin >> interInt;
		if (!(tempCamion.verifierEntree(interInt))) {
			cout << "Veuillez entrer une valeur supérieure à 0 pour la puissance du moteur." << endl;
		}
		else {
			tempCamion.moteur.puissance = interInt;
			break;
		}

	} while (true); // Verifier si la puissance du moteur est supérieur à 0

	do {
		cout << "Cylindre : ";
		cin >> interInt;
		if (!(tempCamion.verifierEntree(interInt))) {
			cout << "Veuillez entrer une valeur supérieure à 0 pour la puissance du moteur." << endl;
		}
		else {
			tempCamion.moteur.cylindree = interInt;
			break;
		}

	} while (true); // Verifier si la cylindrée du moteur est supérieur à 0



	// Roues de la voiture
	for (int x = 0; x < tempCamion.roues.size(); x++) {
		cout << "Entrez les informations des roues numero " << x + 1 << " de la voiture : " << endl;
		cout << "Numero de serie : ";
		cin >> interInt;
		tempCamion.roues[x].setNumeruo_serie(interInt);

		cout << "Marque : ";
		cin >> interString;
		tempCamion.roues[x].setMarque(interString);

		// Largeur du pneu	
		do {
			cout << "Largeur : ";
			cin >> interInt;
			if (!(tempCamion.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour la largeur de la roue." << endl;
			}
			else {
				tempCamion.roues[x].largeur = interInt;
				break;
			}
		} while (true);

		// Hauteur du pneu
		do {
			cout << "Hauteur : ";
			cin >> interInt;
			if (!(tempCamion.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour la hauteur de la roue." << endl;
			}
			else {
				tempCamion.roues[x].hauteur = interInt;
				break;
			}
		} while (true); // Verifier si la largeur de la roue est supérieur à 0),

		// Radial du pneu
		do {
			cout << "Radial : ";
			cin >> interInt;
			if (!(tempCamion.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour le radial de la roue." << endl;
			}
			else {
				tempCamion.roues[x].radial = interInt;
				break;
			}
		} while (true);

		// Calcul du diametre de la roue
		tempCamion.roues[x].calculDiametre();
		cout << "Diametre : " << tempCamion.roues[x].diametre << endl;

		cout << "Indice de charge : ";
		cin >> tempCamion.roues[x].indiceCharge;
		cout << "Indice de vitesse : ";
		cin >> tempCamion.roues[x].indiceVitesse;

		if (x == 0) { // Lifechanger
			cout << "Voulez-vous ajouter les mêmes informations pour les autres roues ? (O/N) : ";
			cin >> interString;
			if (interString == "O" || interString == "o") {
				for (int y = 1; y < tempCamion.roues.size(); y++) {
					tempCamion.roues[y] = tempCamion.roues[0];
				}
				break;
			}
		}
	}
}
