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

int numArmies(Player player);



int main(int argc, char** argv) {
    
    //Generating the world
    string mapName;
    cout << "Enter map name to generate the world." << endl;
    cin >> mapName;
    cout << "Generating world" << endl;
    Maploader* mapLoader = new Maploader(mapName);
    
    //Generating the deck
    cout << "Generating deck" << endl;
    Deck* deck = new Deck;//Creating deck
    
    //Generating Players
    cout << "Generating 2 players" << endl;
    vector<Territory*> territories1;
    vector<Territory*> territories2;
    Hand* hand1 = new Hand();
    Hand* hand2 = new Hand();
    Diepool* diepool1 = new Diepool();
    Diepool* diepool2 = new Diepool();
    Player* player1 = new Player(territories1, hand1, diepool1);
    Player* player2 = new Player(territories2, hand2, diepool2);
    
    
//    deck->shuffle();
//    Card card = deck->draw();
//    hand->insert(card);
//    card = deck->draw();
//    hand->insert(card);
//    card = deck->draw();
//    hand->insert(card);

    return 0;
}


int numArmies(Player player){
    
    int numCountries = player.getTerritories().size()/3;
    if (numCountries < 3){
        numCountries = 3;
    }
    
    return numCountries;
    
    
}