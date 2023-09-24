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
    
    int arr2 [][3] {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    const int outerArrSize = sizeof(arr2) / sizeof(arr2[0]);
    cout << "outer size: " << outerArrSize << endl;
    for (int i = 0; i < outerArrSize; i++) {
        for (int k = 0; k < 3; k++) {
            cout << arr2[i][k] << " ";
        }
        cout << endl;
    }
    
    return 0;
} 