/*
 * TimeSpan.h
 * TimeSpan interface.
 * Program 1
 * October 15, 2020
 * Alex Lai
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class TimeSpan {

public:
    //Constructors
    TimeSpan();

    TimeSpan(double hours, double minutes, double seconds);

    TimeSpan(double minutes, double seconds);

    TimeSpan(double seconds);

    //Getters & Setters
    int getHours() const;

    int getMinutes() const;

    int getSeconds() const;

    bool setTime(int hours, int minutes, int seconds);

    //Operator Overload
    friend ostream& operator << (ostream &out_stream, const TimeSpan& time);

    friend istream& operator >> (istream& in_stream, TimeSpan& time);

    TimeSpan operator+(const TimeSpan &right_hand_side) const;

    TimeSpan operator-(const TimeSpan &right_hand_side) const;

    TimeSpan operator+=(const TimeSpan &right_hand_side);

    TimeSpan operator-=(const TimeSpan &right_hand_side);

    bool operator==(const TimeSpan &right_hand_side);

    bool operator!=(const TimeSpan &right_hand_side);

    TimeSpan operator-();


private:
    //Private Variables
    int hour_, min_, sec_;
    void set(double hours, double minutes, double seconds);
};