#include <iostream>
#include <memory>
#include <utility>

using namespace std;

class B;

class A {
    shared_ptr<B> b_ptr;
public:
    ~A() {cout << "A destructor" << endl;};
    void set_b(shared_ptr<B>& b) {b_ptr = b;};
};

class B {
    weak_ptr<A> a_ptr;
public:
    ~B() {cout << "B destructor" << endl;};
    void set_a(shared_ptr<A>& a) {a_ptr = a;};
};

int main() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_b(b);
    b->set_a(a);

    return 0;
}