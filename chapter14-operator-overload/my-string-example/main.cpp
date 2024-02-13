#include <iostream>
#include "my-string.h"

int main() {
    MyString hello{"Hello"};
    MyString line = hello + " " + "world";
    std::cout << line.get_str() << std::endl;
    return 0;
}