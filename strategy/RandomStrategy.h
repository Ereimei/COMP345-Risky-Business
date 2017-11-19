/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: RandomStrategy.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 4
Professor: Dr. Joey Paquet
Created on November 18, 2017, 8:31 PM */

#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include "Strategy.h"

class RandomStrategy: public Strategy  {
private:
    
public:
    RandomStrategy();
    RandomStrategy(const RandomStrategy& orig);
    virtual ~RandomStrategy();
    
    void reinforce(int reinforcements, Player* player);
    void attack(World* world, vector<Player*> players, Player* player);
    void fortify(World* world, Player* player);
        


    
};


#endif /* RANDOMSTRATEGY_H */

