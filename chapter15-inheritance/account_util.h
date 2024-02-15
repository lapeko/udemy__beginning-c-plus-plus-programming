#ifndef CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
#define CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H

#include <vector>
#include "account.h"
#include "saving_account.h"

using namespace std;


void display(const vector<Account>& accounts);
void deposit(vector<Account>& accounts, double amount);
void withdraw(vector<Account>& accounts, double amount);

void display(const vector<SavingAccount>& accounts);
void deposit(vector<SavingAccount>& accounts, double amount);
void withdraw(vector<SavingAccount>& accounts, double amount);


#endif //CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
