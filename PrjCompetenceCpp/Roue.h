#pragma once
#include <string>

using namespace std;

/*
* La classe roue contient les informations de la roue
*/

class Roue
{
private:
	int numeroSerie;
	string marque;
public : 
	/*
	* Informations de la roue
	*/
	int largeur;
	int hauteur;
	int radial;
	int diametre;
	int indiceCharge;
	int indiceVitesse;

	/*
	* Constructeur et destructeur
	*/
	Roue() { 
		this->largeur = 0;
		this->hauteur = 0;
		this->radial = 0;
		this->diametre = 0;
		this->indiceCharge = 0;
		this->indiceVitesse = 0;
		this->marque = "";
		this->numeroSerie = 0;
	}
	~Roue() {

	}
	/*
	* Cette méthode vas permettre de calculer le diametre de la roue en fonction de sa hauteur, largeur et de son radial
	*/
	void calculDiametre() { // Calcul du diametre de la roue
		this->diametre = (this->hauteur * 2) + (this->largeur * this->radial / 100);
	}

	/*
	* Getter et setter
	*/
	void setNumeruo_serie(int numeruo_serie) {
		this->numeroSerie = numeruo_serie;
	}
	void setMarque(string marque) {
		this->marque = marque;
	}
	int getNumeruo_serie() {
		return this->numeroSerie;
	}
	string getMarque() {
		return this->marque;
	}
};

