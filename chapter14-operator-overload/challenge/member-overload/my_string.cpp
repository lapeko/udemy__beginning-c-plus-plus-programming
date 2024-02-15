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

MyString::MyString(const MyString& rhs): str{nullptr} {
    if (rhs.str == nullptr) {
        str = new char[]{'\0'};
    } else {
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
    }
}

MyString::MyString(MyString&& rhs) noexcept : str{rhs.str} {
    rhs.str = nullptr;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& rhs) {
    if (this == &rhs)
        return *this;

    delete[] str;
    if (rhs.str == nullptr) {
        str = new char[] {'\0'};
    } else {
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
    }
    return *this;
}

MyString MyString::operator-() {
    size_t size = strlen(str) + 1;
    char* temp = new char[size];
    for (int i = 0; i < size; i++)
        temp[i] = static_cast<char>(tolower(str[i]));
    temp[size - 1] = '\0';
    MyString new_my_str{temp};
    delete[] temp;
    return new_my_str;
}

bool MyString::operator==(const MyString& rhs) const {
    return strcmp(str, rhs.str) == 0;
}

bool MyString::operator!=(const MyString& rhs) const {
    return strcmp(str, rhs.str) != 0;
}

bool MyString::operator<(const MyString& rhs) const {
    return strcmp(str, rhs.str) < 0;
}

bool MyString::operator>(const MyString& rhs) const {
    return strcmp(str, rhs.str) > 0;
}

MyString MyString::operator+(const MyString& rhs) const {
    size_t size = strlen(str) + strlen(rhs.str) + 1;
    char temp[size];
    strcpy(temp, str);
    strcat(temp, rhs.str);
    temp[size - 1] = '\0';
    return MyString{temp};
}

void MyString::operator+=(const MyString& rhs) {
    MyString temp = *this + rhs;
    delete[] this->str;
    this->str = temp.str;
    temp.str = nullptr;
}

MyString MyString::operator*(const unsigned int multiplier) const {
    size_t size = strlen(str) * multiplier + 1;
    char temp[size];
    strcpy(temp, str);
    for (int i = 0; i < multiplier - 1; i++)
        strcat(temp, str);
    temp[size - 1] = '\0';
    return MyString{temp};
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

MyString MyString::operator++() {
    size_t size = strlen(str);
    for (int i = 0; i < size; i++)
        str[i] = static_cast<char>(toupper(str[i]));
    return *this;
}

void MyString::operator++(int) {
    ++(*this);
}

MyString MyString::operator--() {
    size_t size = strlen(str);
    for (int i = 0; i < size; i++)
        str[i] = static_cast<char>(tolower(str[i]));
    return *this;
}

void MyString::operator--(int) {
    --(*this);
}

const char* MyString::get_string() const {
    return str;
}
