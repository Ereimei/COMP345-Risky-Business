/* 
 * File:   main.cpp
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
 * Created on September 27, 2017, 7:09 PM
 */

#include <cstdlib>
#include <iostream>
#include "Maploader.h"

using namespace std;

int main(int argc, char** argv) {
    const string fileName;
    cout << "Please enter the name of the map file." << endl;
    cin >> fileName;
    
    //Generating the world
    Maploader mapLoader(fileName);
    
}


