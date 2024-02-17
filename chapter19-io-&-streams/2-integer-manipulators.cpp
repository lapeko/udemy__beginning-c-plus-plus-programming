#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int num {255};

    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    cout << showbase << "====" << endl;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    cout << uppercase << "====" << endl;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    cout << showpos << "====" << endl;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    cout << resetiosflags(ios::basefield);
    cout << resetiosflags(ios::showbase);
    cout << resetiosflags(ios::showpos);
    cout << resetiosflags(ios::uppercase) << "====" << endl;

    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    return 0;
}