#include <iostream>
#include "saving_account.h"
#include "trust_account.h"

using namespace std;

int main() {
    SavingAccount sa {"a"};
    TrustAccount ta {"b"};

    sa.deposit(100);
    sa.withdraw(50);
    cout << sa << endl;
    cout << ta << endl;
}
