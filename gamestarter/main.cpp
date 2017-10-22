/* 
 * File:   main.cpp
 * Author: Patman1
 *
 * Created on October 14, 2017, 1:36 PM
 */

#define GAME_START "===== STARTING GAME ====="

#include "../maploader/Maploader.h"
#include "GameStarter.h"

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
    cout << gameStarter->getWorld()->getTerritories()->territory[0].getName() << endl;
    return 0;
}

