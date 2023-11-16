#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    Account acc;
    acc.set_name("Vasya");
    acc.set_balance(123);
    acc.withdraw(100);
    acc.deposit(200);
    cout << "Your balance is " << acc.get_balance() << " now." << endl;
    return 0;
}