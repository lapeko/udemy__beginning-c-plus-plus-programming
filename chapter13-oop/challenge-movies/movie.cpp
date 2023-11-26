#include "movie.h"

Movie::Movie(std::string &&name, int rating) : name{std::move(name)}, rating{rating}, views{1} {};

void Movie::change_rating(int new_rating) { rating = new_rating; };

void Movie::inc_views() { views++; };

const std::string& Movie::get_name() const { return name; }

void Movie::log() const {
    std::cout << "[Movie] name: " << name << ", views: " << views << ", rating: " << rating << std::endl;
};
