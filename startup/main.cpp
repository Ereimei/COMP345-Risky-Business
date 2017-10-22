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
    cout <<"ccc"<<endl;
    su->displayPlayerOrder();
    cout << "===========================" << endl;
    su->displayTerritory();
   
    return 0;
}

