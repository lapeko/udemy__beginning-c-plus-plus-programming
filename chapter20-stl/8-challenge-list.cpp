#include <iostream>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;


const int first_col_width = 30;
const int second_col_width = 30;
const int third_col_width = 5;

void delimiter() {
    cout << setw(first_col_width + second_col_width + third_col_width) <<  setfill('=') << "" << setfill(' ') << endl;
}

class Song {
    string band;
    string name;
    unsigned int rating{};
    friend ostream& operator<<(ostream& os, const Song& s) {
        cout << left
            << setw(first_col_width) << s.band
            << setw(second_col_width) << s.name
            << right << setw(third_col_width) << s.rating;
        return os;
    };
public:
    Song() = default;
    Song(string b, string n, int r): band(std::move(b)), name(std::move(n)), rating(r) {};
    bool operator<(const Song& rhs) const {return rating < rhs.rating;};
    bool operator==(const Song& rhs) {return band == rhs.band && name == rhs.name && rating == rhs.rating;};
};

class Player {
    list<Song> playlist {
        Song{"Rammstein", "Du hast", 4},
        Song{"Metallica", "One", 4},
        Song{"Pantera", "Cemetery Gates", 5},
        Song{"Children of Bodom", "Downfall", 4},
    };
    list<Song>::iterator current_song_it {this->playlist.begin()};
    void show_playing_song() {
        delimiter();
        cout << "Playing song:" << "\n" << *this->current_song_it << endl;
        delimiter();
        cout << endl;
    }
    friend ostream& operator<<(ostream& os, Player& p) {
        delimiter();
        for (const auto& s: p.playlist) cout << s << endl;
        p.show_playing_song();
        return os;
    };
public:
    void add_song(const Song& s) {
        this->playlist.insert(this->current_song_it, s);
        cout << "Added new song...\n" << *--this->current_song_it << endl;
    };
    void play_first() {
        this->current_song_it = this->playlist.begin();
        show_playing_song();
    }
    void play_next() {
        this->current_song_it == --this->playlist.end()
            ? this->current_song_it = this->playlist.begin()
            : this->current_song_it++;
        show_playing_song();
    };
    void play_prev() {
        this->current_song_it == this->playlist.begin()
            ? this->current_song_it = prev(this->playlist.end())
            : this->current_song_it--;
        show_playing_song();
    };
};

class PlayerController {
    Player player;
    bool handle_user_input() {
        char input;
        cin >> input;
        switch (toupper(input)) {
            case 'F': player.play_first(); break;
            case 'N': player.play_next(); break;
            case 'P': player.play_prev(); break;
            case 'A': player.add_song(build_song()); break;
            case 'L': cout << player; break;
            case 'Q': return true;
            default: cout << "Incorrect input. Please try again" << endl;
        }
        return false;
    };
    static Song build_song() {
        string band, song;
        int rating{0};

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a band:" << endl;
        getline(cin, band);
        cout << "Enter a song name:" << endl;
        getline(cin, song);

        while (true) {
            cout << "Enter rating (min: 1, max: 5):" << endl;
            cin >> rating;

            if (cin.fail() || rating < 1 || rating > 5) {
                cout << "Looks like you provided incorrect rating data. Please, try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else break;
        }

        return Song{band, song, rating};
    };
public:
    static void show_player_interface() {
        cout
            << "F - Play First Song\n"
            << "N - Play Next Song\n"
            << "P - Play Previous Song\n"
            << "A - Add and play a new Song at current location\n"
            << "L - List this current playlist\n"
            << "Q - Quit" << endl;
    };
    void run() {
        cout << player;
        bool exit{false};
        while(!exit) {
            show_player_interface();
            exit = handle_user_input();
        }
    };
};

int main() {
    PlayerController p;
    p.run();
};