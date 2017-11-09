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
Created on October 25, 2017, 7:12 PM */

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector> 
#include <string>

#include "mainGame.h"
#include "../startup/startup.h"
#include "../gamestarter/GameStarter.h"
#include "../phaseObserver/phaseObserver.h"

using namespace std;

/*
 * part 3
 * system will set up the game by determining the amount of players and territories 
 * then it will set up the order and assign territories to the players
 * finally it will loop the game until a player owns all the territory
 */
int main(int argc, char** argv) {
    
    cout << "start up ..." << endl;
    cout << "===========================" << endl;
    GameStarter* gs = new GameStarter();
    gs->startGame();
    cout << "===========================" << endl;
    Startup* su = new Startup(gs->getPlayers(),gs->getNumPlayers());
    su->displayPlayerOrder();
    su->assignTerritory(su->getAllTerritories(gs->getWorld()));
    su->placeArmies(su->assignArmies());
    cout << "start up finished" << endl;
    cout << "===========================" << endl;
    
    MainGame* main = new MainGame();
    PhaseObserver* phaseOb = new PhaseObserver(main, su);
    main->loopGame(gs, su);
    
    return 0;
}

