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


<<<<<<< HEAD
using std::vector;
using std::string;
=======
using namespace std;
>>>>>>> 111cf225a447a3142b5368a02d6646cef6419ad2


class Player {
public:
    //Constructor
    //Normally, you dont want multiple constructors like that... it doesnt make sense... but wtv
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
<<<<<<< HEAD
    string attack();
    void fortify(World* world);
=======
    void attack(World* world, vector<Player*> players);
    string fortify();
>>>>>>> 111cf225a447a3142b5368a02d6646cef6419ad2
    
private:
    //Player attributes
    vector<Territory*>* territories;
    Hand* hand;
    Diepool* diepool;
    int playerNum;
    
};

#endif /* PLAYER_H */

