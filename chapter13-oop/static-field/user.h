#ifndef PLAY_WITH_CPP_USER
#define PLAY_WITH_CPP_USER

#include <iostream>

class User {
    static int counter;
    std::string name;
public:
    User(std::string name);
    static void show_counter();
    ~User();
};

#endif