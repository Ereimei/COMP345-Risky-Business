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

#include <cstdlib>
#include <string>
#include <iostream>

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
    string getFilename() const;
private:
    void assignNumOfPlayers();
    unsigned int numPlayers;
    string filename;
    static const unsigned int MIN_PLAYERS;
    static const unsigned int MAX_PLAYERS;
    static const string MAP_DIRECTORY;
    static const string PLAYER_NUM_ERROR;
    static const string INIT_PLAYERS;
    static const string ASSIGN_NUM_PLAYERS;
};

#endif /* GAMESTARTER_H */

