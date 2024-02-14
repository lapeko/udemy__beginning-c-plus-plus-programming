#include <iostream>
#include "my-string.h"

/*
 * TODO implement two projects with MyString class. First project with member overloading and second one with non-member functions
 * 1) implement unary -
 * 2) implement ==
 * 3) implement !=
 * 4) implement <
 * 5) implement >
 * 6) implement +
 * 7) implement +=
 * 8) implement *  e.g. "Abc" * 3 => AbcAbcAbc
 * 9) implement *=
 * 10) implement ++() (What ever you want) can be uppercase
 * 11) implement ++(int) postincrement (a - should do the same as prev one, b - it is said that should be returned by value)
 * 12) implement -- (optional)
 */

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