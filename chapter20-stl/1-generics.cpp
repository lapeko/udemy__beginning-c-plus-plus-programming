#include <iostream>

using namespace std;


template<typename T>
T min(T& a, T& b) {
    return a < b ? a : b;
}

class Person {
    string name;
    int age{};
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "[Person] name: " << p.name << ", age: " << p.age << endl;
        return os;
    };
public:
    Person() = default;
    Person(string name, int age): name{std::move(name)}, age{age} {};
    bool operator<(Person& person) const {
        return age < person.age;
    };
};

int main() {
    // example 1 - generic based on define
    {
        #define multiply(a, b)(a * b)
        cout << (4 / multiply(2, 2)) << endl; // definition will be called first
    }

    // example 2 - min generic func
    {
        Person p1{"Mary", 23};
        Person p2{"Katrin", 26};
        cout << "Min: " << min(p1, p2) << endl;
    }

    return 0;
}