/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eagle
 *
 * Created on November 22, 2017, 6:52 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include "../gamestarter2/GameStarter.h"
#include "../startup/startup.h"
#include "../mainGame/mainGame.h"
#include "../phaseObserver/phaseObserver.h"
#include "../strategy/Strategy.h"
#include "../strategy/AggressiveStrategy.h"
#include "../interfaces/interfaces.h"
#include "tournament.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int numGames, maxTurns, numMaps, select, numPlayers;

    //select the number of maps to be used
    cout << "How many different maps do you wish to play? (1 to 5)" << endl;
    cin >> numMaps;
    while (numMaps < 1 || numMaps > 5) {
        cout << "Please enter a number between 1 and 5" << endl;
        cin >> numMaps;
    }
    string mapNames[numMaps - 1];
    int mapSelection[numMaps - 1];
    //fill the mapSelection array with 0
    for (int i = 0; i < numMaps; i++) {
        mapSelection[i] = 0;
    }
    // select the maps
    for (int i = 0; i < numMaps; i++) {
        cout << "Select map" << (i + 1) << "by typing appropriate number (please no repeat maps)" << endl;
        cout << "1 World" << endl;
        cout << "2 Antarctica" << endl;
        cout << "3 Canada" << endl;
        cout << "4 India" << endl;
        cout << "5 Europe" << endl;
        cin >> select;
        while (select < 1 || select > 5) {
            cout << "Please enter a number between 1 and 5" << endl;
            cin >> select;
        }

        for (int j = 0; j < i; j++) {
            if (mapSelection[j] == select) {
                while (mapSelection[j] == select) {
                    cout << "Please enter a number between 1 and 5" << endl;
                    cin >> select;
                    while (select < 1 || select > 5) {
                        cout << "Please enter a number between 1 and 5" << endl;
                        cin >> select;
                    }
                }
                j = 0;
            }
        }
        mapSelection[i] = select;
    }//end of map selection
    //stash selected maps   
    for (int i = 0; i < sizeof (mapSelection); i++) {
        if (mapSelection[i] == 1) {
            mapNames[i] = "World.map";
        }
        if (mapSelection[i] == 2) {
            mapNames[i] = "Antarctica.map";
        }
        if (mapSelection[i] == 3) {
            mapNames[i] = "Canada.map";
        }
        if (mapSelection[i] == 4) {
            mapNames[i] = "India.map";
        }
        if (mapSelection[i] == 5) {
            mapNames[i] = "Europe.map";
        }
    }//end of stashing selected maps

    cout << "How many different player strategies do you want to play? (2 to 4)" << endl;
    cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 4) {
        cout << "Please enter a number between 2 and 4" << endl;
        cin >> numPlayers;
    }
    int playerStrat[numPlayers - 1];
    //fill the playerStrat array with 0
    for (int i = 0; i < numPlayers; i++) {
        playerStrat[i] = 0;
    }
    // select the strats
    for (int i = 0; i < numPlayers; i++) {
        cout << "Select player strategy " << (i + 1) << "by typing appropriate number (please no repeat maps)" << endl;
        cout << "1 Aggressive" << endl;
        cout << "2 Benevolent" << endl;
        cout << "3 Random" << endl;
        cout << "4 Cheater" << endl;
        cin >> select;
        while (select < 1 || select > 4) {
            cout << "Please enter a number between 2 and 4" << endl;
            cin >> select;
        }

        for (int j = 0; j < i; j++) {
            if (playerStrat[j] == select) {
                while (playerStrat[j] == select) {
                    cout << "Please enter a number between 1 and 4" << endl;
                    cin >> select;
                    while (select < 1 || select > 4) {
                        cout << "Please enter a number between 1 and 4" << endl;
                        cin >> select;
                    }
                }
                j = 0;
            }
        }
        playerStrat[i] = select;
    }//end of player selection

    cout << "Set turn limit for each game(10-50)" << endl;
    cin >> maxTurns;
    while (maxTurns < 10 || maxTurns > 50) {
        cout << "Please enter a number between 10 and 50" << endl;
        cin >> maxTurns;
    }
    cout << "Set number of games per map" << endl;
    cin >> numGames;
    while (numGames < 1 || numGames > 5) {
        cout << "Please enter a number between 1 and 5" << endl;
        cin >> numGames;
    }
    //initialize winner array
    int winner[numMaps - 1][numGames - 1];
    for (int i = 0; i < numMaps; i++) {
        for (int j = 0; j < numGames; j++) {
            winner[i][j] = 0;
        }
    }
    //run all the games per map and store winning player number in winner array
    for (int i = 0; i < numMaps; i++) {
        for (int j = 0; j < numGames; j++) {

            GameStarter* gs = new GameStarter();
            gs->startGame(numPlayers, playerStrat, mapNames[i]);
            Startup* su = new Startup(gs->getPlayers(), gs->getNumPlayers());
            su->displayPlayerOrder();
            su->assignTerritory(su->getAllTerritories(gs->getWorld()));
            su->placeArmies(su->assignArmies());
            cout << "start up finished" << endl;
            cout << "===========================" << endl;
            MainGame* main = new MainGame();
            winner[i][j] = main->loopGame(gs, su, maxTurns);

        }
    }
    string win;
    //cycle through winner array and store winning strategy, or draw, in win var
    //print out the winner of each game for each map
    for (int i = 0; i < numMaps; i++) {
        for (int j = 0; j < numGames; j++) {

            if (winner[i][j] == 5) {
                win = "Draw";
            } else {
                if (playerStrat[winner[i][j]] == 0) {
                    win = "Aggressive";
                }
                if (playerStrat[winner[i][j] - 1] == 1) {
                    win = "Benevolent";
                }
                if (playerStrat[winner[i][j] - 1] == 2) {
                    win = "Random";
                }
                if (playerStrat[winner[i][j] - 1] == 3) {
                    win = "Cheater";
                }
            }
            cout << "Map: " << mapNames[i] << " Game: " << j << "Winner: " << win << endl;
        }
    }

    return 0;
}

