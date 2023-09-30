#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void runApp();
void printVector(const vector<int> &);
void addNumberToVector(vector<int> &);
void showAverageVectorValue(const vector<int> &);
void showSmallest(const vector<int> &);
void showLargest(const vector<int> &);

int main() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl << endl;

    runApp();

    return 0;
}

void runApp() {
    vector<int> ints {};

    while(true) {
        cout << "Enter your choice" << endl;
        char userChoice;
        cin >> userChoice;
        userChoice = static_cast<char>(tolower(userChoice));

        switch(userChoice) {
            case 'p': printVector(ints); break;
            case 'a': addNumberToVector(ints); break;
            case 'm': showAverageVectorValue(ints); break;
            case 's': showSmallest(ints); break;
            case 'l': showLargest(ints); break;
            case 'q': return;
            default: cout << "Unknown selection, please try again" << endl;
        }
    }
}

void printVector(const vector<int> &ints) {
    cout << "[";
    for (int num: ints) cout << " " << num;
    if (!ints.empty()) cout << " ";
    cout << "]" << endl;
}

void addNumberToVector(vector<int> &ints) {
    int newIntNumber {0};
    cout << "Enter an integer number: ";
    cin >> newIntNumber;
    ints.push_back(newIntNumber);
    cout << ints.at(ints.size() -1) << " added" << endl;
}

void showAverageVectorValue(const vector<int> &ints) {
    if (ints.empty()) {
        cout << "Unable to calculate the mean - no data" << endl;
        return;
    }
    double sum {0};
    for (double num: ints) sum += num;
    cout << fixed << setprecision(2);
    cout << "The average number is: " << sum / static_cast<double>(ints.size()) << endl;
}

void showSmallest(const vector<int> &ints) {
    if (ints.empty()) {
        cout << "Unable to determine the smallest number - list is empty" << endl;
        return;
    }
    int smallestElement = ints.at(0);
    for (int num: ints) if (num < smallestElement) smallestElement = num;
    cout << "The smallest number is: " << smallestElement << endl;
};

void showLargest(const vector<int> &ints) {
    if (ints.empty()) {
        cout << "Unable to determine the largest number - list is empty" << endl;
        return;
    }
    int smallestElement = ints.at(0);
    for (int num: ints) if (num > smallestElement) smallestElement = num;
    cout << "The smallest number is: " << smallestElement << endl;
};