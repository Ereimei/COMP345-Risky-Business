/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Subject.h"
#include "Observer.h"

Subject::Subject(){
	_observers = new list<Observer*>;
}
Subject::~Subject(){ 
	delete _observers;
}
void Subject::Attach(Observer* o){
  _observers->push_back(o);
};
void Subject::Detach(Observer* o){
  _observers->remove(o);
};
void Subject::Notify(){
  list<Observer *>::iterator i = _observers->begin();
  for (; i != _observers->end(); ++i)
	(*i)->Update(); 
};