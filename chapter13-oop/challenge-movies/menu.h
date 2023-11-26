#ifndef CHALLENGE_MOVIES_MENU_H
#define CHALLENGE_MOVIES_MENU_H

#include "movies.h"

class Menu {
private:
    static Movies movies;
    static void show_menu();
    static bool read_handle_user_input();
    static int read_rating();
    static void ask_press_any_key();
public:
    static void run_in_loop();
};

#endif //CHALLENGE_MOVIES_MENU_H
