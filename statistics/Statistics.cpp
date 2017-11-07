/* 
 * File:   Statistics.cpp
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #
 * Professor: Dr. Joey Paquet
 * 
 * Created on November 4, 2017, 11:13 PM
 */

#include "Statistics.h"

string Statistics::PLAYER_OWNERSHIP_GRAPH = "===== OWNERSHIP GRAPH =====";
string Statistics::PLAYER = "player #";
string Statistics::OWNERLESS = "No owner-";
string Statistics::GRAPH_ELEMENT = "#";
string Statistics::GRAPH_DELIMITER_START = ": [";
string Statistics::GRAPH_DELIMITER_END = "]";
string Statistics::SPACE = " ";
unsigned int Statistics::GRAPH_MULTIPLIER = 50;

Statistics::Statistics(World* w, unsigned int nplayers) :
    numPlayers(nplayers),
    numTerritories(w->getTerritoriesCount()) {
    worldSubject = w;
    worldSubject->attach(this);
    playerTerritoriesCount = new unsigned int[numPlayers];
}

Statistics::~Statistics() {
    worldSubject->detach(this);
    delete[] playerTerritoriesCount;
}

void Statistics::update() {
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
        percent = (float)playerTerritoriesCount[n] / numTerritories;
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
    percent = (float)ownerlessTerritories / numTerritories;
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
