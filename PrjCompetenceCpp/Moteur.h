#pragma once
#include <string>

using namespace std;

/*
* La classe moteur contient les informations du moteur
*/

class Moteur
{
private:
	int numeroSerie;
	string model;
public:
	int puissance; // Puissance du moteur en chevaux
	int cylindree; // Cylindrée du moteur en cm3

	/*
	* Constructeur et deconstucteur
	*/


	/*
	* Verifier les entrées fournies par l'utilisateur
	*/
	Moteur() {
		this->cylindree = 0;
		this->puissance = 0;
		this->numeroSerie = 0;
		this->model = "";
	}
	Moteur(const Moteur& moteur) {
		this->cylindree = moteur.cylindree;
		this->puissance = moteur.puissance;
		this->numeroSerie = moteur.numeroSerie;
		this->model = moteur.model;
	}
	~Moteur() {
	}

	/*
	* Setter et getter
	*/
	void setNumero_serie(int numero_serie) {
		this->numeroSerie = numero_serie;
	}
	void setModel(string model) {
		this->model = model;
	}
	int getNumero_serie() {
		return this->numeroSerie;
	}
	string getModel() {
		return this->model;
	}
};

