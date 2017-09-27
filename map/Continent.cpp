/* 
 * File:   Continent.cpp
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
 * Created on September 25, 2017, 3:19 PM
 */

#include "Continent.h"

Continent::Continent() : name(""),
    territoriesCount(0),
    insertPosition(0) {
    exit(EXIT_FAILURE);
}

Continent::Continent(string n, unsigned int terrsCount) : name(n),
    territoriesCount(terrsCount),
    insertPosition(0) {
    Territory** terrs = new Territory*[territoriesCount];
    territories = terrs;
}

Continent::~Continent() {
}

void Continent::addTerritory(Territory* terr) {
    if (insertPosition < territoriesCount) {
        territories[insertPosition] = terr;
        ++insertPosition;
    } else {
        cerr << "Continent is already full!\n";
    }
}

string Continent::getName() const {return name;}

unsigned int Continent::getTerritoriesCount() const {return territoriesCount;}
