#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;


bool is_palindrome(const string& candidate) {
    stack<char> s;
    queue<char> q;

    for (char c: candidate)
        if (isalpha(c)) {
            s.push(static_cast<char>(toupper(c)));
            q.push(static_cast<char>(toupper(c)));
        }

    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front())
            return false;
        s.pop();
        q.pop();
    }

    return true;
};

int main() {
    vector<string> tests {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva",
                          "Amore, Roma", "A Toyota's a Toyota", "A Santa at NASA", "C++",
                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome",
    };

    cout << boolalpha;
    for (const string& test : tests)
        cout << "Is palindrome: " << setw(5) << is_palindrome(test) << ", line: " << test << endl;

    return 0;
};
