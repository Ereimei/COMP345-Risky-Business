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
class Strategy;

#include "../strategy/Strategy.h"
#include "../dice/Diepool.h"
#include "../cards/hand.h"
#include "../map/map.h"
#include "../player/Player.h"


using std::vector;
using std::string;



class Player{
public:
    //Constructor
    Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, Strategy* strategy);
    //Destructor
    virtual ~Player();
    
    //Getters
    vector<Territory*>* getTerritories();
    Hand* getHand();
    Diepool* getDiepool();
    Strategy* getStrategy();
    unsigned int getPlayerNum(){return playerNum;};
    const inline string getCurrentAction(){return currentAction;};
    
    //Setters
    void setHand(Hand* hand);
    void setDiePool(Diepool* diepool);
    void setStrategy(Strategy* strategy);
    void setPlayerNum(int x);
    
    //Player functions
    void addTerritory(Territory*);
    void removeTerritory(Territory*);
    
    void reinforce(World* world);
    void attack(World* world, vector<Player*> players);
    void fortify(World* world);
    int numArmies(World* world);
    
    
private:
    //Player attributes
    vector<Territory*>* territories;
    Hand* hand;
    Diepool* diepool;
    Strategy* strategy;
    unsigned int playerNum;
    static unsigned int objectCount;
    
    //Observer update line
    string currentAction = "Player is starting";
    
};

#endif /* PLAYER_H */

