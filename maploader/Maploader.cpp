/* 
 * File:   Maploader.cpp
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
 * Created on September 25, 2017, 7:09 PM
 */
#include <iostream>
#include <tuple>
#include "Maploader.h"
#include "../map/Continent.h"
#include "../map/World.h"
#include "../map/Territory.h"


//Default constructor
Maploader::Maploader(const string fileName) : fileName(fileName) {this->generateWorld(fileName);}
//Copy constructor
Maploader::Maploader(const Maploader& orig) : fileName(orig.getFileName()) {}
//Destructor
Maploader::~Maploader() {}

//Getters
const string Maploader::getFileName() const {return fileName;}

//Other functions
Maploader::generateWorld(string fileName) {
    int* values;
    int numTerritories;
    int numContinents;
    
    values = analyseFile(fileName);
    numTerritories = &values++;
    numContinents = &values;
    
    World* world = new World(numTerritories, numContinents);
    
    generateMap(fileName, world);
    
}
//Returns a pointer to an array that contains two int: the amount of territories & continents
int* Maploader::analyseFile(string fileName) {}

//Will add the required continents to the world
Maploader::generateMap(string fileName, World* world) {

    //First we generate the continents of the world
    Continent** continents = new Continent*[world->getContinentsCount()];
    
    
    
    
    
}


