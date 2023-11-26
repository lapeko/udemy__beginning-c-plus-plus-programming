#include "movies.h"
#include <iostream>

int Movies::find_index_by_name(const std::string &name) {
    for (int i = 0; i < movies.size(); i++) if (movies[i].get_name() == name) return i;
    return -1;
}

Movies::Movies() : movies{} {}

void Movies::add_movie(std::string &&name, int rating) {
    if (find_index_by_name(name) == -1) movies.emplace_back(std::move(name), rating);
    else {
        std::cout << "Error: The movie \"" << name << "\" already exist." << std::endl;
        std::cout << "Press any key to continue." << std::endl;
        std::cin.get();
    }
}

void Movies::change_rating(std::string &&name, int new_rating) {
    int foundIndex = find_index_by_name(name);

    if (foundIndex != -1) movies[foundIndex].change_rating(new_rating);
    else {
        std::cout << "Error: The movie \"" << name << "\" does not exist." << std::endl;
        std::cout << "Press any key to continue." << std::endl;
        std::cin.get();
    }
}

void Movies::view(std::string &&name) {
    int foundIndex = find_index_by_name(name);

    if (foundIndex != -1) movies[foundIndex].inc_views();
    else {
        std::cout << "Error: The movie \"" << name << "\" does not exist." << std::endl;
        std::cout << "Press any key to continue." << std::endl;
        std::cin.get();
    }
}

void Movies::print() { for (const auto &m: movies) m.log(); };

