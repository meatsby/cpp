#include <iostream>
using namespace std;
int main() {
    short a = 3, b = 5, c;
    c = a & b;
    cout << c << endl; // 1
    c = a | b;
    cout << c << endl; // 7
    c = a ^ b;
    cout << c << endl; // 6
    char t = 254;
    c = ~t;
    cout << c << endl; // 1

    char x = 6;
    int i = (x >> 1) & 1; // 1
    cout << i << endl;
    int j = (x >> 3) & 1; // 0
    cout << j << endl;
    return 0;
}
