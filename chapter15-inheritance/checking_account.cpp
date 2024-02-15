#include "checking_account.h"
#include "account.h"


CheckingAccount::CheckingAccount(const std::string& name, double balance): Account(name, balance) {};

bool CheckingAccount::withdraw(double amount) {
    const double fee = 1.5;
    if (balance - amount - fee < 0)
        return false;
    balance -= amount + fee;
    return true;
}