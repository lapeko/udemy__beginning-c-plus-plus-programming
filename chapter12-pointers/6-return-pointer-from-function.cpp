#include <iostream>

using namespace std;

int* createArray(int size, int initValue);
void displayArray(const int* array, int size);

int main() {
    const int size = 4;
    const int* arrPtr = createArray(size, 5);
    displayArray(arrPtr, size);
    delete[] arrPtr;
}

int* createArray(int size, int initValue = 0) {
    int* array = new int[size];
    for (int i = size; i != 0; i--) array[i - 1] = initValue;
    return array;
};

void displayArray(const int* const array, int size) {
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "]: " << array[i] << endl;
};