#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int* data;
public:
    explicit Move(int data_value): data(new int(data_value)) { cout << "Constructor for " << data_value << endl; }
    Move(const Move& copy): Move{*copy.data} { cout << "Copy constructor for " << *copy.data << endl; }
    ~Move() {
        data == nullptr
            ? cout << "Destructor for nullptr" << endl
            : cout << "Destructor for " << *data << endl;
        delete data;
    }
};

int main() {
    vector<Move> vec;
    vec.push_back(Move{1});
    cout << "---------------------------" << endl;
    vec.push_back(Move{2});
    cout << "---------------------------" << endl;
    return 0;
}
