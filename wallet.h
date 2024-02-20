/*************************************************************
* 1. Name:
*-your name -
*2. Module
* WALLET
* 3. Assignment Description :
*A class to represent an wallet with multiple credit cards
* *************************************************************/
#pragma once
#include <cassert>
#include <iostream>
using namespace std;
class TestWallet;
class Wallet
{
    friend TestWallet;
public:
    //Constructor
    Wallet() {
        accountSam = 0.0;
        accountSue = 0.0;
        pCurrentAccount = &accountSam;
    }
    //Methods
    void updateSam(double cashChange) {
        accountSam = accountSam + cashChange;
    }
    void updateSue(double cashChange) {
        accountSue = accountSue + cashChange;
    }
    void updateCurrent(double amount) {
        if (pCurrentAccount == &accountSam) 
        {
            updateSam(amount);
        }
        else if (pCurrentAccount == &accountSue)
        {
            updateSue(amount);
        }
    }
    void chooseSam() {
        pCurrentAccount = &accountSam;
    }
    void chooseSue() {
        // Assign a pointer
        pCurrentAccount = &accountSue;
    };
    void chooseCurrent() {
        if (accountSam > accountSue) {
            chooseSam();
        }
        else if (accountSam < accountSue) {
            chooseSue();
        }
    }
    double getSam() {
        return accountSam;
    }
    double getSue() {
        return accountSue;
    }
    double getCurrent() {
        return *pCurrentAccount;
    }
private:
    double accountSam;
    double accountSue;
    double* pCurrentAccount;
};












