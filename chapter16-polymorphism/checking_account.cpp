#include "checking_account.h"


std::ostream& operator<<(std::ostream& os, const CheckingAccount& obj) {
    os << "[Checking account: " << obj.name << ": " << obj.balance << "]";
    return os;
}

CheckingAccount::CheckingAccount(std::string name, double balance): Account(std::move(name), balance) {}

bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount + per_check_fee);
}