#include <iostream>
using namespace std;
int main() {
    // Integer
    int x, y;
    cin >> x;               // input 21
    cout << x << endl;      // x=21
    cin >> x >> y;          // input 5 3
    cout << x << y << endl; // x=5, y=3

    // Float
    float a, b;
    cin >> a;               // input 14.5
    cout << a << endl;      // a=14.5

    // Character
    char c, d;
    cin >> c;               // input Hi
    cout << c << endl;      // c=H
    cin >> c >> d;          // input Hi
    cout << c << d << endl; // c=H, d=i

    // String
    char i[20];
    char j[20];
    cin >> i;               // input hello
    cout << i << endl;      // i=hello
    cin >> i >> j;          // input Hello World
    cout << i << j << endl; // i=Hello, j=World
    return 0;
}
