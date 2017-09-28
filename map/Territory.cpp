/* 
 * File:   Territory.cpp
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #1
 * Professor: Dr. Joey Paquet
 *
 * Created on September 25, 2017, 3:20 PM
 */

#include "Territory.h"

unsigned int Territory::objectCount = 1;

Territory::Territory(string n) : armies(0),
    owner(""),
    name(n),
    id(objectCount++) {}

Territory::~Territory() {}

unsigned int Territory::getArmies() const {return armies;}
string Territory::getOwner() const {return owner;}
string Territory::getName() const {return name;}
void Territory::setArmies(unsigned int arm) {armies = arm;}
void Territory::setOwner(string own) {owner = own;}
unsigned int Territory::getId() {return id;}
