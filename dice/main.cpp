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
using std::cout;

class Diepool{
    private:
        //dice array, set of 3 dice
        int dice[3];
        //counters for each number value, and total dice rolls
        int num1, num2, num3, num4, num5, num6, numt;
    
    public:
        int getNum1(){return num1;}
        int getNum2(){return num2;}
        int getNum3(){return num3;}
        int getNum4(){return num4;}
        int getNum5(){return num5;}
        int getNum6(){return num6;}
        int getNumt(){return numt;}
        int getDie1(){return dice[0];}
        int getDie2(){return dice[1];}
        int getDie3(){return dice[2];}
        void setDie1(int d6){dice[0] = d6;}
        void setDie2(int d6){dice[1] = d6;}
        void setDie3(int d6){dice[2] = d6;}
        void roll();
        void showPercentage();
        Diepool();
};
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
        int numDice = 0;
        std::cout << "Enter number of dice to be used(1,2 or 3)" << std::endl;
        std::cin >> numDice;
        srand((int)time(NULL));
       
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

