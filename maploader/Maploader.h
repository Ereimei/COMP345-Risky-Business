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

#include "../map/Continent.h"
#include "../map/Territory.h"
#include "../map/World.h"

class Maploader {
public:
    //Default Constructor
    Maploader(string fileName);
    //Copy constructor
    Maploader(const Maploader& orig);
    //Destructor
    virtual ~Maploader();
    
    //Getters
    const string getFileName();
    
private:
    //Attributes
    const string fileName;

    //Other functions
    generateWorld(string fileName);
    analyseFile();
    generateTerritories();
    generateContinents();
    
};

#endif /* MAPLOADER_H */

