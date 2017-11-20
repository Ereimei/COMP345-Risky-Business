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
#include "../gamestarter2/GameStarter.h"

using namespace std;

/*
 * part 2
 * system will set up the game by determining the amount of players and territories 
 * then it will set up the order and assign territories to the players
 * 
 * system will also determine the amount of armies each player gets by the amount of players
 * then the players will assign the armies to their territories
 */
int main(int argc, char** argv) {
    
    cout << "start up ..." << endl;
    cout << "===========================" << endl;
    //create object GameStarter to get the amount of players and the map for the game
    GameStarter* gs = new GameStarter();
    gs->startGame();
    cout << "===========================" << endl;
    
    cout << "There are " << gs->getNumPlayers() <<" players." << endl;
    //shuffle the order of the player and display it
    Startup* su = new Startup(gs->getPlayers(),gs->getNumPlayers());
    su->displayPlayerOrder();
    cout << "===========================" << endl;
    int size = gs->getWorld()->getTerritoriesCount();
    cout << "There are " << size << " territories." << endl;
    //get all the territories and assign them to the players
    su->assignTerritory(su->getAllTerritories(gs->getWorld()));
    //code to display territory
    //su->displayTerritory();
    cout << "===========================" << endl;
    //assign the amount of armies depending on the amount of players
    //and place the armies into the territories
    int armies = su->assignArmies();
    cout << "Each player gets " << armies << " armies." << endl;
    su->placeArmies(armies);
    su->displayArmiesInTerritory();
    cout << "===========================" << endl;
     cout << "start up finished" << endl;
    return 0;
}

