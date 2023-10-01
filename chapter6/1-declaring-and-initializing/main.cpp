#include <iostream>

using namespace std;

int main() {
    int roomWidth {0};
    cout << "Enter the width of your room" << endl;
    cin >> roomWidth;
    
    int roomLength {0};
    cout << "Enter the length of your room" << endl;
    cin >> roomLength;
    
    cout << "The area of your romm is " << roomWidth * roomLength << " square meters" << endl;
    
    return 0;
}