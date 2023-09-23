#include <iostream>

using namespace std;

int main() {
    // characters
    char letter {'a'};
    cout << "letter is: " << letter << endl;
    
    // numbers
    short shortNumber {123};
    cout << "short number: " << shortNumber << endl;
    
    int intNumber {45};
    cout << "int number: " << intNumber << endl;
    
    long unsigned longNumber {1234567890}; // try this {1'234'567'890'123};
    cout << "long number: " << longNumber << endl;
    
    long long longLongNumber {1'234'567'890'123};
    cout << "long long number: " << longLongNumber << endl;
    
    // decimal numbers
    float floatNumber {123.456};
    cout << "float number: " << floatNumber << endl;
    
    double pi {3.14159};
    cout << "PI is " << pi << endl;
    
    long double longDoubleNumber {2.7e120};
    cout << "lng double number: " << longDoubleNumber << endl;
    
    bool gameOver = false;
    cout << "boolean value: " << gameOver << endl;
}