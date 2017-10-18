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
const string GameStarter::CHOOSE_MAP = "Enter a map contained in /maps/:";

GameStarter::GameStarter() : numPlayers(0) {
}

GameStarter::GameStarter(const GameStarter& orig) : numPlayers(orig.getNumPlayers()) {
}

GameStarter::~GameStarter() {
}

unsigned int GameStarter::getNumPlayers() const {
    return numPlayers;
}

void GameStarter::startGame() {
    assignNumOfPlayers();
    chooseAndCreateWorld();
    createPlayers();
}

void GameStarter::assignNumOfPlayers() {
    bool invalidInput = true;
    unsigned int np = 0;
    while (invalidInput) {
        cout << ASSIGN_NUM_PLAYERS << endl;
        cin >> np;
        if (np >= MIN_PLAYERS && np <= MAX_PLAYERS) {
            numPlayers = np;
            invalidInput = false;
        } else {
            cout << PLAYER_NUM_ERROR << endl;
        }
    }
}

void GameStarter::createPlayers() {
    cout << INIT_PLAYERS << endl;
}

void GameStarter::chooseAndCreateWorld() {
    bool invalidMap = true;
    string filename = "";
    Maploader* maploader;
    while (invalidMap) {
        cout << CHOOSE_MAP << endl;
        cin >> filename;
        maploader = new Maploader(MAP_DIRECTORY + filename);
        if (maploader->worldValid()) {
            world = maploader->getWorld();
            invalidMap = false;
        }
        delete maploader;
    }
}
