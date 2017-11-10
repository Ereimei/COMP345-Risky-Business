/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlayerStrategy.cpp
 * Author: olitr
 * 
 * Created on November 6, 2017, 10:17 AM
 */

#include <iostream>
#include <string>
#include <sstream>

#include "PlayerStrategy.h"



using namespace std;

PlayerStrategy::PlayerStrategy() {
}

PlayerStrategy::PlayerStrategy(const PlayerStrategy& orig) {
}

PlayerStrategy::~PlayerStrategy() {
}

void PlayerStrategy::reinforce(int reinforcements, Player* player){

    string territory = "";
    string input = "";
    //Observer update
    currentAction = "Player is starting...";
    notify();
    int reinAmount;
        cin.ignore(1, EOF);
        while (reinforcements != 0){
            cout << "You have " << reinforcements << " army available for reinforcements." << endl;
            cout << "Your territories" << endl;
            cout << "----------------" << endl;
            for (int i = 0; i < player->getTerritories()->size(); i++){
                cout << player->getTerritories()->at(i)->getName() << " army: " << player->getTerritories()->at(i)->getArmies() << endl;
            }
            cout << "Please type the name of the territory you wish to to reinforce." << endl;
            
            
            getline(cin, territory);
            
            cout << "Please enter the amount of reinforcement." << endl;
            
            
            getline(cin, input);
            stringstream myStream(input);
            myStream >> reinAmount;
            for (int i = 0; i < player->getTerritories()->size(); i++){
                if (player->getTerritories()->at(i)->getName() == territory){
                    //If the player entered a # higher than the max amount of reinforcements
                    if (reinAmount > reinforcements){
                       player->getTerritories()->at(i)->setArmies(player->getTerritories()->at(i)->getArmies() + reinforcements);
                        reinforcements = 0;
                    }
                    else if (reinAmount < 0){
                        cout << "Please enter a number greater than 0." << endl;
                    }
                    else {
                        player->getTerritories()->at(i)->setArmies(player->getTerritories()->at(i)->getArmies() + reinAmount);
                        reinforcements -= reinAmount;
                        //Observer update
                        currentAction = "Player reinforces " + to_string(reinAmount)+" armies to "+territory;
                        notify();
                    }    
                }
            }
        }
        currentAction ="//////";
};

