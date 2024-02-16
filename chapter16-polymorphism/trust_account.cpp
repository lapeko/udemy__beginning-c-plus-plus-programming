#include <string>
#include <utility>
#include "trust_account.h"

using namespace std;


TrustAccount::TrustAccount(string name, const double balance, const double int_rate)
    : SavingAccount(std::move(name), balance, int_rate) {
}

bool TrustAccount::deposit(const double amount) {
    return SavingAccount::deposit(amount < min_bonus_deposit ? amount : amount + bonus);
}

bool TrustAccount::withdraw(const double amount) {
    if (withdraw_available_amount <= 0) {
        cout << "Forbidden. Maximum amount of withdrawals achieved" << endl;
        return false;
    }
    if (amount / balance * 100 > max_withdraw_percent) {
        cout << "Forbidden. Max percentage of withdrawal is 20%" << endl;
        return false;
    }
    withdraw_available_amount--;
    return SavingAccount::withdraw(amount);
}

void TrustAccount::print(ostream &os) {
    os << "[Trust account: " << name << ": " << balance << ", " << int_rate << "%]";
}
