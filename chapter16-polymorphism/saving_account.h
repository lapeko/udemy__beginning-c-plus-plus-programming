#ifndef CHAPTER15_INHERITANCE_SAVING_ACCOUNT_H
#define CHAPTER15_INHERITANCE_SAVING_ACCOUNT_H

#include <iostream>
#include "account.h"


class SavingAccount: public Account {
    static constexpr const char* def_name{"Unnamed saving account"};
    static constexpr const double def_balance{0.0};
    static constexpr const double def_int_rate{0.0};
protected:
    double int_rate;
    void print(std::ostream& os) override;
public:
    SavingAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};


#endif //CHAPTER15_INHERITANCE_SAVING_ACCOUNT_H
