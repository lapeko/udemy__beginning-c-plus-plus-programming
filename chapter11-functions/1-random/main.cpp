#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void test_prototype(int a);

int main() {
    cout << "Max random: " << RAND_MAX << endl;
    cout << "time(NULL) is " << time(NULL) << endl;
    
    srand(time(NULL));
    
    int min_random = 1;
    int max_random = 5;
    
    for (int i {0}; i < 10; i++) cout << rand() % (max_random - min_random + 1) + min_random << endl;
    
    return 0;
}

void test_prototype(int b) {
    cout << "It is b. Not a: " << b << endl;
}