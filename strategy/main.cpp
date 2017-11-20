/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: olitr
 *
 * Created on November 6, 2017, 10:16 AM
 */

#include <cstdlib>


#include "../gamestarter2/GameStarter.h"
#include "../startup/startup.h"
#include "../mainGame/mainGame.h"
#include "../phaseObserver/phaseObserver.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    cout << "start up ..." << endl;
    cout << "===========================" << endl;
    GameStarter* gs = new GameStarter();
    gs->startGame();
    //PhaseObserver* phaseOb = new PhaseObserver();
    cout << "===========================" << endl;
    Startup* su = new Startup(gs->getPlayers(),gs->getNumPlayers());
    su->displayPlayerOrder();
    su->assignTerritory(su->getAllTerritories(gs->getWorld()));
    su->placeArmies(su->assignArmies());
    cout << "start up finished" << endl;
    cout << "===========================" << endl;
    MainGame* main = new MainGame();
    cin.ignore(1, EOF);
    main->loopGame(gs, su);
    
    
}

