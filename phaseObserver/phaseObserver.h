/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: phaseObserver.h
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 3
Professor: Dr. Joey Paquet
Created on November 7, 2017, 9:43 PM */


#ifndef PHASEOBSERVER_H
#define PHASEOBSERVER_H

#include "../interfaces/interfaces.h"
#include "../mainGame/mainGame.h"
#include <iostream>
#include <string>




using namespace std;

class PhaseObserver: public Observer{
    
private:
    MainGame* mainGame;
public:
    
    void update();
    
};


#endif /* PHASEOBSERVER_H */

