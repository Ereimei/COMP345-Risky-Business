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
#include <ostream>

#include "../cards/hand.h"
#include "../dice/Diepool.h"
#include "../map/map.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::string;
        
//Constructor
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool) : territories(territories),
    hand(hand),
    diepool(diepool) {}

//Constructor with player number
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, int n) : territories(territories),
    hand(hand),
    diepool(diepool),
    playerNum(n) {}

//Destructors
Player::~Player() {}

//Getters
vector<Territory*>* Player::getTerritories() {return territories;}
Hand* Player::getHand() {return hand;}
Diepool* Player::getDiepool() {return diepool;}

//Setters
void Player::setHand(Hand* hand) {hand = hand;}
void Player::setDiePool(Diepool* diepool) {diepool = diepool;}
void Player::setPlayerNum(int x) {playerNum = x;}
void Player::setStrategy(Strategy* strategy) {strategy = strategy;}

void Player::addTerritory(Territory* territory){
    this->territories->insert(territories->begin(), territory);
    territory->setOwner(this);
};
void Player::removeTerritory(Territory* territory){};

void Player::executeTurn(int reinforcements, World* world, vector<Player*> players){
    this->strategy->reinforce(reinforcements, this);
    this->strategy->attack(world, players, this);
    this->strategy->fortify(world, this);
}