#include <cctype>
#include <cstring>

#include "my_string.h"

MyString::MyString(): str{new char[]{'\0'}} {}

MyString::MyString(char* s) {
    if (s == nullptr) {
        str = new char[]{'\0'};
        return;
    };
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString& rhs) {
    if (this == &rhs)
        return;
    delete[] str;
    if (rhs.str == nullptr) {
        str = new char[]{'\0'};
    } else {
        str = new char[strlen(rhs.str)];
        strcpy(str, rhs.str);
    }
}

MyString::MyString(MyString&& rhs) noexcept {
    str = rhs.str;
    rhs.str = nullptr;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator-() {
    size_t size = strlen(str) + 1;
    char* temp = new char[size];
    for (int i = 0; i < size; i++)
        temp[i] = static_cast<char>(tolower(str[i]));
    auto new_my_str = new MyString{temp};
    delete[] temp;
    return *new_my_str;
}

bool MyString::operator==(const MyString& rhs) {
    return strcmp(str, rhs.str) == 0;
}

bool MyString::operator!=(const MyString& rhs) {
    return strcmp(str, rhs.str) != 0;
}

bool MyString::operator<(const MyString& rhs) {
    return strcmp(str, rhs.str) < 0;
}

bool MyString::operator>(const MyString& rhs) {
    return strcmp(str, rhs.str) > 0;
}

MyString& MyString::operator+(const MyString& rhs) {
    size_t size = strlen(str) + strlen(rhs.str) + 1;
    char temp[size];
    strcpy(temp, str);
    strcat(temp, rhs.str);
    return *(new MyString(temp));
}

void MyString::operator+=(const MyString& rhs) {
    MyString temp = *this + rhs;
    delete[] this->str;
    this->str = temp.str;
    temp.str = nullptr;
}

MyString& MyString::operator*(const unsigned int multiplier) {
    size_t size = strlen(str) * multiplier + 1;
    char temp[size];
    strcpy(temp, str);
    for (int i = 0; i < multiplier - 1; i++)
        strcat(temp, str);
    return *(new MyString{temp});
}

void MyString::operator*=(const unsigned int multiplier) {
    size_t size = strlen(str) * multiplier + 1;
    char temp[size];
    strcpy(temp, str);
    delete[] str;
    str = new char[size];
    strcpy(str, temp);
    for (int i = 0; i < multiplier - 1; i++)
        strcat(str, temp);
}

const char* MyString::get_string() {
    return str;
}

