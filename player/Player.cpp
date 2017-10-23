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

//Constructor with player number
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, int n) : territories(territories),
    hand(hand),
    diepool(diepool), playerNum(n) {}

//Destructors
Player::~Player() {}

//Getters
vector<Territory*>* Player::getTerritories() {return territories;}
Hand* Player::getHand() {return hand;}
Diepool* Player::getDiepool() {return diepool;}

//Setters
void Player::setHand(Hand* hand) {hand = hand;}
void Player::setDiePool(Diepool* diepool) {diepool = diepool;}

void Player::addTerritory(Territory* territory){
    this->territories->insert(territories->begin(), territory);
};
void Player::removeTerritory(Territory* territory){};

//Other functions
void Player::reinforce(int reinforcements){ 
    string territory;
    int reinAmount;
    
    while (reinforcements != 0){
        cout << "You have " << reinforcements << " army available for reinforcements." << endl;
        cout << "Your territories" << endl;
        cout << "----------------" << endl;
        for (int i = 0; i < this->territories->size(); i++){
            cout << this->territories->at(i)->getName() << " army: " << this->territories->at(i)->getArmies() << endl;
        }
        cout << "Please type the name of the territory you wish to to reinforce followed by the amount of reinforcement." << endl;
        cin >> territory >> reinAmount;
        for (int i = 0; i < this->territories->size(); i++){
            if (this->territories->at(i)->getName() == territory){
                //If the player entered a # higher than the max amount of reinforcements
                if (reinAmount > reinforcements){
                   this->territories->at(i)->setArmies(this->territories->at(i)->getArmies() + reinforcements);
                    reinforcements = 0;
                }
                else if (reinAmount < 0){
                    cout << "Please enter a number greater than 0." << endl;
                }
                else {
                    this->territories->at(i)->setArmies(this->territories->at(i)->getArmies() + reinAmount);
                    reinforcements -= reinAmount;
                }    
            }
        }
    }
    
}

string Player::attack(){ return "This player can attack!";}
string Player::fortify(){ return "This player can fortify";}
