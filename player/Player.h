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
#include <string>

class Territory;
class World;

#include "../dice/Diepool.h"
#include "../cards/hand.h"
#include "../player/Player.h"
#include "../strategy/Strategy.h"


using std::vector;
using std::string;



class Player: public Subject{
public:
    //Constructor
    Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, Strategy* strategy);
    //Destructor
    virtual ~Player();
    
    //Getters
    vector<Territory*>* getTerritories();
    Hand* getHand();
    Diepool* getDiepool();
    unsigned int getPlayerNum(){return playerNum;};
    
    //Setters
    void setHand(Hand* hand);
    void setDiePool(Diepool* diepool);
    void setStrategy(Strategy* strategy);
    
    //Player functions
    void addTerritory(Territory*);
    void removeTerritory(Territory*);
    
    void executeTurn(int reinforcements, World* world, vector<Player*> players);
    int numArmies(World* world);
    
private:
    //Player attributes
    vector<Territory*>* territories;
    Hand* hand;
    Diepool* diepool;
    Strategy* strategy;
    unsigned int playerNum;
    static unsigned int objectCount;
    
};

#endif /* PLAYER_H */

