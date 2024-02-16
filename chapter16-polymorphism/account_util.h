#ifndef CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
#define CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H

#include <vector>
#include "checking_account.h"
#include "trust_account.h"

using namespace std;


void display(const vector<IPrintable*>& accounts);
void deposit(vector<Account*>& accounts, double amount);
void withdraw(vector<Account*>& accounts, double amount);


#endif //CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
