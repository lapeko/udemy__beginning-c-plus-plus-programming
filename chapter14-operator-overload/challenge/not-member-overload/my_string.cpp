#include <iostream>
#include <cstring>
#include <cctype>
#include "my_string.h"


MyString operator+(MyString& rhs) {
    for (int i = static_cast<int>(strlen(rhs.str)); i >= 0; i--)
        rhs.str[i] = static_cast<char>(toupper(rhs.str[i]));
    return rhs;
}

MyString operator-(MyString &rhs) {
    for (int i = static_cast<int>(strlen(rhs.str)); i >= 0; i--)
        rhs.str[i] = static_cast<char>(tolower(rhs.str[i]));
    return rhs;
}

bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.str, rhs.str) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.str, rhs.str) != 0;
}

bool operator<(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.str, rhs.str) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs) {
    return strcmp(lhs.str, rhs.str) > 0;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
    char temp[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(temp, lhs.str);
    strcat(temp, rhs.str);
    temp[strlen(lhs.str) + strlen(rhs.str)] = '\0';
    return MyString{temp};
}

void operator+=(MyString& lhs, const MyString& rhs) {
    char* temp = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(temp, lhs.str);
    strcat(temp, rhs.str);
    delete[] lhs.str;
    lhs.str = temp;
}

MyString operator*(const MyString& lhs, unsigned int multiplier) {
    if (multiplier == 0)
        return MyString{};

    char temp[strlen(lhs.str) * multiplier + 1];
    strcpy(temp, lhs.str);
    for (int i = 1; i < multiplier; i++)
        strcat(temp, lhs.str);

    return MyString{temp};
}

void operator*=(MyString& lhs, unsigned int multiplier) {
    if (multiplier == 0)
        return;

    char* temp = new char[strlen(lhs.str) * multiplier + 1];
    strcpy(temp, lhs.str);
    for (int i = 1; i < multiplier; i++)
        strcat(temp, lhs.str);

    delete[] lhs.str;
    lhs.str = temp;
};


MyString operator++(MyString &rhs) {
    return +rhs;
}

void operator++(MyString &lhs, int) {
    size_t size = strlen(lhs.str);
    if (size == 0)
        return;
    for (size_t i = 0; i < size; i++)
        lhs.str[i] = static_cast<char>(toupper(lhs.str[i]));
}

MyString operator--(MyString& rhs) {
    return -rhs;
}

void operator--(MyString& lhs, int) {
    size_t size = strlen(lhs.str);
    if (size == 0)
        return;
    for (size_t i = 0; i < size; i++)
        lhs.str[i] = static_cast<char>(tolower(lhs.str[i]));
}

std::ostream& operator<<(std::ostream& os, const MyString& rhs) {
    os << rhs.str;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& rhs) {
    char temp[1000];
    is.getline(temp, 1000);
    delete rhs.str;
    rhs.str = new char[strlen(temp) + 1];
    strcpy(rhs.str, temp);
    return is;
}

MyString::MyString(): str{nullptr} {
    str = new char[]{'\0'};
}

MyString::MyString(const char* s): str{nullptr} {
    if (s == nullptr) {
        str = new char[]{'\0'};
        return;
    }
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString& rhs): str{nullptr} {
    if (rhs.str == nullptr) {
        str = new char[]{'\0'};
        return;
    }
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
}

MyString::MyString(MyString&& rhs) noexcept: str{rhs.str} {
    rhs.str = nullptr;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString &rhs) {
    if (this == &rhs)
        return *this;
    delete[] str;
    if (rhs.str == nullptr)
        str = new char[]{'\0'};
    else {
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
    }
    return *this;
}

MyString& MyString::operator=(MyString&& rhs) noexcept {
    if (this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}
const char* MyString::get_string() const {
    return str;
}

