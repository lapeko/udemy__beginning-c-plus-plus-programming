#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << true << endl;
    cout << false << endl;

    cout << boolalpha;
    cout << true << endl;
    cout << false << endl;

    cout << noboolalpha;
    cout << true << endl;
    cout << false << endl;

    cout.setf(ios::boolalpha);
    cout << true << endl;
    cout << false << endl;

    cout << resetiosflags(ios::boolalpha);
    cout << true << endl;
    cout << false << endl;

    return 0;
}
