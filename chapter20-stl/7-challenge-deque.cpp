#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;


bool is_palindrome(const string& candidate) {
    deque<char> deq;
    deque<char> reverse_deq;

    for (char c: candidate)
        if (isalpha(c)) {
            deq.push_back(static_cast<char>(toupper(c)));
            reverse_deq.push_front(static_cast<char>(toupper(c)));
        }

    return equal(deq.begin(), deq.end(), reverse_deq.begin());
};

bool is_palindrome2(const string& candidate) {
    deque<char> deq;

    for (const char c : candidate)
        if (isalpha(c))
            deq.push_back(static_cast<char>(toupper(c)));

    while (deq.size() > 1) {
        char c1 = deq.front();
        char c2 = deq.back();
        if (c1 != c2) return false;
        deq.pop_front();
        deq.pop_back();
    }
    return true;
}

int main() {
    vector<string> tests {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva",
      "Amore, Roma", "A Toyota's a Toyota", "A Santa at NASA", "C++",
      "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome",
    };

    cout << boolalpha;
    for (const string& test : tests)
        cout << "Is palindrome: " << setw(5) << is_palindrome(test) << ", line: " << test << endl;

    cout << setw(100) << setfill('=') << "" << setfill(' ') << endl;

    for (const string& test : tests)
        cout << "Is palindrome: " << setw(5) << is_palindrome2(test) << ", line: " << test << endl;

    return 0;
};
