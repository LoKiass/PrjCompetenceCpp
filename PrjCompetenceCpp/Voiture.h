#pragma once
#include <string>
#include "Roue.h"
#include "Moteur.h"
#include <vector>
using namespace std;

class Voiture
{
private:
	int numero_serie;
	string marque;
	/*
	On considère que la voiture doit avoir 4 roues, on peut ajouter une méthode pour remplir le tableau de roues
	La méthode doit être appele 1 seules fois ! 
	*/
	void setTableauRoues(){
		for (int x = 0; x < 4; x++) {
			this->roues.push_back(Roue());
		}
	}
public :
	Moteur moteur; // Une voiture a un moteur
	vector<Roue> roues; // Une voiture peut avoir plusieurs roues (MAX/MIN 4)
	Voiture() { // Informations de base pour une voiture, avec 4 roues de base
		this->numero_serie = 0;
		this->marque = "";
		setTableauRoues(); 
	}
	Voiture(const Voiture& voiture) {
		this->numero_serie = voiture.numero_serie;
		this->marque = voiture.marque;
		this->moteur = voiture.moteur;
		this->roues = voiture.roues;
	}
	~Voiture() {

	}

	/*
	* Getter et setter
	*/
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
};