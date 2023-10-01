#include <iostream>

using namespace std;

void printLine();

int main() {
    int integer {100};
    int integer2 {1};
    double decimal {1.23};

    int *integerPointer {&integer};

    cout << "integerPointer link: " << integerPointer << endl;
    cout << "integerPointer size: " << sizeof integerPointer << endl;
    cout << "integerPointer value: " << *integerPointer << endl;
    printLine();

    integerPointer = &integer2;
    cout << "integerPointer updated" << endl;
    cout << "integerPointer link: " << integerPointer << endl;
    cout << "integerPointer value: " << *integerPointer << endl;
    printLine();

    integerPointer = nullptr;
    integerPointer = &integer2;
    cout << "integerPointer was reset" << endl;
    cout << "integerPointer link: " << integerPointer << endl;
    cout << "integerPointer value: " << *integerPointer << endl;
    printLine();

    double *decimalPointer {&decimal};

    cout << "decimalPointer size:" << sizeof decimalPointer << endl;
    cout << "decimalPointer link:" << decimalPointer << endl;
    cout << "decimalPointer value:" << *decimalPointer << endl;
    decimalPointer = nullptr;
    printLine();

    cout << "decimalPointer was reset" << endl;
    cout << "decimalPointer size:" << sizeof decimalPointer << endl;
    cout << "decimalPointer link:" << decimalPointer << endl;

    return 0;
}

void printLine() {
    cout << "========================================" << endl;
};