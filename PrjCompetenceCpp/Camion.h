#pragma once
#include "Voiture.h"
class Camion : public Voiture{
public :
    /*
	* Constructeur et deconstucteur
    */
    Camion() : Voiture() {
        this->capaciteCharge = 0;
    }
    Camion(Camion *pCamion) : Voiture(pCamion) {
        this->capaciteCharge = pCamion->capaciteCharge;
	}
    /*
    * Setter et getter
    */
    int getCapaciteCharge() const {
        return this->capaciteCharge;
	}
    void setCapaciteCharge(int capaciteCharge) {
        this->capaciteCharge = capaciteCharge;
	}
private : 
	int capaciteCharge; // Capacité de charge du camion en tonnes
};

