/* 
 * File:   Territory.cpp
 *  *** AUTHORS ***
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *	
 *** COMP 345 SECTION D ***
 * Assignment #
 * Professor: Dr. Joey Paquet
 *
 * Created on September 25, 2017, 3:20 PM
 */

#include "Territory.h"


Territory::Territory() : armies(0),
        owner("") {}

Territory::Territory(unsigned int arm, string own) : armies(arm),
        owner(own) {}

Territory::Territory(const Territory& orig) : armies(orig->getArmies()),
    owner(orig->getOwner()) {}

Territory::~Territory() {}

unsigned int Territory::getArmies() {return armies;}
string Territory::getOwner() {return owner;}
void Territory::setArmies(unsigned int arm) {armies = arm;}
void Territory::setOwner(string own) {owner = own;}
