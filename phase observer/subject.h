/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   subject.h
 * Author: eagle
 *
 * Created on November 4, 2017, 1:27 AM
 */

#ifndef SUBJECT_H
#define SUBJECT_H
#pragma once
#include "Observer.h"
#include <list>
using namespace std;

class Subject {
  public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();
  private:
	list<Observer*> *_observers;
};



#endif /* SUBJECT_H */

