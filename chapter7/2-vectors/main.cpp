#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    for (const vector<int>& vec: matrix) {
        for (const int& item: vec) {
            cout << item << " ";
        }
        cout << endl;
    }
    
    return 0;
}