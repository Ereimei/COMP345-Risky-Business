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

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;

const unsigned int GameStarter::MIN_PLAYERS = 2;
const unsigned int GameStarter::MAX_PLAYERS = 6;
const string GameStarter::MAP_DIRECTORY = "maps/";
const string GameStarter::ASSIGN_NUM_PLAYERS = "Enter how many players (between 2 and 6):";
const string GameStarter::PLAYER_NUM_ERROR = "Incorrect number of players...";
const string GameStarter::INIT_PLAYERS = "===== INITIALIZING PLAYERS =====";
const string GameStarter::CHOOSE_MAP = "Enter a map contained in /maps/:";
const string GameStarter::INIT_MAP = "===== INITIALIZING MAP =====";
const string GameStarter::INVALID_MAP = "This map is not valid...";
const string GameStarter::INIT_DECK = "===== INITIALIZING DECK =====";
const string GameStarter::SHUFFLING_DECK = "Deck has been created and shuffled";
const string GameStarter::CREATING_PLAYER = "Creating player #";

GameStarter::GameStarter() : numPlayers(0) {
}

GameStarter::GameStarter(const GameStarter& orig) : numPlayers(orig.getNumPlayers()) {
}

GameStarter::~GameStarter() {
}

/**
 * Control method for starting the game
 * It calls helper methods to get
 * everything going
 */
void GameStarter::startGame() {
    assignNumOfPlayers();
    chooseAndCreateWorld();
    createDeck();
    createPlayers();
}

/**
 * Choose how many players and validate
 */
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

/**
 * Actually create players and assign
 * an empty hands of cards, a vector
 * of territories, and a die pool
 */
void GameStarter::createPlayers() {
    Hand* hand;
    vector<Territory*>* territories;
    Diepool* diepool;
    cout << INIT_PLAYERS << endl;
    players = new Player*[numPlayers];
    for (int n = 0; n < numPlayers; ++n) {
        cout << CREATING_PLAYER << n << endl;
        hand = new Hand();
        diepool = new Diepool();
        territories = new vector<Territory*>;
        players[n] = new Player(territories, hand, diepool);
    }
}

/**
 * Choose a world and try to load it from file
 */
void GameStarter::chooseAndCreateWorld() {
    bool invalidMap = true;
    string filename = "";
    Maploader* maploader;
    cout << INIT_MAP << endl;
    while (invalidMap) {
        cout << CHOOSE_MAP << endl;
        cin >> filename;
        maploader = new Maploader(MAP_DIRECTORY + filename);
        if (maploader->worldValid()) {
            world = maploader->getWorld();
            invalidMap = false;
        } else {
            cout << INVALID_MAP << endl;
        }
        delete maploader;
    }
}

/**
 * Create a deck of cards and shuffle them
 */
void GameStarter::createDeck() {
    cout << INIT_DECK << endl;
    deck = new Deck();
    deck->shuffle();
    deck->shuffle();
    cout << SHUFFLING_DECK << endl;
}

/**
 * Accessor for World
 * @return {World*} world
 */
World* GameStarter::getWorld() const {
    return world;
}

/**
 * Accessor for the deck of cards
 * @return {Deck*} deck
 */
Deck* GameStarter::getDeck() const {
    return deck;
}

/**
 * Accessor for players
 * @return {Player**} players
 */
Player** GameStarter::getPlayers() const {
    return players;
}

/**
 * Accessor for number of players
 * @return {unsigned int} numPLayers
 */
unsigned int GameStarter::getNumPlayers() const {
    return numPlayers;
}
