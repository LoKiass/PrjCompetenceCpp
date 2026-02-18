#pragma once
#include <string>
#include "Roue.h"
#include <vector>
using namespace std;

class Voiture
{
private:
	int numero_serie;
	string marque;

	// Getter et setter
	void setNumero_serie(int numero_serie) {
		this->numero_serie = numero_serie;
	}
	void setMarque(string marque) {
		this->marque = marque;
	}
	int getNumero_serie() {
		return this->numero_serie;
	}
	string getMarque() {
		return this->marque;
	}
public :
	vector<Roue> roues; // Une voiture peut avoir plusieurs roues (MAX/MIN 4)
	Voiture() { // Informations de base pour une voiture
		this->numero_serie = 0;
		this->marque = "";
	}
	~Voiture() {

	}
};