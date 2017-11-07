/* 
 * File:   Statistics.h
 * Patrick Bednarski, 40002239
 * Hiu Tung Lam (Emily), 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 * 
 *** COMP 345 SECTION D ***
 * Assignment #3
 * Professor: Dr. Joey Paquet
 *
 * Created on November 6, 2017, 11:13 PM
 */

#include "interfaces.h"

Observer::Observer() {}
Observer::~Observer() {}

Subject::Subject() {
    observers = new list<Observer*>;
}

Subject::~Subject() {
    delete observers;
}

void Subject::attach(Observer* o) {
    observers->push_back(o);
}

void Subject::detach(Observer* o) {
    observers->remove(o);
}

void Subject::notify() {
    for (list<Observer*>::iterator i = observers->begin(); i != observers->end(); ++i) {
        (*i)->update();
    }
}
