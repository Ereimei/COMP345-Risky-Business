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
//    bool mapNotSelected = true;
//    string mapSelection;
//    Maploader* maploader;
//    cout << GAME_START << endl;
//    while (mapNotSelected) {
//        cout << SELECT_MAP << endl;
//        cin >> mapSelection;
//        cout << mapSelection << endl;
//        mapNotSelected = false;
//        maploader = new Maploader(MAP_DIRECTORY + mapSelection);
//        if (maploader->worldValid()) {
//            
//        }
//    }
    GameStarter* gameStarter = new GameStarter();
    cout << GAME_START << endl;
    gameStarter->startGame();
    return 0;
}

