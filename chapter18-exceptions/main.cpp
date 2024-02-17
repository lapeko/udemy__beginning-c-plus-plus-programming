#include <iostream>
#include "trust_account.h"
#include "exceptions/illegal_balance_exception.h"
#include "exceptions/insufficient_funds_exception.h"

using namespace std;

int main() {
    TrustAccount t;
    try {
        t.deposit(-10);
        cout << "Deposited" << endl;
    } catch (IllegalBalanceException& ex) {
        cout << "Error: " << ex.what() << ". Message: " << ex.get_message() << endl;
    }

    try {
        t.withdraw(100);
        cout << "Withdrawn" << endl;
    } catch(InsufficientFundsException& ex) {
        cout << "Error: " << ex.what() << endl;
    } catch(IllegalBalanceException& ex) {
        cout << "Error: " << ex.what() << ". Message: " << ex.get_message() << endl;
    }

    t.deposit(1000);

    t.withdraw(1);
    t.withdraw(1);
    t.withdraw(1);
    t.withdraw(1);

    try {
        t.withdraw(1);
    } catch(IllegalBalanceException& ex) {
        cout << "Error: " << ex.what() << ". Message: " << ex.get_message() << endl;
    }

    cout << t << endl;

    return 0;
}
