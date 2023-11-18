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

    string get_name() const { return name; }
    int get_age() const { return age; }
    int get_xp() const { return xp; }

    explicit Player(string name_value = "None", int age_value = 0, int xp_value = 0) :
            name{std::move(name_value)},
            age{age_value},
            xp{xp_value} {
        cout << "constructor. Creates name: " << name << endl << endl;
    }

    Player(const Player &player) :
            name{player.name},
            age{player.age},
            xp{player.xp} {
        cout << "copy constructor: Name: " << player.name << endl << endl;
    }

    ~Player() {
        cout << "~Player. name: " << name << endl << endl;
    }
};

void show_player_by_copy(const Player player) {
    cout << "Player:" << endl;
    cout << "name: " << player.get_name() << endl;
    cout << "age: " << player.get_age() << endl;
    cout << "xp: " << player.get_xp() << endl << endl;
}

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

    Player player;
    show_player_by_copy(player);

    return 0;
}
