#include <iostream>

using namespace std;

int main() {
    int x = 2;
    int *xPtr = &x;
    cout << *xPtr << endl; // 2
    cout << xPtr << endl;  // 0x16d29b2f8
    cout << &x << endl;    // 0x16d29b2f8
    return 0;
}
