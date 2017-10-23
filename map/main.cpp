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

#include "map.h"

#define NEWLINE '\n'

void createMap(World* world);

/*
 * 
 */
int main(int argc, char** argv) {
    World* world = new World(4, 2);
    createMap(world);
    return 0;
}

void createMap(World* world) {

}

