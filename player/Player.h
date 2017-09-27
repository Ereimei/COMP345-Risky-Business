/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: olitr
 *
 * Created on September 27, 2017, 9:38 AM
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

