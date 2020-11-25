/*
 * TimeMachine.cpp
 * The TimeMachine class contains the main method that tests every method in the TimeSpan class.
 * Program 1
 * October 15, 2020
 * Alex Lai
*/

#include "TimeSpan.h"
#include <iostream>
using namespace std;

int main() {
    //TESTING OUT CONSTRUCTORS
    cout << "Testing out Constructors:" << endl;
    TimeSpan no_time;
    cout << no_time << endl;
    TimeSpan one_param(30);
    cout << one_param << endl;
    TimeSpan two_param(12.5, 30);
    cout << two_param << endl;
    TimeSpan three_param(15, 2.5, 30);
    cout << three_param << endl;
    TimeSpan weird_decimal(127.86);
    cout << weird_decimal << endl;
    weird_decimal.setTime(-5, -5, -.5);
    cout << weird_decimal << endl;
    TimeSpan thirteen_thirty = two_param + one_param;
    cout << thirteen_thirty << endl;
    cout << thirteen_thirty.getHours() << endl;
    cout << thirteen_thirty.getMinutes() << endl;
    cout << thirteen_thirty.getSeconds() << endl;
    one_param.setTime(1, 2, 69);
    cout << one_param << endl;

    TimeSpan test (1, 0 ,0);
    TimeSpan add_one(1, 1, 1);

    //TESTING OVERLOADED OPERARATOR METHODS

    cout << "Before adding: " << test << endl;
    //Testing '+'
    cout << "After adding with '+' : " << test + add_one << endl;
    //Testing '+='
    test += add_one;
    cout << "After adding with '+=' : " << test << endl;
    //Testing '-'
    test - add_one;
    cout << "After subtracting with '-' : " << test - add_one << endl;
    //Testing '-='
    test -= add_one;
    cout << "After subtracting with '-=' : " << test << endl;
    //Testing '==' & '!='
    if(test == add_one)
        cout << "Should not output this" << endl;
    else
        cout << "Should output this because they're not equal" << endl;

    if(test != add_one)
        cout << "Should output this since they're not equal" << endl;
    else
        cout << "Should not output this" << endl;

    //Testing Unary Negation
    TimeSpan time (1, 2, 3);
    cout << "Before unary negation: " << time << endl;
    cout << "After unary negation: " << -time << endl;

    return 0;
}
