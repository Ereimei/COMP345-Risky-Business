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
    Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool);
    Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, int n);
    //Destructor
    virtual ~Player();
    
    //Getters
    vector<Territory*>* getTerritories();
    Hand* getHand();
    Diepool* getDiepool();
    int getPlayerNum(){return playerNum;};
    
    //Setters
    void setHand(Hand* hand);
    void setDiePool(Diepool* diepool);
    void setPlayerNum(int x){playerNum = x;};
    
    //Player functions
    void addTerritory(Territory*);
    void removeTerritory(Territory*);
    
    void reinforce(int reinforcements);
    string attack();
    string fortify();
    
private:
    //Player attributes
    vector<Territory*>* territories;
    Hand* hand;
    Diepool* diepool;
    int playerNum;
    
};

#endif /* PLAYER_H */

