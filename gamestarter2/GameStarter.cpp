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
 * Control method for starting the game
 * It calls helper methods to get
 * everything going
 */
void GameStarter::startGame(int playerNum, int p1[], string mapName) {
    assignNumOfPlayers(playerNum);
    chooseAndCreateWorld(mapName);
    createDeck();
    createPlayers(p1);
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
 * Sets how many players there are based on input
 */
void GameStarter::assignNumOfPlayers(int playerNum) {
    numPlayers = playerNum;
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
    Strategy* strategy;
    int strategyType;
    cout << INIT_PLAYERS << endl;
    players = new Player*[numPlayers];
    for (int n = 0; n < numPlayers; ++n) {
        cout << CREATING_PLAYER << n << endl;
        cout << "Please enter a Strategy for player #" << n << " (1 = Player, 2 = Aggressive, 3 = Benevolent, 4 = Random, 5 = Cheater)" << endl;
        cin >> strategyType;
        while (strategyType < 1 || strategyType > 5) {
            cout << "Please enter a correct strategy value." << endl;
            cin >> strategyType;
        }
        hand = new Hand();
        diepool = new Diepool();
        territories = new vector<Territory*>;
        if (strategyType == 1) {
            strategy = new PlayerStrategy();
        } else if (strategyType == 2) {
            strategy = new AggressiveStrategy();
        } else if (strategyType == 3) {
            strategy = new BenevolentStrategy();
        } else if (strategyType == 4) {
            strategy = new RandomStrategy();
        } else if (strategyType == 5) {
            strategy = new cheaterStrategy();
        }
        players[n] = new Player(territories, hand, diepool, strategy, world);
    }
}

/**
 * Actually create players and assign
 * an empty hands of cards, a vector
 * of territories, and a die pool
 * based on the input value
 */
void GameStarter::createPlayers(int p1[]) {
    Hand* hand;
    vector<Territory*>* territories;
    Diepool* diepool;
    Strategy* strategy;
    int strategyType;
    cout << INIT_PLAYERS << endl;
    players = new Player*[numPlayers];
    for (int n = 0; n < numPlayers; ++n) {
        strategyType = p1[n];
        hand = new Hand();
        diepool = new Diepool();
        territories = new vector<Territory*>;
        if (strategyType == 1) {
            strategy = new AggressiveStrategy();
        } else if (strategyType == 2) {
            strategy = new BenevolentStrategy();
        } else if (strategyType == 3) {
            strategy = new RandomStrategy();
        } else if (strategyType == 4) {
            strategy = new cheaterStrategy();
        }
        players[n] = new Player(territories, hand, diepool, strategy, world);
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
 * Load world based on input filename
 */
void GameStarter::chooseAndCreateWorld(string filename) {
    Maploader* maploader;
    maploader = new Maploader(MAP_DIRECTORY + filename);
    world = maploader->getWorld();
    delete maploader;

}

/**
 * Create a deck of cards and shuffle them
 */
void GameStarter::createDeck() {
    cout << INIT_DECK << endl;
    deck = new Deck();
    deck->shuffle(getWorld());
    deck->shuffle(getWorld());
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
