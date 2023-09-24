#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix) {
    cout << "matrix size: " << matrix.size() << endl;
    for (const vector<int>& vec: matrix) {
        cout << "inner vecor size: " << vec.size() << endl;
        for (const int& item: vec) {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << "==================================================" << endl;
}

int main() {
    vector<vector<int>> matrix {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    printMatrix(matrix);
    
    matrix.at(0).push_back(4);
    
    printMatrix(matrix);
    
    return 0;
}