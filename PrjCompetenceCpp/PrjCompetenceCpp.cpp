#include <iostream>
#include "Voiture.h"
#include "vector"

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

		int inter_int;
		string marque;
		
		// Numero série voiture
		cout << "Entrez le numero de serie de la voiture : ";
		cin >> inter_int;
		tempVoiture.setNumero_serie(inter_int);

		// Marque voiture
		cout << "Entrez la marque de la voiture : ";
		cin >> marque;
		tempVoiture.setMarque(marque);

		// Moteur de la voiture
		cout << "Entrez les informations du moteur de la voiture : " << endl;
		cout << "Numero de serie : ";
		cin >> inter_int;
		tempVoiture.moteur.setNumero_serie(inter_int);
		cout << "Model : ";
		cin >> marque;
		tempVoiture.moteur.setModel(marque);
		cout << "Puissance : ";
		cin >> tempVoiture.moteur.puissance;
		cout << "Cylindree : ";
		cin >> tempVoiture.moteur.cylindree;


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
			
			tempVoiture.roues[x].calculDiametre(); // Calcul du diametre de la roue
			cout << "Diametre : " << tempVoiture.roues[x].diametre << endl;

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
		cout << "Nombre de voitures : " << voitures.size() << endl;
		cout << "Nombre de roues : " << voitures[0].roues.size() << endl;
		cout << "Voulez-vous ajouter une autre voiture ? (O/N) : ";
		cin >> marque;
		if (marque != "O" && marque != "o") {
			break;
		}

	} while (true);

	system("cls"); // Nettoyage de la console
	afficherVoiture(voitures); // Affichage des voitures et de leurs roues
	cin >> wait;

	return 0;
}

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
			cout << "\tIndice de charge : " << voitures[x].roues[y].indice_charge << endl;
			cout << "\tIndice de vitesse : " << voitures[x].roues[y].indice_vitesse << endl;
		}

	}
}
