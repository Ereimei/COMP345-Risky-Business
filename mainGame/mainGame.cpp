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

const unsigned int MainGame::totalDecoratorsCount = 3;
const string MainGame::REMOVE_DECORATOR = "0. Remove last decorator";
const string MainGame::PLAYER_DECORATOR = "1. Player domination decorator";
const string MainGame::HANDS_DECORATOR = "2. Player hands decorator";
const string MainGame::CONTINENT_DECORATOR = "3. Continent control decorator";
const string MainGame::DONT_ASK = "4. Stop asking me!";
const string MainGame::DECORATOR_OPTIONS = "Please choose from the following options...";
const string MainGame::BAD_INPUT = "Bad input, ignoring...";

MainGame::MainGame() : turn(1),
    decoratorsCount(0),
    askUser(true),
    world(NULL),
    playerSize(0),
    lastDecoratorAdded(0) {
    decorators = new bool[totalDecoratorsCount];
    for (int n = 0; n < totalDecoratorsCount; ++n) {
        decorators[n] = false;
    }
}

MainGame::~MainGame() {
    
}

/*
 * function will loop the main game in the following sequence; reinforcement, attack and fortification
 * for test purpose, the loop will use force end on the 3rd round
 */
void MainGame::loopGame(GameStarter* gameSt, Startup* startup) {
    gameStatistics = new GameStatistics(this);
    world = gameSt->getWorld();
    playerSize = startup->getSetOfPlayer().size();
    
    // go through all the continents at the beginning and see if any one player owns a single continent
    for (int n = 0; n < world->getContinentsCount(); ++n) {
        world->getContinents()[n]->checkIfSingleOwner();
    }
    
    while (!playerOwnsAll(gameSt)){
        notify();
        chooseDecorators();
        for(int i = 0; i < playerSize; i++) {
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
        
        //force game to end 
        if(turn == 20){
            forceEnd(gameSt, startup);
        }
    }
    
    cout << "Congratulation on owning all the territories. " << endl;
    cout << "Game over." << endl;
}
/*
 * function will loop the main game in the following sequence; reinforcement, attack and fortification
 * for test purpose, the loop will use force end on the 3rd round
 */
void MainGame::loopGame(GameStarter* gameSt, Startup* startup, int maxTurns) {
    gameStatistics = new GameStatistics(this);
    world = gameSt->getWorld();
    playerSize = startup->getSetOfPlayer().size();
    
    // go through all the continents at the beginning and see if any one player owns a single continent
    for (int n = 0; n < world->getContinentsCount(); ++n) {
        world->getContinents()[n]->checkIfSingleOwner();
    }
    
    while (!playerOwnsAll(gameSt)){
        notify();
        chooseDecorators();
        for(int i = 0; i < playerSize; i++) {
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
        
        //force game to end 
        if(turn == maxTurns){
            forceEnd(gameSt, startup);
        }
    }
    
    cout << "Congratulation on owning all the territories. " << endl;
    cout << "Game over." << endl;
    return gameSt->getWorld()->getTerritories()[0].territory->getOwner()->getPlayerNum();
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

unsigned int MainGame::getTurn() const {
    return turn;
}

void MainGame::chooseDecorators() {
    unsigned int input;
    if (askUser) {
        cout << DECORATOR_OPTIONS << endl;
        if (decoratorsCount > 0) {
            cout << REMOVE_DECORATOR << endl;
        }
        if (!decorators[0]) {
            cout << PLAYER_DECORATOR << endl;
        }
        if (!decorators[1]) {
            cout << HANDS_DECORATOR << endl;
        }
        if (!decorators[2]) {
            cout << CONTINENT_DECORATOR << endl;
        }
        cout << DONT_ASK << endl;
        cin >> input;
        switch(input) {
            case 0:
                removeDecorator();
                break;
            case 1:
                addPlayerDecorator();
                break;
            case 2:
                break;
            case 3:
                addContinentDecorator();
                break;
            case 4:
                askUser = false;
                break;
            default:
                cout << BAD_INPUT << endl;
                break;
        }
    }
}

void MainGame::addPlayerDecorator() {
    if (!decorators[0]) {
        gameStatistics = new PlayerDomination(gameStatistics, world, playerSize);
        decorators[0] = true;
        lastDecoratorAdded = 0;
        ++decoratorsCount;
    }
}

void MainGame::addContinentDecorator() {
    if (!decorators[2]) {
        gameStatistics = new ContinentControl(gameStatistics, world->getContinents(), world->getContinentsCount());
        decorators[2] = true;
        lastDecoratorAdded = 2;
        ++decoratorsCount;
    }
}

void MainGame::removeDecorator() {
    if (decoratorsCount > 0) {
        ObserverDecorator* decoratedObserver = dynamic_cast<ObserverDecorator*>(gameStatistics);
        if (decoratedObserver) {
            Observer* temp = decoratedObserver->getDecoratedObserver();
            delete gameStatistics;
            gameStatistics = temp;
            decorators[lastDecoratorAdded] = false;
            --decoratorsCount;
        }
    }
}
