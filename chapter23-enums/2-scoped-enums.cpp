#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Player {
public:
    enum class Direction: uint8_t {South, North, East, West};
    enum class Mode: uint8_t {Attack, Defence, Idle};
private:
    string name;
    Direction direction;
    Mode mode;
    [[nodiscard]] string get_direction() const {
        switch (direction) {
            case Direction::South: return "South";
            case Direction::North: return "North";
            case Direction::East: return "East";
            case Direction::West: return "West";
            default: return "Unknown direction";
        }
    };
    [[nodiscard]] string get_mode() const {
        switch (mode) {
            case Mode::Attack: return "Attack";
            case Mode::Defence: return "Defence";
            case Mode::Idle: return "Idle";
            default: return "Unknown mode";
        }
    };
public:
    explicit Player(
        string name = "Default name",
        Direction direction = Direction::North,
        Mode mode = Mode::Defence
    ):
        name{std::move(name)},
        direction{direction},
        mode{mode} {};
    friend ostream& operator<<(ostream& os, const Player& player) {
        os << "Player: " << player.name << ", direction: " << player.get_direction() << ", mode: " << player.get_mode();
        return os;
    };
};

int main() {
    vector<Player> players;

    players.emplace_back("Cloud Strife", Player::Direction::North, Player::Mode::Attack);
    players.emplace_back("Tifa Lockhart", Player::Direction::West, Player::Mode::Defence);
    players.emplace_back("Sephiroth", Player::Direction::South, Player::Mode::Idle);

    for_each(players.begin(), players.end(), [](Player& player) {cout << player << endl;});

    return 0;
}
