#pragma once
#include <string>
#include "Roue.h"
#include <iostream>
#include "Moteur.h"
#include <vector>

using namespace std;

class Voiture
{
private:
	int numeroSerie;
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
		this->numeroSerie = 0;
		this->marque = "";
		setTableauRoues(); 
	}
	Voiture(const Voiture& voiture) {
		this->numeroSerie = voiture.numeroSerie;
		this->marque = voiture.marque;
		this->moteur = voiture.moteur;
		this->roues = voiture.roues;
	}
	~Voiture() {

	}

	/*
	* Méthode qui verifie si l'entrée est supérieur à 0 (obligatoire pour les numéros de série, puissance, cylindrée, etc.)
	*/
	bool verifierEntree(int entree) { 
		if (!(entree)) { // Verifier si l'entrée est alphanumérique (Autrement dit, verifie si le CIN à raté)
			cin.clear();
			cin.ignore(10000, '\n');
			return false; 
		}
		if (entree < 0) {
			return false; 
		}
		return true; 
	}

	/*
	* Getter et setter
	*/
	void setNumero_serie(int numero_serie) {
		this->numeroSerie = numero_serie;
	}
	void setMarque(string marque) {
		this->marque = marque;
	}
	int getNumero_serie() {
		return this->numeroSerie;
	}
	string getMarque() {
		return this->marque;
	}
};