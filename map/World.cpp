/* 
 * File:   World.cpp
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

#include "World.h"

World::World() : territoriesCount(0),
    insertPosition(0),
    continentsCount(0) {
    exit(EXIT_FAILURE);
}

World::World(unsigned int terrsCount, unsigned int contsCount) : territoriesCount(terrsCount),
    insertPosition(0),
    continentsCount(contsCount) {
    Node* terr = new Node[territoriesCount];
    territories = terr;
}

World::~World() {}

void World::addTerritory(Territory* terr, unsigned int adjCount, Territory** adjTerrs) {
    if (insertPosition < territoriesCount) {
        territories[insertPosition].territory = terr;
        territories[insertPosition].adjacentCount = adjCount;
        territories[insertPosition].adjacentTerritories = adjTerrs;
        ++insertPosition;
    } else {
        cerr << "World is already full!\n";
    }
}

World::Node::Node() : territory(NULL), adjacentTerritories(NULL), adjacentCount(0) {
    
}

unsigned int World::getContinentsCount() const {return continentsCount;}

unsigned int World::getTerritoriesCount() const {return territoriesCount;}

void World::addContinents(Continent** conts) {
    unsigned int terrsCount = 0;
    for (unsigned int n = 0; n < continentsCount; ++n) {
        terrsCount += conts[n]->getTerritoriesCount(); //what if the pointer is null? yolo!
    }
    if (terrsCount == territoriesCount) {
        continents = conts;
    } else {
        cerr << "Your continents have to have the same number of territories as the whole map!\n";
        exit(EXIT_FAILURE);
    }
}

void World::DFS() {
    
}

World::Node* World::getTerritories() const {return territories;}

Continent** World::getContinents() const {return continents;}
