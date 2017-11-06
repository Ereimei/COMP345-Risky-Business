/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerStrategy.h
 * Author: olitr
 *
 * Created on November 6, 2017, 10:17 AM
 */

#ifndef PLAYERSTRATEGY_H
#define PLAYERSTRATEGY_H

class PlayerStrategy : public Strategy {
public:
    PlayerStrategy();
    PlayerStrategy(const PlayerStrategy& orig);
    virtual ~PlayerStrategy();
    
    void reinforce(int reinforcements, Player* player);
    void attack(World* world, vector<Player*> players, Player* player);
    void fortify(World* world, Player* player);
private:

};

#endif /* PLAYERSTRATEGY_H */

