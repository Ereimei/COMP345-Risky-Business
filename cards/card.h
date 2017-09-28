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
#include <vector>
#include <string>
    

class Card{
        
public:
    //static const std::vector<std::string> COUNTRIES;
    //static const std::vector<std::string> CARD_TYPES;
    
private:
    
    std::string m_Country;
    std::string m_Type;
    
public:
    Card(std::string country, std::string type) : m_Country(country), m_Type(type) { }  
    const std::string getCountry(){return m_Country;}
    const std::string getType(){return m_Type;}
    
};

#endif /* CARD_H */
