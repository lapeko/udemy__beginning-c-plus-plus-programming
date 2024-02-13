#include <iostream>
#include "my-string.h"

int main() {
    MyString a{"Hello"};
    a = MyString{"Hola"};
    a = "Bonjour";
    std::cout << a.get_str() << std::endl;
    return 0;
}