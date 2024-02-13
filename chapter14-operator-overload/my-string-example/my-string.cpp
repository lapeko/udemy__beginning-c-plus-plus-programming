#include <iostream>
#include "my-string.h"
#include "cstring"

MyString::MyString(): str{nullptr} {
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *rhs): str{nullptr} {
    if (rhs == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(rhs) + 1];
        strcpy(str, rhs);
    }
}

MyString::MyString(const MyString &rhs) {
    if (this == &rhs)
        return;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
}

MyString::MyString(MyString &&rhs) noexcept: str {rhs.str}  {
    rhs.str = nullptr;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = new char[rhs.get_length() + 1];
    strcpy(str, rhs.str);
    return *this;
}

MyString& MyString::operator=(MyString &&rhs) noexcept {
    if (this != &rhs) {
        delete[] str;
        str = rhs.str;
        rhs.str = nullptr;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const MyString &obj) {
    os << obj.str;
    return os;
}

std::istream& operator>>(std::istream &is, MyString &obj) {
    char buff[1000];
    is.getline(buff, 1000);
    delete obj.str;

    obj.str = new char[strlen(buff) + 1];
    strcpy(obj.str, buff);

    return is;
};

//MyString& MyString::operator-() {
//    size_t size = strlen(str) + 1;
//    char *buff = new char[size];
//    for (size_t i = 0; i < size; i++)
//        buff[i] = static_cast<char>(tolower(str[i]));
//    auto *temp = new MyString{buff};
//    delete[] buff;
//    return *temp;
//}

//MyString& MyString::operator+(const MyString &rhs) {
//    size_t size = strlen(str) + strlen(rhs.str) + 1;
//    char *buff = new char[size];
//
//    strcpy(buff, str);
//    strcat(buff, rhs.str);
//
//    auto *temp = new MyString{buff};
//    delete[] buff;
//    return *temp;
//}

//bool MyString::operator==(const MyString &rhs) {
//    return strcmp(str, rhs.str) == 0;
//}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    size_t size = strlen(lhs.str) + strlen(rhs.str) + 1;
    char *buff = new char[size];

    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);

    auto *temp = new MyString{buff};
    delete[] buff;
    return *temp;
}

MyString operator-(const MyString &rhs) {
    size_t size = strlen(rhs.str) + 1;
    char *buff = new char[size];

    for (int i = 0; i < size; i++)
        buff[i] = static_cast<char>(tolower(rhs.str[i]));

    auto *temp = new MyString{buff};
    delete[] buff;

    return *temp;
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) == 0;
}

void MyString::display() const {
    std::cout << (strlen(str) == 0 ? "EMPTY" : str) << std::endl;
}

size_t MyString::get_length() const {
    return strlen(str);
}

const char* MyString::get_str() const {
    return str;
}
