/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapLoader.h
 * Author: olitr
 *
 * Created on September 25, 2017, 7:12 PM
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

