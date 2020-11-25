/*
 * Point.h
 * Represents a point.
 * Program 2
 * November 2, 2020
 * Alex Lai
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Point {
public:
    Point();
    Point(int x, int y);
    int getX() const;
    int getY() const;

private:
    int x_ = 0;
    int y_ = 0;
};