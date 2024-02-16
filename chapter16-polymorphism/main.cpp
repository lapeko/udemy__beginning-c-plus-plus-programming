#include <iostream>
#include <vector>
#include "saving_account.h"
#include "trust_account.h"
#include "account_util.h"

using namespace std;

int main() {
    vector<Account*> vec;
    auto sa1 = new SavingAccount();
    auto sa2 = new SavingAccount("Saving name", 2000);
    auto ta1 = new TrustAccount();
    auto ca1 = new CheckingAccount();

    vec.push_back(sa1);
    vec.push_back(sa2);
    vec.push_back(ta1);
    vec.push_back(ca1);

    display(vec);
}
