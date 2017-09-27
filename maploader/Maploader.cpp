/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MapLoader.cpp
 * Author: olitr
 * 
 * Created on September 25, 2017, 7:12 PM
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