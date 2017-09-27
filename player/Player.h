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

#include "../map/Territory.h"
#include "../dice/Diepool.h"
#include "../cards/Hand.h"

class Player {
public:
    //Default Constructor
    Player(vector<Territory> territories, Hand hand, Diepool diepool);
    //Constructor
    Player(const Player& orig);
    //Destructor
    virtual ~Player();
    
    //Getters
    vector<Territory> getTerritories();
    Hand getHand();
    Diepool getDiepool();
    
    //Setters
    setTerritories(vector<Territory>);
    setHand(Hand hand);
    setDiePool(Diepool diepool);
    
    //Player functions
    reinforce();
    attack();
    fortify();
    
private:
    //Player attributes
    vector<Territory> territories;
    Hand hand;
    Diepool diepool;
    
};

#endif /* PLAYER_H */

