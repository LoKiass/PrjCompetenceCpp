
#include <iostream>
#include "Voiture.h"
#include <vector>

using namespace std;

/*
* Déclaration de fonction 
*/
void afficherVoiture(vector<Voiture>& voitures); // Affichage des voitures et de leurs roues

int main()
{
	vector<Voiture> voitures; 
	string wait;


	do {
		Voiture tempVoiture;

		int interInt;
		string interString;

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

		do { 
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

		try {
			voitures.push_back(tempVoiture);
		}
		catch (const exception& e) {
			cerr << "Erreur lors de l'ajout de la voiture : " << e.what() << std::endl;
		} 
		//cout << "Nombre de voitures : " << voitures.size() << endl;
		//cout << "Nombre de roues : " << voitures[0].roues.size() << endl;
		cout << "Voulez-vous ajouter une autre voiture ? (O/N) : ";
		cin >> interString;
		if (interString != "O" && interString != "o") {
			break;
		}

	} while (true);

	system("cls"); // Nettoyage de la console
	afficherVoiture(voitures); // Affichage des voitures et de leurs roues
	cin >> wait;

	return 0;
}
/*
* Cette fonction permet d'afficher les informations des voitures et de leurs roues.
*/
void afficherVoiture(vector<Voiture>& voitures) {
	for (int x = 0; x < voitures.size(); x++) {
		cout << "Voiture numero " << x + 1 << " : " << endl;
		cout << "\tNumero de serie : " << voitures[x].getNumero_serie() << endl;
		cout << "\tMarque : " << voitures[x].getMarque() << endl;
		cout << "Moteur : " << endl;
		cout << "\tNumero de serie : " << voitures[x].moteur.getNumero_serie() << endl;
		cout << "\tModel : " << voitures[x].moteur.getModel() << endl;
		cout << "\tPuissance : " << voitures[x].moteur.puissance << endl;
		cout << "\tCylindree : " << voitures[x].moteur.cylindree << endl;
		for (int y = 0; y < voitures[x].roues.size(); y++) {
			cout << "Roues numero " << y + 1 << " : " << endl;
			cout << "\tNumero de serie : " << voitures[x].roues[y].getNumeruo_serie() << endl;
			cout << "\tMarque : " << voitures[x].roues[y].getMarque() << endl;
			cout << "\tLargeur : " << voitures[x].roues[y].largeur << endl;
			cout << "\tHauteur : " << voitures[x].roues[y].hauteur << endl;
			cout << "\tRadial : " << voitures[x].roues[y].radial << endl;
			cout << "\tDiametre : " << voitures[x].roues[y].diametre << endl;
			cout << "\tIndice de charge : " << voitures[x].roues[y].indiceCharge << endl;
			cout << "\tIndice de vitesse : " << voitures[x].roues[y].indiceVitesse << endl;
		}

	}
}
