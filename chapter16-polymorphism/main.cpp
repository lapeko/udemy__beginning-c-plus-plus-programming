#include <iostream>
#include "saving_account.h"

int main() {
    SavingAccount sa {"a"};
    sa.deposit(100);
    sa.withdraw(50);
    std::cout << sa << std::endl;
}
