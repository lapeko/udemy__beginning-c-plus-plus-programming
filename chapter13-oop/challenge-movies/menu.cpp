#include <limits>
#include "menu.h"
#include "movies.h"

Movies Menu::movies;

void Menu::show_menu() {
    std::cout << "1. Add movie" << std::endl;
    std::cout << "2. Change rating" << std::endl;
    std::cout << "3. View movie" << std::endl;
    std::cout << "4. Print movies" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

bool Menu::read_handle_user_input() {
    std::string user_input;
    std::getline(std::cin, user_input);

    if (user_input == "1" || user_input == "2") {
        std::string name;
        std::cout << "Enter the name of the movie: " << std::endl;
        std::getline(std::cin, name);
        int rating = read_rating();
        if (rating == -1)
            return true;
        if (user_input == "1")
            movies.add_movie(std::move(name), rating);
        else
            movies.change_rating(std::move(name), rating);
    } else if (user_input == "3") {
        std::string name;
        std::cout << "Enter the name of the movie: " << std::endl;
        std::getline(std::cin, name);
        movies.view(std::move(name));
    } else if (user_input == "4") {
        movies.print();
        ask_press_any_key();
    }

    if (user_input == "1" || user_input == "2" || user_input == "3" || user_input == "4")
        return true;
    else if (user_input == "0") {
        std::cout << "Exiting..." << std::endl;
        return false;
    } else {
        std::cout << "Invalid user_input." << std::endl;
        ask_press_any_key();
        return true;
    }
}

int Menu::read_rating() {
    std::string rating_line;
    int rating;

    std::cout << "Enter the rating of the movie: " << std::endl;
    std::getline(std::cin, rating_line);

    try {
        rating = std::stoi(rating_line);
        return rating;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        ask_press_any_key();
        return -1;
    }
}

void Menu::ask_press_any_key() {
    std::cout << "Press any key to continue." << std::endl;
    std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::run_in_loop() {
    while (true) {
        show_menu();
        if (!read_handle_user_input()) break;
    }
}
