#include "checking_account.h"


CheckingAccount::CheckingAccount(std::string name, double balance): Account(std::move(name), balance) {}

CheckingAccount::~CheckingAccount() {
    std::cout << "CheckingAccount destructor" << std::endl;
}

void CheckingAccount::deposit(double amount) {
    Account::deposit(amount);
}

void CheckingAccount::withdraw(double amount) {
    Account::withdraw(amount + per_check_fee);
}

void CheckingAccount::print(std::ostream &os) const {
    os << "[Checking account: " << name << ": " << balance << "]";
}
