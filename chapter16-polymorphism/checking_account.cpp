#include "checking_account.h"


CheckingAccount::CheckingAccount(std::string name, double balance): Account(std::move(name), balance) {}

bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount + per_check_fee);
}

void CheckingAccount::print(std::ostream &os) {
    os << "[Checking account: " << name << ": " << balance << "]";
}
