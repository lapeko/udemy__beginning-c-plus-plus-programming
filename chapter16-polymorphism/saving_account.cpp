#include "saving_account.h"

using namespace std;


SavingAccount::SavingAccount(string name, double balance, double int_rate):
    Account{std::move(name), balance},
    int_rate{int_rate} {
}

bool SavingAccount::deposit(double amount) {
    amount += amount * int_rate / 100;
    return Account::deposit(amount);
}

bool SavingAccount::withdraw(double amount) {
    return Account::withdraw(amount);
}

void SavingAccount::print(ostream& os) {
    os << "[Saving account: " << name << ": " << balance << ", " << int_rate << "%]";
}


