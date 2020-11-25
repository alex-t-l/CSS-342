/*
 * Catalan.cpp
 * Catalan number method which takes in one argument and calls a recursive function which computes the nth catalan number.
 * Program 2
 * October 24, 2020
 * Alex Lai
*/
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

bool check(string s);
int compute(int n);

//Main Method
int main(int argc, char* argv[]) {
    if(argc != 2)
        cout << "Error: Invalid number of arguments.";
    int input = atoi(argv[1]);
    if(input >= 0)
        cout << "The catalan Number of " << input << " is " << compute(input) << "." << endl;
    else
        cout << "Error: Catalan number cannot be smaller than zero.";

}

//Recursive calculation method to calculate the Catalan number.
int compute(int n){
int total = 0;
   if (n <= 1)
   return 1;

for(int i = 0; i < n; i++)
    total += compute(i) * compute (n-i-1);

    return total;
}


