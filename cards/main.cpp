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

using std::cout;

/*
 * 
 */
int main(int argc, char *argv[]) {

    Deck deck = Deck();
    cout << "shuffling the deck" << std::endl;
    deck.shuffle();
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
    
    cout << "player draws five cards" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    for(int i = 0; i < 5; i++)
    {
        hand.insert(deck.draw());
    }
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
    cout << "player exchange cards" << std:: endl;
    int army = hand.exchange();
    cout << "player receives " << army << " armies" << std:: endl;
    
    cout << "-----------------" << std:: endl;
    
    cout << "player's current hand:" << std:: endl;
    hand.display();
    
    cout << "-----------------" << std:: endl;
    
    return 0;
}

