#include "user.h"
#include <iostream>

int User::counter {0};
User::User(std::string name): name{name} {User::counter++;};
User::~User() {User::counter--;};
void User::show_counter() {std::cout << "counter: " << User::counter << std::endl;};
