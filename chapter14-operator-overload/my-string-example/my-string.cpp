#include <iostream>
#include "my-string.h"
#include "cstring"

MyString::MyString(): str{nullptr} {
    std::cout << "Empty constructor" << std::endl;
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *rhs): str{nullptr} {
    std::cout << "One argument constructor" << std::endl;
    if (rhs == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(rhs) + 1];
        strcpy(str, rhs);
    }
}

MyString::MyString(const MyString &rhs): str {rhs.str}  {
    std::cout << "Copy constructor" << std::endl;
    if (this == &rhs)
        return;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
}

MyString::MyString(MyString &&rhs) noexcept: str {rhs.str}  {
    std::cout << "Move constructor" << std::endl;
    rhs.str = nullptr;
}

MyString::~MyString() {
    std::cout << "Destructor" << std::endl;
    delete[] str;
}

MyString &MyString::operator=(const MyString &rhs) {
    std::cout << "Overloaded copy operator" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = new char[rhs.get_length() + 1];
    strcpy(str, rhs.str);
    return *this;
}

MyString &MyString::operator=(MyString &&rhs) noexcept {
    std::cout << "Overloaded move operator" << std::endl;
    if (this != &rhs) {
        delete[] str;
        str = rhs.str;
        rhs.str = nullptr;
    }
    return *this;
};

void MyString::display() const {
    std::cout << (strlen(str) == 0 ? "EMPTY" : str) << std::endl;
}

size_t MyString::get_length() const {
    return strlen(str);
}

const char* MyString::get_str() const {
    return str;
}
