/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AggressiveStrategy.cpp
 * Author: olitr
 * 
 * Created on November 6, 2017, 10:17 AM
 */

#include <vector>

#include "AggressiveStrategy.h"
using namespace std;

AggressiveStrategy::AggressiveStrategy() {
}

AggressiveStrategy::AggressiveStrategy(const AggressiveStrategy& orig) {
}

AggressiveStrategy::~AggressiveStrategy() {
}

void AggressiveStrategy::reinforce(int reinforcements, Player* player){
    
    cout << "Aggressive player reinforcement phase." << endl;
    
    Territory* strongest = player->getTerritories()->at(0);
    //Find strongest territory
    for (int i = 1; i < player->getTerritories()->size(); i++){
        if (player->getTerritories()->at(i)->getArmies() > strongest->getArmies()){
            strongest = player->getTerritories()->at(i);
        }
    }
    
    //Reinforce the territory
    cout << "Current reinforcements value: " << reinforcements << endl;
    cout << "Strongest territory: " << strongest->getName() << endl;
    cout << "Strongest territory army value: " << strongest->getArmies() << endl;
    strongest->setArmies(strongest->getArmies() + reinforcements);
    
}

void AggressiveStrategy::attack(World* world, vector<Player*> players, Player* player){
    
    cout << "Aggressive player attack phase." << endl;
    
    Territory* strongest = player->getTerritories()->at(0);
    //Find strongest territory
    for (int i = 1; i < player->getTerritories()->size(); i++){
        if (player->getTerritories()->at(i)->getArmies() > strongest->getArmies()){
            strongest = player->getTerritories()->at(i);
        }
    }
    
    //Find strongest territory location within the world
    int worldLocation;
    for (int i = 0; i < world->getTerritoriesCount() ; i++){
        if (world->getTerritories()[i].territory == strongest) {
            worldLocation = i;
        }
    }
    
    //Find an attackable territory (if there is one)
    int attackableTerritory = -1;
    for (int i = 0; i < world->getTerritories()[worldLocation].adjacentCount; i++){
        if (world->getTerritories()[worldLocation].adjacentTerritories[i]->getOwner() != player){
            attackableTerritory = i;
        }
    }
    
    if (attackableTerritory > -1){
        
        int maxAtk = world->getTerritories()[worldLocation].territory->getArmies() - 1;
    
        //Player attacks as long as they can attack
        while (maxAtk > 0){
            cout << "Player can attack a territory." << endl;
        
            if (maxAtk > 3){
                maxAtk = 3;
            }
            player->getDiepool()->roll(maxAtk);
            player->getDiepool()->sortDice(maxAtk);
        
            int maxDef = world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->getArmies();
            if (maxDef > 2){
                maxDef = 2;
            }
            Player* defendingPlayer = (world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->getOwner());
        
            // rolls and sorts defenders dice
            
            defendingPlayer->getDiepool()->roll(maxDef);
            defendingPlayer->getDiepool()->sortDice(maxDef);
            
            cout << "Attacker rolled " << player->getDiepool()->getDie1() << " Defender rolled " << defendingPlayer->getDiepool()->getDie1() << endl;
            
            //compares the dice rolls and distributes damage appropriately
            
            if (player->getDiepool()->getDie1()> defendingPlayer->getDiepool()->getDie1()){
                int n = world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->getArmies() - 1;
                world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->setArmies(n);
                cout << "attacker wins" << endl;
            }
            else{
                int n = world->getTerritories()[worldLocation].territory->getArmies() - 1;
                world->getTerritories()[worldLocation].territory->setArmies(n);
                cout << "defender wins" << endl;
            }
            
            if(maxDef == 2 && maxAtk >= 2){
                cout << "Attacker rolled " << player->getDiepool()->getDie2() << " Defender rolled " << defendingPlayer->getDiepool()->getDie2() << endl;
                
                if (player->getDiepool()->getDie2()> defendingPlayer->getDiepool()->getDie2()){
                    int n = world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->getArmies() - 1;
                    world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->setArmies(n);
                    cout << "attacker wins" << endl;
                }
                else{
                    int n = world->getTerritories()[worldLocation].territory->getArmies() - 1;
                    world->getTerritories()[worldLocation].territory->setArmies(n);
                    cout << "defender wins" << endl;
                }
            }
            
            //checks to see if defender has ran out of units
            //if yes, proceeds to transfer units from attacker to conquered territory
          
            if (world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->getArmies() == 0){
                cout << "defending territory has been defeated" << endl;
                int transMax = world->getTerritories()[worldLocation].territory->getArmies()-1;
                
                //performs the transfer
                
                world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]->setArmies(transMax);
                player->addTerritory(world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]);
                defendingPlayer->removeTerritory(world->getTerritories()[worldLocation].adjacentTerritories[attackableTerritory]);
                world->getTerritories()[worldLocation].territory->setArmies(world->getTerritories()[worldLocation].territory->getArmies()-transMax);
                }
            maxAtk = world->getTerritories()[worldLocation].territory->getArmies() - 1;
        }
    }
    else {
        cout << "Player can't attack a territory." << endl;
    }
    
    cout << "Aggressive player attack phase finished" << endl;
    
}

void AggressiveStrategy::fortify(World* world, Player* player){
    
    cout << "Aggressive player fortification phase." << endl;
    
    Territory* strongest = player->getTerritories()->at(0);
    //Find strongest territory
    for (int i = 1; i < player->getTerritories()->size(); i++){
        if (player->getTerritories()->at(i)->getArmies() > strongest->getArmies()){
            strongest = player->getTerritories()->at(i);
        }
    }
    
    //Find strongest territory location within the world
    int worldLocation;
    for (int i = 0; i < world->getTerritoriesCount() ; i++){
        if (world->getTerritories()[i].territory == strongest) {
            worldLocation = i;
        }
    }
    
    //Find adjacent strongest territory to move all its armies
    int secondStrongestLocation = 0;
    for (int i = 1; i < world->getTerritories()[worldLocation].adjacentCount; i++){
        if (world->getTerritories()[worldLocation].adjacentTerritories[i]->getArmies() > world->getTerritories()[worldLocation].adjacentTerritories[secondStrongestLocation]->getArmies() &&
            world->getTerritories()[worldLocation].territory->getOwner() == player){
            secondStrongestLocation = i;
        }
    }
    
    //Move armies, if possible
    if (world->getTerritories()[worldLocation].adjacentTerritories[secondStrongestLocation]->getArmies() > 1){
        world->getTerritories()[worldLocation].territory->setArmies(world->getTerritories()[worldLocation].territory->getArmies() + world->getTerritories()[worldLocation].adjacentTerritories[secondStrongestLocation]->getArmies() - 1);
        world->getTerritories()[worldLocation].adjacentTerritories[secondStrongestLocation]->setArmies(1);
    }
    
    cout << "Aggressive player fortification phase over." << endl;
    
}