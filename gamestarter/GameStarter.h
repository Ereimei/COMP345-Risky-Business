/* 
 * File:   GameStarter.h
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #2
 * Professor: Dr. Joey Paquet
 *
 * Created on October 14, 2017, 3:00 PM
 */

#ifndef GAMESTARTER_H
#define GAMESTARTER_H

#include "../map/map.h"
#include "../maploader/Maploader.h"
#include "../dice/Diepool.h"
#include "../cards/hand.h"
#include "../cards/deck.h"
#include "../player/Player.h"
#include "../interfaces/interfaces.h"
#include "../statistics/Statistics.h"
#include "../strategy/Strategy.h"
#include "../strategy/PlayerStrategy.h"
#include "../strategy/AggressiveStrategy.h"
#include "../strategy/BenevolentStrategy.h"
#include "../strategy/cheaterStrategy.h"
#include "../strategy/RandomStrategy.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class GameStarter {
public:
    GameStarter();
    GameStarter(const GameStarter& orig);
    virtual ~GameStarter();
    void startGame();
    unsigned int getNumPlayers() const;
    World* getWorld() const;
    Deck* getDeck() const;
    Player** getPlayers() const;
private:
    void assignNumOfPlayers();
    void createPlayers();
    void chooseAndCreateWorld();
    void createDeck();
    void createStatistics();
    World* world;
    Deck* deck;
    Player** players;
    unsigned int numPlayers;
    static const unsigned int MIN_PLAYERS;
    static const unsigned int MAX_PLAYERS;
    static const string MAP_DIRECTORY;
    static const string PLAYER_NUM_ERROR;
    static const string INIT_PLAYERS;
    static const string ASSIGN_NUM_PLAYERS;
    static const string CHOOSE_MAP;
    static const string INIT_MAP;
    static const string INVALID_MAP;
    static const string INIT_DECK;
    static const string SHUFFLING_DECK;
    static const string CREATING_PLAYER;
};

#endif /* GAMESTARTER_H */

