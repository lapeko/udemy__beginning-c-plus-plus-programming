#include <string>
#include <utility>
#include "trust_account.h"
#include "exceptions/illegal_balance_exception.h"

using namespace std;


TrustAccount::TrustAccount(string name, const double balance, const double int_rate)
    : SavingAccount(std::move(name), balance, int_rate) {
}

TrustAccount::~TrustAccount() {
    std::cout << "TrustAccount destructor" << std::endl;
}

void TrustAccount::deposit(const double amount) {
    SavingAccount::deposit(amount < min_bonus_deposit ? amount : amount + bonus);
}

void TrustAccount::withdraw(const double amount) {
    if (withdraw_available_amount <= 0)
        throw IllegalBalanceException("Forbidden. Maximum amount of withdrawals achieved");
    if (amount / balance * 100 > max_withdraw_percent)
        throw IllegalBalanceException("Forbidden. Max percentage of withdrawal is 20%");
    withdraw_available_amount--;
    SavingAccount::withdraw(amount);
}

void TrustAccount::print(ostream &os) const {
    os << "[Trust account: " << name << ": " << balance << ", " << int_rate << "%]";
}
