/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: main.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 2
Professor: Dr. Joey Paquet
Created on October 15, 2017, 11:25 PM */

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector> 

#include "startup.h"
#include "../gamestarter/GameStarter.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "start up ..." << endl;
    cout << "===========================" << endl;
    GameStarter* gs = new GameStarter();
    gs->startGame();
    cout << "===========================" << endl;
    cout << "There are " << gs->getNumPlayers() <<" players." << endl;
    Startup* su = new Startup(gs->getPlayers(),gs->getNumPlayers());
    su->displayPlayerOrder();
    cout << "===========================" << endl;
    int size = gs->getWorld()->getTerritoriesCount();
    cout << "There are " << size << " territories." << endl;
    su->assignTerritory(su->getAllTerritories(gs->getWorld()));
    //su->displayTerritory();
    cout << "===========================" << endl;
    int armies = su->assignArmies();
    cout << "Each player gets " << armies << " armies." << endl;
    su->placeArmies(armies);
    su->displayArmiesInTerritory();
    cout << "===========================" << endl;
     cout << "start up finished" << endl;
    return 0;
}

