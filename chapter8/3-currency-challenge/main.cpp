#include <iostream>

using namespace std;

int main() {
    cout << "Enter an amount in cents: ";
    int whole_part {0} ;
    int cents_ammount {0};
    cin >> cents_ammount;
    
    cout << endl << "You can provide this change as follows:" << endl;
    
    whole_part = cents_ammount / 100;
    cents_ammount -= whole_part * 100;
    cout << "dollars\t\t: " << whole_part << endl;
    
    whole_part = cents_ammount / 25;
    cents_ammount -= whole_part * 25;
    cout << "quarters\t: " << whole_part << endl;
    
    whole_part = cents_ammount / 10;
    cents_ammount -= whole_part * 10;
    cout << "dimes\t\t: " << whole_part << endl;
    
    whole_part = cents_ammount / 5;
    cents_ammount -= whole_part * 5;
    cout << "nickels\t\t: " << whole_part << endl;
    
    cout << "pennies\t\t: " << cents_ammount << endl;
    
    return 0;
}