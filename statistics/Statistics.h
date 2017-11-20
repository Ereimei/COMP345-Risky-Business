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
#include "../map/map.h"
#include "../player/Player.h"
#include "../dice/Diepool.h"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::string;
using std::endl;

class GameStatistics : public Observer {
public:
    GameStatistics();
    virtual ~GameStatistics();
    void update();
};

class PlayerDomination : public Observer {
public:
    PlayerDomination(World* w, unsigned int nplayers);
    virtual ~PlayerDomination();
    void update();
private:
    World* worldSubject;
    unsigned int numPlayers, numTerritories;
    unsigned int* playerTerritoriesCount;
    static string PLAYER_OWNERSHIP_GRAPH;
    static string PLAYER;
    static string OWNERLESS;
    static string GRAPH_DELIMITER_START;
    static string GRAPH_DELIMITER_END;
    static string GRAPH_ELEMENT;
    static string SPACE;
    static unsigned int GRAPH_MULTIPLIER;
};

#endif /* STATISTICS_H */

