#include <iostream>

using namespace std;

int* createArray(int size, int initValue);

int main() {
    const int size = 4;
    const int* arr = createArray(size, 5);
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "]: " << arr[i] << endl;
}

int* createArray(int size, int initValue = 0) {
    int* array = new int[size];
    for (int i = size; i != 0; i--) array[i - 1] = initValue;
    return array;
};
