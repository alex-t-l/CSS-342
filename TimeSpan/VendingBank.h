/*
 * VendingBank.h
 * Interface which models the coin-operated bank part of a vending machine which sells snacks.
 * Program 1
 * October 15, 2020
 * Alex Lai
*/
#pragma once
#include <string>
using namespace std;

class VendingBank {
public:
    //Constructors
    VendingBank();
    VendingBank(int id);
    VendingBank(int id, int pennies, int nickels, int dimes, int quarters, int dollars);
    VendingBank(int id, int amount);

    ~VendingBank();

    int getVendingBankID() const;

    //Getters and Setters
    int getPennies() const;
    int getNickels() const;
    int getDimes() const;
    int getQuarters() const;
    int getDollars() const;
    int getId();
    void setPennies(const int &num);
    void setNickels(const int &num);
    void setDimes(const int &num);
    void setQuarters(const int &num);
    void setDollars(const int &num);
    void setId(const int &id);

    //Operator Overloads
    VendingBank operator+(const VendingBank &) const;
    VendingBank operator+=(const VendingBank &);
    VendingBank operator-(const VendingBank &) const;
    VendingBank operator-=(const VendingBank &);
    bool operator==(const VendingBank &) const;
    bool operator!=(const VendingBank &) const;


    //Actions
    void Deposit(double amount);
    void Withdraw(double amount);
    bool CheckCoins();


    //Private Variables
    private:
    int pennies_;
    int nickels_;
    int dimes_;
    int quarters_;
    int dollars_;
    int id_;
    double giveChange(double amount);
};
