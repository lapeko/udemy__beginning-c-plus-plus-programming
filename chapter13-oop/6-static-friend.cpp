#include <iostream>

using namespace std;

class User;

class UserPrinter {
public:
    static void print(User &user);
};

class User {
public:
    User(string name, int age, int xp): name{std::move(name)}, age{age}, xp{xp} {
        activeUsers++;
    }
    ~User() {
        activeUsers--;
    }
    friend void UserPrinter::print(User &user);
    static void printActiveUsers() {
        cout << "Active users: " << activeUsers << endl;
    }
private:
    static int activeUsers;
    string name;
    int age;
    int xp;
};
int User::activeUsers {0};

void UserPrinter::print(User &user) {
    cout << "[User] Name: " << user.name << ", Age: " << user.age << ", Xp: " << user.xp << endl;
}

int main() {
    {
        User user{"Igor", 4, 123};
        User user_grodno{"Marina", 38, 95};
        UserPrinter::print(user);
        User::printActiveUsers();
    }
    User::printActiveUsers();
    return 0;
}