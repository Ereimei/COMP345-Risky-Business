/* 
 * File:   World.h
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #
 * Professor: Dr. Joey Paquet
 *
 * Created on September 25, 2017, 3:17 PM
 */

#ifndef WORLD_H
#define WORLD_H

#include "Territory.h"

class World {
public:
    World(unsigned int territoriesCount);
    World(const World& orig);
    virtual ~World();
    addTerritory(Territory* terr);
private:
    class Node {
    public:
        Node();
    private:
        Territory* territory;
        Territory* adjacentTerritories;
    };
    unsigned int territoriesCount;
    unsigned int insertPosition;
    Node* territories;
};

#endif /* WORLD_H */

