#include <cstring>
#include <cctype>
#include "my_string.h"


MyString operator-(const MyString &rhs) {
    for (int i = static_cast<int>(strlen(rhs.str)); i >= 0; i--)
        rhs.str[i] = static_cast<char>(tolower(rhs.str[i]));
    return rhs;
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
        str = new char[strlen(rhs.str)];
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
