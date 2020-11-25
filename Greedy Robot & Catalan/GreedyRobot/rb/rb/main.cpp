/*
 * GreedyRobot.cpp
 * Main method which checks if the user inputted the right amount of arguments.
 * November 2, 2020
 * Alex Lai
*/
#include "Robot.h"
#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    /*
   if(argc != 6){
      cout << "Invalid input, please enter five integers." << endl;
   }
   else if (atoi(argv[1]) == atoi(argv[3]) && atoi(argv[2])== atoi(argv[4])){
      cout << "It seems that your robot's starting point matches the endpoint.";
   }
   else{
     */
      Robot bot(Point(10, 10), Point(1, 1), 1);
      cout << bot << endl;
    }

    
