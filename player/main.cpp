/* 
 * File:   main.cpp
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

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Player.h"
#include "../map/map.h"
#include "../dice/Diepool.h"
#include "../cards/hand.h"
#include "../cards/deck.h"
#include "../cards/card.h"

using namespace std;

int main(int argc, char** argv) {
  
    cout << "Creating player object." << endl;
    
    //Creating pointers to territories owned by player
    vector<Territory*> territories;
    territories.push_back(new Territory("Alaska"));
    territories.push_back(new Territory("Mars"));
    territories.push_back(new Territory("Canada"));
    
    //Creating player's hand of cards
    Hand* hand = new Hand();
    
    Deck* deck = new Deck();
    deck->shuffle();
    Card card = deck->draw();
    hand->insert(card);
    card = deck->draw();
    hand->insert(card);
    card = deck->draw();
    hand->insert(card);
    
    hand->display();
    
    //Creating player's diepool object
    Diepool* diepool = new Diepool();
    
    
    Player* demoplayer = new Player(territories, hand, diepool);
    
    cout << endl << "Player owns a hand of Risk cards" << endl;
    demoplayer->getHand()->display();
    
    cout << endl << "Player has his own dice rolling facility object" << endl;
    demoplayer->getDiepool()->roll();
    demoplayer->getDiepool()->roll();
    demoplayer->getDiepool()->roll();
    
    cout << endl << "Player has his own territories" << endl;
    Territory* pointer = (demoplayer->getTerritories().at(0));
    cout << pointer->getName() << endl;
    pointer = (demoplayer->getTerritories().at(1));
    cout << pointer->getName() << endl;
    pointer = (demoplayer->getTerritories().at(2));
    cout << pointer->getName() << endl;
    
    cout << endl;
    cout << "Player's functions demonstration" << endl << "-------------------" << endl;
    cout << demoplayer->attack() << endl;
    cout << demoplayer->fortify() << endl;
    cout << demoplayer->reinforce() << endl;
    
  
}

