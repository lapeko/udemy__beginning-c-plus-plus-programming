#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


class Person {
    string name;
    int age{0};
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "[Person]: name: " << p.name << ", age: " << p.age;
        return os;
    };
public:
    Person() = default;
    explicit Person(string name, int age): name(std::move(name)), age{age} {};
    bool operator<(const Person& rhs) const {return name < rhs.name;};
    bool operator==(const Person& rhs) const {return name == rhs.name && age == rhs.age;};
    [[nodiscard]] int get_age() const {return age;};
};

class People {
    vector<Person> people;
    int max_people{0};
public:
    vector<Person> get_people_under(int age) {
        vector<Person> result;
        int count{0};
        for (const auto& p : people) {
            if (p.get_age() > age)
                continue;
            result.push_back(p);
            count++;
            if (max_people && count >= max_people) break;
        }
        return result;
    }
    void add_person(const string& name, int age) {people.emplace_back(name, age);};
    void set_max_people(int num) {max_people = num;};
};

int main() {
    People ppl;
    ppl.add_person("Igor", 23);
    ppl.add_person("Anna", 14);
    ppl.add_person("Kate", 26);
    ppl.add_person("Egor", 22);
    ppl.add_person("Vitali", 10);
    ppl.add_person("Maria", 53);
    ppl.add_person("Fedor", 49);
    ppl.add_person("Dima", 34);
    ppl.add_person("Marta", 12);
    ppl.add_person("Janek", 2);

    ppl.set_max_people(2);
    auto vec = ppl.get_people_under(20);

    for (auto& p: vec)
        cout << p << endl;

    cout << setw(50) << setfill('=') << "" << endl;

    ppl.set_max_people(0);
    vec = ppl.get_people_under(20);

    for (auto& p: vec)
        cout << p << endl;

    return 0;
}