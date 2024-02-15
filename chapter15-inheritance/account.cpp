#include <iostream>
#include <string>
#include "account.h"

using namespace std;

ostream& operator<<(ostream& os, const Account &obj) {
    os << "[Account: " << obj.name << ": " << obj.balance << "]";
    return os;
}

Account::Account(string name, double balance): name{std::move(name)}, balance{balance} {}

bool Account::deposit(double amount) {
    if (amount <= 0)
        return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance - amount < 0)
        return false;
    balance -= amount;
    return true;
}

double Account::get_balance(double amount) const {
    return balance;
}
