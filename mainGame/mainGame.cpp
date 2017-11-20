/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: mainGame.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 2
Professor: Dr. Joey Paquet
Created on October 25, 2017, 7:12 PM */

#include "mainGame.h"

MainGame::MainGame() : turn(1) {
    //gameStatistics = new GameStatistics(this);
}

MainGame::~MainGame() {
    //delete gameStatistics;
}

/*
 * function will loop the main game in the following sequence; reinforcement, attack and fortification
 * for test purpose, the loop will use force end on the 3rd round
 */
void MainGame::loopGame(GameStarter* gameSt, Startup* startup){
    int playerSize = startup->getSetOfPlayer().size();
    while (!playerOwnsAll(gameSt)){
        notify();
        for(int i = 0; i < playerSize; i++){
            cout <<"player #" << startup->getSetOfPlayer().at(i)->getPlayerNum() <<"'s turn:"<< endl;
            currentPlayer = startup->getSetOfPlayer().at(i);
            currentPlayerNum = startup->getSetOfPlayer().at(i)->getPlayerNum();
            currentPhase = "turn starts";
            currentPhase = "reinforcement";
            currentPlayer->reinforce();            
            currentPhase = "attack";
            currentPlayer->attack(startup->getSetOfPlayer());            
            currentPhase = "fortification";
            currentPlayer->fortify();
        }
        
        ++turn;
        //on the 3rd round, the game will force end by assigning a player to own all the territories 
        if(turn == 3){
            forceEnd(gameSt, startup);
        }
    }
    
    cout << "Congratulation on owning all the territories. " << endl;
    cout << "Game over." << endl;
}

/* 
 * playerOwnsAll function will check if a player owns all the territories
 * it will take the first player and compare with the rest
 * if function detects a player's name that isn't the same, then it will return false
 * function returns true, if a player owns all the territories
 */
bool MainGame:: playerOwnsAll(GameStarter* gameSt){
    
    int terrCount = gameSt->getWorld()->getTerritoriesCount();
    //set name to the first player of the game
    Player* player = gameSt->getWorld()->getTerritories()[0].territory->getOwner();
    //check if all the territories have the same owner, if it doesn't then it will return false
    for(int i = 0; i < terrCount; i++){
        if(gameSt->getWorld()->getTerritories()[i].territory->getOwner() != player){
            return false;
        }
    }
    return true;
}

/*
 * function for test purpose
 * it will force the game to end by assigning all the territories to the first player
 */
void MainGame:: forceEnd(GameStarter* gameSt, Startup* startup){
    
    int terrCount = gameSt->getWorld()->getTerritoriesCount();
    Player * player = gameSt->getWorld()->getTerritories()[0].territory->getOwner();
    for(int i = 0; i < terrCount; i++){
        gameSt->getWorld()->getTerritories()[i].territory->setOwner(player);
    }
    cout << "==================================" << endl;
    cout << "A player owns all the territories." << endl;
}

int MainGame::getTurn() const {
    return turn;
}
