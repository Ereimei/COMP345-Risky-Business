/* 
 * File:   main.cpp
 * Author: Patrick Bednarski
 *
 * Created on September 19, 2017, 3:40 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::string;

#include "Territory.h"
#include "World.h"

#define NEWLINE '\n'

void createMap(World* world);

/*
 * 
 */
int main(int argc, char** argv) {
    World* world = new World(10);
    createMap(world);
    cout << world->getTerritories()[0].territory->getName() << NEWLINE;
    cout << world->getTerritories()[0].adjacentTerritories[0]->getName() << NEWLINE;
    cout << world->getTerritories()[0].adjacentTerritories[1]->getName() << NEWLINE;
    return 0;
}

void createMap(World* world) {
    Territory* territory1 = new Territory("Alaska", "North America");
    Territory* territory2 = new Territory("Yukon", "North America");
    Territory* territory3 = new Territory("North Pole", "North America");
    Territory** adjTerrs = new Territory*[2];
    adjTerrs[0] = territory2;
    adjTerrs[1] = territory3;
    world->addTerritory(territory1, 2, adjTerrs);
}

