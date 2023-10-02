#include <iostream>

using namespace std;

int main() {
    int size {};
    int* arrPointer {nullptr};

    cout << "Input size of the array: " << endl;
    cin >> size;

    arrPointer = new int [size];

    for (int i = 0; i < size; i++) {
        cout << "Enter a value for element: " << i << endl;
        int newNum {};
        cin >> newNum;
        arrPointer[i] = newNum;
    }

    cout << "Your array is:" << endl;

    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]" << ": " << arrPointer[i] << endl;
    }

    return 0;
}
