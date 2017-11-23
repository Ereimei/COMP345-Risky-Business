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

#include "card.h"
#include "../interfaces/interfaces.h"
#include <vector>


class Hand : public Subject {
private:
    static int counterArmy;
    int army = 4;
    std::vector<Card> playerHand = std::vector<Card>();
    int exchangeArmy();
public:
    int exchange();
    void insert(Card card);
    void display();
    int countType(std::string type);
    void removeThree(std::string type);
    void removeEach();
    int getArmy();
    std::vector<Card> getCards();
};

#endif /* HAND_H */

