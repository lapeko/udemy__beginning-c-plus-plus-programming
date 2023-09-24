#include <iostream>
#include <vector>

using namespace std;

void displayIntVector(const vector<int>& vec) {
    cout << "==================================================" << endl;
    cout << "size of the vector is: " << vec.size() << endl;
    cout << "elements: " << endl;
    for (const auto& item: vec) {
        cout << item << " ";
    }
    cout << endl;
}

void displayIntMatrix(const vector<vector<int>> matrix) {
    for (const auto& vec: matrix) {
        displayIntVector(vec);
    }
}

int main() {
    vector<int> vector1;
    vector<int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    vector<vector<int>> vector_2d;
    
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    displayIntMatrix(vector_2d);
    
    vector1.at(0) = 1000;
    
    displayIntMatrix(vector_2d);
    
    displayIntVector(vector1);
    
    return 0;
}