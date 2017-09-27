/* 
 * File:   main.cpp
 * Author: Patrick Bednarski, 40002239
 * Emily Lam, 26311326
 * James Ferreira-Fernandez, 21964216
 * Olivier Trepanier-Desfosses, 27850956
 *
 * Created on September 19, 2017, 3:40 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "dice.h"

using std::cout;

 

/*
 * 
 */
int main(int argc, char** argv) {
    Diepool dice1;
    dice1.roll();
    dice1.roll();
    dice1.roll();
    dice1.roll();
    dice1.showPercentage();
    Diepool dice2;
    dice2.roll();
    dice2.roll();
    dice2.roll();
    dice2.showPercentage();
    
    return 0;
}

