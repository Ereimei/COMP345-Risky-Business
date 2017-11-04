/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   observer.h
 * Author: eagle
 *
 * Created on November 4, 2017, 1:27 AM
 */

#ifndef OBSERVER_H
#define OBSERVER_H
#pragma once


class Observer {
public:
    ~Observer();
    virtual void Update() = 0;
protected:
    Observer();

};

#endif /* OBSERVER_H */

