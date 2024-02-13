#include <iostream>
#include "my-string.h"

int main() {
    MyString str1 {"123"};
    MyString str2;
    str2 = std::move(str1);
    std::cout << "Length:" << str2.get_length() << std::endl;
    return 0;
}