#include <string>
#include "account.h"
#include "exceptions/illegal_balance_exception.h"
#include "exceptions/insufficient_funds_exception.h"

using namespace std;


Account::Account(string name, double balance): name{std::move(name)}, balance{balance} {}

void Account::deposit(double amount) {
    if (amount <= 0)
        throw IllegalBalanceException("Not positive amount");
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0)
        throw IllegalBalanceException("Not positive amount");
    if (balance - amount < 0)
        throw InsufficientFundsException();
    balance -= amount;
}

double Account::get_balance() const {
    return balance;
}
