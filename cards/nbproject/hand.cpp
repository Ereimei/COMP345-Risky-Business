/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "hand.h"
#include "deck.h"
#include "card.h"

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

int Hand::exchange(){
    
    int army = 4;
    int counterType[3];
    for(int i = 0; i < sizeof(counterType); i++)
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
            that country get two extra armies
        }*/
    }   
    if(counterType[0]==3 || counterType[1]==3 || counterType[2]==3 )
    {
        counterArmy ++;
    }else
    if(counterType[0]>= 1 && counterType[1]>=1 && counterType[2]>=1)
    {
        counterArmy ++;
    }
    
    if(counterArmy == 1)
    {
        return army;
    }else
    if(counterArmy<=5)
    {
        army+=2;
        return army;
    }else
    if(counterArmy==6)
    {
        army+=3;
        return army;
    }else{
        army+=5;
        return army;
    }
    
    
}