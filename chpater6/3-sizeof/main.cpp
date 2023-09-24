#include <iostream>
#include <climits>

using namespace std;

int main() {
    cout << "sizeof information" << endl;
    cout << "================================" << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "================================" << endl;
    cout << "size of short is: " << sizeof (short) << endl;
    cout << "size of integer is: " << sizeof (int) << endl;
    cout << "size of long is: " << sizeof (long) << endl;
    cout << "size of long long is: " << sizeof (long long) << endl;
    cout << "================================" << endl;
    cout << "decimal numbers" << endl;
    cout << "size of float is: " << sizeof (float) << endl;
    cout << "size of double is: " << sizeof (double) << endl;
    cout << "size of long double is: " << sizeof (long double) << endl;
    cout << "================================" << endl;
    cout << "minimum values:" << endl;
    cout << "char: " << CHAR_MIN << endl;
    cout << "int: " << INT_MIN << endl;
    cout << "long: " << LONG_MIN << endl;
    cout << "long long: " << LONG_LONG_MIN << endl;
    cout << "================================" << endl;
    cout << "maximum values:" << endl;
    cout << "char: " << CHAR_MAX << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "long: " << LONG_MAX << endl;
    cout << "long long: " << LONG_LONG_MAX << endl;

    return 0;
}