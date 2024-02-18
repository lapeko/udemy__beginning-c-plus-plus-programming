#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream text_file;
    text_file.open("text.txt");

    if (!text_file) {
        cerr << "File not found" << endl;
        return 1;
    }

    string line;
    while (getline(text_file, line)) {
        cout << line << endl;
    }
    text_file.close();

    text_file.open("./text.txt");
    char c;
    while (text_file.get(c)) {
        cout << c;
    }
    text_file.close();

    cout << "\n==============================" << endl;
    string name;
    int num;
    double d;
    text_file.open("./text.txt");
    while (text_file >> name >> num >> d)
        cout << name << " | " << num << " | " << d << endl;
    text_file.close();

    return 0;
};
