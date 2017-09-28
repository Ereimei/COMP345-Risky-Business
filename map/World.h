/* 
 * File:   World.h
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #1
 * Professor: Dr. Joey Paquet
 *
 * Created on September 25, 2017, 3:17 PM
 */

#ifndef WORLD_H
#define WORLD_H

#include "Territory.h"
#include "Continent.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cerr;

class World {
public:
    World();
    World(unsigned int terrsCount, unsigned int contsCount);
    virtual ~World();
    void addTerritory(Territory* terr, unsigned int adjCount, Territory** adjTerrs);
    void addContinents(Continent** conts);
    unsigned int getContinentsCount() const;
    unsigned int getTerritoriesCount() const;
private:
    class Node {
    public:
        Node();
        Territory* territory;
        Territory** adjacentTerritories;
        unsigned int adjacentCount;
    };
    void DFS();
    unsigned int findPositionInArrayById(unsigned int id); 
    
    const unsigned int territoriesCount;
    const unsigned int continentsCount;
    unsigned int insertPosition;
    Node* territories;
    Continent** continents;
public:
    Node* getTerritories() const; //temporary function just for testing
    Continent** getContinents() const; //temporary function just for testing
};

#endif /* WORLD_H */

