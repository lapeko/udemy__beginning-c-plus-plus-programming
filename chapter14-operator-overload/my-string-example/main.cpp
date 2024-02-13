#include <iostream>
#include "my-string.h"

int main() {
    MyString hello{"Hello"};
    MyString world = - MyString{"WORLD"};
    MyString line = hello + " " + world;
    std::cout << line << std::endl;
    std::cout << "Enter new line:" << std::endl;
    std::cin >> line;
    std::cout << line << ". length: " << line.get_length() << std::endl;
    return 0;
}