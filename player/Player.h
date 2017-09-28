/* 
 * File:   Player.h
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

#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>


#include "../map/map.h"
#include "../dice/Diepool.h"
#include "../cards/hand.h"


using std::vector;


class Player {
public:
    //Constructor
    Player(vector<Territory> territories, Hand* hand, Diepool* diepool);
    //Destructor
    virtual ~Player();
    
    //Getters
    vector<Territory> getTerritories();
    Hand* getHand();
    Diepool* getDiepool();
    
    //Setters
    setHand(Hand* hand);
    setDiePool(Diepool* diepool);
    
    //Player functions
    addTerritory(Territory);
    removeTerritory(Territory);
    
    string reinforce();
    string attack();
    string fortify();
    
private:
    //Player attributes
    vector<Territory> territories;
    Hand* hand;
    Diepool* diepool;
    
};

#endif /* PLAYER_H */

