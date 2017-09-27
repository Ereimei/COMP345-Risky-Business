/* 
 * File:   Continent.h
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

#ifndef CONTINENT_H
#define CONTINENT_H

#include "Territory.h"

#include <string>
#include <cstdlib>
#include <iostream>

using std::string;
using std::cerr;

class Continent {
public:
    Continent();
    Continent(string n, unsigned int terrsCount);
    virtual ~Continent();
    void addTerritory(Territory* terr);
    string getName() const;
    unsigned int getTerritoriesCount() const;
    Territory** getTerritories() const;
private:
    const string name;
    const unsigned int territoriesCount;
    unsigned int insertPosition;
    Territory** territories;
};

#endif /* CONTINENT_H */