void PlayerStrategy::attack(World* world, vector<Player*> players, Player* player){
    //Observer update
    currentAction = "Player is starting...";
    notify();
    
    string answer;
    cout << "Do you want to attack? (y/n)" << endl;
    getline(cin, answer);
    
    //loop to ensure answer is in proper format
    
    while (answer != "y" && answer != "n"){
        cout << "Please answer in proper format (y/n)" << endl;
        getline(cin, answer);
    }
    
    //variables needed to check if player can attack
    bool canAtk = false;
    int atkTerr = 0;
    
    //loops to increment the atkTerr counter, which regulates amount of territories that can attack
    
    for (int i = 0; i < player->getTerritories()->size(); i++){
        for (int j = 0; j < world->getTerritoriesCount() ; j++){
            if (player->getTerritories()->at(i)->getName() == world->getTerritories()[j].territory->getName()){
                for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() != player && player->getTerritories()->at(i)->getArmies() > 1){
                        canAtk = true;
                    }
                } 
            }
        }
        if (canAtk){
            atkTerr += 1;
        }
        
        canAtk = false;
            
    }
    
    //start of attack phase loop, user can keep attacking
    while (answer == "y" && atkTerr > 0){
        
        //prints out territories that can be attacked
        //Territories that can be attacked will be listed under owned territories
        
        cout << "Possible territories to attack" << endl << endl;
        for (int i = 0; i < player->getTerritories()->size(); i++){
            cout << "From territory " << player->getTerritories()->at(i)->getName() << endl;
            for (int j = 0; j < world->getTerritoriesCount() ; j++){
                if (player->getTerritories()->at(i)->getName() == world->getTerritories()[j].territory->getName()){
                    for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                        if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() != player){
                        cout << world->getTerritories()[j].adjacentTerritories[k]->getName()<< endl;
                        }
                    } 
                }
            }
        }
        
        //user enter who they wish to attack with
        
        string attacker, defender;
        
        cout << "Please enter attacking territory" << endl;
        
        getline(cin, attacker);
        bool exists = false;
        
        //loop to ensure that the name entered corresponds to an existing territory
        while(exists == false)
        {
            for (int i = 0; i <player->getTerritories()->size(); i++)
            {
                if (player->getTerritories()->at(i)->getName() == attacker)
                {
                    exists = true;
                
                    if (player->getTerritories()->at(i)->getArmies() < 2)
                    {
                        cout << "The territory selected does not have sufficient armies to attack" << endl;
                        exists = false;
                    }
                }
            }            
            if (!exists){
                cout << "You did not enter a correct attacking territory" << endl;
                cout << "Please enter an attacking territory again." << endl;
                
                getline(cin, attacker);
            }
            
        }
        
        
        int atkPos, defPos;
        
        //user enters which territory they wish to attack
        
        cout << "Please enter territory you wish to conquer champion" << endl;
        
        getline(cin, defender);
        
        cout << "You entered: " << defender << endl;
        exists = false;
        
        //loop ensures that name entered corresponds to an existing territory
        while(!exists)
        {
            for (int i = 0; i < world->getTerritoriesCount(); i++)
            {
                if (world->getTerritories()[i].territory->getName() == attacker){
                    atkPos = i;
                    for (int j = 0; j < world->getTerritories()[i].adjacentCount; j++){
                        if (world->getTerritories()[i].adjacentTerritories[j]->getName() == defender){
                            exists = true;
                            defPos = j;
                        }
                    }
                }
             
            }            
            if (!exists){
                cout << "You did not enter a correct territory to conquer, champion" << endl;
                cout << "Please enter a territory again." << endl;
                
                getline(cin, defender);
            }
        }
        
        //attacker and defender selected, time to roll
        
        //variables required for dice rolling
        
        int atkDie, defDie, atkMax, defMax;
        string attacking = "y";
        //loop for current attack pattern , current attacker vs current defender
        
        while (attacking == "y"){
            
            //asks attacker how many dice they wish to roll with
            //checks that it is valid
            
            cout << attacker << " has " << world->getTerritories()[atkPos].territory->getArmies() << " armies" << endl;
            atkMax =  world->getTerritories()[atkPos].territory->getArmies() - 1;
            if(atkMax > 3){
                atkMax = 3;}
            cout << "Please enter amount of dice you wish to attack with champion (min 1, max " << atkMax << " )" << endl;
            string input = "";
            getline(cin, input);
            stringstream myStream(input);
            myStream >> atkDie;
            while(atkDie != 1 && atkDie != 2 && atkDie != 3 || atkDie > atkMax){
                cout << "I have no time for your games champion, enter an appropriate number (min 1, max " << atkMax << " )" << endl;
                getline(cin, input);
                stringstream myStream(input);
                myStream >> atkDie;
            }
        
            
            //asks defender how many dice they wish to roll with
            //checks that it is valid
            
            cout << defender << " is being attacked!!! and has " << world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() << " armies" << endl;
            defMax =  world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies();
            if(defMax > 2){
                defMax = 2;}
            cout << "Please enter amount of dice you wish to use to defend (min 1, max " << defMax << " )" << endl;
            string input2 = "";
            getline(cin, input2);
            stringstream myStream2(input2);
            myStream2 >> defDie;
            while(defDie != 1 && defDie != 2 || defDie > defMax){
                cout << "I have no time for your shenanigans vaunted defender, enter an appropriate number (min 1, max " << defMax << " )" << endl;
                getline(cin, input2);
                stringstream myStream(input2);
                myStream >> defDie;
            }
            
            //rolls and sorts attackers dice
            
            player->getDiepool()->roll(atkDie);
            player->getDiepool()->sortDice(atkDie);
        
            Player* defendingPlayer = (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getOwner());
        
            // rolls and sorts defenders dice
            
            defendingPlayer->getDiepool()->roll(defDie);
            defendingPlayer->getDiepool()->sortDice(defDie);
            
            //observer update
            currentAction = "Attacker rolled " + to_string(player->getDiepool()->getDie1()) + " Defender rolled " + to_string(defendingPlayer->getDiepool()->getDie1());
            notify();
            
            //compares the dice rolls and distributes damage appropriately
            
            if (player->getDiepool()->getDie1()> defendingPlayer->getDiepool()->getDie1()){
                int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                //observer update
                currentAction = "Attacker wins";
                notify();
            }
            else{
                int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                world->getTerritories()[atkPos].territory->setArmies(n);
                //observer update
                currentAction = "Defender wins";
                notify();
            }
            
            if(defDie == 2 && atkDie >= 2){
                cout << "Attacker rolled " << player->getDiepool()->getDie2() << " Defender rolled " << defendingPlayer->getDiepool()->getDie2() << endl;
                
                if (player->getDiepool()->getDie2()> defendingPlayer->getDiepool()->getDie2()){
                    int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                    world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                    //observer update
                    currentAction = "Attacker wins";
                    notify();
                }
                else{
                    int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                    world->getTerritories()[atkPos].territory->setArmies(n);
                    //observer update
                    currentAction = "Defender wins";
                    notify();
                }
            }
            
            //checks to see if defender has ran out of units
            //if yes, proceeds to transfer units from attacker to conquered territory
            
            if (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() == 0){
                cout << "defending territory has been defeated" << endl;
                cout << "champion, please select how many armies you wish to transfer to your new territory" << endl;
                int transMax = world->getTerritories()[atkPos].territory->getArmies()-1;
                cout << "min = 1, max = " << transMax << endl;
                int transfer;
                string trans = "";
                getline(cin, trans);
                stringstream myStream(trans);
                myStream >> transfer;
                while(transfer > transMax || transfer < 1 ){
                    cout << "please enter a number in the proper range champion" << endl;
                    cout << " min = 1, max = " << transMax << endl;
                    getline(cin, trans);
                    stringstream myStream(trans);
                    myStream >> transfer;
                }
                
                //performs the transfer
                
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(transfer);
                player->addTerritory(world->getTerritories()[atkPos].adjacentTerritories[defPos]);
                defendingPlayer->removeTerritory(world->getTerritories()[atkPos].adjacentTerritories[defPos]);
                world->getTerritories()[atkPos].territory->setArmies(world->getTerritories()[atkPos].territory->getArmies()-transfer);
                
                //checks to see if counter needs to be incremented or decremented
                if (world->getTerritories()[atkPos].territory->getArmies() == 1){
                    atkTerr -= 1;
                }
                
                if (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() > 1){
                    atkTerr += 1;
                }
                
                cout << "Transfer complete" << endl;
                cout << "Attacker, your territories are now " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < player->getTerritories()->size(); i++){
                    cout << player->getTerritories()->at(i)->getName()<< endl;
                }
                cout << "Defender your territories are now " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < defendingPlayer->getTerritories()->size(); i++){
                    cout << defendingPlayer->getTerritories()->at(i)->getName()<< endl;
                }   
            }
            
            //if attacker can no longer attack, decrement the counter
            
            if (world->getTerritories()[atkPos].territory->getArmies() == 1){
                atkTerr -= 1;
            }
                
            //if the current atk and def setup is no longer valid, end the current setup loop
            
            if(world->getTerritories()[atkPos].territory->getArmies() == 1 || world->getTerritories()[atkPos].adjacentTerritories[defPos]->getOwner() == player){
                attacking = "n";
            }
            else{
                cout << "Champion, do you wish to keep attacking the same location? (y/n)" << endl;
                getline(cin, attacking);
                while (attacking != "y" && attacking != "n"){
                    cout << "Please answer in proper format (y/n)" << endl;
                    getline(cin, attacking);
                }  
            }
        }
        
        //ask user if they want to keep attacking
        
        cout << "Do you want to attack? (y/n)" << endl;
        getline(cin, answer);
        while (answer != "y" && answer != "n"){
            cout << "Please answer in proper format (y/n)" << endl;
            getline(cin, answer);
        }
    }
    cout << "attack phase complete." << endl;

    currentAction ="//////";
};

