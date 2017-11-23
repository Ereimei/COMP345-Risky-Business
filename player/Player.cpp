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

#include "Player.h"

using std::cout;
using std::cin;
using std::string;

unsigned int Player::objectCount = 0;
        
//Constructor
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, Strategy* strategy, World* w) : territories(territories),
    hand(hand),
    diepool(diepool),
    playerNum(objectCount++),
    strategy(strategy),
    world(w) {}

//Destructors
Player::~Player() {}

//Getters
vector<Territory*>* Player::getTerritories() {return territories;}
Hand* Player::getHand() {return hand;}
Diepool* Player::getDiepool() {return diepool;}
Strategy* Player::getStrategy() {return strategy;}

//Setters
void Player::setHand(Hand* hand) {hand = hand;}
void Player::setDiePool(Diepool* diepool) {diepool = diepool;}
void Player::setPlayerNum(int x) {playerNum = x;}
void Player::setStrategy(Strategy* strategy) {strategy = strategy;}

void Player::addTerritory(Territory* territory){
    this->territories->insert(territories->begin(), territory);
    world->setTerritoryOwner(territory->getName(), this);
};
void Player::removeTerritory(Territory* territory){
    //Find index where territory is
    int terrPos;

    for (int i = 0; i < this->territories->size(); i ++){
        if (this->territories->at(i) == territory){
            terrPos = i;
        }
    }
    
    //Remove territory
    this->territories->erase(this->territories->begin() + terrPos);
    
    
};

void Player::reinforce(){
    int reinforcements = this->numArmies();
    this->strategy->reinforce(reinforcements, this);
}

void Player::attack(vector<Player*> players){
    this->strategy->attack(world, players, this);
}

void Player::fortify(){
    this->strategy->fortify(world, this);
}

int Player::numArmies() {
    int numCountries, numContinents, numTerrInCont, numReinf;
    bool ownsTerr = false, ownsCont;
    string exchangeCards;
    //Checking the amount of territories the player owns
    numCountries = this->getTerritories()->size();
    cout << endl << "Territory Army Bonus" << endl;
    cout << "--------------------" << endl;
    numReinf = numCountries/3;
    if (numReinf < 3){
        numReinf = 3;
    }
    cout << "Total amount of territory owned: " << numCountries << endl;
    cout << "Army value (territories/3 floored): " << numReinf << endl << endl;

    
    //Checking if a player owns an entire continent, for every continent
    numContinents = world->getContinentsCount();
    cout << "Continent Army Bonus" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numContinents; i++) {
        if (playerNum == world->getContinents()[i]->getOwnerPlayerNumber()){
            //commented out because now there's an observer for this
            //cout << "Player owns continent: " << world->getContinents()[i]->getName() << " adding army bonus of " << world->getContinents()[i]->getArmyBonus() << endl;
            numReinf += world->getContinents()[i]->getArmyBonus();
            cout << "Reinforcements amount = " << numReinf << endl << endl;
        }
        else {
            //commented out because now there's an observer for this
            //cout << "Player does not own continent: " << world->getContinents()[i]->getName() << endl ;
        }

    }
    
    //Display player's hand, commented out because there is now an observer for this
//    cout << endl << "Player's hand" << endl;
//    cout << "--------------" << endl;
//    this->getHand()->display();
//    cout << endl;
    //If player has enough cards to exchange but not more than 5 cards, give them the choice to exchange
    if (2 < this->getHand()->getCards().size() && this->getHand()->getCards().size() < 6) {
        cout << "Do you want to try to exchange your cards for additional reinforcements? (y/n)" << endl;
        cin >> exchangeCards;
        //Make sure they properly input y or n
        while (exchangeCards != "y" && exchangeCards != "n"){
            cout << "You did not properly enter y or n as an answer, please try again." << endl;
            cin >> exchangeCards;
        }
        
        if (exchangeCards == "y"){
            cout << "Trying to exchange cards for " << this->getHand()->getArmy() << " reinforcement." << endl;
            numReinf += this->getHand()->exchange();
            cout << "Reinforcements amount = " << numReinf << endl;
        }
        else {
            cout << "Player does not want to exchange cards for reinforcement" << endl;
        }
    }
    //If player has less than 3 cards
    else if (this->getHand()->getCards().size() < 3){
        cout << "Player does not have enough cards to increase reinforcements." << endl;
    }
    //If player has over 5 cards, they must exchange cards
    else {
        cout << "Player has more than 5 cards, forcing them to exchange them for " << this->getHand()->getArmy() << " reinforcements." << endl;
        numReinf += this->getHand()->exchange();
        cout << "Reinforcements amount = " << numReinf << endl;
    }
    cout << "--------------" << endl << endl;
    
    cout << "Reinforcements amount = " << numReinf << endl;

    
    return numReinf; 
}
