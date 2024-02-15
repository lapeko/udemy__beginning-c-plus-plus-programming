#include <iostream>
#include <vector>
#include "checking_account.h"
#include "account_util.h"

using namespace std;


int main() {
    cout.precision(2);
    cout << fixed;

    Account a{};
    a.deposit(100);
    a.withdraw(50);
    cout << a << endl;

    CheckingAccount ca{"Name", 300};
    ca.withdraw(299);
    cout << ca << endl;

    TrustAccount ta{"Name 2", 10000};
    ta.withdraw(2000);
    ta.withdraw(1000);
    ta.withdraw(2000);
    ta.withdraw(1000);
    ta.withdraw(1000);
    ta.withdraw(1000);
    ta.deposit(5000);
    cout << ta << endl;

    return 0;
}
