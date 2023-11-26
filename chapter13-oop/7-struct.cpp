#include <iostream>
using namespace std;

struct User {
    string name;
    int age;
    void print_name() const {
        cout << "[User] Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    User user{"Andrew", 223};
    user.print_name();
    return 0;
}
