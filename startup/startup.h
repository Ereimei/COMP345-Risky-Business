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

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

//class playerInGame, inherit from class Player
class PlayerInGame{
private:
    Player* player;
    int playerNum;
    
public:
    //default constructor
    PlayerInGame();
    PlayerInGame(Player* pl, int n);
    //getters
    int getPlayerNum(){return playerNum;};
    Player* getPlayer(){return player;};
    //setters
    void setPlayerNum(int x){playerNum = x;};
    void setPlayer(Player* pl){*player=*pl;};
    
};

class Startup{
private:
    vector<PlayerInGame> setOfPlayer;
    
public:
    //constructor that will create a dynamic array of players
    Startup(Player** pl, int size);
    //add territory to player
    void addTerritory(Player* pl, Territory* tr);
    //remove territory from player
    void removeTerritory(Player* pl, Territory* tr);
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

