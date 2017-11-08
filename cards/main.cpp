/* 
 * File:   main.cpp
 * Author: Patrick Bednarski
 *
 * Created on September 19, 2017, 3:40 PM
 */

#include <iostream>
#include <string>
#include <vector>

#include "deck.h"
#include "hand.h"

#include "../map/map.h"
#include "../maploader/Maploader.h"

using std::cout;

/*
 * 
 */
int main(int argc, char *argv[]) {
    World* world = new World();
    
    Deck deck = Deck();
    cout << "shuffling the deck" << std::endl;
    deck.shuffle(world);
    cout << "deck shuffled:" << std:: endl;
    deck.display();
    
    cout << "-----------------" << std:: endl;
    
    cout << "player draws a card" << std:: endl;
    Hand hand = Hand();
    Card card = deck.draw();
    hand.insert(card);
    cout << "Card drawn:" << std::endl;
    cout << "Country: " << card.getCountry() << ", Type: " << card.getType() << std::endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player exchange cards" << std:: endl;
    int army1 = hand.exchange();
    cout << "player receives " << army1 << " armies" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player draws four cards" << std:: endl;
    
    for(int i = 0; i < 4; i++)
    {
        hand.insert(deck.draw());
    }
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
    cout << "player exchange cards" << std:: endl;
    int army2 = hand.exchange();
    cout << "player receives " << army2 << " armies" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
    cout << "player draws three cards" << std:: endl;
    
    for(int i = 0; i < 3; i++)
    {
        hand.insert(deck.draw());
    }
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
    cout << "player exchange cards" << std:: endl;
    int army3 = hand.exchange();
    cout << "player receives " << army3 << " armies" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
        cout << "player exchange cards" << std:: endl;
    int army4 = hand.exchange();
    cout << "player receives " << army4 << " armies" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    return 0;
}

