/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BenevolentStrategy.h
 * Author: olitr
 *
 * Created on November 6, 2017, 10:17 AM
 */

#ifndef BENEVOLENTSTRATEGY_H
#define BENEVOLENTSTRATEGY_H

#include "Strategy.h"

class BenevolentStrategy : public Strategy {
public:
    BenevolentStrategy();
    BenevolentStrategy(const BenevolentStrategy& orig);
    virtual ~BenevolentStrategy();
    
    void reinforce(int reinforcements, Player* player);
    void attack(World* world, vector<Player*> players, Player* player);
    void fortify(World* world, Player* player);
    
    
private:

};

#endif /* BENEVOLENTSTRATEGY_H */

