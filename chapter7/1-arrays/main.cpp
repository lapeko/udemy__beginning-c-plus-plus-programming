#include <iostream>

using namespace std;

int main() {
    long double arr [5];
    cin >> arr[0];
    cout << "you added: " << arr[0] << endl;
//    cin >> arr[10];
//    cout << "you added: " << arr[10] << endl;
    cout << "array length: " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "size of the first arr element: " << sizeof(arr[0]) << endl;
    return 0;
} 