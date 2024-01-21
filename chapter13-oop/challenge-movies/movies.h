#ifndef CHALLENGE_MOVIES_MOVIES_H
#define CHALLENGE_MOVIES_MOVIES_H

#include "movie.h"
#include <vector>

class Movies {
private:
    std::vector<Movie> movies;

    int find_index_by_name(const std::string &name);

public:
    Movies();

    void add_movie(std::string &&, int);

    void change_rating(std::string &&, int);

    void view(std::string &&);

    void print() const;
};

#endif //CHALLENGE_MOVIES_MOVIES_H
