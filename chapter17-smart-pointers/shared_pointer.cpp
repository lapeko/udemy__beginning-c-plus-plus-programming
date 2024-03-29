#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Object {
    int data;
public:
    explicit Object(int data = 0): data{data} {};
    int get_data() const {return data;};
};

int main() {
    vector<shared_ptr< Object> > objects;

    {
        shared_ptr<Object> ptr1 {new Object{20}, [] (Object* obj) {
            cout << "Custom deleter" << endl;
            delete obj;
        }};
        shared_ptr<Object> ptr2 = ptr1;
        objects.push_back(ptr1);
        cout << objects[0].use_count() << endl;
        ptr2.reset();
        cout << objects[0].use_count() << endl;
    }

    cout << objects[0].use_count() << endl;

    objects.clear();

    cout << "==================================================" << endl;
    return 0;
}