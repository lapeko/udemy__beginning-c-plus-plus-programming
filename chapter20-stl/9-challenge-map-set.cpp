#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;


const string file_path = "words.txt";

int main() {
    ifstream text_file{file_path};

    if (!text_file) {
        cout << "File " << file_path << " not found";
        return 1;
    }

    map<string, int> word_count_map;
    map<string, set<int>> word_position_map;

    string word;
    int position{0};
    while (text_file >> word) {
        auto it = word_count_map.find(word);
        if (it == word_count_map.cend()) {
            word_count_map.insert(pair<string, int>{word, 1});
            word_position_map.insert(pair<string, set<int>>{word, set{position}});
        } else {
            it->second++;
            auto position_it = word_position_map.find(word);
            position_it->second.insert(position);
        }
        position++;
    }

    for_each(word_count_map.begin(), word_count_map.end(), [](pair<const basic_string<char>, int>& m){
        cout << left << setw(20) << m.first << m.second << endl;
    });

    for_each(word_position_map.begin(), word_position_map.end(), [](pair<const basic_string<char>, set<int>>& m){
        cout << left << setw(20) << m.first << ": [ ";
        for_each(m.second.begin(), m.second.end(), [](int pos){cout << pos << " ";});
        cout << "]" << endl;
    });

    return 0;
}
