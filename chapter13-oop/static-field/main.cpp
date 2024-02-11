#include <iostream>
#include "user.h"

int main() {
    User user1{"Andrew"};
    User* user2 = new User{"Anna"};

    User::show_counter();

    {
        User user3{"Andrew"};
        user3.show_counter();
    }

    User::show_counter();

    delete user2;

    User::show_counter();

    return 0;
};
