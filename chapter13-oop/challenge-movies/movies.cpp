#include "movies.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int Movies::find_index_by_name(const string &name) {
    for (int i = 0; i < movies.size(); i++) if (movies[i].get_name() == name) return i;
    return -1;
}

Movies::Movies() : movies{} {}

void Movies::add_movie(string &&name, int rating) {
    if (find_index_by_name(name) == -1) movies.emplace_back(std::move(name), rating);
    else {
        cout << "Error: The movie \"" << name << "\" already exist." << endl;
        cout << "Press any key to continue." << endl;
        cin.get();
    }
}

void Movies::change_rating(string &&name, int new_rating) {
    int foundIndex = find_index_by_name(name);

    if (foundIndex != -1) movies[foundIndex].change_rating(new_rating);
    else {
        cout << "Error: The movie \"" << name << "\" does not exist." << endl;
        cout << "Press any key to continue." << endl;
        cin.get();
    }
}

void Movies::view(string &&name) {
    int foundIndex = find_index_by_name(name);

    if (foundIndex != -1) movies[foundIndex].inc_views();
    else {
        cout << "Error: The movie \"" << name << "\" does not exist." << endl;
        cout << "Press any key to continue." << endl;
        cin.get();
    }
}

void Movies::print() const { for (const auto &m: movies) m.log(); };

