#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


class Multiplier {
    int multiplier;
public:
    explicit Multiplier(int n): multiplier{n} {};
    int operator() (int to_multiply) const {
        return to_multiply * multiplier;
    };
};

class Displayer {
public:
    template<typename T>
    void operator() (T& data) {
        cout << data << endl;
    }
};

int main() {
    vector<int> nums {1, 2, 3, 4, 5};
    transform(nums.begin(), nums.end(), nums.begin(), Multiplier{10});
    for_each(nums.begin(), nums.end(), Displayer{});

    cout << setfill('-') << setw(40) << "" << endl;

    vector<int> nums2 {1, 2, 3, 4, 5};
    transform(nums2.begin(), nums2.end(), nums2.begin(), [](int num) {return num * 10;});
    for_each(nums.begin(), nums.end(), [](int num) {cout << num << endl;});
}