#include <iostream>

using namespace std;

int main() {
    int arr [] {5, 4, 2};
    int* arrPtr {arr};

    for (int i = 0; i < 3; i++)
        cout << *arrPtr++ << endl;

    cout << "==================================================" << endl;

    char name[] {"Vitali"};
    char* firstLetterPtr {&name[0]};
    char* fourthLetterPtr {&name[3]};

    cout << "firstLetterPtr: " << firstLetterPtr << ", fourthLetterPtr: " << fourthLetterPtr << endl;
    cout << "fourthLetterPtr - firstLetterPtr: " << fourthLetterPtr - firstLetterPtr << endl;

    cout << "==================================================" << endl;

    int anotherArr[] {2, 5, 6, 3};
    int* firstNumPtr {&anotherArr[0]};
    int* fourthNumPtr {&anotherArr[3]};

    cout << "firstNumPtr: " << firstNumPtr << ", fourthNumPtr: " << fourthNumPtr << endl;
    cout << "fourthNumPtr - firstNumPtr: " << fourthNumPtr - firstNumPtr << endl;
}