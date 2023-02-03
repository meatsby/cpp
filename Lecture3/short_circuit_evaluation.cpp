#include <iostream>

using namespace std;

int main() {
    int x = 0;
    bool b = (x == 0 || ++x == 1); // ++x will not be executed
    cout << b << endl;

    x = 0;
    b = (x != 0 && ++x == 1);     // ++x will not be executed
    cout << b << endl;
}
