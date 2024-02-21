#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    vector<int> vec{1, 3, 5};

    for (auto/*vector<int>::iterator*/ it = vec.begin(); it != vec.end(); it++)
        cout << *it << endl;

    cout << "==================================================" << endl;

    for (auto/*vector<int>::reverse_iterator*/ it = vec.rbegin(); it != vec.rend(); it++)
        cout << *it << endl;

    cout << "==================================================" << endl;

    map<string, string> people {
        {"First", "Some value 1"},
        {"Second", "Some value 2"},
        {"Third", "Some value 3"},
    };
    for (auto it = people.crbegin(); it != people.crend(); it++)
        cout << "Name: " << it->first << ", value: " << it->second << endl;

    cout << "==================================================" << endl;

    vector<int> vec2 {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    auto begin_p = vec2.cbegin() + 2;
    auto end_p = vec2.cend() - 3;

    while (begin_p != end_p)
        cout << *begin_p++ << endl;

    return 0;    
};
