#include <iostream>
#include <iomanip>

using namespace std;


void show_doubles();

int main() {
    show_doubles();

    cout << setprecision(2);
    show_doubles();

    cout << setprecision(5);
    show_doubles();

    cout << setprecision(10);
    show_doubles();

    cout << setprecision(2) << fixed;
    show_doubles();

    cout << setprecision(5) << scientific << uppercase << showpos;
    show_doubles();

    cout.unsetf(ios::scientific | ios::fixed);
    cout << resetiosflags(ios::showpos);

    cout << setprecision(12) << showpoint;
    show_doubles();

    cout.unsetf(ios::scientific | ios::fixed);
    cout << setprecision(6);
    cout << resetiosflags(ios::showpos);
    cout << resetiosflags(ios::showpoint);
    show_doubles();

    return 0;
}

void show_doubles() {
    double long_d = {1234567890.12345667890};
    double middle_d = {1234.5678};
    double short_d = {1234.0};

    cout << long_d << endl;
    cout << middle_d << endl;
    cout << short_d << endl;
    cout << "===========" << endl;
};