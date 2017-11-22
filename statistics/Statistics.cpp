/* 
 * File:   Statistics.cpp
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #3
 * Professor: Dr. Joey Paquet
 * 
 * Created on November 4, 2017, 11:13 PM
 */

#include "Statistics.h"

const string GameStatistics::TURN_START = "===== Turn: ";
const string GameStatistics::TURN_END = " =====";
const string GameStatistics::STATISTICS = "\n########## STATISTICS ##########\n";

GameStatistics::GameStatistics() {
    mainGameSubject = NULL;
}

GameStatistics::GameStatistics(MainGame* mg) {
    mainGameSubject = mg;
    mainGameSubject->attach(this);
}

GameStatistics::~GameStatistics() {
    mainGameSubject->detach(this);
}

void GameStatistics::update() {
    cout << TURN_START << mainGameSubject->getTurn() << TURN_END << endl;
}

ObserverDecorator::ObserverDecorator() : decoratedObserver(NULL) {

}

ObserverDecorator::ObserverDecorator(Observer* o) : decoratedObserver(o) {

}

ObserverDecorator::~ObserverDecorator() {

}

void ObserverDecorator::update() {
    decoratedObserver->update();
}

Observer* ObserverDecorator::getDecoratedObserver() const {
    return decoratedObserver;
}

string PlayerDomination::PLAYER_OWNERSHIP_GRAPH = "===== OWNERSHIP GRAPH =====";
string PlayerDomination::PLAYER = "player #";
string PlayerDomination::OWNERLESS = "No owner-";
string PlayerDomination::GRAPH_ELEMENT = "#";
string PlayerDomination::GRAPH_DELIMITER_START = ": [";
string PlayerDomination::GRAPH_DELIMITER_END = "]";
string PlayerDomination::SPACE = " ";
unsigned int PlayerDomination::GRAPH_MULTIPLIER = 50;

PlayerDomination::PlayerDomination(Observer* o, World* w, unsigned int nplayers) :
ObserverDecorator::ObserverDecorator(o),
numPlayers(nplayers),
numTerritories(w->getTerritoriesCount()) {
    worldSubject = w;
    worldSubject->attach(this);
    playerTerritoriesCount = new unsigned int[numPlayers];
    if (numTerritories < GRAPH_MULTIPLIER) {
        GRAPH_MULTIPLIER = numTerritories;
    }
}

PlayerDomination::~PlayerDomination() {
    worldSubject->detach(this);
    delete[] playerTerritoriesCount;
}

/**
 * Generate the graph
 */
void PlayerDomination::update() {
    unsigned int ownerlessTerritories, barMultiplier, spaceFiller;
    float percent;
    string output = "";
    ownerlessTerritories = numTerritories;
    for (int n = 0; n < numPlayers; ++n) {
        playerTerritoriesCount[n] = 0;
    }
    for (int n = 0; n < numTerritories; ++n) {
        if (worldSubject->getTerritories()[n].territory->getOwner() != NULL) {
            --ownerlessTerritories;
            ++playerTerritoriesCount[worldSubject->getTerritories()[n].territory->getOwner()->getPlayerNum()];
        }
    }
    cout << PLAYER_OWNERSHIP_GRAPH << endl;
    for (int n = 0; n < numPlayers; ++n) {
        percent = (float) playerTerritoriesCount[n] / numTerritories;
        barMultiplier = percent * GRAPH_MULTIPLIER;
        spaceFiller = GRAPH_MULTIPLIER - barMultiplier;
        output += PLAYER + std::to_string(n) + GRAPH_DELIMITER_START;
        for (int m = 0; m < barMultiplier; ++m) {
            output += GRAPH_ELEMENT;
        }
        for (int m = 0; m < spaceFiller; ++m) {
            output += SPACE;
        }
        output += GRAPH_DELIMITER_END;
        cout << output << endl;
        output = "";
    }
    output = OWNERLESS + GRAPH_DELIMITER_START;
    percent = (float) ownerlessTerritories / numTerritories;
    barMultiplier = percent * GRAPH_MULTIPLIER;
    spaceFiller = GRAPH_MULTIPLIER - barMultiplier;
    for (int n = 0; n < barMultiplier; ++n) {
        output += GRAPH_ELEMENT;
    }
    for (int n = 0; n < spaceFiller; ++n) {
        output += SPACE;
    }
    output += GRAPH_DELIMITER_END;
    cout << output << endl;
}

const string ContinentControl::CONTINENT_START = "##### Continent ";
const string ContinentControl::NOT_OWNED = " is not owned by a single player";
const string ContinentControl::OWNED = " is owned by player ";

ContinentControl::ContinentControl(Continent** c, unsigned int cCount) : continentCount(cCount) {
    continentSubjects = c;
    for (int n = 0; n < continentCount; ++n) {
        continentSubjects[n]->attach(this);
    }
}

ContinentControl::~ContinentControl() {
    for (int n = 0; n < continentCount; ++n) {
        continentSubjects[n]->detach(this);
    }
}

/**
 * update the continental control view
 */
void ContinentControl::update() {
    int ownedByPlayer;
    for (int n = 0; n < continentCount; ++n) {
        ownedByPlayer = continentSubjects[n]->getOwnerPlayerNumber();
        if (ownedByPlayer == continentSubjects[n]->NOT_CONTROLLED) {
            cout << CONTINENT_START << continentSubjects[n]->getName() << NOT_OWNED << endl;
        } else {
            cout << CONTINENT_START << continentSubjects[n]->getName() << OWNED << ownedByPlayer << endl;
        }
    }
}
