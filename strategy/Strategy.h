/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Strategy.h
 * Author: olitr
 *
 * Created on November 6, 2017, 10:16 AM
 */

#ifndef STRATEGY_H
#define STRATEGY_H


#include "../map/map.h"
#include "../player/Player.h"

class Strategy {
public:
    Strategy();
    Strategy(const Strategy& orig);
    virtual ~Strategy();
    
    virtual void reinforce(int reinforcements, Player* player);
    virtual void attack(World* world, vector<Player*> players, Player* player);
    virtual void fortify(World* world, Player* player);
    
private:

};

#endif /* STRATEGY_H */

