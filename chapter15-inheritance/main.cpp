#include <iostream>
#include <vector>
#include "account.h"
#include "saving_account.h"
#include "account_util.h"

using namespace std;


int main() {
    cout.precision(2);
    cout << fixed;

    vector<Account> accounts;
    accounts.emplace_back();
    accounts.emplace_back("Larry");
    accounts.emplace_back("Moe", 2000);
    accounts.emplace_back("Curly", 5000);

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    vector<SavingAccount> saving_accounts;
    saving_accounts.emplace_back();
    saving_accounts.emplace_back("Superman");
    saving_accounts.emplace_back("Batman", 2000);
    saving_accounts.emplace_back("Wonderwoman", 5000, 5.0);

    display(saving_accounts);
    deposit(saving_accounts, 1000);
    withdraw(saving_accounts, 2000);

    return 0;
}
