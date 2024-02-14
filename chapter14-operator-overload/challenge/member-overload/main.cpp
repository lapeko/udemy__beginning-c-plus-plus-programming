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

    return 0;
}
