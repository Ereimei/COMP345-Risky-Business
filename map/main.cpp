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
#include "Continent.h"

#define NEWLINE '\n'

void createMap(World* world);

/*
 * 
 */
int main(int argc, char** argv) {
    World* world = new World(5, 2);
    createMap(world);
    return 0;
}

void createMap(World* world) {
    Continent** continents = new Continent*[world->getContinentsCount()];
    continents[0] = new Continent("North America", 3);
    continents[1] = new Continent("Asia", 2);
    world->addContinents(continents);
    Territory* territory1 = new Territory("Alaska");
    continents[0]->addTerritory(territory1);
    Territory* territory2 = new Territory("Yukon");
    continents[0]->addTerritory(territory2);
    Territory* territory3 = new Territory("North Pole");
    continents[0]->addTerritory(territory3);
    Territory* territory4 = new Territory("Russia");
    continents[1]->addTerritory(territory4);
    Territory* territory5 = new Territory("Moon");
    Territory** adjTerrs1 = new Territory*[2];
    Territory** adjTerrs2 = new Territory*[2];
    Territory** adjTerrs3 = new Territory*[3];
    Territory** adjTerrs4 = new Territory*[1];
    adjTerrs1[0] = territory2;
    adjTerrs1[1] = territory3;
    world->addTerritory(territory1, 2, adjTerrs1);
    adjTerrs2[0] = territory1;
    adjTerrs2[1] = territory3;
    world->addTerritory(territory2, 2, adjTerrs2);
    adjTerrs3[0] = territory1;
    adjTerrs3[1] = territory2;
    adjTerrs3[2] = territory4;
    world->addTerritory(territory3, 3, adjTerrs3);
    adjTerrs4[0] = territory3;
    world->addTerritory(territory4, 1, adjTerrs4);
    world->addTerritory(territory5, 0, NULL);
}

