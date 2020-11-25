/*
 * TimeSpan.cpp
 * TimeSpan class that represents a duration of time in hours, minutes, and seconds.
 * Program 1
 * October 15, 2020
 * Alex Lai
*/

#include "TimeSpan.h"
#include <math.h>
#include <iostream>
using namespace std;

    //Constructors
    TimeSpan::TimeSpan(){ //default constructor
        this -> hour_ = 0;
        this -> min_ = 0;
        this -> sec_ = 0;
    }

    TimeSpan::TimeSpan(double s){ //one param constructor
        set(0, 0, s);
    }

    TimeSpan::TimeSpan(double m, double s){ //two param constructor
        set(0, m, s);
    }

    TimeSpan::TimeSpan(double h, double m, double s){ //three param constructor
        set(h, m, s);
    }

    void TimeSpan::set(double hours, double minutes, double seconds) { //Helper method that takes in doubles to set time as int.
        seconds = round(seconds);
        double totalSeconds = (hours * 3600) + (minutes * 60) + (seconds);
        this->hour_ = (int) totalSeconds / 3600;
        this->min_ = ((int) totalSeconds % 3600) / 60;
        this->sec_ = (((int) totalSeconds % 3600) % 60);
    }

    //Getters and Setters
    int TimeSpan::getHours() const {
        return hour_;
    }

    int TimeSpan::getMinutes() const {
        return min_;
    }

    int TimeSpan::getSeconds() const {
        return sec_;
    }

    bool TimeSpan::setTime(int hours, int minutes, int seconds) { //Changes the timeSpan to a new time.
       set(hours, minutes, seconds);
        return true;
    }

    //Operator Declarations
    ostream& operator<<(ostream& out_stream, const TimeSpan& right_hand_side) {
        cout << "Hours: " << right_hand_side.getHours() << ", Minutes: " << right_hand_side.getMinutes() << ", Seconds: " << right_hand_side.getSeconds();
        return out_stream;
    }

    istream& operator>>(istream& in_stream, TimeSpan& right_hand_side) {
        cin >> right_hand_side.hour_;
        cin >> right_hand_side.min_;
        cin >> right_hand_side.sec_;
        return in_stream;
    }

    TimeSpan TimeSpan::operator+(const TimeSpan &right_hand_side) const{
        TimeSpan total = * this;
        total += right_hand_side;
        return total;
    }

    TimeSpan TimeSpan::operator-(const TimeSpan &right_hand_side) const{
        TimeSpan total = *this;
        total -= right_hand_side;
        return total;
    };

    TimeSpan TimeSpan::operator+=(const TimeSpan &right_hand_side){
        int hours = this -> getHours() + right_hand_side.getHours();
        int minutes = this -> getMinutes() + right_hand_side.getMinutes();
        int seconds = this -> getSeconds() + right_hand_side.getSeconds();
        this -> setTime(hours ,minutes, seconds);
        return *this;
    }

    TimeSpan TimeSpan::operator-=(const TimeSpan &right_hand_side){
         int hours = this -> getHours() - right_hand_side.getHours();
         int minutes = this -> getMinutes() - right_hand_side.getMinutes();
         int seconds = this -> getSeconds() - right_hand_side.getSeconds();
         this -> setTime(hours ,minutes, seconds);
         return *this;
    }

    bool TimeSpan::operator==(const TimeSpan &right_hand_side){
        if(hour_ != right_hand_side.getHours()) return false;
        else if (min_ != right_hand_side.getMinutes()) return false;
        else if (sec_ != right_hand_side.getSeconds()) return false;
        else return true;
    }

    bool TimeSpan::operator!=(const TimeSpan &right_hand_side){
        if(hour_ != right_hand_side.getHours()) return true;
        else if (min_ != right_hand_side.getMinutes()) return true;
        else if (sec_ != right_hand_side.getSeconds()) return true;
        else return false;
    }

    TimeSpan TimeSpan::operator-(){ //Unary negation - turn negative to positive, positive to negative
        hour_ *= -1;
        min_ *= -1;
        sec_ *= -1;
        return *this;
    };


