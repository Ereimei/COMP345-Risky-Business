/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: startup.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 2
Professor: Dr. Joey Paquet
Created on October 17, 2017, 10:20 PM */

#ifndef STARTUP_H
#define STARTUP_H

#include "../gamestarter/Gamestarter.h"
#include "../player/Player.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <set>

class Startup{
private:
    vector<Player*> setOfPlayer;
    
public:
    //constructor that will create a dynamic array of players
    Startup(Player** pl, int size);
    //assign all the territories in round robin style
    void assignTerritory(vector<Territory*> vTerritory);
    //get a list of all territories
    vector<Territory*> getAllTerritories(World* world);
    //assign armies to players
    int assignArmies();
    //place armies to territories
    void placeArmies(int armies);
    
    //display information
    void displayPlayerOrder();
    void displayTerritory();
    void displayArmiesInTerritory();
    
};


#endif /* STARTUP_H */

