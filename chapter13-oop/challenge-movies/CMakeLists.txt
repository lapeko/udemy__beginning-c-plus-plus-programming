cmake_minimum_required(VERSION 3.26)
project(challenge_movies)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        challenge_movies
        main.cpp
        movie.cpp
        movies.cpp
        menu.cpp
)
