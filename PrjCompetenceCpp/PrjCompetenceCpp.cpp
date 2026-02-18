// PrjCompetenceCpp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Voiture.h"
#include "vector"

using namespace std;

int main()
{
	vector<Voiture> voitures; 
	
	do {
		Voiture tempVoiture;

		int inter_int;
		string marque;
		
		// Numero série voiture
		cout << "Entrez le numero de serie de la voiture (0 pour terminer) : ";
		cin >> inter_int;
		tempVoiture.setNumero_serie(inter_int);

		// Marque voiture
		cout << "Entrez la marque de la voiture : ";
		cin >> marque;
		tempVoiture.setMarque(marque);

		// Roues de la voiture
		for (int x = 0; x < 4; x++) {
			cout << "Entrez les informations des roues numero " << x + 1 << " de la voiture : " << endl;
			cout << "Numero de serie : ";
			cin >> inter_int;
			tempVoiture.roues[x].setNumeruo_serie(inter_int);
			cout << "Marque : ";
			cin >> marque;
			tempVoiture.roues[x].setMarque(marque);
			cout << "Largeur : ";
			cin >> tempVoiture.roues[x].largeur;
			cout << "Hauteur : ";
			cin >> tempVoiture.roues[x].hauteur;
			cout << "Radial : ";
			cin >> tempVoiture.roues[x].radial;
			cout << "Diametre : ";
			cin >> tempVoiture.roues[x].diametre; // Dans le future, le calculer dans une methode de la classe roue
			cout << "Indice de charge : ";
			cin >> tempVoiture.roues[x].indice_charge;
			cout << "Indice de vitesse : ";
			cin >> tempVoiture.roues[x].indice_vitesse;
		}

		try {
			voitures.push_back(tempVoiture);
		}
		catch (const exception& e) {
			cerr << "Erreur lors de l'ajout de la voiture : " << e.what() << endl;
		} 

		cout << "Voulez-vous ajouter une autre voiture ? (O/N) : ";
		cin >> marque;
		if (marque != "O" && marque != "o") {
			break;
		}
	} while (true);

	return 0;
}
