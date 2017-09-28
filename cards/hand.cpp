/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hand.h"
#include "card.h"
#include "deck.h"

/*

File: hand.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 1
Professor: Dr. Joey Paquet
Created on September 25, 2017, 9:49 PM */

/*
int Hand::counterArmy = 0;

int Hand::exchange(){
    
    std::string ownedCountry = "";
    int army = 4;
    int counterType[Card::CARD_TYPES.size()];
    for(int i = 0; i < sizeof(counterType)/sizeof(int); i++)
    {
        counterType[i] = 0;
    }
    
    for(int n = 0; n < sizeof(playerHand); n++)
    {
        if(playerHand[n].getType() == "Infantry")
        {
            counterType[0]++;
        }
        if(playerHand[n].getType() == "Artillery")
        {
            counterType[1]++;
        }
        if(playerHand[n].getType() == "Cavalry")
        {
            counterType[2]++;
        }
        /*if(playerHand[n].getCountry == "owned country")
        {
         ownedCountry == "owned country"
        }*//*
    }   
    if(counterType[0]==3 || counterType[1]==3 || counterType[2]==3 )
    {
        counterArmy ++;
    }else
    if(counterType[0]>= 1 && counterType[1]>=1 && counterType[2]>=1)
    {
        counterArmy ++;
    }
    

     if(ownedCountry != ""){
         //add two armies to country
    }

    
    if(counterArmy == 1)
    {
        counterArmy ++;
        return army;
    }else
    if(counterArmy<=5)
    {
        counterArmy ++;
        army+=2;
        return army;
    }else
    if(counterArmy==6)
    {
        counterArmy ++;
        army+=3;
        return army;
    }else{
        counterArmy ++;
        army+=5;
        return army;
    }
    
    
}
*/