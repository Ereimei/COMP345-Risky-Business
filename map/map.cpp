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

#include "map.h"

unsigned int Territory::objectCount = 1;

Territory::Territory() : armies(0),
    owner(""),
    name("Default"),
    id(objectCount++) {
    cerr << "Called Territory default constructor" << endl;
    exit(EXIT_FAILURE);
}

Territory::Territory(string n) : armies(0),
    owner(""),
    name(n),
    id(objectCount++) {}

Territory::Territory(const Territory& orig) : armies(orig.getArmies()),
    owner(orig.getOwner()),
    name(orig.getName()),
    id(objectCount++) {}

Territory::~Territory() {}

unsigned int Territory::getArmies() const {return armies;}
string Territory::getOwner() const {return owner;}
string Territory::getName() const {return name;}
void Territory::setArmies(unsigned int arm) {armies = arm;}
void Territory::setOwner(string own) {owner = own;}
unsigned int Territory::getId() {return id;}

Continent::Continent() : name(""),
    territoriesCount(0),
    insertPosition(0) {
    cerr << "Called Continent default constructor" << endl;
    exit(EXIT_FAILURE);
}

Continent::Continent(string n, unsigned int terrsCount) : name(n),
    territoriesCount(terrsCount),
    insertPosition(0) {
    Territory** terrs = new Territory*[territoriesCount];
    territories = terrs;
}

Continent::Continent(const Continent& orig) : name(orig.getName()),
    territoriesCount(orig.getTerritoriesCount()),
    insertPosition(0) {}

Continent::~Continent() {
    delete[] territories;    
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

Territory** Continent::getTerritories() const {return territories;}

World::World() : territoriesCount(0),
    insertPosition(0),
    continentsCount(0) {
    cerr << "Called World default constructor" << endl;
    exit(EXIT_FAILURE);
}

World::World(unsigned int terrsCount, unsigned int contsCount) : territoriesCount(terrsCount),
    insertPosition(0),
    continentsCount(contsCount) {
    Node* terr = new Node[territoriesCount];
    territories = terr;
}

World::World(const World& orig) : territoriesCount(orig.getTerritoriesCount()),
    insertPosition(0),
    continentsCount(orig.getContinentsCount()) {
    Node* terr = new Node[territoriesCount];
    territories = terr;
}

World::~World() {
    delete[] territories;
    for (int n = 0; n < continentsCount; ++n) {
        delete continents[n];
    }
    delete[] continents;
}

void World::addTerritory(Territory* terr, unsigned int adjCount, Territory** adjTerrs) {
    if (insertPosition < territoriesCount) {
        territories[insertPosition].territory = terr;
        territories[insertPosition].adjacentCount = adjCount;
        territories[insertPosition].adjacentTerritories = adjTerrs;
        ++insertPosition;
        if (insertPosition == territoriesCount) {
            DFS();
        }
    } else {
        cerr << "World is already full!\n";
    }
}

World::Node::Node() : territory(NULL), adjacentTerritories(NULL), adjacentCount(0) {
    
}

World::Node::~Node() {
    delete territory;
    delete[] adjacentTerritories;
}

unsigned int World::getContinentsCount() const {return continentsCount;}

unsigned int World::getTerritoriesCount() const {return territoriesCount;}

void World::addContinents(Continent** conts) {
    unsigned int terrsCount = 0;
    for (unsigned int n = 0; n < continentsCount; ++n) {
        terrsCount += conts[n]->getTerritoriesCount(); //what if the pointer points to null? yolo!
    }
    if (terrsCount == territoriesCount) {
        continents = conts;
    } else {
        cerr << "Your continents have to have the same number of territories as the whole map!\n";
        exit(EXIT_FAILURE);
    }
}

void World::DFS() {
    bool visited[territoriesCount];
    unsigned int stack[territoriesCount + 1];
    unsigned int idToVisit, stackPosition = 0, positionInArray, adjacentId, adjacentPositionInArray;
    bool keepGoing = true, isConnected = true;
    for (unsigned int n = 0; n < territoriesCount; ++n) {
        visited[n] = false;
        stack[n] = 0;
    }
    stack[stackPosition] = territories[0].territory->getId(); //set the point of entry into the graph
    ++stackPosition;
    while (keepGoing) {
        keepGoing = false;
        
        //pop the stack
        (stackPosition == 0) ? : --stackPosition;
        idToVisit = stack[stackPosition];
        stack[stackPosition] = 0;
        
        //visit the node
        positionInArray = findPositionInArrayById(idToVisit);
        if (positionInArray >= territoriesCount) {
            cerr << "Id not found in the array\n";
            break;
        }
        visited[positionInArray] = true;
        
        //add adjacent territories to stack if they aren't visited
        for (unsigned int n = 0; n < territories[positionInArray].adjacentCount; ++n) {
            adjacentId = territories[positionInArray].adjacentTerritories[n]->getId();
            adjacentPositionInArray = findPositionInArrayById(adjacentId);
            if (!visited[adjacentPositionInArray]) {
                
                //push to stack
                stack[stackPosition] = adjacentId;
                ++stackPosition;
                visited[adjacentPositionInArray] = true;
                //I know the above statement hasn't actually visited the node
                //but it's already in the stack so it will have to be visited
                //this way if there is a cycle in the graph it won't get added
                //to the stack another time.
            }
        }
        
        //check if stack is empty        
        for (unsigned int n = 0; n < territoriesCount; ++n) {
            if (stack[n] > 0) {
                keepGoing = true;
                break;
            }
        }
    }
    for (int n = 0; n < territoriesCount; ++n) {
        if (!visited[n]) {
            isConnected = false;
            break;
        }
    }
    if (isConnected) {
        cout << "This is a connected graph!\n";
    } else {
        cerr << "This is not a connected graph\n";
    }
}

unsigned int World::findPositionInArrayById(unsigned int id) {
    unsigned int n;
    for (n = 0; n < territoriesCount; ++n) {
        if (territories[n].territory->getId() == id) {
            break;
        }
    }
    return n;
}

World::Node* World::getTerritories() const {return territories;}

Continent** World::getContinents() const {return continents;}
