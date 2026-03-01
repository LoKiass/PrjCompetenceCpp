#pragma once
#include "Voiture.h"
class Camion : public Voiture{
public :
    Camion() : Voiture() {
        this->capaciteCharge = 0;
    }
    Camion(Camion *pCamion) : Voiture(pCamion) {
        this->capaciteCharge = pCamion->capaciteCharge;
	}
private : 
	int capaciteCharge; // Capacité de charge du camion en tonnes
};

