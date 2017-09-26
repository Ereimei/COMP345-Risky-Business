/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: card.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment #
Professor: Dr. Joey Paquet
Created on September 24, 2017, 4:23 PM */

#ifndef CARD_H
#define CARD_H
#include <list>
#include <string>

std::list<std::string> countries[9] = {"Canada", "US", "China", "Brazil", "Mexico", "India", "Japan", "Germany", "France"};
std::list<std::string> cardTypes[3] = {"Infantry", "Artillery", "Cavalry"};
    
class Card{
        
private:
    char* country;
    char* type;
    
public:
    Card(std::string country, std::string cardType);    
    const std::string getCountry(){return country;}
    const std::string getType(){return type;}
    const std::list<std::string> getAllCountry(){return countries;}
    const std::list<std::string> getAllTypes(){return cardTypes;}
    
};

#endif /* CARD_H */
