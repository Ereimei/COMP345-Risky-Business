/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cheaterStrategy.cpp
 * Author: trep
 * 
 * Created on November 18, 2017, 12:06 PM
 */

#include <vector>

#include "cheaterStrategy.h"

cheaterStrategy::cheaterStrategy() {
}

cheaterStrategy::cheaterStrategy(const cheaterStrategy& orig) {
}

cheaterStrategy::~cheaterStrategy() {
}

//Doubles all the amount of armies on each of its territories
void cheaterStrategy::reinforce(int reinforcements, Player* player){
    
    //Doubles the amount of army on each territory they own
    for (int i = 0; i < player->getTerritories()->size(); i++){
        player->getTerritories()->at(i)->setArmies(player->getTerritories()->at(i)->getArmies() * 2);
    }
    
}
//Automatically conquers all adjacent territories
void cheaterStrategy::attack(World* world, vector<Player*> players, Player* player){
    
    int playerTerritoryIndex;
    
    //Find territory in the world, for every territory the player owns
    for (int i = 0; i < player->getTerritories()->size(); i++){
        for (int j = 0; j < world->getTerritoriesCount(); j++){
            if (player->getTerritories()->at(i) == world->getTerritories()[j].territory){
                playerTerritoryIndex = j;                
            }
            break;
        }
        
        //Check every adjacent territory if they are owned by the player, if not, conquer it
        for (int j = 0; j < world->getTerritories()[playerTerritoryIndex].adjacentCount; j++){
            if (world->getTerritories()[playerTerritoryIndex].adjacentTerritories[j]->getOwner() != player){
                world->getTerritories()[playerTerritoryIndex].adjacentTerritories[j]->setOwner(player);
                world->getTerritories()[playerTerritoryIndex].adjacentTerritories[j]->setArmies(player->getTerritories()->at(i)->getArmies());
            }
        }
    }
    
}

//Doubles number of armies that have enemy country as neighbor
void cheaterStrategy::fortify(World* world, Player* player){
    
    int playerTerritoryIndex;
    
    //Find territory in the world, for every territory the player owns
    for (int i = 0; i < player->getTerritories()->size(); i++){
        for (int j = 0; j < world->getTerritoriesCount(); j++){
            if (player->getTerritories()->at(i) == world->getTerritories()[j].territory){
                playerTerritoryIndex = j;                
            }
            break;
        }
        
        //Check every adjacent territory if they are owned by the player, if not, conquer it
        for (int j = 0; j < world->getTerritories()[playerTerritoryIndex].adjacentCount; j++){
            if (world->getTerritories()[playerTerritoryIndex].adjacentTerritories[j]->getOwner() != player){
                player->getTerritories()->at(i)->setArmies(player->getTerritories()->at(i)->getArmies() * 2);
            }
        }  
    }
}
