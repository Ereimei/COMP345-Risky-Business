/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BenevolentStrategy.cpp
 * Author: olitr
 * 
 * Created on November 6, 2017, 10:17 AM
 */

#include "BenevolentStrategy.h"

BenevolentStrategy::BenevolentStrategy() {
}

BenevolentStrategy::BenevolentStrategy(const BenevolentStrategy& orig) {
}

BenevolentStrategy::~BenevolentStrategy() {
}

void BenevolentStrategy::reinforce(int reinforcements, Player* player){
    
    cout << "Benevolent player reinforcement phase." << endl;
    
    Territory* weakest = player->getTerritories()->at(0);
    //Find weakest territory
    for (int i = 1; i < player->getTerritories()->size(); i++){
        if (player->getTerritories()->at(i)->getArmies() < weakest->getArmies()){
            weakest = player->getTerritories()->at(i);
        }
    }
    
    //Reinforce the territory
    cout << "Current reinforcements value: " << reinforcements << endl;
    cout << "Strongest territory: " << weakest->getName() << endl;
    cout << "Strongest territory army value: " << weakest->getArmies() << endl;
    weakest->setArmies(weakest->getArmies() + reinforcements);
}

void BenevolentStrategy::attack(World* world, vector<Player*> players, Player* player){
    cout << "Benevolent player never attacks!" << endl;
}

void BenevolentStrategy::fortify(World* world, Player* player){
    cout << "Benevolent player fortification phase." << endl;
    
    Territory* weakest = player->getTerritories()->at(0);
    //Find weakest territory
    for (int i = 1; i < player->getTerritories()->size(); i++){
        if (player->getTerritories()->at(i)->getArmies() < weakest->getArmies()){
            weakest = player->getTerritories()->at(i);
        }
    }
    
    //Find weakest territory location within the world
    int worldLocation;
    for (int i = 0; i < world->getTerritoriesCount() ; i++){
        if (world->getTerritories()[i].territory == weakest) {
            worldLocation = i;
        }
    }
    
    //Find adjacent strongest territory to move all its armies
    int strongestLocation = 0;
    for (int i = 1; i < world->getTerritories()[worldLocation].adjacentCount; i++){
        if (world->getTerritories()[worldLocation].adjacentTerritories[i]->getArmies() > world->getTerritories()[worldLocation].adjacentTerritories[strongestLocation]->getArmies() &&
            world->getTerritories()[worldLocation].territory->getOwner() == player){
            strongestLocation = i;
        }
    }
    
    //Move armies, if possible
    if (world->getTerritories()[worldLocation].adjacentTerritories[strongestLocation]->getArmies() > 1){
        int totalArmies = world->getTerritories()[worldLocation].territory->getArmies() + world->getTerritories()[worldLocation].adjacentTerritories[strongestLocation]->getArmies();
        int armies1, armies2;
        if (totalArmies % 2 == 1){
            armies1 = totalArmies / 2;
            armies2 = armies1 + 1;
        }
        else {
            armies1 = totalArmies / 2;
            armies2 = armies1;
        }
        world->getTerritories()[worldLocation].territory->setArmies(armies1);
        world->getTerritories()[worldLocation].adjacentTerritories[strongestLocation]->setArmies(armies2);
    }
    
    cout << "Benevolent player fortification phase over." << endl;
}