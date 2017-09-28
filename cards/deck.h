/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "card.h"

/*

File: deck.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 1
Professor: Dr. Joey Paquet
Created on September 24, 2017, 3:48 PM */

#ifndef DECK_H
#define DECK_H
#include <vector>


class Deck 
{
private:
    std::vector<Card> deck = std::vector<Card>();
        
public:
    void shuffle();
    Card draw();
    const bool isEmpty() { return deck.empty(); }
    void display();
};


#endif /* DECK_H */
