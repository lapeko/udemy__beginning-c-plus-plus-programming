#include <iostream>
using namespace std;

class Test {
private:
    int* num;
public:
    explicit Test(int init_num): num( num = new int(init_num) ) {};
    Test(const Test& src): Test(*src.num) {};

    int get_num() { return *num; }
    void set_num(int new_num) { *num = new_num; }

    ~Test() {
        delete num;
    }
};

void log_test(Test test) {
    cout << "[Test] num: " << test.get_num() << endl;
}

int main() {
    Test test1(10);
    Test test2 = Test(test1);
    test1.set_num(100);
    log_test(test1);
    log_test(test2);
}