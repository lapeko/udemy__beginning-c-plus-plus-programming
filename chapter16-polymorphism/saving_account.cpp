#include "saving_account.h"

using namespace std;

ostream &operator<<(ostream& os, const SavingAccount& obj) {
    os << "[Saving account: " << obj.name << ": " << obj.balance << ", " << obj.int_rate << "%]";
    return os;
}

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
