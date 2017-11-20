/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*

File: phaseObserver.cpp
 *** AUTHORS ***

Patrick Bednarski, 40002239
Hiu Tung Lam (Emily), 26311326
James Ferreira-Fernandez, 21964216
Olivier Trepanier-Desfosses, 27850956
 *** COMP 345 SECTION D ***

Assignment # 3
Professor: Dr. Joey Paquet
Created on November 7, 2017, 9:44 PM */

#include "phaseObserver.h"

#include <iostream>
#include <string> 

PhaseObserver::PhaseObserver(MainGame* mg, Startup* su){
    mainGame = mg;
    mg->attach(this);
    for(int i = 0; i< su->getSetOfPlayer().size() ; i++)
    su->getSetOfPlayer().at(i)->getStrategy()->attach(this);

};


void PhaseObserver::update(){

    cout << "///// Update: Player #" << mainGame->getCurrentPlayerNum() << ": " << mainGame->getCurrentphase() <<" /////"<< endl;
    cout << "///// " << mainGame->getCurrentPlayer()->getStrategy()->getCurrentAction() <<" /////"<< endl; 
  
    
}