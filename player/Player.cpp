/* 
 * File:   Player.cpp
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #1
 * Professor: Dr. Joey Paquet
 *
 * Created on September 27, 2017, 3:40 PM
 */


#include <iostream>
#include <ostream>

#include "../cards/hand.h"
#include "../dice/Diepool.h"
#include "../map/map.h"
#include "Player.h"

using std::cout;
using std::cin;
using std::string;
using namespace std;
        
//Constructor
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool) : territories(territories),
    hand(hand),
    diepool(diepool) {}

//Constructor with player number
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool, int n) : territories(territories),
    hand(hand),
    diepool(diepool),
    playerNum(n) {}

//Destructors
Player::~Player() {}

//Getters
vector<Territory*>* Player::getTerritories() {return territories;}
Hand* Player::getHand() {return hand;}
Diepool* Player::getDiepool() {return diepool;}

//Setters
void Player::setHand(Hand* hand) {hand = hand;}
void Player::setDiePool(Diepool* diepool) {diepool = diepool;}

void Player::addTerritory(Territory* territory){
    this->territories->insert(territories->begin(), territory);
    territory->setOwner(this);
};
void Player::removeTerritory(Territory* territory){};

//Other functions
void Player::reinforce(int reinforcements){ 
    string territory;
    int reinAmount;
    
    while (reinforcements != 0){
        cout << "You have " << reinforcements << " army available for reinforcements." << endl;
        cout << "Your territories" << endl;
        cout << "----------------" << endl;
        for (int i = 0; i < this->territories->size(); i++){
            cout << this->territories->at(i)->getName() << " army: " << this->territories->at(i)->getArmies() << endl;
        }
        cout << "Please type the name of the territory you wish to to reinforce followed by the amount of reinforcement." << endl;
        cin >> territory >> reinAmount;
        for (int i = 0; i < this->territories->size(); i++){
            if (this->territories->at(i)->getName() == territory){
                //If the player entered a # higher than the max amount of reinforcements
                if (reinAmount > reinforcements){
                   this->territories->at(i)->setArmies(this->territories->at(i)->getArmies() + reinforcements);
                    reinforcements = 0;
                }
                else if (reinAmount < 0){
                    cout << "Please enter a number greater than 0." << endl;
                }
                else {
                    this->territories->at(i)->setArmies(this->territories->at(i)->getArmies() + reinAmount);
                    reinforcements -= reinAmount;
                }    
            }
        }
    }
    
}
void Player::attack(World* world, vector<Player*> players){
    
    string answer;
    cout << "Do you want to attack? (y/n)" << endl;
    cin >> answer;
    //loop to ensure answer is in proper format
    while (answer != "y" && answer != "n"){
        cout << "Please answer in proper format (y/n)" << endl;
        cin >> answer;
    }
    
    bool canAtk = false;
    int atkTerr = 0;
    
    for (int i = 0; i < this->getTerritories()->size(); i++){
        for (int j = 0; j < world->getTerritoriesCount() ; j++){
            if (this->getTerritories()->at(i)->getName() == world->getTerritories()[j].territory->getName()){
                for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() != this && this->getTerritories()->at(i)->getArmies() > 1){
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
        cout << "Possible territories to attack" << endl << endl;
        for (int i = 0; i < this->getTerritories()->size(); i++){
            cout << "From territory " << this->getTerritories()->at(i)->getName() << endl;
            for (int j = 0; j < world->getTerritoriesCount() ; j++){
                if (this->getTerritories()->at(i)->getName() == world->getTerritories()[j].territory->getName()){
                    for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                        if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() != this){
                        cout << world->getTerritories()[j].adjacentTerritories[k]->getName()<< endl;
                        }
                    } 
                }
            }
        }
        
        string attacker, defender;
        cout << "Please enter attacking territory" << endl;
        cin >> attacker;
        bool exists = false;
        //loop to ensure that the name entered corresponds to an existing territory
        while(exists == false)
        {
            for (int i = 0; i <this->getTerritories()->size(); i++)
            {
                if (this->getTerritories()->at(i)->getName() == attacker)
                {
                    exists = true;
                
                    if (this->getTerritories()->at(i)->getArmies() < 2)
                    {
                        cout << "The territory selected does not have sufficient armies to attack" << endl;
                        exists = false;
                    }
                }
            }            
            if (!exists){
                cout << "You did not enter a correct attacking territory" << endl;
                cout << "Please enter an attacking territory again." << endl;
                cin >> attacker;
            }
            
        }
        
        
        int atkPos, defPos;
        
        cout << "Please enter territory you wish to conquer champion" << endl;
        cin >> defender;
        exists = false;
        //loop ensures that name entered corresponds to an existing territory
        while(exists == false)
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
                cin >> defender;
            }
        }
        
        int atkDie, defDie, atkMax, defMax;
        string attacking = "y";
        while (attacking == "y"){
            
            cout << attacker << " has " << world->getTerritories()[atkPos].territory->getArmies() << " armies" << endl;
            atkMax =  world->getTerritories()[atkPos].territory->getArmies() - 1;
            if(atkMax > 3){
                atkMax = 3;}
            cout << "Please enter amount of dice you wish to attack with champion (min 1, max " << atkMax << " )" << endl;
            cin >> atkDie;
            while(atkDie != 1 && atkDie != 2 && atkDie != 3 || atkDie > atkMax){
                cout << "I have no time for your games champion, enter an appropriate number (min 1, max " << atkMax << " )" << endl;
                cin >> atkDie;    
            }
        
            cout << defender << " is being attacked!!! and has " << world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() << " armies" << endl;
            defMax =  world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies();
            if(defMax > 2){
                defMax = 2;}
            cout << "Please enter amount of dice you wish to use to defend (min 1, max " << defMax << " )" << endl;
            cin >> defDie;
            while(defDie != 1 && defDie != 2 || defDie > defMax){
                cout << "I have no time for your shenanigans vaunted defender, enter an appropriate number (min 1, max " << defMax << " )" << endl;
                cin >> defDie;    
            }
          
            this->getDiepool()->roll(atkDie);
            this->getDiepool()->sortDice(atkDie);
        
            Player* defendingPlayer = (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getOwner());
        
            defendingPlayer->getDiepool()->roll(defDie);
            defendingPlayer->getDiepool()->sortDice(defDie);
            
            cout << "Attacker rolled " << getDiepool()->getDie1() << " Defender rolled " << defendingPlayer->getDiepool()->getDie1() << endl;
            
            //compares the dice rolls
            if (this->getDiepool()->getDie1()> defendingPlayer->getDiepool()->getDie1()){
                int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                cout << "attacker wins" << endl;
            }
            else{
                int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                world->getTerritories()[atkPos].territory->setArmies(n);
                cout << "defender wins" << endl;
            }
            
            if(defDie == 2 && atkDie >= 2){
                cout << "Attacker rolled " << getDiepool()->getDie2() << " Defender rolled " << defendingPlayer->getDiepool()->getDie2() << endl;
                
                if (this->getDiepool()->getDie2()> defendingPlayer->getDiepool()->getDie2()){
                    int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                    world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                    cout << "attacker wins" << endl;
                }
                else{
                    int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                    world->getTerritories()[atkPos].territory->setArmies(n);
                    cout << "defender wins" << endl;
                }
            }
            
            if (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() == 0){
                cout << "defending territory has been defeated" << endl;
                cout << "champion, please select how many armies you wish to transfer to your new territory" << endl;
                int transMax = world->getTerritories()[atkPos].territory->getArmies()-1;
                cout << "min = 1, max = " << transMax << endl;
                int transfer;
                cin >> transfer;
                while(transfer > transMax || transfer < 1 ){
                    cout << "please enter a number in the proper range champion" << endl;
                    cout << " min = 1, max = " << transMax << endl;
                    cin >> transfer;
                }
                
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(transfer);
                this->addTerritory(world->getTerritories()[atkPos].adjacentTerritories[defPos]);
                defendingPlayer->removeTerritory(world->getTerritories()[atkPos].adjacentTerritories[defPos]);
                world->getTerritories()[atkPos].territory->setArmies(world->getTerritories()[atkPos].territory->getArmies()-transfer);
                
                if (world->getTerritories()[atkPos].territory->getArmies() == 1){
                    atkTerr -= 1;
                }
                
                if (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() > 1){
                    atkTerr += 1;
                }
                
                cout << "Transfer complete" << endl;
                cout << "Attacker, your territories are now " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < this->territories->size(); i++){
                    cout << this->territories->at(i)->getName()<< endl;
                }
                cout << "Defender your territories are now " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < defendingPlayer->territories->size(); i++){
                    cout << defendingPlayer->territories->at(i)->getName()<< endl;
                }   
            }
            
            if (world->getTerritories()[atkPos].territory->getArmies() == 1){
                atkTerr -= 1;
            }
                
            
            if(world->getTerritories()[atkPos].territory->getArmies() == 1 || world->getTerritories()[atkPos].adjacentTerritories[defPos]->getOwner() == this){
                attacking = "n";
            }
            else{
                cout << "Champion, do you wish to keep attacking the same location? (y/n)" << endl;
                cin >> attacking;
                while (attacking != "y" && attacking != "n"){
                    cout << "Please answer in proper format (y/n)" << endl;
                    cin >> attacking;
                }  
            }
        }
        cout << "Do you want to attack? (y/n)" << endl;
        cin >> answer;
        while (answer != "y" && answer != "n"){
            cout << "Please answer in proper format (y/n)" << endl;
            cin >> answer;
        }
    }
    cout << "attack phase complete." << endl;
    //world->getTerritories()[i].adjacentTerritories[j]->getOwner();
}


