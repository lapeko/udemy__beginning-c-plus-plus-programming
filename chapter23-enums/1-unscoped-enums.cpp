#include <iostream>

using namespace std;


enum Test {One, Two};
istream & operator>>(istream& is, Test& test) {
    underlying_type_t<Test> u_input;
    is >> u_input;
    switch (u_input) {
        case One: test = Test{One}; break;
        case Two: test = Test{Two}; break;
        default: throw "User input is unknwon";
    }
    return is;
}

int main() {
    // Example 1
    {
        enum: uint8_t {Bread, Milk, Salt = 0, Meat, Egg};
    //    enum SomeOtherEnum {Water, Milk}; You can't use the same name for unscoped enum item

        cout << "Meat: " << int(Meat) << ". Sizeof Meat: " << sizeof Meat << endl;
    }

    // example 2
    Test t;
    cout << "Enter test value. (0 or 1)" << endl;
    try {
        cin >> t;
        cout << t;
    } catch (const char* ex) {
        cerr << ex << endl;
    }

    return 0;
}