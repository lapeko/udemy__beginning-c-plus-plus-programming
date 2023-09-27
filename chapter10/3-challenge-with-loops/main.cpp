#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Enter letters for a piramide: ";
    string line;    
    getline(cin, line);
    
    const size_t size = line.size();
    
    string reverse_line = line.substr(0, size -1);
    
    for (size_t i = 0; i < size; i++)
        reverse_line[i] = line[size - i - 2];
    
    for (size_t i = 0; i < size; i++) {
        cout << string (size - i - 1, ' ');
        cout << line.substr(0, i + 1);
        cout << reverse_line.substr(size - i - 1, i) << endl;
    }
    
    return 0;
}