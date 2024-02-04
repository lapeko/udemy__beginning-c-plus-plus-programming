#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void show_menu();
char handle_user_input();
void print_numbers(vector<int>* numbers);
void add_number(vector<int>* numbers);
void print_mean_number(vector<int>* numbers);
void print_smallest_number(vector<int>* numbers);
void print_largest_number(vector<int>* numbers);
void clear_console();

int main() {
    bool quit_pressed {false};
    vector<int> numbers {};
    do {
        show_menu();
        const char user_input {handle_user_input()};
        switch (user_input) {
            case 'p': print_numbers(&numbers); break;
            case 'a': add_number(&numbers); break;
            case 'm': print_mean_number(&numbers); break;
            case 's': print_smallest_number(&numbers); break;
            case 'l': print_largest_number(&numbers); break;
            case 'q': quit_pressed = true; break;
            default: cout << "Unknown value. PLease, try again" << endl;
        }
    } while (!quit_pressed);
}

void show_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

char handle_user_input() {
    char user_input {};
    cin >> user_input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    clear_console();

    return tolower(user_input);
}

void print_numbers(vector<int>* numbers) {
    if (numbers->empty()) {
        cout << "[] - this list is empty" << endl;
        return;
    };
    cout << "[";
    for (auto num : *numbers) cout << " " << num << " ";
    cout << "]" << endl;
};

void add_number(vector<int>* numbers) {
    cout << "Enter a number: ";
    int new_number {};
    while (!(cin >> new_number)) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
    };
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    numbers->push_back(new_number);
};

void print_mean_number(vector<int>* numbers) {
    if (numbers->empty()) {
        cout << "Unable to calculate the mean" << endl;
        return;
    }
    int sum {};
    for (auto num : *numbers) sum += num;
    cout << "The mean of numbers is: " << static_cast<double>(sum) / numbers->size() << endl;
};

void print_smallest_number(vector<int>* numbers) {
    if (numbers->empty()) {
        cout << "Unable to determine the smallest number" << endl;
        return;
    }
    int smallest_number = numbers->at(0);
    for (auto num : *numbers)
        if (num < smallest_number) smallest_number = num;
    cout << "The smallest number is: " << smallest_number << endl;
};

void print_largest_number(vector<int>* numbers) {
    if (numbers->empty()) {
        cout << "Unable to determine the largest number" << endl;
        return;
    }
    int biggest_number = numbers->at(0);
    for (auto num : *numbers)
        if (num > biggest_number) biggest_number = num;
    cout << "The smallest number is: " << biggest_number << endl;
};

void clear_console() {
    string environment = getenv("TERM");
    environment == "xterm" ? system("clear") : system("cls");
}