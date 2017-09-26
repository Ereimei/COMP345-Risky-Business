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

/*
 * 
 */
int main(int argc, char** argv) {
    Territory* territory = new Territory("Alaska", "North America");
    territory->setOwner("Emily");
    cout << territory->getOwner() << NEWLINE;
    cout << territory->getName() << NEWLINE;
    cout << territory->getContinent() << NEWLINE;
    World* world = new World(10);
    return 0;
}

