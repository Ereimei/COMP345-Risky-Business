/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "deck.h"
#include "card.h"

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

#include <cmath>
#include <algorithm>

/*
void Deck::shuffle()
{
    // Get the maximum amount of each card type available
    int typesRemaining[Card::CARD_TYPES.size()];
    for (int i = 0; i < sizeof(typesRemaining)/sizeof(int); i++ )
    {
        typesRemaining[i] = ceil((double)Card::COUNTRIES.size() / Card::CARD_TYPES.size());
    }
    
    // Copy the list of countries into another list to modify
    std::vector<std::string> countries(Card::COUNTRIES.begin(), Card::COUNTRIES.end());
    
    for (int n = 0; n < Card::COUNTRIES.size(); n++ )
    {
        int randomCountryIndex = rand() % countries.size();
        std::string randomCountry = countries.at(randomCountryIndex);
        countries.erase(countries.begin() + randomCountryIndex - 1);
        
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
*/