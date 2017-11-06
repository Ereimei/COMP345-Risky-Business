/* 
 * File:   Statistics.cpp
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #
 * Professor: Dr. Joey Paquet
 * 
 * Created on November 4, 2017, 11:13 PM
 */

#include "Statistics.h"

Statistics::Statistics(World* w, unsigned int nplayers) :
    numPlayers(nplayers),
    numTerritories(w->getTerritoriesCount()) {
    worldSubject = w;
    worldSubject->attach(this);
    playerTerritoriesCount = new unsigned int[numPlayers];
}

Statistics::~Statistics() {
    worldSubject->detach(this);
    delete[] playerTerritoriesCount;
}

void Statistics::update() {
    unsigned int ownerlessTerritories;
    ownerlessTerritories = numTerritories;
    for (int n = 0; n < numPlayers; ++n) {
        playerTerritoriesCount[n] = 0;
    }
    for (int n = 0; n < numTerritories; ++n) {
        if (worldSubject->getTerritories()[n].territory->getOwner() != NULL) {
            --ownerlessTerritories;
            ++playerTerritoriesCount[worldSubject->getTerritories()[n].territory->getOwner()->getPlayerNum()];
        }
    }
}
