#include <iostream>
#include "account_util.h"

using namespace std;


void display(const vector<Account*>& accounts) {
    cout << "\n========================= Accounts =============================" << endl;
    for (auto account : accounts)
        cout << *account << endl;
};
void deposit(const vector<Account*>& accounts, double amount) {
    cout << "\n========================= Depositing to accounts =============================" << endl;
    for (auto account : accounts)
        cout << (account->deposit(amount) ? "Deposited " : "Failed deposit of ") << amount << " to " << *account << endl;
};
void withdraw(const vector<Account*>& accounts, double amount) {
    cout << "\n========================= Withdrawing from accounts =============================" << endl;
    for (auto account : accounts)
        cout << (account->withdraw(amount) ? "Withdrew " : "Failed withdrawal of ") << amount << " to " << *account << endl;
};