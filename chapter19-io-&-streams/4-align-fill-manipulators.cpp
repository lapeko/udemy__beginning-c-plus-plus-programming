#include <iostream>
#include <iomanip>

using namespace std;


int main() {
//    cout << setfill('*');
    cout << setw(10) << left << "Hello"
        << "|"
        << setw(10) << right << "world" << endl;
    return 0;
}