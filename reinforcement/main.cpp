#include <cstdlib>
#include <vector>
#include <string>

#include "../player/Player.h"
#include "../cards/deck.h"
#include "../cards/hand.h"
#include "../cards/card.h"
#include "../map/map.h"
#include "../maploader/Maploader.h"

using namespace std;

int numArmies(Player* player, World* world);



int main(int argc, char** argv) {
    int reinforcement;
    
    //Generating the world
    cout << "Generating Antarctica world" << endl;
    Maploader* mapLoader = new Maploader("Antarctica.map");
    World* world = mapLoader->getWorld();
    
    //Generating the deck
    cout << "Generating deck" << endl;
    Deck* deck = new Deck;//Creating deck
    deck->shuffle();
    
    //Generating players
    cout << "Generating 2 players" << endl;
    vector<Territory*>* territories1 = new vector<Territory*>;
    vector<Territory*>* territories2 = new vector<Territory*>;
    Hand* hand1 = new Hand();
    Hand* hand2 = new Hand();
    Diepool* diepool1 = new Diepool();
    Diepool* diepool2 = new Diepool();
    Player* player1 = new Player(territories1, hand1, diepool1);
    Player* player2 = new Player(territories2, hand2, diepool2);
    cout << "----------------------" << endl << endl;
    
    
    //Giving territories to players
    cout << "Distributing territories to players" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < world->getTerritoriesCount(); i++){
        //Giving first 5 territories to player 1
        if (i < 5){
            cout << "Giving " << world->getTerritories()[i].territory->getName() << " to player 1." << endl;
            player1->addTerritory(world->getTerritories()[i].territory);
        }
        //Giving other territories to player 2
        else{
            cout << "Giving " << world->getTerritories()[i].territory->getName() << " to player 2." << endl;
            player2->addTerritory(world->getTerritories()[i].territory);
        }
    }
    cout << "-----------------------------------" << endl;
    

    
    cout << endl << "Amount of territories owned by players" << endl;
    cout << "------------------------------------" << endl;
    cout << "Player1: " << player1->getTerritories()->size() << endl;
    cout << "Player2: " << player2->getTerritories()->size() << endl;
    cout << "------------------------------------" << endl << endl;
    
    //Making players 1 draw 6 cards
    cout << "Players draw cards" << endl;
    cout << "------------------" << endl;
    cout << "Player 1 draws 6 cards" << endl;
    Card card = deck->draw();
    player1->getHand()->insert(card);
    card = deck->draw();
    player1->getHand()->insert(card);
    card = deck->draw();
    player1->getHand()->insert(card);
    card = deck->draw();
    player1->getHand()->insert(card);
    card = deck->draw();
    player1->getHand()->insert(card);
    card = deck->draw();
    player1->getHand()->insert(card);
    
    //Making player 2 draw 3 cards
    cout << "Player 2 draws 3 cards" << endl;
    player2->getHand()->insert(card);
    card = deck->draw();
    player2->getHand()->insert(card);
    card = deck->draw();
    player2->getHand()->insert(card);
    cout << "------------------" << endl << endl;
    
    
    cout << "Reinforcement phase" << endl;
    cout << "-------------------" << endl;
    cout << "Player 1 reinforcement phase" << endl;
    reinforcement = numArmies(player1, world);
    player1->reinforce(reinforcement);
    
    cout << "Player 2 reinforcement phase" << endl;
    reinforcement = numArmies(player2, world);
    player2->reinforce(reinforcement);
    cout << "-------------------" << endl << endl;
    
    cout << "Reinforcement completed for both players!" << endl;

    return 0;
}


int numArmies(Player* player, World* world) {
    int numCountries, numContinents, numTerrInCont, numReinf;
    bool ownsTerr = false, ownsCont;
    string exchangeCards;
    //Checking the amount of territories the player owns
    numCountries = player->getTerritories()->size();
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
                if (world->getContinents()[i]->getTerritories()[j]->getName() == player->getTerritories()->at(k)->getName()){
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
    player->getHand()->display();
    cout << endl;
    //If player has enough cards to exchange but not more than 5 cards, give them the choice to exchange
    if (2 < player->getHand()->getCards().size() && player->getHand()->getCards().size() < 6) {
        cout << "Do you want to try to exchange your cards for additional reinforcements? (y/n)" << endl;
        cin >> exchangeCards;
        //Make sure they properly input y or n
        while (exchangeCards != "y" && exchangeCards != "n"){
            cout << "You did not properly enter y or n as an answer, please try again." << endl;
            cin >> exchangeCards;
        }
        
        if (exchangeCards == "y"){
            cout << "Trying to exchange cards for " << player->getHand()->getArmy() << " reinforcement." << endl;
            numReinf += player->getHand()->exchange();
            cout << "Reinforcements amount = " << numReinf << endl;
        }
        else {
            cout << "Player does not want to exchange cards for reinforcement" << endl;
        }
    }
    //If player has less than 3 cards
    else if (player->getHand()->getCards().size() < 3){
        cout << "Player does not have enough cards to increase reinforcements." << endl;
    }
    //If player has over 5 cards, they must exchange cards
    else {
        cout << "Player has more than 5 cards, forcing them to exchange them for " << player->getHand()->getArmy() << " reinforcements." << endl;
        numReinf += player->getHand()->exchange();
        cout << "Reinforcements amount = " << numReinf << endl;
    }
    cout << "--------------" << endl << endl;

    
    return numReinf; 
}