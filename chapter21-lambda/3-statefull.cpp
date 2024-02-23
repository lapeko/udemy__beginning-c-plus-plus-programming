#include <iostream>

using namespace std;


int y = 0;
int main() {
    // example 1
    {
        class anonymous_lambda {
            int first_arg;
        public:
            explicit anonymous_lambda(int f): first_arg{f} {};
            int operator() (int a) const { return first_arg + a; };
        };
        cout << anonymous_lambda{12}(1) << endl;
    }
    // example 2
    {
        int a{10};
        int b{20};

        auto l = [=](int b) mutable { // [=] will capture everything by value
            a += b;
            cout << a << endl;
        };
        l(33);
        l(33); // Variable "a" was captured once during initialization and this call will change the variable again
        cout << "Will not be updated => " << a << endl;

        [&a](int b) mutable {
            a += b;
            cout << a << endl;
        }(33);
        cout << "Will be updated => " << a << endl;

        [&]() mutable { // "&" -> all by reference, "=" -> (Default) all by value, "this" - will capture this object by reference
            a = 100;
            b = 200;
            y = 300;
        }();
        cout << "Will overwrite everything. a: " << a << ", b: " << b << ", y: " << y << endl;
    }
}
