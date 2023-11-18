#include <iostream>
#include <utility>

using namespace std;

class Player {
private:
    string name;
    int age;
    int xp;

public:
    void set_name(string new_name) { name = std::move(new_name); }

    string get_name() { return name; }

    explicit Player(string name_value = "None", int age_value = 0, int xp_value = 0) :
            name{std::move(name_value)},
            age{age_value},
            xp{xp_value} {
        cout << "constructor. Creates name: " << name << endl;
    }

    ~Player() {
        cout << "~Player. name: " << name << endl;
    }
};

int main() {
    {
        Player player;
        player.set_name("Vasya");
        Player player2{"Marta"};
    }

    {
        auto *player = new Player("Igor", 55);
        delete player;
    }
    return 0;
}
