/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: hand.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 1
Professor: Dr. Joey Paquet
Created on September 25, 2017, 9:49 PM */

#ifndef HAND_H
#define HAND_H
#include <list>

static const int counterArmy = 0;

class Hand{
private:
    std::list<Card> playerHand;
public:
    int exchange();
};

#endif /* HAND_H */

