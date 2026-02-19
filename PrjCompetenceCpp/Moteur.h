#pragma once
#include <string>

using namespace std;

/*
* La classe moteur contient les informations du moteur
*/

class Moteur
{
private:
	int numero_serie;
	string model;
public:
	int puissance; // Puissance du moteur en chevaux
	int cylindree; // Cylindrée du moteur en cm3

	/*
	* Constructeur et deconstucteur
	*/
	Moteur() {
		this->cylindree = 0;
		this->puissance = 0;
		this->numero_serie = 0;
		this->model = "";
	}
	Moteur(const Moteur& moteur) {
		this->cylindree = moteur.cylindree;
		this->puissance = moteur.puissance;
		this->numero_serie = moteur.numero_serie;
		this->model = moteur.model;
	}
	~Moteur() {
	}

	/*
	* Setter et getter
	*/
	void setNumero_serie(int numero_serie) {
		this->numero_serie = numero_serie;
	}
	void setModel(string model) {
		this->model = model;
	}
	int getNumero_serie() {
		return this->numero_serie;
	}
	string getModel() {
		return this->model;
	}
};

