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

#include <vector>

class Player;

#include "../map/map.h"
#include "../player/Player.h"
#include "../dice/Diepool.h"
#include "../cards/hand.h"
#include "../interfaces/interfaces.h"

using std::vector;

class Strategy : public Subject{
public:
    Strategy();
    Strategy(const Strategy& orig);
    virtual ~Strategy();
    
    virtual void reinforce(int reinforcements, Player* player);
    virtual void attack(World* world, vector<Player*> players, Player* player);
    virtual void fortify(World* world, Player* player);
    string currentAction = "//////";
    string getCurrentAction(){return currentAction;};
    
private:

};

#endif /* STRATEGY_H */

