#include "Account.h"

void Account::set_balance(int new_balance) {balance = new_balance;}
int Account::get_balance() {return balance;}
void Account::deposit(unsigned int amount) {balance += amount;}
void Account::withdraw(unsigned int amount) {balance -= amount;}