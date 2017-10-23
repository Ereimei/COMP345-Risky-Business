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

#include <iostream>
using std::cout;

int Hand::counterArmy = 1;

void Hand::insert(Card card)
{
    playerHand.insert(playerHand.begin(), card);
}

void Hand::display()
{
    for(int i = 0; i < playerHand.size(); i++){
        cout << "Country: " << playerHand[i].getCountry() << ", Type: " << playerHand[i].getType() << std::endl;
    }
}

int Hand::countType(std::string type)
{
    int counter = 0;
    for(int k = 0; k < playerHand.size(); k++)
    {
        if(playerHand[k].getType() == type){
            counter ++;
        }
    }
    return counter;
}

void Hand::removeThree(std::string type)
{
    int counter = 0;
    int index[3];
    for(int k = 0; k < playerHand.size(); k++)
    {
        if(playerHand[k].getType() == type){
            index[counter] = k;
            counter ++;
        }
        if(counter == 3)
        {
            for(int m = 0; m < 3; m ++)
            {
            playerHand.erase(playerHand.begin()+index[m]-m);
            }
            return;
        }
    }
    
}

void Hand::removeEach()
{
    bool type1 = false;
    bool type2 = false;
    bool type3 = false;
    int index[3];
    int counter = 0;
    
    for(int k = 0; k < playerHand.size(); k++)
    {
        if(playerHand[k].getType() == "Infantry" && type1 == false){
            index[counter] = k;
            counter++;
            type1 = true;
        }
        if(playerHand[k].getType() == "Artillery" && type2 == false){
            index[counter] = k;
            counter++;
            type2 = true;
        }
        if(playerHand[k].getType() == "Cavalry" && type3 == false){
            index[counter] = k;
            counter++;
            type3 = true;
        }
        if(type1 == true && type2 == true && type3 == true)
        {
            for(int m = 0; m < 3; m ++)
            {
            playerHand.erase(playerHand.begin()+index[m]-m);
            }
            return;
        }
    }
}

int Hand::getArmy(){
    return army;
}

int Hand::exchangeArmy()
{
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

int Hand::exchange(){
    
    int countInfantry = countType("Infantry");
    int countArtillery = countType("Artillery");
    int countCavalry = countType("Cavalry");
    bool exchanged = false;
    
    if(countInfantry >= 3 ){
        removeThree("Infantry");
        exchanged = true;
    }else
        if(countArtillery >= 3){
           removeThree("Artillery");
           exchanged = true;
        }else
            if(countCavalry >= 3){
                removeThree("Cavalry");
                exchanged = true;
            }else
                if(countInfantry >= 1 && countArtillery >= 1 && countCavalry >= 1){
                    removeEach();
                    exchanged = true;
                }
    
    if (exchanged == true){
        return exchangeArmy();
    }else{
        return 0;
    }
}

std::vector<Card> Hand::getCards(){
    return this->playerHand;
}