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
using namespace std;

class Card{
        
public:
    static const vector<string> COUNTRIES;
    static const vector<string> CARD_TYPES;
    
private:
    
    string m_Country;
    string m_Type;
    
public:
    Card(string country, string type) : m_Country(country), m_Type(type) { }  
    const string getCountry(){return m_Country;}
    const string getType(){return m_Type;}
    
    
};

#endif /* CARD_H */
