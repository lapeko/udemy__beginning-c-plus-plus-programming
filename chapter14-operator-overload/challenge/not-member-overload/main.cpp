#include <iostream>
#include "my_string.h"

int main() {
    MyString str{"Hello"};
    str += MyString{" world "};
    str *= 3;
    MyString upper = ++str;

    std::cout << upper << std::endl;

    MyString temp;
    std::cout << "Enter some line: " << std::endl;
    std::cin >> temp;
    std::cout << "You entered: " << temp << std::endl;
    int count{0};
    std::cout << "enter count of repeating: " << std::endl;
    std::cin >> count;
    std::cout << temp * count << std::endl;

    return 0;
}
