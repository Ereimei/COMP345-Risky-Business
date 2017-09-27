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

#include "Maploader.h"

//Default constructor
Maploader::Maploader(const string fileName) : fileName(fileName) {this->generateWorld(fileName);}
//Copy constructor
Maploader::Maploader(const Maploader& orig) : fileName(orig.getFileName()) {}
//Destructor
Maploader::~Maploader() {}

//Getters
const string Maploader::getFileName() const {return fileName;}

//Other functions
Maploader::generateWorld(string fileName) {}
Maploader::analyseFile() {}
Maploader::generateTerritories() {}
Maploader::generateContinents() {}