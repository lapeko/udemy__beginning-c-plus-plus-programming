#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Object {
    int data;
public:
    explicit Object(int data = 0): data{data} {};
    ~Object() { cout << "Destructor for Object data: " << data << ", ref: " << this << endl; };
    [[nodiscard]] int get_data() const {return data;};
};
vector<unique_ptr<Object>> create_vector();

int main() {
    auto objects = create_vector();
    for (auto& obj: objects)
        cout << "Data: " << obj->get_data() << ", ref: " << obj.get() << endl;
    objects.clear();
    cout << "==================================================" << endl;
    return 0;
}

vector<unique_ptr<Object>> create_vector() {
    vector<unique_ptr<Object>> vector;

    vector.push_back(make_unique<Object>(10));
    vector.push_back(make_unique<Object>(20));

    return vector;
};
