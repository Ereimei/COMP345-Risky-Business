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

#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <cstdlib>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

class Territory {
public:
    Territory();
    Territory(string n);
    Territory(const Territory& orig);
    virtual ~Territory();
    unsigned int getArmies() const;
    string getOwner() const;
    string getName() const;
    void setArmies(unsigned int arm);
    void setOwner(string own);
    unsigned int getId();
private:
    static unsigned int objectCount;
    unsigned int armies, id;
    string owner;
    const string name;
};

class Continent {
public:
    Continent();
    Continent(string n, unsigned int terrsCount);
    Continent(const Continent& orig);
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

class World {
public:
    World();
    World(unsigned int terrsCount, unsigned int contsCount);
    World(const World& orig);
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

#endif /* MAP_H */