#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


int main() {
    vector<string> cars {
        "Mercedes A300 2798 249",
        "BMW M2 2998 249",
    };
    istringstream iss;
    ostringstream oss;

    string producer;
    string line;
    int engine_volume;
    int max_speed;

    oss << left << setw(15) << "Producer" << setw(8) << right << "Line" << setw(16) << "Engine volume" << setw(12) << "Max speed" << endl;

    for (string& car: cars) {
        iss.clear();
        iss.str(car);
        iss >> producer >> line >> engine_volume >> max_speed;
        oss << left << setw(15) << producer << setw(8) << right << line << setw(16) << engine_volume << setw(12) << max_speed << endl;
    }

    cout << oss.str();

    return 0;
}