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

#include "../interfaces/interfaces.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

/*
 * Just for future knowledge. Instead of adding a forward declaration for player,
 * effectively coupling Player and Territory together, we could've created a
 * struct which contains pairs of Player and Territory.
 */
class Player;

class Territory {
public:
    Territory();
    Territory(string n);
    Territory(const Territory& orig);
    virtual ~Territory();
    unsigned int getArmies() const;
    Player* getOwner() const;
    string getName() const;
    void setArmies(unsigned int arm);
    void setOwner(Player* own);
    unsigned int getId();
private:
    static unsigned int objectCount;
    unsigned int armies, id;
    Player* owner;
    const string name;
};

class Continent : public Subject {
public:
    Continent();
    Continent(string n, unsigned int terrsCount, unsigned int bonus);
    Continent(const Continent& orig);
    virtual ~Continent();
    void addTerritory(Territory* terr);
    string getName() const;
    unsigned int getTerritoriesCount() const;
    unsigned int getArmyBonus() const;
    int getOwnerPlayerNumber() const;
    Territory** getTerritories() const;
    void checkIfSingleOwner();
    static const int NOT_CONTROLLED;
private:
    const string name;
    const unsigned int territoriesCount;
    const unsigned int armyBonus;
    unsigned int insertPosition;
    int ownedByPlayer;
    Territory** territories;
};

class World : public Subject {
public:
    World();
    World(unsigned int terrsCount, unsigned int contsCount);
    World(const World& orig);
    virtual ~World();
    void addTerritory(Territory* terr, unsigned int adjCount, Territory** adjTerrs);
    void addContinents(Continent** conts);
    unsigned int getContinentsCount() const;
    unsigned int getTerritoriesCount() const;
    unsigned int findPositionInArrayByName(string name) const;
    bool setTerritoryOwner(string territoryName, Player* owner);
    bool setTerritoryOwner(unsigned int arrayPosition, Player* owner);
    bool checkSearchResult(unsigned int arrayPosition);
    
private:
    class Node {
    public:
        Node();
        virtual ~Node();
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
    Node* getTerritories() const;
    Continent** getContinents() const;
};

#endif /* MAP_H */
