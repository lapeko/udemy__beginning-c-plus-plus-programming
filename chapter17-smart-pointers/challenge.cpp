#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {
    int data;
public:
    Test(): data{0} { cout << "Test constructor (" << data << ")" << endl; };
    explicit Test(int data): data{data} { cout << "Test constructor (" << data << ")" << endl; };
    [[nodiscard]] int get_data() const {return data;};
    ~Test() { cout << "Test destructor (" << data << ")" << endl; };
};

unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>>& vec, int num);
void display(const vector<shared_ptr<Test>>& vec);

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: " << flush;
    int num {0};
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

unique_ptr<vector<shared_ptr<Test>>> make() {
    return make_unique<vector<shared_ptr<Test>>>(vector<shared_ptr<Test>>{});
};

void fill(vector<shared_ptr<Test>>& vec, int num) {
    for (int i = 0; i < num; i++) {
        cout << "Enter a value for " << i + 1 << " item: ";
        int user_input;
        cin >> user_input;
        vec.emplace_back(make_shared<Test>(user_input));
    }
}

void display(const vector<shared_ptr<Test>>& vec) {
    for (auto& test: vec)
        cout << test->get_data() << endl;
}
