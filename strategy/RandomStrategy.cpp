/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: RandomStrategy.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 4
Professor: Dr. Joey Paquet
Created on November 18, 2017, 8:32 PM */

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

#include "RandomStrategy.h"

using namespace std;
        
RandomStrategy::RandomStrategy(){}
    
RandomStrategy::RandomStrategy(const RandomStrategy& orig){}

RandomStrategy::~RandomStrategy(){}

void RandomStrategy::reinforce(int reinforcements, Player* player){
    
     cout << "---Random player reinforcement phase---" << endl;
     
     //Get random territory
     int randomIndex = rand() % player->getTerritories()->size();
     Territory* randomTerritory = player->getTerritories()->at(randomIndex);
     
     cout << "Random territory selected: " << randomTerritory->getName() << endl;
     
    //Reinforce random territory
     randomTerritory->setArmies(randomTerritory->getArmies() + reinforcements);
     
     cout << randomTerritory->getName() << " now has " << randomTerritory->getArmies() <<" armies" << endl;
     

}
    
void RandomStrategy:: attack(World* world, vector<Player*> players, Player* player){
    
    cout << "---Random player attack phase---" << endl;
    
    bool foundTerritory = false;
    int randomIndex;
    Territory* randomTerritory;
    Territory* targetTerritory;
    Player* defendingPlayer;
    int maxAttack;
    int maxDefend;
    int randomTime;
    Diepool* playerResult;
    Diepool* defenderResult;
    int transferArmy;
    
    //find a random territory with an adjacent territory that belongs to another player
    while(foundTerritory == false){
        randomIndex = rand() % player->getTerritories()->size();
        randomTerritory = player->getTerritories()->at(randomIndex);
        //check if random territory has enough armies to make an attack
        if(randomTerritory->getArmies() > 1){
            for (int k = 0; k < world->getTerritories()[randomIndex].adjacentCount; k++){
               if (world->getTerritories()[randomIndex].adjacentTerritories[k]->getOwner() != player){
                   targetTerritory = world->getTerritories()[randomIndex].adjacentTerritories[k];
                   foundTerritory = true;
               }
            }  
        }
    }
    
    //get the max. amount of attack possible and max. amount of defense possible
    maxAttack = randomTerritory->getArmies() - 1;
    maxDefend = targetTerritory->getArmies();
    
    //get random amount of times to attack
    randomTime = rand() % maxAttack;
    cout << "Random player strategy will attack " << targetTerritory->getName() << " from " << randomTerritory->getName() << " " << randomTime << " times" << endl;
    
    //get owner of the target territory
    defendingPlayer = (targetTerritory->getOwner());
    
    if(randomTime == 0){
        cout<<"Random player is not attacking." << endl;
        cout<<"Let's attack at least once." << endl;
        randomTime = 1;
    }
    
    //loop the set amount of time of attacks
    while(randomTime > 0 ){
        
        //set maximum amount of dices
        //attacker can't roll more than 3, while defender can't roll more than 2
        if(maxAttack > 3){
            maxAttack = 3;
        }
        if(maxDefend > 2){
            maxDefend = 2;
        }
    
        //player rolls the dices
        player->getDiepool()->roll(maxAttack);
        player->getDiepool()->sortDice(maxAttack);
        playerResult = player->getDiepool();
        
        //defender rolls the dices
        defendingPlayer->getDiepool()->roll(maxDefend);
        defendingPlayer->getDiepool()->sortDice(maxDefend);
        defenderResult = defendingPlayer->getDiepool();

        //announce result
        cout << "Attacker rolled " << playerResult->getDie1() << " Defender rolled " << defenderResult->getDie1() << endl;
        
        //result of first dice
        //if attacker wins, then the target territory loses 1 army
        //else defender wins, then the random territory loses 1 army
        if(playerResult->getDie1() > defenderResult->getDie1()){
            targetTerritory->setArmies(targetTerritory->getArmies() - 1);
            cout << "Attacker wins" << endl;
        }else{
            randomTerritory->setArmies(randomTerritory->getArmies() - 1);
            cout << "Defender wins" << endl;
        }
        
        //result of second dice
        if(maxDefend == 2 && maxAttack >= 2){
            cout << "Attacker rolled "  << playerResult->getDie2() << " Defender rolled " << defenderResult->getDie2() << endl;
            if(playerResult->getDie2() > defenderResult->getDie2()){
                targetTerritory->setArmies(targetTerritory->getArmies() - 1);
                cout << "Attacker wins" << endl;
            }else{
                randomTerritory->setArmies(randomTerritory->getArmies() - 1);
                cout << "Defender wins" << endl;
            }
        }
        
        //goes to next round
        randomTime = randomTime-1;
                
        //check if defender has ran out of units
        //if so, then attacker gets to conquer the target territory
        if(targetTerritory->getArmies() == 0){
            cout << "Targeted territory, " << targetTerritory->getName() << ", has been conquered" << endl;
            //transfer the army and the target territory to the attacker
            transferArmy = randomTerritory->getArmies()-1;
            targetTerritory->setArmies(transferArmy);
            randomTerritory->setArmies(1);
            player->addTerritory(targetTerritory);
            randomTime = 0;
        }
        
        //reset the amount of max. attack and max. defend
        maxAttack = randomTerritory->getArmies() - 1;
        maxDefend = targetTerritory->getArmies();

    }
    
}
 
void RandomStrategy:: fortify(World* world, Player* player){
    cout << "---Random player fortification phase---" << endl;
     
    //Get random territory
    int randomIndexFrom = rand() % player->getTerritories()->size();
    Territory* randomTerritoryFrom = player->getTerritories()->at(randomIndexFrom);
     
     //Get random territory
    int randomIndexTo = rand() % player->getTerritories()->size();
    Territory* randomTerritoryTo = player->getTerritories()->at(randomIndexTo);
    
    int transferArmy = randomTerritoryFrom->getArmies() - 1;
    
    //ensure that random territory has enough army to transfer
    if(transferArmy > 0 ){
        randomTerritoryFrom->setArmies(1);
        randomTerritoryTo->setArmies(transferArmy);     
        cout << "Transferring " << transferArmy << " armies from " << randomTerritoryFrom->getName() << " to " << randomTerritoryTo->getName() << endl;
    }else{
        cout << randomTerritoryFrom->getName() << " does not have enough army to transfer. " << endl;
    }
}
        