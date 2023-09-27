#include <iostream>
#include <string>
using namespace std;

int main() {
    string alphabet {"ABCDEFGHIJKLMNOPQASTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    string key      {"ToHkvwdNURzGpsObmhVXLPgeQDqaiExyYCnFWtcfJZlIMKSjuBAr"};
    
    string secret_massage;
    cout << "Enter your secret message: ";
    getline(cin, secret_massage);
    
    cout << endl << "Encrypring..." << endl;
    
    for (size_t i {secret_massage.size() - 1}; i + 1 != 0; i--) {
        int index = alphabet.find(secret_massage[i]);
        if (index == -1) continue;
        secret_massage[i] = key[index];
    }
    
    cout << "Encrypted message: " << secret_massage << endl;
    
    cout << "Decrypting..." << endl;
    
    for (size_t i {secret_massage.size() - 1}; i + 1 != 0; i--) {
        int index = key.find(secret_massage[i]);
        if (index == -1) continue;
        secret_massage[i] = alphabet[index];
    }
        
    cout << "Decrypted message: " << secret_massage << endl;
}