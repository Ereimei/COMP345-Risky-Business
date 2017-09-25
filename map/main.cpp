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

#define NEWLINE '\n'

/*
 * 
 */
int main(int argc, char** argv) {
    Territory* territory = new Territory(0, 0, 0, "Patrick");
    cout << territory->getOwner() << NEWLINE;
    territory->setOwner("Emily");
    cout << territory->getOwner() << NEWLINE;
    cout << territory->getInfantry() << NEWLINE;
    return 0;
}

