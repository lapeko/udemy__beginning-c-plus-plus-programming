#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream text_file;
    text_file.open("text.txt");

    string word;
    while (text_file >> word) {
        cout << word << endl;
    }
};
