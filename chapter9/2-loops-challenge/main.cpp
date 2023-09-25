#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
    vector<int> ints {};
    
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;
    
    while(true) {
        cout << "Enter your choice" << endl;
        char userChoice;
        cin >> userChoice;
        userChoice = tolower(userChoice);
        
        if (userChoice == 'p') {
            cout << "[";
            for (int num: ints) cout << " " << num;
            if (ints.size()) cout << " ";
            cout << "]" << endl;
        }
        
        else if (userChoice == 'a') {
            int newIntNumber {0};
            cout << "Enter an integer number: ";
            cin >> newIntNumber;
            ints.push_back(newIntNumber);
            cout << ints.at(ints.size() -1) << " added" << endl;
        }
        
        else if (userChoice == 'm') {
            if (!ints.size()) {
                cout << "Unable to calculate the mean - no data" << endl;
                continue;
            }
            float sum {0};
            for (int num: ints) sum += num;
            cout << fixed << setprecision(2);
            cout << "The average number is: " << sum / ints.size() << endl;
        }
        
         else if (userChoice == 's') {
            if (!ints.size()) {
                cout << "Unable to determine the smallest number - list is empty" << endl;
                continue;
            }
            int smallestElement = ints.at(0);
            for (int num: ints) if (num < smallestElement) smallestElement = num;
            cout << "The smallest number is: " << smallestElement << endl;
        }
        
        else if (userChoice == 'l') {
            if (!ints.size()) {
                cout << "Unable to determine the largest number - list is empty" << endl;
                continue;
            }
            int smallestElement = ints.at(0);
            for (int num: ints) if (num > smallestElement) smallestElement = num;
            cout << "The smallest number is: " << smallestElement << endl;
        }
        
        else if (userChoice == 'q'){
            cout << "Exit";
            break;
        } else {
            cout << "Unknown selection, please try again" << endl;
        }
    }
    
    return 0;
}