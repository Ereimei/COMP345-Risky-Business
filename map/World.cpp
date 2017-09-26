/* 
 * File:   World.cpp
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

#include "World.h"

World::World() : territoriesCount(0), insertPosition(0) {
    Node* terr = new Node[territoriesCount];
    territories = terr;
}

World::World(unsigned int terrcount) : territoriesCount(terrcount), insertPosition(0) {
    Node* terr = new Node[territoriesCount];
    territories = terr;
}

World::World(const World& orig) {}

World::~World() {}

void World::addTerritory(Territory* terr, unsigned int adjCount, Territory** adjTerrs) {
    if (insertPosition < territoriesCount) {
        territories[insertPosition].territory = terr;
        territories[insertPosition].adjacentCount = adjCount;
        territories[insertPosition].adjacentTerritories = adjTerrs;
        ++insertPosition;
    }
}

World::Node::Node() : territory(NULL), adjacentTerritories(NULL), adjacentCount(0) {
    
}

World::Node* World::getTerritories() {return territories;}
