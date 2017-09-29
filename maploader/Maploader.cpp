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

Maploader::Maploader(string fn) : fileName(fn) {
    scanFile();
}

Maploader::~Maploader() {}

string Maploader::getFileName() {return fileName;}

void Maploader::scanFile() {
    unsigned int territoriesCount, continentsCount;
    string** continentNames;
    unsigned int continentTerritoriesCount;
    if (fileExists()){
        cout << fileName << " found, beginning scan..." << endl;
        if (validMapFile()) {
            //count the continents / territories
            cout << "This is a valid map file" << endl;
            continentsCount = countContinents();
            cout << "Number of continents: " << continentsCount << endl;
            territoriesCount = countTerritories();
            cout << "Number of territories: " << territoriesCount << endl;
            
            //create the world
            world = new World(territoriesCount, continentsCount);
            continents = new Continent*[world->getContinentsCount()];
            cout << "Map has been initialized, now populating map..." << endl;
            
            //create continents with how many territories they have;
            continentNames = getContinentNames();
            for (unsigned int n = 0; n < continentsCount; ++n) {
                continentTerritoriesCount = countTerritoriesInContinent(*continentNames[n]);
                continents[n] = new Continent(*continentNames[n], continentTerritoriesCount);
                cout << "Created continent " << continents[n]->getName() << " with " << continentTerritoriesCount << " territories" << endl;
            }
            world->addContinents(continents);
            
            //create territories
            
            
        } else {
            cout << "This is not a valid map file" << endl;
        }        
    } else {
        cout << fileName << " not found, terminating map loader..." << endl;
    }
    delete continentNames;
}

bool Maploader::fileExists() {
    bool result = false;
    if (ifstream(fileName)) {
        result = true;
    }
    return result;
}

//3 conditions for valid map, has: [Map], [Continents], [Territories]
bool Maploader::validMapFile() {
    unsigned int conditionsCount = 3, conditionsPosition = 0;
    bool result = true;
    bool conditionsMet[conditionsCount];
    string line;
    string conditions[3];
    ifstream file(fileName);
    for (int n = 0; n < conditionsCount; ++n) {
        conditionsMet[n] = false;
    }
    conditions[0] = "[Map]";
    conditions[1] = "[Continents]";
    conditions[2] = "[Territories]";
    
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == conditions[conditionsPosition]) {
                conditionsMet[conditionsPosition] = true;
                ++conditionsPosition;
            }    
        }
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    for (int n = 0; n < conditionsCount; ++n) {
        if (!conditionsMet[n]) {
            result = false;
            break;
        }
    }
    return result;
}

unsigned int Maploader::countContinents() {
    unsigned int result = 0;
    bool startCounting = false;
    string line;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            if (line == "[Continents]") {
                startCounting = true;
                continue;
            }
            if (startCounting) {
                if (line == "") {
                    break;
                }
                ++result;
            }
        }
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return result;
}

unsigned int Maploader::countTerritories() {
    unsigned int result = 0;
    bool startCounting = false;
    string line;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            if (line == "[Territories]") {
                startCounting = true;
                continue;
            }
            if (startCounting) {
                if (line == "") {
                    continue;
                }
                ++result;
            }
        }
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return result;
}

string** Maploader::getContinentNames() {
    unsigned int position = 0, continentsCount = world->getContinentsCount();
    string** continentNames = new string*[continentsCount];    
    bool startNaming = false;
    string segment, line, delimiter = "=";
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            if (line == "[Continents]") {
                startNaming = true;
                continue;
            }
            if (startNaming) {
                if (line == "") {
                    break;
                }
                segment = line.substr(0, line.find(delimiter));
                continentNames[position] = new string(segment);
                ++position;
                if (position >= continentsCount) {
                    break;
                }
            }
        }
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return continentNames;
}

unsigned int Maploader::countTerritoriesInContinent(string continentName) {
    unsigned int iterationCounter, result = 0;
    bool startCounting = false;
    string line;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            if (line == "[Territories]") {
                startCounting = true;
                continue;
            }
            if (startCounting) {
                if (line == "") {
                    continue;
                }
                iterationCounter = 0;
                stringstream stream(line);
                string token;
                while (getline(stream, token, ',')) {
                    if (iterationCounter == 3) {
                        if (token == continentName) {
                            ++result;
                        }
                    }
                    ++iterationCounter;
                }
            }
        }
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return result;
}
