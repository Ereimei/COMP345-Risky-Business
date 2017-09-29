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
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::cerr;
using std::stringstream;

#include "../map/map.h"

class Maploader {
public:
    Maploader(string fn);
    virtual ~Maploader();    
    string getFileName();
    generateWorld(World* world, string fileName);    
private:
    std::vector<int> analyseFile(string fileName);
    generateMap(string fileName, World* world);  
    void scanFile();
    void createTerritories();
    void linkTerritory(unsigned int position);
    bool fileExists();
    bool validMapFile();
    unsigned int countContinents();
    unsigned int countTerritories();
    unsigned int countTerritoriesInContinent(string continentName);
    string** getContinentNames();
    const string fileName;
    World* world;
    Continent** continents;
    Territory** territories;
};

#endif /* MAPLOADER_H */

