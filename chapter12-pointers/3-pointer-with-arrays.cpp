#include <iostream>

using namespace std;

int main() {
    int arr[] {1, 2, 3, 4};
    int* arrPtr {arr};

    cout << "arr value: " << arr << endl;
    cout << "arrPtr value: " << arrPtr << endl;
    cout << "arr == arrPtr: " << boolalpha << (arr == arrPtr) << endl;

    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;
    cout << "arr[3]: " << arr[3] << endl;

    cout << "arrPtr[0]: " << arrPtr[0] << endl;
    cout << "arrPtr[1]: " << arrPtr[1] << endl;
    cout << "arrPtr[2]: " << arrPtr[2] << endl;
    cout << "arrPtr[3]: " << arrPtr[3] << endl;

    cout << "*(arr): " << *(arr) << endl;
    cout << "*(arr + 1): " << *(arr + 1) << endl;
    cout << "*(arr + 2): " << *(arr + 2) << endl;
    cout << "*(arr + 3): " << *(arr + 3) << endl;

    cout << "*(arrPtr): " << *(arrPtr) << endl;
    cout << "*(arrPtr + 1): " << *(arrPtr + 1) << endl;
    cout << "*(arrPtr + 2): " << *(arrPtr + 2) << endl;
    cout << "*(arrPtr + 3): " << *(arrPtr + 3) << endl;

    return 0;
}