void PlayerStrategy::fortify(World* world, Player* player) {
    //Observer update
    currentAction = "Player is starting...";
    notify();
        
    string source, target, choice;
    int xferArmies, sourceArmies, sourceIndex, targetIndex;
    bool valid = false, adjacentTerr;
    vector <Territory*> validTerritories;
    
    
    cout << "Do you want to fortify? (y/n)" << endl;
    getline(cin, choice);
    
    while(choice != "y" && choice !="n"){
        cout << "Give me a valid input, peasant." << endl;
        getline(cin, choice);
    }
    if (choice == "y"){
    //Printing out in console all the owned territories and their respective adjacent territories.
    for (int i = 0; i < player->getTerritories()->size(); i++){
        adjacentTerr = false;
        cout << endl << endl << "Territory: " << player->getTerritories()->at(i)->getName() << endl;
        cout << "Army amount: " << player->getTerritories()->at(i)->getArmies() << endl;
        cout << "Adjacent territories, and their army value." << endl;
        
        //Find the corresponding territory in the world to then find its adjacent territories
        for (int j = 0; j < world->getTerritoriesCount(); j++){
            //If we find the correct territory in the world, print all its adjacent territories that is owned by the player
            if (world->getTerritories()[j].territory->getName() == player->getTerritories()->at(i)->getName() && player->getTerritories()->at(i)->getArmies() > 1){
                for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() == player){
                        cout << "Name: " << world->getTerritories()[j].adjacentTerritories[k]->getName() << " Armies: " << world->getTerritories()[j].adjacentTerritories[k]->getArmies() << endl;
                        adjacentTerr = true;
                    }
                }
            }
        }
        
        if (!adjacentTerr){
            cout << "Territory " << player->getTerritories()->at(i)->getName() << " does not have any adjacent territory owned by the player or has an army value of 1." << endl;
        }
        else {
           valid = true;
           validTerritories.insert(validTerritories.begin(), player->getTerritories()->at(i));
        }
        
        cout << endl;
        
    }
    
    if (!valid){
        cout << "Player has no territories that can fortify. Skipping fortification phase." << endl;
    }
    else {
        valid = false;
        cout << endl << "Please enter the name of the source territory." << endl;
        source = "";
        getline(cin, source);
    
        while (!valid){
            for (int i = 0; i < validTerritories.size(); i++) {
                if (validTerritories.at(i)->getName() == source){
                    valid = true;
                }
            }
            
            if (!valid){
                cout << "You did not enter a proper valid source territory. Please try again." << endl;
                getline(cin, source);
            }
        
        }
        valid = false;
        
        //Print again the available adjacent territories
        cout << "You chose: " << source << " as a source country, the following are the available target countries." << endl;
        for (int j = 0; j < world->getTerritoriesCount(); j++){
            //If we find the correct territory in the world, print all its adjacent territories
            if (world->getTerritories()[j].territory->getName() == source){
                sourceArmies = world->getTerritories()[j].territory->getArmies();
                sourceIndex = j;
                for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() == player) {
                        cout << "Name: " << world->getTerritories()[j].adjacentTerritories[k]->getName() << " Armies: " << world->getTerritories()[j].adjacentTerritories[k]->getArmies() << endl;
                    }
                }
            }
        }
    
    
        cout << "Please enter the name the name of the target country." << endl;
        target = "";
        getline(cin, target);
    
    
    
        while (!valid){
        
            for (int i = 0; i < world->getTerritories()[sourceIndex].adjacentCount; i++){
                if (world->getTerritories()[sourceIndex].adjacentTerritories[i]->getName() == target && world->getTerritories()[sourceIndex].adjacentTerritories[i]->getOwner() == player){
                    targetIndex = i;
                    valid = true;
                    cout << "Valid target country." << endl;
                }
            
            }
        
            if (!valid){
                cout << "Target country entered is wrong, please try again." << endl;
                
                getline(cin, target);
            }
        
        }
    
        cout << "You chose: " << target << " as the target country, please enter the amount of armies you wish to send to " << target << "." << endl;
        cout << target << " currently has " << sourceArmies << ". Therefore, you can send between 1 and " << (sourceArmies - 1) << " armies." << endl; 
        string temp = "";
            getline(cin, temp);
            stringstream myStream(temp);
            myStream >> xferArmies;
    
        while (xferArmies < 1 || xferArmies > (sourceArmies-1) ){
            cout << "You did not enter a correct amount of armies. Please try again." << endl;
            getline(cin, temp);
            stringstream myStream(temp);
            myStream >> xferArmies;
        }
        //Observer update
        currentAction = "Transferring " + to_string(xferArmies) + " armies to the target country " + target;
        notify();
    
        world->getTerritories()[sourceIndex].territory->setArmies(world->getTerritories()[sourceIndex].territory->getArmies() - xferArmies);
        world->getTerritories()[sourceIndex].adjacentTerritories[targetIndex]->setArmies(world->getTerritories()[sourceIndex].adjacentTerritories[targetIndex]->getArmies() + xferArmies);

        cout << endl << "Printing out results to demonstrate proper transfer of armies." << endl;
    
        
        for (int i = 0; i < player->getTerritories()->size() ; i++){
            cout << "Name: " << player->getTerritories()->at(i)->getName() << " armies: " << player->getTerritories()->at(i)->getArmies() << endl;
        }
    
        cout << endl;
    
    }
    }
    currentAction ="//////";
};