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

#ifndef INTERFACES_H
#define INTERFACES_H

class Observer {
public:
    virtual ~Observer();
    virtual void update() = 0;
protected:
    Observer();
};

#include <list>

using std::list;

class Subject {
public:
    virtual void attach(Observer* o);
    virtual void detach(Observer* o);
    virtual void notify();
    Subject();
    virtual ~Subject();
private:
    list<Observer*>* observers;
};

#endif	// INTERFACES_H

