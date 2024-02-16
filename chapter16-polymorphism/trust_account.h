#ifndef CHAPTER15_INHERITANCE_TRUST_ACCOUNT_H
#define CHAPTER15_INHERITANCE_TRUST_ACCOUNT_H

#include <string>
#include "saving_account.h"


class TrustAccount: public SavingAccount {
    static constexpr const char* def_name{"Unnamed trust account"};
    static constexpr const double def_balance{0.0};
    static constexpr const double def_int_rate{0.0};
    static constexpr const double min_bonus_deposit{5000};
    static constexpr const double bonus{50};
    static constexpr const double max_withdraw_percent{20};
    unsigned int withdraw_available_amount{4};
protected:
    void print(std::ostream& os) override;
public:
    TrustAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};


#endif //CHAPTER15_INHERITANCE_TRUST_ACCOUNT_H
