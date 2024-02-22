#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;


const string file_path = "words.txt";

string clean_string(string& word) {
    string clean_word;
    copy_if(word.cbegin(), word.cend(), back_inserter(clean_word), [](char c){return !ispunct(c);});
    return clean_word;
}

int main() {
    ifstream text_file{file_path};

    if (!text_file) {
        cout << "File " << file_path << " not found";
        return 1;
    }

    map<string, int> word_count_map;
    map<string, set<int>> word_position_map;

    string dirty_word;
    int position{0};
    while (text_file >> dirty_word) {
        string word = clean_string(dirty_word);
        auto it = word_count_map.find(word);
        word_count_map[word]++;
        word_position_map[word].insert(position);
        position++;
    }

    for_each(word_count_map.begin(), word_count_map.end(), [](pair<const basic_string<char>, int>& m){
        cout << left << setw(20) << m.first << m.second << endl;
    });

    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    for_each(word_position_map.begin(), word_position_map.end(), [](pair<const basic_string<char>, set<int>>& m){
        cout << left << setw(20) << m.first << ": [ ";
        for_each(m.second.begin(), m.second.end(), [](int pos){cout << pos << " ";});
        cout << "]" << endl;
    });

    text_file.close();

    return 0;
}
