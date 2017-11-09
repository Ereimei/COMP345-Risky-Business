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

unsigned int Player::objectCount = 0;
        
//Constructor
Player::Player(vector<Territory*>* territories, Hand* hand, Diepool* diepool) : territories(territories),
    hand(hand),
    diepool(diepool),
    playerNum(objectCount++){}

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
/*
 *Function which will control reinforcement phase for player objects
 */
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
                        /*
                         * Observer notify that player is reinforcing
                         */
                        currentAction = "Player is reinforcing "+ to_string(reinAmount) +" armies to "+territory;
                        notify();
                    }   
                }
            }

        }
    
}



/*
 * attack command for players
 * enables player to attack another player, if possible
 * 
 * 
 */
void Player::attack(World* world, vector<Player*> players){
    
    string answer;
    cout << "Do you want to attack? (y/n)" << endl;
    cin >> answer;
    
    //loop to ensure answer is in proper format
    
    while (answer != "y" && answer != "n"){
        cout << "Please answer in proper format (y/n)" << endl;
        cin >> answer;
    }
    
    //variables needed to check if player can attack
    bool canAtk = false;
    int atkTerr = 0;
    
    //loops to increment the atkTerr counter, which regulates amount of territories that can attack
    
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
        //Territories that can be attacked will be listed under owned territories
        
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
        
        //user enter who they wish to attack with
        
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
        
        //user enters which territory they wish to attack
        
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
            cin >> atkDie;
            while(atkDie != 1 && atkDie != 2 && atkDie != 3 || atkDie > atkMax){
                cout << "I have no time for your games champion, enter an appropriate number (min 1, max " << atkMax << " )" << endl;
                cin >> atkDie;    
            }
        
            
            //asks defender how many dice they wish to roll with
            //checks that it is valid
            
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
            
            //rolls and sorts attackers dice
            
            this->getDiepool()->roll(atkDie);
            this->getDiepool()->sortDice(atkDie);
        
            Player* defendingPlayer = (world->getTerritories()[atkPos].adjacentTerritories[defPos]->getOwner());
        
            // rolls and sorts defenders dice
            
            defendingPlayer->getDiepool()->roll(defDie);
            defendingPlayer->getDiepool()->sortDice(defDie);
            
            currentAction = "Attacker rolled " + to_string(getDiepool()->getDie1()) + " Defender rolled " + to_string(defendingPlayer->getDiepool()->getDie1());
            notify();
            
            //compares the dice rolls and distributes damage appropriately
            
            if (this->getDiepool()->getDie1()> defendingPlayer->getDiepool()->getDie1()){
                int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                /*
                 * Observer update
                 */
                currentAction = "Attack wins";
                notify();
            }
            else{
                int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                world->getTerritories()[atkPos].territory->setArmies(n);
                /*
                 * Observer update
                 */
                currentAction = "defender wins";
                notify();
            }
            
            if(defDie == 2 && atkDie >= 2){
                cout << "Attacker rolled " << getDiepool()->getDie2() << " Defender rolled " << defendingPlayer->getDiepool()->getDie2() << endl;
                
                if (this->getDiepool()->getDie2()> defendingPlayer->getDiepool()->getDie2()){
                    int n = world->getTerritories()[atkPos].adjacentTerritories[defPos]->getArmies() - 1;
                    world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(n);
                    /*
                     * Observer update
                     */
                    currentAction = "Attack wins";
                    notify();
                }
                else{
                    int n = world->getTerritories()[atkPos].territory->getArmies() - 1;
                    world->getTerritories()[atkPos].territory->setArmies(n);
                     /*
                     * Observer update
                     */
                    currentAction = "defender wins";
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
                cin >> transfer;
                while(transfer > transMax || transfer < 1 ){
                    cout << "please enter a number in the proper range champion" << endl;
                    cout << " min = 1, max = " << transMax << endl;
                    cin >> transfer;
                }
                
                //performs the transfer
                
                world->getTerritories()[atkPos].adjacentTerritories[defPos]->setArmies(transfer);
                this->addTerritory(world->getTerritories()[atkPos].adjacentTerritories[defPos]);
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
                for (int i = 0; i < this->territories->size(); i++){
                    cout << this->territories->at(i)->getName()<< endl;
                }
                cout << "Defender your territories are now " << endl;
                cout << "----------------" << endl;
                for (int i = 0; i < defendingPlayer->territories->size(); i++){
                    cout << defendingPlayer->territories->at(i)->getName()<< endl;
                }   
            }
            
            //if attacker can no longer attack, decrement the counter
            
            if (world->getTerritories()[atkPos].territory->getArmies() == 1){
                atkTerr -= 1;
            }
                
            //if the current atk and def setup is no longer valid, end the current setup loop
            
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
        
        //ask user if they want to keep attacking
        
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

/*
 *Function that will handle fortification phase of player objects
 */
void Player::fortify(World* world){ 
    
    string source, target, choice;
    int xferArmies, sourceArmies, sourceIndex, targetIndex;
    bool valid = false, adjacentTerr;
    vector <Territory*> validTerritories;
    
    
    cout << "Do you want to fortify? (y/n)" << endl;
    cin >> choice;
    
    while(choice != "y" && choice !="n"){
        cout << "Give me a valid input, peasant." << endl;
        cin >> choice;
    }
    if (choice == "y"){
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
}

int Player::numArmies(World* world) {
    int numCountries, numContinents, numTerrInCont, numReinf;
    bool ownsTerr = false, ownsCont;
    string exchangeCards;
    //Checking the amount of territories the player owns
    numCountries = this->getTerritories()->size();
    cout << endl << "Territory Army Bonus" << endl;
    cout << "--------------------" << endl;
    numReinf = numCountries/3;
    if (numCountries < 3){
        numCountries = 3;
    }
    cout << "Total amount of territory owned: " << numCountries << endl;
    cout << "Army value (territories/3 floored): " << numReinf << endl << endl;

    
    //Checking if a player owns an entire continent, for every continent
    numContinents = world->getContinentsCount();
    cout << "Continent Army Bonus" << endl;
    cout << "------------------" << endl;
    for (int i = 0; i < numContinents; i++){
        //Assume player owns the continent
        ownsCont = true;
        ownsTerr = false;
        numTerrInCont = world->getContinents()[i]->getTerritoriesCount();
        
        //Checking for every territory in the continent if the player has control over it
        
        for (int j = 0; j < numTerrInCont; j++){
            for (int k = 0; k < numCountries; k++){
                if (world->getContinents()[i]->getTerritories()[j]->getName() == this->getTerritories()->at(k)->getName()){
                    ownsTerr = true;
                    break;
                }
            }
            //If player doesn't own a territory in a continent, he doesn't own the continent
            if (!ownsTerr){
                ownsCont = false;
                //Skipping other territory checking
                break;
            }
        }
        
        //If player owns the continent
        if (ownsCont){
            cout << "Player owns continent: " << world->getContinents()[i]->getName() << " adding army bonus of " << world->getContinents()[i]->getArmyBonus() << endl;
            numReinf += world->getContinents()[i]->getArmyBonus();
            cout << "Reinforcements amount = " << numReinf << endl << endl;
        }
        else {
            cout << "Player does not own continent: " << world->getContinents()[i]->getName() << endl ;
        }

    }
    
    //Display player's hand
    cout << endl << "Player's hand" << endl;
    cout << "--------------" << endl;
    this->getHand()->display();
    cout << endl;
    //If player has enough cards to exchange but not more than 5 cards, give them the choice to exchange
    if (2 < this->getHand()->getCards().size() && this->getHand()->getCards().size() < 6) {
        cout << "Do you want to try to exchange your cards for additional reinforcements? (y/n)" << endl;
        cin >> exchangeCards;
        //Make sure they properly input y or n
        while (exchangeCards != "y" && exchangeCards != "n"){
            cout << "You did not properly enter y or n as an answer, please try again." << endl;
            cin >> exchangeCards;
        }
        
        if (exchangeCards == "y"){
            cout << "Trying to exchange cards for " << this->getHand()->getArmy() << " reinforcement." << endl;
            numReinf += this->getHand()->exchange();
            cout << "Reinforcements amount = " << numReinf << endl;
        }
        else {
            cout << "Player does not want to exchange cards for reinforcement" << endl;
        }
    }
    //If player has less than 3 cards
    else if (this->getHand()->getCards().size() < 3){
        cout << "Player does not have enough cards to increase reinforcements." << endl;
    }
    //If player has over 5 cards, they must exchange cards
    else {
        cout << "Player has more than 5 cards, forcing them to exchange them for " << this->getHand()->getArmy() << " reinforcements." << endl;
        numReinf += this->getHand()->exchange();
        cout << "Reinforcements amount = " << numReinf << endl;
    }
    cout << "--------------" << endl << endl;

    
    return numReinf; 
}