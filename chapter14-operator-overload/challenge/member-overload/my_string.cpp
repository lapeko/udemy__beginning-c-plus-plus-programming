#include "my_string.h"
#include <cctype>
#include <cstring>

MyString::MyString(): str{new char[]{'\0'}} {}

MyString::MyString(char *s) {
    if (s == nullptr) {
        str = new char[]{'\0'};
        return;
    };
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &rhs) {
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

MyString::MyString(MyString &&rhs) noexcept {
    str = rhs.str;
    rhs.str = nullptr;
}

MyString &MyString::operator-() {
    size_t size = strlen(str) + 1;
    char* temp = new char[size];
    for (int i = 0; i < size; i++)
        temp[i] = static_cast<char>(tolower(str[i]));
    auto new_my_str = new MyString{temp};
    delete[] temp;
    return *new_my_str;
}
