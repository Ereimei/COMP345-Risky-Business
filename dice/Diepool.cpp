/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Diepool.h"

using std::cout;

   Diepool::Diepool(){
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
        num5 = 0;
        num6 = 0;
        numt = 0;
        dice[0] = 1;
        dice[1] = 1;
        dice[2] = 1;
    }
    
    void Diepool::roll(){
        srand((int)time(NULL));
        int numDice = 0;
        std::cout << "Enter number of dice to be used(1,2 or 3)" << std::endl;
        std::cin >> numDice;
       
        while(numDice < 1 || numDice > 3){
            std::cout << "Incorrect value. Please enter a 1,2 or 3." << std::endl;
            std::cin >> numDice;
        }
        for(int i = 0; i <= numDice - 1; i++){
            this->dice[i] = (rand() % 6) + 1;
            std::cout << "you rolled a " << dice[i] << std::endl;

            this->numt++;
            switch(dice[i]){
                case 1: 
                    this->num1++;
                    break;
                case 2:
                    this->num2++;
                    break;
                case 3:
                    this->num3++;
                    break;
                case 4:
                    this->num4++;
                    break;
                case 5:
                    this->num5++;
                    break;
                case 6:
                    this->num6++;
                    break;
            } //end of switch case
        }//end of for loop 
    }//end of function
    
    void Diepool::showPercentage(){
        std::cout << "You have rolled 1 " << (100 * this->num1 / this->numt) << " % of the time" << std::endl;
        std::cout << "You have rolled 2 " << (100 * this->num2 / this->numt) << " % of the time" << std::endl;
        std::cout << "You have rolled 3 " << (100 * this->num3 / this->numt) << " % of the time" << std::endl;
        std::cout << "You have rolled 4 " << (100 * this->num4 / this->numt) << " % of the time" << std::endl;
        std::cout << "You have rolled 5 " << (100 * this->num5 / this->numt) << " % of the time" << std::endl;
        std::cout << "You have rolled 6 " << (100 * this->num6 / this->numt) << " % of the time" << std::endl;
    }