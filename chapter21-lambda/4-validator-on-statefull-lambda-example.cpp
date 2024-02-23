#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


class PasswordValidator {
    string restricted_symbols;
public:
    explicit PasswordValidator(string restricted_symbols): restricted_symbols{std::move(restricted_symbols)} {};
    bool is_valid(const string& s) {
        return all_of(s.cbegin(), s.cend(), [this](char c){
            return find(this->restricted_symbols.cbegin(), this->restricted_symbols.cend(), c) == this->restricted_symbols.cend();
        });
    };
};

int main() {
    PasswordValidator validator{"!@"};
    cout << boolalpha;
    string test{"abba"};
    cout << "Is " << test << " valid: " << validator.is_valid(test) << endl;
    return 0;
}