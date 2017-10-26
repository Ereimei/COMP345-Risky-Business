/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: mainGame.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 2
Professor: Dr. Joey Paquet
Created on October 25, 2017, 7:13 PM */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "../startup/startup.h"
#include "../gamestarter/GameStarter.h"

#ifndef MAINGAME_H
#define MAINGAME_H

class MainGame{
    
private:
    
public:
    
    //reinforcements phase
    void reinforcement();
    //attack phase
    void attack();
    //fortification phase
    void fortification();
    //loop the game until a player own all the territories
    void loopGame(GameStarter* gameSt, Startup* startup);
    //check if a player own all the territories
    bool playerOwnsAll(GameStarter* gameSt);
    
    /*
     * test purpose
     */
    //force the a player to own all the territories
    void forceEnd(GameStarter* gameSt, Startup* startup);
    
};


#endif /* MAINGAME_H */

