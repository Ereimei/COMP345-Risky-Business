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

#include "Player.h"
using namespace std
        
//Constructor
Player::Player(vector<Territory> territories, Hand hand, Diepool diepool) : territories(territories),
    hand(hand),
    diepool(diepool) {}

Player::Player(const Player& orig) : territories(orig.getTerritories()),
        hand(orig.getHand()),
        diepool(orig.getDiepool()) {}

//Destructors
Player::~Player() {}

//Getters
vector<Territory> Player::getTerritories() {return territories;}
Hand Player::getHand() {return hand;}
Diepool Player::getDiepool() {return diepool;}

//Setters
Player::setTerritories(vector<Territory>) {this->territories = vector<Territory>;}
Player::setHand(Hand hand) {this->hand = hand;}
Player::setDiePool(Diepool diepool) {this->diepool = diepool;}

//Other functions
Player::reinforce(){ cout << "This player can reinforce!" << endl;}
Player::attack(){ cout << "This player can attack!" << endl;}
Player::fortify(){ cout << "This player can fortify" << endl;}
