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
Maploader::Maploader(string fileName){
    fileName = fileName; 
    generateWorld(world, fileName);
}

//Destructor
Maploader::~Maploader() {}

//Getters
string Maploader::getFileName() {return fileName;}



//Other functions
Maploader::generateWorld(World* world, string fileName) {
    vector<int> values;
    int numTerritories;
    int numContinents;
    
    values = analyseFile(fileName);
    numTerritories = values.at(0);
    numContinents = values.at(1);

    Maploader::generateMap(fileName, world);

    
}
//Returns a pointer to an array that contains two int: the amount of territories & continents
vector<int> Maploader::analyseFile(string fileName) {
    
    int continentsAmount = 0;
    int territoriesAmount = 0;
    
    std::ifstream reader(fileName);
    
    if (!reader){
        
        cout << "Error opening map file." << endl;
        vector<int> err(2);
        return err;
        
    } else {
        
        string line;
        
        //Skipping useless information at top of file
        for (int i = 0; i < 8; i ++){
            std::getline(reader, line);
        }
        
        //Counting the amount of continents
        for (;line != "";){
            std::getline(reader, line);
            if (line != ""){
                continentsAmount++;
            }
        }
        
        std::getline(reader, line);
        
        //Counting amount of territories
        for (;!reader.eof();){
            std::getline(reader, line);
            if (line != ""){
                territoriesAmount++;
            }
        }
        
        reader.close();
    }

    vector<int> test(2);
    
    test.at(0) = territoriesAmount;
    test.at(1) = continentsAmount;
    
    return test;
}

//Will add the required continents to the world
Maploader::generateMap(string fileName, World* world) {
    
    //First we generate the continents of the world
    //Continent** continents = new Continent*[world->getContinentsCount()];
    
    //Opening input file stream
    std::ifstream reader(fileName);
    
    if (!reader){
        
        cout << "Error opening map file." << endl;
        return -1;
        
    } else {
        string line;
        for (int i = 0; !reader.eof(); i++){
            
            std::getline(reader, line);
            cout << line;
            
            reader.close();
        }
    }
    
    
    
}


