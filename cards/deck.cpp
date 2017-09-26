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

#include <list>

void Deck::shuffle()
{
    int typesRemaining[sizeof(cardTypes)];
    
    for (int i = 0; i < sizeof(typesRemaining); i++ )
    {
        typesRemaining[i] = ceil(sizeof(countries) / sizeof(cardTypes));
    }
    
    std::list<std::string> listCountry = getAllCountry();
    int typePosition;
    std::string randomCountry;
    std::string randomType;
    
    for (int n = 0; n < sizeof(countries); n++ )
    {
        randomCountry = std[rand()/sizeof(countries)];
        listCountry.remove(randomCountry);
        
        typePosition = rand()/sizeof(cardTypes);
        while(typesRemaining[typePosition] == 0){
            typePosition++;
        }
        
        randomType = cardTypes[typePosition];
        typesRemaining[typePosition] -= 1; 
        
        deck[n] = Card(randomCountry, randomType);
    }
}



Card Deck::draw()
{
    Card drawnCard = deck.back();
    deck.pop_back();
    return drawnCard;
}