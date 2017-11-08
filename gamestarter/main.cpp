/* 
 * File:   main.cpp
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #2
 * Professor: Dr. Joey Paquet
 * Created on October 14, 2017, 1:36 PM
 */

#define GAME_START "===== STARTING GAME ====="

#include "../maploader/Maploader.h"
#include "GameStarter.h"
#include "../map/map.h"
#include "../player/Player.h"

#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char** argv) {
    GameStarter* gameStarter = new GameStarter();
    cout << GAME_START << endl;
    gameStarter->startGame();
    World* world = gameStarter->getWorld();
    Player** players = gameStarter->getPlayers();
//    world->setTerritoryOwner("Alberta", NULL);
//    world->setTerritoryOwner("Alberta", players[0]);
//    world->setTerritoryOwner("Greenland", players[0]);
//    world->setTerritoryOwner("Alaska", players[0]);
//    world->setTerritoryOwner("Alaska", players[1]);
//    world->setTerritoryOwner("Alberta", NULL);
//    world->setTerritoryOwner("Alaska", NULL);
//    world->setTerritoryOwner("Greenland", NULL); //code for testing with world.map
    world->setTerritoryOwner("Territory01", players[0]);
    world->setTerritoryOwner("Territory02", players[0]);
    world->setTerritoryOwner("Territory03", players[0]);
    world->setTerritoryOwner("Territory04", players[0]);
    world->setTerritoryOwner("Territory05", players[0]);
    world->setTerritoryOwner("Territory06", players[0]);
    world->setTerritoryOwner("Territory07", players[0]);
    world->setTerritoryOwner("Territory08", players[1]);
    world->setTerritoryOwner("Territory09", players[1]);
    world->setTerritoryOwner("Territory10", players[1]);
    world->setTerritoryOwner("Territory11", players[1]);
    world->setTerritoryOwner("Territory12", players[1]);
    world->setTerritoryOwner("Territory13", players[1]);
    world->setTerritoryOwner("Territory14", players[1]);//code for testing with antarctica.map  
    return 0;
}

