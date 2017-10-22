/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: startup.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 2
Professor: Dr. Joey Paquet
Created on October 17, 2017, 10:20 PM */

#include <cmath>
#include <algorithm>
#include <iostream>
# include "startup.h"

using namespace std;

//constructor for playerInGame, it takes a player and add a number to the player
PlayerInGame::PlayerInGame(Player* pl, int n){
    *player = *pl;
    playerNum = n;
}

//constructor for set up, it creates a vector of players and randomizes the order of the players
Startup::Startup(Player** pl, int size){
    vector<PlayerInGame> vplayer;
    Player* player; 
    
    //put all players into a tamp vector to randomize
    for(int x = 0; x < size; x++){
        vplayer.push_back(PlayerInGame(pl[x], x));
    }
    
    int randomInd;
    for(int y = 0; y < size; y++){
        randomInd = rand() % vplayer.size();
        setOfPlayer.push_back(vplayer.at(randomInd));
        vplayer.erase(vplayer.begin() + randomInd);
    }
}

void Startup::addTerritory(Player* pl, Territory* tr){
    vector<Territory*>* vcTr = pl->getTerritories();
    vcTr->push_back(tr);
};

void Startup::removeTerritory(Player* pl, Territory* tr){
    vector<Territory*>* vcTr = pl->getTerritories();
    for(int i = 0; i<vcTr->size(); i++){
        if(&tr == &vcTr->at(i)){
            vcTr->erase(vcTr->begin() + i);
        }
    }
};
/*
vector<Territory*> Startup::getAllTerritories(World* world){
    int countryCont = world->getContinentsCount(); 
    Continent** continent; 
    Territory* territory;
    for(int y = 0; y<countryCont; y++){
        continent = world->getContinents();
        territory = continent->getTerritories();
        
    }
    
}
 */
    
void Startup::assignTerritory(vector<Territory*> vTerritory){
    cout << "Assigning countries..." << endl;
    int randomTerritory; 
    int playerCounter;
    Player* player;
    for(int x = 0; x < vTerritory.size(); x++){
        randomTerritory = rand() % vTerritory.size();
        player = setOfPlayer.at(playerCounter).getPlayer(); 
        addTerritory(player, vTerritory.at(randomTerritory));
        vTerritory.erase(vTerritory.begin() + randomTerritory);
        playerCounter ++;
    }
    
}

void Startup::displayPlayerOrder(){
    cout<<"Players are going in this order."<< endl;
    for(int i = 0; i< setOfPlayer.size(); i++){
        cout<<"Player #"<< setOfPlayer.at(i).getPlayerNum() <<endl;
    }
}

void Startup::displayTerritory(){
    cout<<"Territory assigned."<<endl;
    vector<Territory*>* vTr; 
    for(int i = 0; setOfPlayer.size(); i++){
        cout<<"Player #"<< setOfPlayer.at(i).getPlayerNum() <<"'s territories:" <<endl;
        vTr = setOfPlayer.at(i).getPlayer()->getTerritories();
        for(int j = 0; j < 2; j++){
            cout<<&vTr->begin()[j]<<endl;
        }
    }
}

int Startup::assignArmies(){
    int playerAmount = setOfPlayer.size();
    int armies = 0;
    if(playerAmount==2){
        armies = 40;
    }
    if(playerAmount==3){
        armies = 35;
    }
    if(playerAmount==4){
        armies = 30;
    }
    if(playerAmount==5){
        armies = 25;
    }
    if(playerAmount==6){
        armies = 20;
    }
    return armies;
};
    
void Startup::placeArmies(int armies){
    int splitedArmies = 0;
    int remainArmies = 0;
    for(int k = 0; k < setOfPlayer.size(); k++){
        Player* pl = setOfPlayer.at(k).getPlayer();
        splitedArmies = armies / pl->getTerritories()->size();
        for(int d = 0; d < pl->getTerritories()->size(); d++){
            pl->getTerritories()[d]->setArmies(splitedArmies);
       }
        if(armies % pl->getTerritories()->size() != 0){
            remainArmies = armies % pl->getTerritories()->size();
            for(int h = 0; h < remainArmies; h++){
                pl->getTerritories()[h]->setArmies(splitedArmies++);
            }
        }
    }
};
