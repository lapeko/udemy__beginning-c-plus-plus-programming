#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
private:
    string name;
    int balance;
public:
    string get_name() {return name;};
    void set_name(string new_name) {name = new_name;}
    int get_balance();
    void set_balance(int new_balance);
    void withdraw(unsigned int amount);
    void deposit(unsigned int amount);
};

#endif
