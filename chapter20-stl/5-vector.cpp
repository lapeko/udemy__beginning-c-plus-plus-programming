#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


auto print_nums(vector<int>& nums) {
    for_each(nums.cbegin(), nums.cend(), [](const int& n){cout << n << " ";});
    cout << endl;
}

int main() {
    // erase
    vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    nums.erase(nums.cbegin(), nums.cbegin() + 2);
    print_nums(nums);

    // left in vector only even numbers (with erase)
    nums.erase(std::remove_if(nums.begin(), nums.end(), [](int n){return n % 2 != 0;}), nums.cend());
    print_nums(nums);

    // copy_if + back_inserter
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2;
    copy_if(nums.begin(), nums.end(), back_inserter(nums2), [](int n){return n % 2 == 0;});
    print_nums(nums2);

    // transform
    nums = {1, 2, 3, 4, 5};
    nums2 = {10, 20, 30, 40, 50};
    vector<int> nums3;
    transform(nums.begin(), nums.end(),nums2.begin(), back_inserter(nums3), multiplies<>());
    print_nums(nums3);

    // find and insert
    nums.insert(find(nums.begin(), nums.end(), 3), nums2.begin(), nums2.end());
    print_nums(nums);

    return 0;
}