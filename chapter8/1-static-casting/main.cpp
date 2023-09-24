#include <iostream>

using namespace std;

int main() {
    cout << "Calculate average programm" << endl;
    
    int number1 {0};
    cout << "Enter number 1" << endl;
    cin >> number1;
    
    int number2 {0};
    cout << "Enter number 2" << endl;
    cin >> number2;
    
    int number3 {0};
    cout << "Enter number 3" << endl;
    cin >> number3;
    
    cout << "The average value is: " << (static_cast<double>(number1) + number2 + number3) / 3 << endl;
    
    return 0;
}