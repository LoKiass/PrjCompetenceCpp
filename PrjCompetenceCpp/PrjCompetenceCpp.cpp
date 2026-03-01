
#include <iostream>
#include "VoitureElec.h"
#include "Camion.h"
#include <vector>

using namespace std;

/*
* Déclaration de fonction
*/
void afficherCamions(vector<Camion*> Camions); // Affichage des voitures et de leurs roues
void afficherVoituresElec(vector<VoitureElec*> voituresElec); // Affichage des voitures électriques et de leurs roues
void saisirInformationVoiture(Voiture& tempVoiture, bool isElec); // Saisie des informations de la voiture et de ses roues

int main()
{
	vector<Camion*> camions;
	vector<VoitureElec*> voituresElec;
	string interString;
	int interInt;
	// vector<Voiture *> voitures; // Sera ajouter lors des notions de polymorphisme
	string wait;
	do {
		do {
			cout << "Voulez vous ajouter une voiture electrique ou un camion ? (V/C) : ";
			cin >> interString;
			if (interString == "c" || interString == "C") {
				Camion* tempCamion = new Camion();
				saisirInformationVoiture(*tempCamion, false);

				do {
					cout << "Capacité de charge ";
					cin >> interInt;
					if (!(tempCamion->verifierEntree(interInt))) {
						cout << "Veuillez entrer une valeur supérieure à 0 pour la capacité de charge du camion." << endl;
					}
					else {
						tempCamion->setCapaciteCharge(interInt);
						break;
					}
				} while (true); // Verifier si la capacité de charge du camion est supérieur à 0),
				
				camions.push_back(tempCamion);
				tempCamion = nullptr;  // Nettoyage mémoire temporaire
				break;
			}
			else if (interString == "v" || interString == "V") {
				VoitureElec* tempVoitureElec = new VoitureElec();
				saisirInformationVoiture(*tempVoitureElec, true);
				do {
					cout << "Autonomie : ";
					cin >> interInt;
					if (!(tempVoitureElec->verifierEntree(interInt))) {
						cout << "Veuillez entrer une valeur supérieure à 0 pour l'autonomie de la voiture électrique." << endl;
					}
					else {
						tempVoitureElec->setAutonomie(interInt);
						break;
					}
				} while (true); // Verifier si l'autonomie de la voiture électrique est supérieur à 0),
				voituresElec.push_back(tempVoitureElec);
				tempVoitureElec = nullptr; // Nettoyage mémoire temporaire
				break;
			}
			else {
				cout << "Veuillez entrer V pour voiture ou C pour camion." << endl;
				break;
			}
		} while (true);

		cout << "Voulez-vous ajouter une autre voiture ? (O/N) : ";
		cin >> interString;
		if (interString != "O" && interString != "o") {
			break;
		}

	} while (true);

	system("cls"); // Nettoyage de la console
	
	if (camions.size() > 0) {
		afficherCamions(camions); // Affichage des voitures et de leurs roues
		for (int x = 0; x < camions.size(); x++) {
			delete camions[x]; // Libération de la mémoire allouée pour les voitures
		}
	}
	if (voituresElec.size() > 0) {
		afficherVoituresElec(voituresElec);
		for (int x = 0; x < voituresElec.size(); x++) {
			delete voituresElec[x]; // Libération de la mémoire allouée pour les voitures électriques
		}
	}
	camions.clear(); // Nettoyage du vecteur de voitures
	cin >> wait;

	return 0;
}
/*
* Cette fonction permet d'afficher toute les voitures électriques et leurs roues, ainsi que les informations de leurs moteurs.
*/
void afficherVoituresElec(vector<VoitureElec*> voituresElec) {
	for (int x = 0; x < voituresElec.size(); x++) {
		cout << "Voiture electrique numero " << x + 1 << " : " << endl;
		cout << "\tNumero de serie : " << voituresElec[x]->getNumero_serie() << endl;
		cout << "\tMarque : " << voituresElec[x]->getMarque() << endl;
		cout << "Moteur : " << endl;
		cout << "\tNumero de serie : " << voituresElec[x]->moteur.getNumero_serie() << endl;
		cout << "\tModel : " << voituresElec[x]->moteur.getModel() << endl;
		cout << "\tPuissance : " << voituresElec[x]->moteur.puissance << endl;
		for (int y = 0; y < voituresElec[x]->roues.size(); y++) {
			cout << "Roues numero " << y + 1 << " : " << endl;
			cout << "\tNumero de serie : " << voituresElec[x]->roues[y].getNumeruo_serie() << endl;
			cout << "\tMarque : " << voituresElec[x]->roues[y].getMarque() << endl;
			cout << "\tLargeur : " << voituresElec[x]->roues[y].largeur << endl;
			cout << "\tHauteur : " << voituresElec[x]->roues[y].hauteur << endl;
			cout << "\tRadial : " << voituresElec[x]->roues[y].radial << endl;
			cout << "\tDiametre : " << voituresElec[x]->roues[y].diametre << endl;
			cout << "\tIndice de charge : " << voituresElec[x]->roues[y].indiceCharge << endl;
			cout << "\tIndice de vitesse : " << voituresElec[x]->roues[y].indiceVitesse << endl;
		}
		cout << "\tAutonomie : " << voituresElec[x]->getAutonomie() <<" km"  << endl;
	}
}
/*
* Cette fonction permet d'afficher les informations des voitures et de leurs roues.
*/
void afficherCamions(vector<Camion*> camions) {
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
		cout << "\tCapacité de charge : " << camions[x]->getCapaciteCharge() << " tonnes" << endl;

	}
}
/*
* Cette fonction permet de saisir les informations d'une voiture et de ses roues.
*/
void saisirInformationVoiture(Voiture& tempVoiture, bool isElec) {
	int interInt;
	string interString;
	do {
		// Numero série voiture
		cout << "Entrez le numero de serie de la voiture : ";
		cin >> interInt;
		tempVoiture.setNumero_serie(interInt);

		// Marque voiture
		cout << "Entrez la marque de la voiture : ";
		cin >> interString;
		tempVoiture.setMarque(interString);

		// Moteur de la voiture
		cout << "Entrez les informations du moteur de la voiture : " << endl;
		cout << "Numero de serie : ";
		cin >> interInt;
		tempVoiture.moteur.setNumero_serie(interInt);
		cout << "Model : ";
		cin >> interString;
		tempVoiture.moteur.setModel(interString);

		cout << "Puissance : ";
		cin >> interInt;
		if (!(tempVoiture.verifierEntree(interInt))) {
			cout << "Veuillez entrer une valeur supérieure à 0 pour la puissance du moteur." << endl;
		}
		else {
			tempVoiture.moteur.puissance = interInt;
			break;
		}

	} while (true); // Verifier si la puissance du moteur est supérieur à 0

	if (isElec) tempVoiture.moteur.cylindree = NULL; // Si la voiture est électrique, la cylindrée du moteur est de 0
	else {
		do {
			cout << "Cylindre : ";
			cin >> interInt;
			if (!(tempVoiture.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour la puissance du moteur." << endl;
			}
			else {
				tempVoiture.moteur.cylindree = interInt;
				break;
			}

		} while (true); // Verifier si la cylindrée du moteur est supérieur à 0
	}
	
	// Roues de la voiture
	for (int x = 0; x < tempVoiture.roues.size(); x++) {
		cout << "Entrez les informations des roues numero " << x + 1 << " de la voiture : " << endl;
		cout << "Numero de serie : ";
		cin >> interInt;
		tempVoiture.roues[x].setNumeruo_serie(interInt);

		cout << "Marque : ";
		cin >> interString;
		tempVoiture.roues[x].setMarque(interString);

		// Largeur du pneu	
		do {
			cout << "Largeur : ";
			cin >> interInt;
			if (!(tempVoiture.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour la largeur de la roue." << endl;
			}
			else {
				tempVoiture.roues[x].largeur = interInt;
				break;
			}
		} while (true);

		// Hauteur du pneu
		do {
			cout << "Hauteur : ";
			cin >> interInt;
			if (!(tempVoiture.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour la hauteur de la roue." << endl;
			}
			else {
				tempVoiture.roues[x].hauteur = interInt;
				break;
			}
		} while (true); // Verifier si la largeur de la roue est supérieur à 0),

		// Radial du pneu
		do {
			cout << "Radial : ";
			cin >> interInt;
			if (!(tempVoiture.verifierEntree(interInt))) {
				cout << "Veuillez entrer une valeur supérieure à 0 pour le radial de la roue." << endl;
			}
			else {
				tempVoiture.roues[x].radial = interInt;
				break;
			}
		} while (true);

		// Calcul du diametre de la roue
		tempVoiture.roues[x].calculDiametre();
		cout << "Diametre : " << tempVoiture.roues[x].diametre << endl;

		cout << "Indice de charge : ";
		cin >> tempVoiture.roues[x].indiceCharge;
		cout << "Indice de vitesse : ";
		cin >> tempVoiture.roues[x].indiceVitesse;

		if (x == 0) { // Lifechanger
			cout << "Voulez-vous ajouter les mêmes informations pour les autres roues ? (O/N) : ";
			cin >> interString;
			if (interString == "O" || interString == "o") {
				for (int y = 1; y < tempVoiture.roues.size(); y++) {
					tempVoiture.roues[y] = tempVoiture.roues[0];
				}
				break;
			}
		}
	}
}