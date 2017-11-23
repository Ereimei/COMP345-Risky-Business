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

#ifndef MAINGAME_H
#define MAINGAME_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

#include "../startup/startup.h"
#include "../gamestarter2/GameStarter.h"
#include "../interfaces/interfaces.h"
#include "../statistics/Statistics.h"
#include "../map/map.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class MainGame: public Subject {
    
private:
    Player* currentPlayer;
    int currentPlayerNum;
    string currentPhase;
    unsigned int turn;
    Observer* gameStatistics;
    bool* decorators;
    bool askUser;
    unsigned int decoratorsCount;
    unsigned int playerSize;
    unsigned int lastDecoratorAdded;
    World* world;
    void chooseDecorators();
    void addPlayerDecorator();
    void addContinentDecorator();
    void removeDecorator();
    
public:
    MainGame();
    virtual ~MainGame();
    Player* getCurrentPlayer(){return currentPlayer;};
    int getCurrentPlayerNum() const {return currentPlayerNum;};
    string getCurrentphase() const {return currentPhase;};

    //loop the game until a player own all the territories
    void loopGame(GameStarter* gameSt, Startup* startup);
    void loopGame(GameStarter* gameSt, Startup* startup, int maxTurns);
    //check if a player own all the territories
    bool playerOwnsAll(GameStarter* gameSt);
    
    /*
     * test purpose
     */
    //force the a player to own all the territories
    void forceEnd(GameStarter* gameSt, Startup* startup);
    
    unsigned int getTurn() const;
    
    static const unsigned int totalDecoratorsCount;
    static const string REMOVE_DECORATOR;
    static const string PLAYER_DECORATOR;
    static const string HANDS_DECORATOR;
    static const string CONTINENT_DECORATOR;
    static const string DONT_ASK;
    static const string DECORATOR_OPTIONS;
    static const string BAD_INPUT;
};


#endif /* MAINGAME_H */

