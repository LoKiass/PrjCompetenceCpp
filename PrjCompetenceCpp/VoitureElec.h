#pragma once
#include "Voiture.h"
class VoitureElec : public Voiture
{
public :
	/*
	* Constructeur et deconstucteur
	*/
	VoitureElec() : Voiture() {
		this->autonomie = 0;
	}
	VoitureElec(VoitureElec *pVoitureElec) : Voiture(pVoitureElec) {
		this->autonomie = pVoitureElec->autonomie;
	}
	/*
	 * Setter et getter
	 */
	int getAutonomie() const {
		return this->autonomie;
	}
	void setAutonomie(int autonomie) {
		this->autonomie = autonomie;
	}
private:
	int autonomie; // Autonomie de la voiture électrique en kilomètres
};

