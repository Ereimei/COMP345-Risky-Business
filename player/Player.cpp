/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: olitr
 * 
 * Created on September 27, 2017, 9:38 AM
 */

#include "Player.h"
using namespace std

Player::Player(vector<Territory*> territories, Hand hand, Diepool diepool) : territories(territories),
    hand(hand),
    diepool(diepool) {}

Player::Player(const Player& orig) : territories(orig.getTerritories()),
        hand(orig.getHand()),
        diepool(orig.getDiepool()) {}

Player::~Player() {}

vector<Territory*> Player::getTerritories() {return territories;}
Hand Player::getHand() {return hand;}
Diepool Player::getDiepool() {return diepool;}

Player::reinforce(){ cout << "This player can reinforce!" << endl;}
Player::attack(){ cout << "This player can attack!" << endl;}
Player::fortify(){ cout << "This player can fortify" << endl;}
