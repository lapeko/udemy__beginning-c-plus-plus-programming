#include <iostream>
#include <deque>

using namespace std;


void print_num(const deque<int>& deq) {
    for (int n: deq)
        cout << n << " ";
    cout << endl;
}

int main() {
    deque<int> deq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    deque<int> deq2;

    for (int n: deq)
        n % 2 == 0 ? deq2.push_front(n) : deq2.push_back(n);

    print_num(deq2);

    deq2.clear();
    copy(deq.cbegin(), deq.cend(), front_inserter(deq2));
    print_num(deq2);

    return 0;
};
