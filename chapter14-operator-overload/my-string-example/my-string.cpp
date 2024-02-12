#include <iostream>
#include "my-string.h"
#include "cstring"

using namespace std;

MyString::MyString(): str{nullptr} {
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char* s): str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

void MyString::display() const {
    cout << (strlen(str) == 0 ? "EMPTY" : str) << endl;
}

MyString::~MyString() {
    delete[] str;
}