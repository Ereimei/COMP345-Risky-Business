/* 
 * File:   Maploader.cpp
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
 * Created on September 25, 2017, 7:09 PM
 */

#include "Maploader.h"
//unsigned int territoriesCount, continentsCount, continentTerritoriesCount;

Maploader::Maploader() : fileName(""),
    territoriesCount(0),
    continentsCount(0),
    continentTerritoriesCount(0),
    worldCreatedSuccessfully(false) {
    scanFile();
}

Maploader::Maploader(string fn) : fileName(fn),
    territoriesCount(0),
    continentsCount(0),
    continentTerritoriesCount(0),
    worldCreatedSuccessfully(false) {
    scanFile();
}

Maploader::~Maploader() {
    delete[] territories;
}

string Maploader::getFileName() {return fileName;}

void Maploader::scanFile() {
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
            getContinentNames();
            for (unsigned int n = 0; n < continentsCount; ++n) {
                continentTerritoriesCount = countTerritoriesInContinent(*continentNames[n]);
                continents[n] = new Continent(*continentNames[n], continentTerritoriesCount, armyBonuses[n]);
                cout << "Created continent " << continents[n]->getName() << " with " << continentTerritoriesCount << " territories" << " and an army bonus of: " << continents[n]->getArmyBonus() << endl;
            }
            world->addContinents(continents);
            
            //create territories
            createTerritories();
            
            //link each territory to their continents and adjacent territories
            //and add them to the world
            for (int n = 0; n < territoriesCount; ++n) {
                linkTerritory(n);
            }
            
            //lets us check if everything was created successfully
            worldCreatedSuccessfully = true;
            
            //free up the continentNames memory
            for (int n = 0; n < continentsCount; ++n) {
                delete continentNames[n];
            }
            delete[] continentNames;
            delete[] armyBonuses;
            
        } else {
            cout << "This is not a valid map file" << endl;
        }        
    } else {
        cout << fileName << " not found, terminating map loader..." << endl;
    }
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
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
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
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
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
        file.close();
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
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
            
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
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return result;
}

void Maploader::getContinentNames() {
    unsigned int position = 0, continentsCount = world->getContinentsCount(), bonus = 0;
    continentNames = new string*[continentsCount];
    armyBonuses = new unsigned int[continentsCount];
    bool startNaming = false;
    string segment, nextSegment, line, delimiter = "=";
    for (int n = 0; n < continentsCount; ++n) {
        armyBonuses[n] = 0;
    }
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
            if (line == "[Continents]") {
                startNaming = true;
                continue;
            }
            if (startNaming) {
                if (line == "") {
                    break;
                }
                segment = line.substr(0, line.find(delimiter));
                nextSegment = line.substr(line.find(delimiter) + 1, line.find(delimiter) + 1);
                bonus = std::stoi(nextSegment);
                armyBonuses[position] = bonus;
                continentNames[position] = new string(segment);
                ++position;
                if (position >= continentsCount) {
                    break;
                }
            }
        }
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
}

unsigned int Maploader::countTerritoriesInContinent(string continentName) {
    unsigned int iterationCounter, result = 0;
    bool startCounting = false;
    string line;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
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
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
    return result;
}

void Maploader::createTerritories() {
    unsigned int position = 0, territoriesCount = world->getTerritoriesCount();
    territories = new Territory*[territoriesCount];
    bool startCounting = false;
    string line;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
            if (line == "[Territories]") {
                startCounting = true;
                continue;
            }
            if (startCounting) {
                if (line == "") {
                    continue;
                }
                stringstream stream(line);
                string token;
                getline(stream, token, ',');
                territories[position] = new Territory(token);
                cout << "Created territory: " << territories[position]->getName() << endl;
                ++position;
            }
        }
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
}

void Maploader::linkTerritory(unsigned int position) {
    bool startCounting = false;
    unsigned int adjacentCount, territoriesCount = world->getTerritoriesCount();
    unsigned int continentsCount = world->getContinentsCount();
    string territoryName = territories[position]->getName();
    string line;
    vector<string> segments;
    Territory** adjacentTerritories;
    ifstream file(fileName);
    if (file.is_open()) {
        while (getline (file, line)) {
            // Remove line endings for the comparison
            line.erase(std::find_if(line.rbegin(), line.rend(), [](int ch) {
                return !std::isspace(ch);
            }).base(), line.end());
            if (line == "[Territories]") {
                startCounting = true;
                continue;
            }
            if (startCounting) {
                if (line == "") {
                    continue;
                }
                stringstream stream(line);
                string token;
                getline(stream, token, ',');
                if (territoryName == token) {
                    while(getline(stream, token, ',')) {
                        segments.push_back(token);
                    }
                    break;
                }
            }
        }
        //cout << segments.at(2) << endl; //position of continent
        //cout << segments.size() - 3 << endl; number of adjacent continents
        if (segments.size() > 0) {
            
            for (int n = 0; n < continentsCount; ++n) {
                if (continents[n]->getName() == segments.at(2)) {
                    continents[n]->addTerritory(territories[position]);
                }
            }
            
            adjacentCount = segments.size() - 3;
            adjacentTerritories = new Territory*[adjacentCount];
            for (int n = 0; n < adjacentCount; ++n) {
                for (int m = 0; m < territoriesCount; ++m) {
                    if (segments.at(n + 3) == territories[m]->getName()) {
                        adjacentTerritories[n] = territories[m];
                    }
                }
            }
            world->addTerritory(territories[position], adjacentCount, adjacentTerritories);
        }
        file.close();
    } else {
        cerr << "An error occurred trying to open " << fileName << endl;
    }
}

bool Maploader::worldValid() const {
    return worldCreatedSuccessfully;
}

World* Maploader::getWorld() const {
    return world;
}
