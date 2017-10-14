/* 
 * File:   GameStarter.cpp
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
 * Created on October 14, 2017, 3:01 PM
 */

#include "GameStarter.h"

const unsigned int GameStarter::MIN_PLAYERS = 2;
const unsigned int GameStarter::MAX_PLAYERS = 6;
const string GameStarter::MAP_DIRECTORY = "maps/";
const string GameStarter::ASSIGN_NUM_PLAYERS = "Enter how many players (between 2 and 6):";
const string GameStarter::PLAYER_NUM_ERROR = "Incorrect number of players...";
const string GameStarter::INIT_PLAYERS = "===== INITIALIZING PLAYERS =====";

GameStarter::GameStarter() : numPlayers(0),
    filename("") {
}

GameStarter::GameStarter(const GameStarter& orig) : numPlayers(orig.getNumPlayers()),
    filename(orig.getFilename()) {
}

GameStarter::~GameStarter() {
}

unsigned int GameStarter::getNumPlayers() const {
    return numPlayers;
}

string GameStarter::getFilename() const {
    return filename;
}

void GameStarter::startGame() {
    assignNumOfPlayers();
}

void GameStarter::assignNumOfPlayers() {
    bool invalidInput = true;
    unsigned int np;
    while (invalidInput) {
        cout << ASSIGN_NUM_PLAYERS << endl;
        cin >> np;
        if (np >= MIN_PLAYERS && np <= MAX_PLAYERS) {
            numPlayers = np;
            invalidInput = false;
            cout << INIT_PLAYERS << endl;
        } else {
            cout << PLAYER_NUM_ERROR << endl;
        }
    }
}
