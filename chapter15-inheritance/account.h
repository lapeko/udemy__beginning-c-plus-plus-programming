#ifndef CHAPTER15_INHERITANCE_ACCOUNT_H
#define CHAPTER15_INHERITANCE_ACCOUNT_H

#include <iostream>
#include <string>


class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& obj);
    static constexpr const char* def_name = "Unnamed account";
    static constexpr const double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance(double amount) const;
};


#endif //CHAPTER15_INHERITANCE_ACCOUNT_H
