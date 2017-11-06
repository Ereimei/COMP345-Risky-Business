/* 
 * File:   Statistics.h
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #3
 * Professor: Dr. Joey Paquet
 *
 * Created on November 4, 2017, 11:13 PM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include "../interfaces/interfaces.h"
#include "../player/Player.h"
#include "../map/map.h"
#include "../dice/Diepool.h"

#include <iostream>

using std::cout;

class Statistics : public Observer {
public:
    Statistics(World* w, unsigned int nplayers, Player** p);
    virtual ~Statistics();
    void update();
private:
    World* worldSubject;
    Player** players;
    unsigned int numPlayers, numTerritories;
    unsigned int* playerTerritoriesCount;
};

#endif /* STATISTICS_H */

