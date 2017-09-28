/* 
 * File:   Territory.h
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

#ifndef TERRITORY_H
#define TERRITORY_H

#include <string>
#include <iostream>

using std::string;
using std::cout;

class Territory {
public:
    Territory(const Territory& orig);
    Territory(string n);
    virtual ~Territory();
    unsigned int getArmies() const;
    string getOwner() const;
    string getName() const;
    void setArmies(unsigned int arm);
    void setOwner(string own);
    unsigned int getId();
private:
    static unsigned int objectCount;
    unsigned int armies, id;
    string owner;
    const string name;
};

#endif /* TERRITORY_H */

