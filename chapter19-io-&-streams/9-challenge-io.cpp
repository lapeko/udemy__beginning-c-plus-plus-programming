#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
    ifstream i_file{"8-romeo-and-juliette.txt"};
    ofstream o_file{"9-number-all.txt"};
    ofstream o_file2{"9-number-not-empty.txt"};

    if (!i_file || !o_file || !o_file2) {
        cerr << "Open file failure" << endl;
        return 1;
    }

    int total_counter{0};
    int not_empty_counter{0};
    string line;
    while (getline(i_file, line)) {
        o_file << left << setw(9) << ++total_counter << line << endl;
        o_file2 << left << setw(9) << (line.length() ? to_string(++not_empty_counter) : "") << line << endl;
    }

    i_file.close();
    o_file.close();
    o_file2.close();

    return 0;
}

