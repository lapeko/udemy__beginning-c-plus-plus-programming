#include <iostream>
#include "account_util.h"
#include "account.h"
#include "saving_account.h"

using namespace std;


void display(const vector<Account>& accounts) {
    cout << "\n========================= Accounts =============================" << endl;
    for (const Account& account : accounts)
        cout << account << endl;
};
void deposit(vector<Account>& accounts, double amount) {
    cout << "\n========================= Depositing to accounts =============================" << endl;
    for (Account& account : accounts)
        cout << (account.deposit(amount) ? "Deposited " : "Failed deposit of ") << amount << " to " << account << endl;
};
void withdraw(vector<Account>& accounts, double amount) {
    cout << "\n========================= Withdrawing from accounts =============================" << endl;
    for (Account& account : accounts)
        cout << (account.withdraw(amount) ? "Withdrew " : "Failed withdrawal of ") << amount << " to " << account << endl;
};

void display(const vector<SavingAccount>& accounts) {
    cout << "\n========================= Saving accounts =============================" << endl;
    for (const SavingAccount& account : accounts)
        cout << account << endl;
};
void deposit(vector<SavingAccount>& accounts, double amount) {
    cout << "\n========================= Depositing to saving accounts =============================" << endl;
    for (SavingAccount& account : accounts)
        cout << (account.deposit(amount) ? "Deposited " : "Failed deposit of ") << amount << " to " << account << endl;
};
void withdraw(vector<SavingAccount>& accounts, double amount) {
    cout << "\n========================= Withdrawing from saving accounts =============================" << endl;
    for (SavingAccount& account : accounts)
        cout << (account.withdraw(amount) ? "Withdrew " : "Failed withdrawal of ") << amount << " to " << account << endl;
};
