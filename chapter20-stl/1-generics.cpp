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

template<typename T>
class Item {
    string name;
    T value;
public:
    Item(string name, T value): name{std::move(name)}, value{std::move(value)} {};
    string get_name() {
        return name;
    };
    T get_value() {
        return value;
    };
};

template<typename T, int N>
class MyArray {
    int size{N};
    T values[N]{};
    friend ostream& operator<<(ostream& os, const MyArray& myArray) {
        os << "[MyArray] size: " << myArray.size << endl << "Elements: ";
        for (int i = 0; i < myArray.size; i++)
            os << myArray.values[i] << (i < myArray.size - 1 ? ", " : "");
        os << endl;
        return os;
    };
public:
    T& operator[](int index) {
        return values[index];
    };
    void fill(T value) {
        for (int i = 0; i < size; i++)
            values[i] = value;
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

    // example 3
    {
        Item<Item<int>> outer{"Outer", {"Inner", 12}};
        Item<int> inner = outer.get_value();
        cout << "Outer name: " << outer.get_name() << ", inner name: " << inner.get_name() << ", inner value: " << inner.get_value() << endl;
    }

    // example 4 - custom array. overload operator []. template int value
    MyArray<int, 5> myArray;
    myArray.fill(5);
    cout << myArray;

    return 0;
}