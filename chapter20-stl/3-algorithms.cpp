#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
    string name;
    int age {};
    friend ostream& operator<<(ostream& os, const Person& p) {
        cout << "[Person] name: " << p.name << ", age: " << p.age;
        return os;
    }
public:
    Person() = default;
    Person(string name, int age): name{std::move(name)}, age{age} {};
    bool operator==(const Person& rhs) const {
        return name == rhs.name && age == rhs.age;
    }
};


int main() {
    cout << boolalpha;

    // example 1 - find
    vector<Person> people {
        Person{"Ivan", 40},
        Person{"Ivanka", 45},
        Person{"Alina", 34},
        Person{"Vitali", 35},
    };
    auto it = find(people.begin(), people.end(), Person{"Ivan", 40});
    if (it != people.end())
        cout << "Person found. " << *it << endl;
    else
        cout << "Person not found" << endl;

    // example 2 - count
    vector<int> numbers {1, 2, 3, 4, 5, 65, 1, 2, 1, 1};
    cout << "1 is met " << count(numbers.begin(), numbers.end(), 1) << " times" <<  endl;

    // example 3 - if_count
    cout
        << "number which is higher then 3 is met "
        << count_if(numbers.begin(), numbers.end(), [](int num){return num > 3;})
        << " times" << endl;

    // example 4 - replace
    replace(numbers.begin(), numbers.end(), 1, 100);
    for (int n: numbers)
        cout << n << " ";
    cout << endl;

    // example 5 - all_of
    cout
        << "are all numbers positive: "
        << all_of(numbers.begin(), numbers.end(), [](int num){return num >= 0;})
        << endl;

    // example 6 - transform
    string s {"Hello"};
    transform(s.cbegin(), s.cend(), s.begin(), [](char c){ return toupper(c);});
    cout << s << endl;

    return 0;
}
