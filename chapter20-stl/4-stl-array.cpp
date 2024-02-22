#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;


template<typename T, int N>
void display(array<T, N> arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    cout << endl;
}

int main() {
    cout << boolalpha;

    array<int, 7> arr {1, -3, 5, 3, 3, 2, 3};
    cout << arr.at(3) << endl;
    cout << "size: " << arr.size() << endl;
    cout << "front: " << arr.front() << endl;
    cout << "back: " << arr.back() << endl;
    cout << "empty: " << arr.empty() << endl;
    cout << "max_size: " << arr.max_size() << endl;
    cout << "data: " << arr.data() << endl;

    // adjacent_find
    cout << "====================" << endl;
    auto res = adjacent_find(arr.begin(), arr.end());
    if (res != arr.end())
        cout << "adjacent found: " << *res << endl;
    else
        cout << "adjacent not found" << endl;

    // accumulate
    cout << "====================" << endl;
    cout << "sum of all elements in array: " << accumulate(arr.begin(), arr.end(), 0) << endl;

    // count_if
    cout << "====================" << endl;
    cout << count_if(arr.begin(), arr.end(), [](int n){return n >= 0 && n <= 3;}) << endl;

    // sort
    cout << "====================" << endl;
    sort(arr.begin(), arr.end());
    display<int, 7>(arr);

    return 0;
}
