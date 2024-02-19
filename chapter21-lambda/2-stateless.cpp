#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;



//void print_if(const vector<int>& numbers, bool (*predicate) (int)) {
//    for (int num: numbers)
//        if (predicate(num))
//            cout << num << endl;
//};

void print_if(const vector<int>& numbers, const function<bool(int)>& predicate) {
    for (int num: numbers)
        if (predicate(num))
            cout << num << endl;
};

auto create_printer() {
    return [](auto data){cout << data << endl;};
};

class User {
    string name;
    int age;
    friend ostream& operator<<(ostream& os, const User& user) {
        cout << "User. name: " << user.name << " age: " << user.age << endl;
        return os;
    }
public:
    User(string name, int age): name{std::move(name)}, age{age} {};
    [[nodiscard]] int get_age() const {return age;};
};

int main() {
    auto log = [](auto log){cout << log << endl;};
    log(123);
    log(12.3);

    function<int(int, int)> multiply = [](int a, int b) -> int {return a * b;}; // auto multiply = ... will be the same
    cout << multiply(2, 3) << endl;

    cout << "========================" << endl;
    vector<int> nums{1, 2, 3, 4, 5, 6};
    print_if(nums, [](int n){return n % 2 == 0;});

    cout << "========================" << endl;

    vector<User> users {
        User{"Ivan", 40},
        User{"Vitali", 35},
        User{"Kiril", 36},
    };

    auto print = create_printer();

    sort(users.begin(), users.end(), [](User& user_a, User& user_b){return user_a.get_age() < user_b.get_age();});
    for_each(begin(users), end(users), print);

    return 0;
}
