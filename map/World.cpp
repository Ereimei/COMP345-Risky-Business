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

World::World(unsigned int terrcount) : territoriesCount(terrcount), insertPosition(0) {
    Node terr[territoriesCount];
}

World::World(const World& orig) {}

World::~World() {}

World::addTerritory(Territory* terr) {

}

World::Node::Node() : territory(NULL), adjacentTerritories(NULL) {
    
}
