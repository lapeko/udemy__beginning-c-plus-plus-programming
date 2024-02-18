#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int calculate_score(string& user_answers, string& correct_answers) {
  size_t size = min(correct_answers.size(), user_answers.size());
  int score {0};
  for (size_t i{0}; i < size; i++)
      if (user_answers[i] == correct_answers[i])
          score++;
  return score;
};

void draw_line() {
    cout << setfill('-') << setw(25) << "" << setfill(' ') << endl;
};

int main() {
    ifstream file;
    file.open("7-students.txt");

    if (!file) {
        cerr << "Open file failure" << endl;
        return 1;
    }

    string correct_answers;
    if (!getline(file, correct_answers)) {
        cerr << "Correct answers not found in file" << endl;
        return 1;
    }

    cout
        << setw(20) << left << "Name"
        << setw(5) << right << "Score" << endl;
    draw_line();

    string student_name;
    string student_answers;
    int total_students{0};
    int total_score{0};
    while (file >> student_name >> student_answers) {
        int score = calculate_score(student_answers, correct_answers);
        cout
            << setw(20) << left << student_name
            << setw(5) << right << score << endl;
        total_students++;
        total_score += score;
    }

    if (total_students == 0) {
        cerr << "No students found" << endl;
        return 2;
    }

    draw_line();
    cout
        << setw(20) << left << "Average score"
        << setw(5) << right << setprecision(1) << fixed << double(total_score) / total_students << endl;

    return 0;
}
