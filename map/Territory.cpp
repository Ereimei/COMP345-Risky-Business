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


Territory::Territory() : infantry(0),
        cavalry(0),
        artillery(0),
        owner("") {}

Territory::Territory(unsigned int inf, unsigned int cav, unsigned int art, string own) : infantry(inf),
        cavalry(cav),
        artillery(art),
        owner(own) {}

Territory::Territory(const Territory& orig) : infantry(orig->getInfantry()),
    cavalry(orig->getCavalry()),
    artillery(orig->getArtillery()),
    owner(orig->getOwner()) {}

Territory::~Territory() {}

unsigned int Territory::getInfantry() {return infantry;}
unsigned int Territory::getCavalry() {return cavalry;}
unsigned int Territory::getArtillery() {return artillery;}
string Territory::getOwner() {return owner;}
void Territory::setInfantry(unsigned int inf) {infantry = inf;}
void Territory::setCavalry(unsigned int cav) {cavalry = cav;}
void Territory::setArtillery(unsigned int art) {artillery = art;}
void Territory::setOwner(string own) {owner = own;}
