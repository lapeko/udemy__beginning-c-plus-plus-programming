#include <iostream>
#include "my_string.h"

int main() {
    MyString hello {"Hello"};
    MyString world {"World"};
    MyString world2 {"world"};

    std::cout << ((-world) == world2) << std::endl;
    std::cout << (hello != world) << std::endl;
    std::cout << (world2 > world) << std::endl;
    std::cout << (hello < world) << std::endl;

    MyString line {"test"};
    line += " line";
    std::cout << line.get_string() << std::endl;

    std::cout << (line * 3).get_string() << std::endl;
    line *= 4;
    std::cout << line.get_string() << std::endl;

    return 0;
}