void Player::fortify(World* world){ 
    
    string source, target;
    int xferArmies, sourceArmies, sourceIndex, targetIndex;
    bool valid = false, adjacentTerr;
    vector <Territory*> validTerritories;
    
    //Printing out in console all the owned territories and their respective adjacent territories.
    for (int i = 0; i < this->getTerritories()->size(); i++){
        adjacentTerr = false;
        cout << endl << endl << "Territory: " << this->getTerritories()->at(i)->getName() << endl;
        cout << "Army amount: " << this->getTerritories()->at(i)->getArmies() << endl;
        cout << "Adjacent territories, and their army value." << endl;
        
        //Find the corresponding territory in the world to then find its adjacent territories
        for (int j = 0; j < world->getTerritoriesCount(); j++){
            //If we find the correct territory in the world, print all its adjacent territories that is owned by the player
            if (world->getTerritories()[j].territory->getName() == this->getTerritories()->at(i)->getName() && this->getTerritories()->at(i)->getArmies() > 1){
                for (int k = 0; k < world->getTerritories()[j].adjacentCount; k++){
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() == this){
                        cout << "Name: " << world->getTerritories()[j].adjacentTerritories[k]->getName() << " Armies: " << world->getTerritories()[j].adjacentTerritories[k]->getArmies() << endl;
                        adjacentTerr = true;
                    }
                }
            }
        }
        
        if (!adjacentTerr){
            cout << "Territory " << this->getTerritories()->at(i)->getName() << " does not have any adjacent territory owned by the player or has an army value of 1." << endl;
        }
        else {
           valid = true;
           validTerritories.insert(validTerritories.begin(), this->getTerritories()->at(i));
        }
        
        cout << endl;
        
    }
    
    if (!valid){
        cout << "Player has no territories that can fortify. Skipping fortification phase." << endl;
    }
    else {
        valid = false;
        cout << endl << "Please enter the name of the source territory." << endl;
    
        cin >> source;
    
        while (!valid){
            for (int i = 0; i < validTerritories.size(); i++) {
                if (validTerritories.at(i)->getName() == source){
                    valid = true;
                }
            }
            
            if (!valid){
                cout << "You did not enter a proper valid source territory. Please try again." << endl;
                cin >> source;
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
                    if (world->getTerritories()[j].adjacentTerritories[k]->getOwner() == this) {
                        cout << "Name: " << world->getTerritories()[j].adjacentTerritories[k]->getName() << " Armies: " << world->getTerritories()[j].adjacentTerritories[k]->getArmies() << endl;
                    }
                }
            }
        }
    
    
        cout << "Please enter the name the name of the target country." << endl;
        cin >> target;
    
    
    
        while (!valid){
        
            for (int i = 0; i < world->getTerritories()[sourceIndex].adjacentCount; i++){
                if (world->getTerritories()[sourceIndex].adjacentTerritories[i]->getName() == target && world->getTerritories()[sourceIndex].adjacentTerritories[i]->getOwner() == this){
                    targetIndex = i;
                    valid = true;
                    cout << "Valid target country." << endl;
                }
            
            }
        
            if (!valid){
                cout << "Target country entered is wrong, please try again." << endl;
                cin >> target;
            }
        
        }
    
        cout << "You chose: " << target << " as the target country, please enter the amount of armies you wish to send to " << target << "." << endl;
        cout << target << " currently has " << sourceArmies << ". Therefore, you can send between 1 and " << (sourceArmies - 1) << " armies." << endl; 
        cin >> xferArmies;
    
        while (xferArmies < 1 || xferArmies > (sourceArmies-1) ){
            cout << "You did not enter a correct amount of armies. Please try again." << endl;
            cin >> xferArmies;
        }
        cout << "Transferring " << xferArmies << " armies to the target country " << target << endl;
    
        world->getTerritories()[sourceIndex].territory->setArmies(world->getTerritories()[sourceIndex].territory->getArmies() - xferArmies);
        world->getTerritories()[sourceIndex].adjacentTerritories[targetIndex]->setArmies(world->getTerritories()[sourceIndex].adjacentTerritories[targetIndex]->getArmies() + xferArmies);

        cout << endl << "Printing out results to demonstrate proper transfer of armies." << endl;
    
        
        for (int i = 0; i < this->getTerritories()->size() ; i++){
            cout << "Name: " << this->getTerritories()->at(i)->getName() << " armies: " << this->getTerritories()->at(i)->getArmies() << endl;
        }
    
        cout << endl;
    
    }
    
}

