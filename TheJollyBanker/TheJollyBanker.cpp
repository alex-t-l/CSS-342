//
//  Driver method, that reads the file, processes the queue, and displays all the accounts in the tree.
//  TheJollyBanker
//
//  Created by Alex Lai on 11/21/20.
//

#include <iostream>
#include "Bank.h"
int main(){
    Bank banker;
    banker.ReadFile("BankTransIn.txt");
    banker.ProcessQueue();
    banker.Display();
}
