#pragma once
#include <string>

using namespace std;

/*
* La classe roue contient les informations de la roue
*/

class Roue
{
private:
	int numeruo_serie;
	string marque;
public : 
	/*
	* Informations de la roue
	*/
	int largeur;
	int hauteur;
	int radial;
	int diametre;
	int indice_charge;
	int indice_vitesse;

	/*
	* Constructeur et destructeur
	*/
	Roue() { 
		this->largeur = 0;
		this->hauteur = 0;
		this->radial = 0;
		this->diametre = 0;
		this->indice_charge = 0;
		this->indice_vitesse = 0;
		this->marque = "";
		this->numeruo_serie = 0;
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
		this->numeruo_serie = numeruo_serie;
	}
	void setMarque(string marque) {
		this->marque = marque;
	}
	int getNumeruo_serie() {
		return this->numeruo_serie;
	}
	string getMarque() {
		return this->marque;
	}
};

