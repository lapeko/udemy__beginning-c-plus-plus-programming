#ifndef CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H
#define CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H

#include <string>
#include "account.h"


class CheckingAccount: public Account {
public:
    CheckingAccount(const std::string& name, double balance);
    bool withdraw(double amount);
};


#endif //CHAPTER15_INHERITANCE_CHECKING_ACCOUNT_H
