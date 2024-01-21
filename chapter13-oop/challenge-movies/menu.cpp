#include <limits>
#include "menu.h"
#include "movies.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Movies Menu::movies;

void Menu::show_menu() {
    cout << "1. Add movie" << endl;
    cout << "2. Change rating" << endl;
    cout << "3. View movie" << endl;
    cout << "4. Print movies" << endl;
    cout << "0. Exit" << endl;
}

bool Menu::read_handle_user_input() {
    string user_input;
    getline(cin, user_input);

    if (user_input == "1" || user_input == "2") {
        string name;
        cout << "Enter the name of the movie: " << endl;
        getline(cin, name);
        int rating = read_rating();
        if (rating == -1)
            return true;
        if (user_input == "1")
            movies.add_movie(std::move(name), rating);
        else
            movies.change_rating(std::move(name), rating);
    } else if (user_input == "3") {
        string name;
        cout << "Enter the name of the movie: " << endl;
        getline(cin, name);
        movies.view(std::move(name));
    } else if (user_input == "4") {
        movies.print();
        ask_press_any_key();
    }

    if (user_input == "1" || user_input == "2" || user_input == "3" || user_input == "4")
        return true;
    else if (user_input == "0") {
        cout << "Exiting..." << endl;
        return false;
    } else {
        cout << "Invalid user_input." << endl;
        ask_press_any_key();
        return true;
    }
}

int Menu::read_rating() {
    string rating_line;
    int rating;

    cout << "Enter the rating of the movie: " << endl;
    getline(cin, rating_line);

    try {
        rating = stoi(rating_line);
        return rating;
    } catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter a number." << endl;
        ask_press_any_key();
        return -1;
    }
}

void Menu::ask_press_any_key() {
    cout << "Press any key to continue." << endl;
    cin.get();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::run_in_loop() {
    while (true) {
        show_menu();
        if (!read_handle_user_input()) break;
    }
}
