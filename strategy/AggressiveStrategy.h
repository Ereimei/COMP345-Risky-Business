/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AggressiveStrategy.h
 * Author: olitr
 *
 * Created on November 6, 2017, 10:17 AM
 */

#ifndef AGGRESSIVESTRATEGY_H
#define AGGRESSIVESTRATEGY_H

#include "Strategy.h"

class AggressiveStrategy : public Strategy {
public:
    AggressiveStrategy();
    AggressiveStrategy(const AggressiveStrategy& orig);
    virtual ~AggressiveStrategy();
    
    void reinforce(int reinforcements, Player* player);
    void attack(World* world, vector<Player*> players, Player* player);
    void fortify(World* world, Player* player);
    
private:

};

#endif /* AGGRESSIVESTRATEGY_H */

