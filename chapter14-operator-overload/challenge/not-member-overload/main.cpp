#include <iostream>
#include "my_string.h"

int main() {
    MyString str{"Hello"};
    std::cout << (-str).get_string() << std::endl;
    return 0;
}
