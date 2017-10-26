#include <cstdlib>
#include <vector>
#include <string>
#include <map>

#include "../player/Player.h"
#include "../dice/Diepool.h"
#include "../cards/deck.h"
#include "../cards/hand.h"
#include "../cards/card.h"
#include "../map/map.h"
#include "../maploader/Maploader.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

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
    Player* player1 = new Player(territories1, hand1, diepool1, 1);
    Player* player2 = new Player(territories2, hand2, diepool2, 2);
    cout << "----------------------" << endl << endl;
    
    
    //Giving territories to players
    cout << "Distributing territories to players" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < world->getTerritoriesCount(); i++){
        //Giving first 5 territories to player 1
        if (i < 5){
            cout << "Giving " << world->getTerritories()[i].territory->getName() << " to player 1." << endl;
            player1->addTerritory(world->getTerritories()[i].territory);
            world->getTerritories()[i].territory->setArmies(5);
            
        }
        //Giving other territories to player 2
        else{
            cout << "Giving " << world->getTerritories()[i].territory->getName() << " to player 2." << endl;
            player2->addTerritory(world->getTerritories()[i].territory);
            world->getTerritories()[i].territory->setArmies(5);
        }
    }
    cout << "-----------------------------------" << endl;
    
    cout << endl << "Amount of territories owned by players" << endl;
    cout << "------------------------------------" << endl;
    cout << "Player1: " << player1->getTerritories()->size() << endl;
    cout << "Player2: " << player2->getTerritories()->size() << endl;
    cout << "------------------------------------" << endl << endl;
    
    
    


    return 0;
}



