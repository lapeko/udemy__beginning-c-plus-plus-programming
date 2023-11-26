#ifndef CHALLENGE_MOVIES_MOVIE_H
#define CHALLENGE_MOVIES_MOVIE_H

#include <iostream>

class Movie {
private:
    std::string name;
    int rating;
    int views;
public:
    Movie(std::string &&name, int rating);

    void change_rating(int rating);

    void inc_views();

    [[nodiscard]] const std::string &get_name() const;

    void log() const;
};

#endif //CHALLENGE_MOVIES_MOVIE_H
