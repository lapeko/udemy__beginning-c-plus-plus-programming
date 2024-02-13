#include <iostream>
#include "my-string.h"

int main() {
    MyString hello{"Hello"};
    MyString hello_lower = -hello;
    MyString combined = hello + " " + hello_lower;
    std::cout << hello_lower.get_str() << std::endl;
    std::cout << (hello_lower == hello) << std::endl;
    std::cout << combined.get_str() << std::endl;
    return 0;
}