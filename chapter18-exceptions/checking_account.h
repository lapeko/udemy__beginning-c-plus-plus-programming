#ifndef CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H
#define CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H

#include <string>
#include "account.h"


class CheckingAccount: public Account {
    static constexpr const char* def_name{"Unnamed checking account"};
    static constexpr const double def_balance{0.0};
    static constexpr const double per_check_fee{1.5};
protected:
    void print(std::ostream& os) const override;
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);
    ~CheckingAccount() override;
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};


#endif //CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H
