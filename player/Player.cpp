/* 
 * File:   Player.cpp
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
#include <iostream>
#include <vector>


#include "../cards/hand.h"
#include "../dice/Diepool.h"
#include "../map/map.h"
#include "Player.h"

using namespace std;
        
//Constructor
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool) : territories(territories),
    hand(hand),
    diepool(diepool) {}
//Destructors
Player::~Player() {}

//Getters
vector<Territory*>* Player::getTerritories() {return territories;}
Hand* Player::getHand() {return hand;}
Diepool* Player::getDiepool() {return diepool;}

//Setters
void Player::setHand(Hand* hand) {hand = hand;}
void Player::setDiePool(Diepool* diepool) {diepool = diepool;}

void Player::addTerritory(Territory*){};
void Player::removeTerritory(Territory*){};

//Other functions
string Player::reinforce(){ return "This player can reinforce!";}
string Player::attack(){ return "This player can attack!";}
string Player::fortify(){ return "This player can fortify";}
