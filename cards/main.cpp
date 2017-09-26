/* 
 * File:   main.cpp
 * Author: Patrick Bednarski
 *
 * Created on September 19, 2017, 3:40 PM
 */

#include <cstdlib>
#include <iostream>

using std::cout;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int test[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* pointer = test;
    for (int i = 0; i < sizeof(test)/sizeof(int); i++)
    {
        cout << pointer[i];
    }
    cout << std::endl;
    
    cout << "Here Emily, that's your workstation.";
    return 0;
}

