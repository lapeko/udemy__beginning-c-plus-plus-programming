#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<int> temperatures {10, 15, 5, -5, 0, 15};
    
    float average {0};
    for (const auto &temp: temperatures)
        average += temp;

    cout << setprecision(2);
    cout << "Average: " << average;
        
    return 0;
}