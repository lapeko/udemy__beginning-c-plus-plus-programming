#include <vector>
#include "saving_account.h"
#include "trust_account.h"
#include "account_util.h"

using namespace std;

int main() {
    vector<Account*> vec;
    Account* sa1 = new SavingAccount();
    Account* sa2 = new SavingAccount("Saving name", 2000);
    Account* ta1 = new TrustAccount();
    Account* ca1 = new CheckingAccount();

    vec.push_back(sa1);
    vec.push_back(sa2);
    vec.push_back(ta1);
    vec.push_back(ca1);

    display(vec);

    delete sa1;
    delete sa2;
    delete ta1;
    delete ca1;
}
