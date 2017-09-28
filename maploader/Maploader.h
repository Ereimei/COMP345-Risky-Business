/* 
 * File:   Maploader.h
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

#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <vector>

#include "../map/Continent.h"
#include "../map/Territory.h"
#include "../map/World.h"

class Maploader {
public:
    //Default Constructor
    Maploader(string fileName);
    //Destructor
    virtual ~Maploader();
    
    //Getters
    string getFileName();
    
private:
    //Attributes
    const string fileName;

    //Other functions
    generateWorld(string fileName);
    std::vector<int> analyseFile(string fileName);
    generateMap(string fileName, World* world);

    
};

#endif /* MAPLOADER_H */

