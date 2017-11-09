/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: deck.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 1
Professor: Dr. Joey Paquet
Created on September 24, 2017, 3:48 PM */
#include "deck.h"
#include "card.h"

#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>


using std::cout;
using namespace std;

void Deck::shuffle(World* world)
{
    
    vector<string> vTerritoryName;
    for(int e = 0; e < world->getTerritoriesCount(); e++){
        vTerritoryName.push_back(world->getTerritories()[e].territory->getName());
    }
    
    // Get the maximum amount of each card type available
    int typesRemaining[Card::CARD_TYPES.size()];
    for (int i = 0; i < Card::CARD_TYPES.size(); i++ )
    {
        typesRemaining[i] = (vTerritoryName.size() / Card::CARD_TYPES.size());
    }
    //Assign the maximum amount of cards each type can have 
    if(typesRemaining[0] * Card::CARD_TYPES.size() != Card::COUNTRIES.size())
    {
        int mod = (vTerritoryName.size()% Card::CARD_TYPES.size());
        for(int x = 0; x < mod ; x++)
        {
            typesRemaining[x]++;
        }
    }
    
    // Copy the list of countries into another list to modify
    std::vector<std::string> countries(vTerritoryName.begin(), vTerritoryName.end());
    
    for (int n = 0; n < vTerritoryName.size(); n++ )
    {
        int randomCountryIndex = rand() % countries.size();
        std::string randomCountry = countries.at(randomCountryIndex);
        countries.erase(countries.begin() + randomCountryIndex);
        
        int randomTypeIndex = rand() % Card::CARD_TYPES.size();
        while(typesRemaining[randomTypeIndex] == 0){
            randomTypeIndex = (randomTypeIndex + 1) % Card::CARD_TYPES.size();
        }
        
        std::string randomType = Card::CARD_TYPES.at(randomTypeIndex);
        typesRemaining[randomTypeIndex] -= 1; 
        
        
        deck.push_back(Card(randomCountry, randomType));
    }
}

Card Deck::draw()
{
    Card drawnCard = deck.back();
    deck.pop_back();
    return drawnCard;
}

void Deck::display()
{
    for(int i = 0; i < deck.size(); i++){
        cout << "Country: " << deck[i].getCountry() << ", Type: " << deck[i].getType() << std::endl;
    }
}