/* 
 * File:   main.cpp
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

#include "../map/map.h"
#include "Maploader.h"

#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    string fileName;
    cout << "Please enter the name of the map file." << endl;
    cin >> fileName;
    //Generating the world
    Maploader* mapLoader = new Maploader(fileName);
//    World* world;
//    if (mapLoader->worldValid()) {
//        world = mapLoader->getWorld();
//        delete mapLoader;
//    }
//    cout << world->getTerritories()[0].territory->getName() << endl;
//    cout << world->getContinents()[0]->getName() << endl;
//    delete world;
}


