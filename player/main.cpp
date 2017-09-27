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
 * Created on September 27, 2017, 3:40 PM
 */

#include <cstdlib>
#include <iostream>
#include "Player.h"

using namespace std;

int main(int argc, char** argv) {
    
    cout << "Creating player object." << endl;
    Player demoplayer;
    
    cout << endl << "Player owns a hand of Risk cards" << endl;
    cout << demoplayer.getHand() << endl;
    
    cout << endl << "Player has his own dice rolling facility object" << endl;
    cout << demoplayer.getDiepool() << endl;
    
    cout << endl << "Player has his own territories" << endl;
    cout << demoplayer.getTerritories() << endl;
    
    cout << "Player's functions" << endl << "-------------------" << endl;
    cout << demoplayer.attack() << endl;
    cout << demoplayer.fortify() << endl;
    cout << demoplayer.reinforce() << endl;
    
    
}

