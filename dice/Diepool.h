/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diepool.h
 * Author: James
 *
 * Created on September 25, 2017, 9:20 PM
 */

#ifndef DIEPOOL_H
#define DIEPOOL_H

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


#endif /* DICE_H */

