#ifndef CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
#define CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H

#include <vector>
#include "checking_account.h"
#include "trust_account.h"

using namespace std;


void display(const vector<Account>& accounts);
void deposit(vector<Account>& accounts, double amount);
void withdraw(vector<Account>& accounts, double amount);

void display(const vector<SavingAccount>& accounts);
void deposit(vector<SavingAccount>& accounts, double amount);
void withdraw(vector<SavingAccount>& accounts, double amount);

void display(const vector<CheckingAccount>& accounts);
void deposit(vector<CheckingAccount>& accounts, double amount);
void withdraw(vector<CheckingAccount>& accounts, double amount);

void display(const vector<TrustAccount>& accounts);
void deposit(vector<TrustAccount>& accounts, double amount);
void withdraw(vector<TrustAccount>& accounts, double amount);


#endif //CHAPTER15_INHERITANCE_ACCOUNT_UTIL_H
