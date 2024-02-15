#include <iostream>
#include <vector>
#include "checking_account.h"
#include "account_util.h"

using namespace std;


int main() {
    cout.precision(2);
    cout << fixed;

    CheckingAccount ca{"Name", 300};
    ca.withdraw(299);
    cout << ca << endl;

    return 0;
}
