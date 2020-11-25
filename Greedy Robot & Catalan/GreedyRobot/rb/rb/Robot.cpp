/*
 * Robot.cpp
 * Implementation of Robot.h, uses recursion to find path to the destination.
 * Program 2
 * October 26, 2020
 * Alex Lai
*/

#include "Robot.h"
#include "Point.h"
#include <vector>
#include <string>
using namespace std;
static vector<string> routes; //Possible routes that are valid are stored here.

Robot::Robot(Point start, Point end, int max_distance){
   startPoint = start;
   endPoint = end;
   maxSteps = max_distance;
   n_ = maxSteps;
   s_ = maxSteps;
   w_ = maxSteps;
   e_ = maxSteps;
   numPaths += goToPath(startPoint, "");
}

int Robot::goToPath(Point current, string path){
   if(current.getX() == endPoint.getX() && current.getY() == endPoint.getY()){
      routes.push_back(path);
      return 1;
   }
   int currSteps = 0;   
   if((endPoint.getY() > current.getY()) && n_ != 0){ //Move North
      n_--;
      s_ = maxSteps;
      w_ = maxSteps;
      e_ = maxSteps;
   currSteps += goToPath(Point(current.getX(), current.getY() + 1), path + "N"); //Point(current.getX(), current.getY() + 1)
}
   if(endPoint.getY() < current.getY() && s_ != 0){ //Move South
      s_--;
      n_ = maxSteps;
      w_ = maxSteps;
      e_ = maxSteps;
   currSteps += goToPath(Point(current.getX(), current.getY() - 1), path + "S");
}
   if(endPoint.getX() > current.getX() && e_ != 0){ //Move East
      e_--;
      s_ = maxSteps;
      w_ = maxSteps;
      n_ = maxSteps;
   currSteps += goToPath(Point(current.getX() + 1, current.getY()),path + "E");
}
   if(endPoint.getX() < current.getX() && w_ != 0){ //Move West
      w_--;
      s_ = maxSteps;
      n_ = maxSteps;
      e_ = maxSteps;
      currSteps += goToPath(Point(current.getX() - 1, current.getY()), path + "W");
}
   return currSteps;
}

std::ostream & operator<<(std::ostream & out_stream, Robot & r)
{
   if(r.numPaths == 0){
   cout << "No paths found..." << endl;
   }
   for(string r: routes){
   cout << r << endl;
   }
	out_stream << "Number of Paths: " << r.numPaths << endl;
	return out_stream;
}
