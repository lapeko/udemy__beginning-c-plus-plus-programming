#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
    cout << "Max random: " << RAND_MAX << endl;
    cout << "time(NULL) is " << time(nullptr) << endl;
    
    srand(time(nullptr));
    
    int min_random = 1;
    int max_random = 5;
    
    for (int i {0}; i < 10; i++) cout << rand() % (max_random - min_random + 1) + min_random << endl;

    return 0;
}