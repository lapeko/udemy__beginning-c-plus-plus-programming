#include <iostream>

using namespace std;

int* applyAll(const int* arr1, int size1, const int* arr2, int size2 );
void printArr(const int* arr1, int size);

int main() {
    const int size1 = 5;
    const int arr1[size1] {1, 2, 3, 4, 5};
    const int size2 = 3;
    const int arr2[size2] {10, 20, 30};
    const int* result = applyAll(arr1, size1, arr2, size2);
    printArr(result, size1 * size2);

    delete[] result;
}

int* applyAll(const int* const arr1, int size1, const int* const arr2, int size2 ) {
    int* returnArr = new int[size1 * size2];

    for (int i = 0, index = 0; i < size2; i++)
        for (int j = 0; j < size1; j++)
            returnArr[index++] = arr1[j] * arr2[i];

    return returnArr;
};

void printArr(const int* const arr, int size) {
    for (int i = 0; i < size; i++)
        cout << "arr[" << i << "]: " << arr[i] << endl;
};
