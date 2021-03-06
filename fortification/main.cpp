/* 
 * File:   main.cpp
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #2
 * Professor: Dr. Joey Paquet
 *
 * Created on October 20, 2017, 3:40 PM
 */

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
    
    //Generating the world
    cout << "Generating Antarctica world" << endl;
    Maploader* mapLoader = new Maploader("Antarctica.map");
    World* world = mapLoader->getWorld();
    
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
        else if (i >= 5 && i < 12) {
            cout << "Giving " << world->getTerritories()[i].territory->getName() << " to player 2." << endl;
            player2->addTerritory(world->getTerritories()[i].territory);
        }
    }
    cout << "-----------------------------------" << endl;
    
    //Giving armies to every territory
    cout << "Giving every territory a random amount of armies." << endl;
    for (int i = 0; i < world->getTerritoriesCount(); i++){
        world->getTerritories()[i].territory->setArmies(3);
    }
    
    
    cout << "Fortification phase" << endl;
    cout << "-------------------" << endl;
    cout << "Player 1 fortification phase";
    player1->fortify(world);
    
    cout << "Player 2 fortification phase";
    player2->fortify(world);
    cout << "-------------------" << endl << endl;
    cout << "Player 2 fortification phase";
    player2->fortify(world);
    cout << "-------------------" << endl << endl;
    
    cout << "Fortification completed for both players!" << endl;

    return 0;
}