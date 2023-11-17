#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int age;
    int xp;

public:
    void set_name(string new_name) { name = new_name; }
    string get_name() { return name; }

    Player(): Player("None") { cout << "Player()" << endl; }
    Player(string name): Player(name, 0) { cout << "Player(string name)" << endl; }
    Player(string name, int age): Player(name, age, 0) { cout << "Player(string name, int age)" << endl; }
    Player(string name_value, int age_value, int xp_value): name{name_value}, age{age_value}, xp{xp_value} {
        cout << "Player(string name_value, int age_value, int xp_value)" << endl;
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
        Player* player = new Player("Igor", 55);
        delete player;
    }
    return 0;
}