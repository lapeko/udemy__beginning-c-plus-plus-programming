#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream file{"8-romeo-and-juliette.txt"};

    if (!file) {
        cerr << "Open file failure" << endl;
        return 1;
    }

    string word_to_find;
    cout << "Enter a word you'd like to find" << endl;
    cin >> word_to_find;
    cin.clear();

    int word_counter{0};
    int total_word_counter{0};
    string word;
    while (file >> word) {
        total_word_counter++;
        if (string::npos != word.find(word_to_find))
            word_counter++;
    }

    cout << "\n" << total_word_counter << " words were searched..." << endl;
    cout << "The word \"" << word_to_find << "\" found " << word_counter << " times." << endl;

    file.close();
    return 0;
}