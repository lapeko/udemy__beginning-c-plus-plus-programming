#include <iostream>

using namespace std;

class Player {
public:
    string name;
    int health;
    int xp;

    void talk(string phrase) {cout << name << " says " << phrase;};
    bool is_dead();
};

int main() {
    Player frank;
    Player hero;

    Player* enemy {nullptr};
    enemy = new Player();

    delete enemy;

    hero.name = "Hero";
    hero.talk("Hi");
}