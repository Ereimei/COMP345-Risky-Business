/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cheaterStrategy.h
 * Author: trep
 *
 * Created on November 18, 2017, 12:06 PM
 */

#ifndef CHEATERSTRATEGY_H
#define CHEATERSTRATEGY_H

#include "Strategy.h"

class cheaterStrategy: public Strategy  {
public:
    cheaterStrategy();
    cheaterStrategy(const cheaterStrategy& orig);
    virtual ~cheaterStrategy();
    
    void reinforce(int reinforcements, Player* player);
    void attack(World* world, vector<Player*> players, Player* player);
    void fortify(World* world, Player* player);
    
    
private:

};

#endif /* CHEATERSTRATEGY_H */

