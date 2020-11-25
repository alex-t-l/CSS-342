/*
 * Robot.h
 * Finds the shortest path given the start and end point and max movement restriction.
 * October 26, 2020
 * Alex Lai
*/

#define ROBOT_H_
#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

class Robot{
public:
   Robot(Point start, Point end, int max_distance);
   friend std::ostream & operator<<(std::ostream & out_stream, Robot & r);
   int findRoutes(Point endPoint);
   int goToPath(Point current, string path);
   //~Robot();

private:
    int maxSteps; 
    int numPaths; 
    int n_, s_, w_, e_; //These variables track the maxSteps as a counter.
    Point startPoint, endPoint;
};



