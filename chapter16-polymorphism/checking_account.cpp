#include "checking_account.h"


CheckingAccount::CheckingAccount(std::string name, double balance): Account(std::move(name), balance) {}

CheckingAccount::~CheckingAccount() {
    std::cout << "CheckingAccount destructor" << std::endl;
}

bool CheckingAccount::deposit(double amount) {
    return Account::deposit(amount);
}

bool CheckingAccount::withdraw(double amount) {
    return Account::withdraw(amount + per_check_fee);
}

void CheckingAccount::print(std::ostream &os) const {
    os << "[Checking account: " << name << ": " << balance << "]";
}
