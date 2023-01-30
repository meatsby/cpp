#include <iostream>
using namespace std;

int main() {
    double vFloat1 = 22.0/7;
    cout << vFloat1 << "\n";

    int i = 5;
    char a = 'b';
    double x = 1.57;
    i = i + x; // 5 + 1.57 -> int + float -> int + int -> 5 + 1 -> 6
    x = x * a; // 1.57 * 'b' -> 1.57 * 98 (ASCII value for 'b' is 98)

    cout << i << "\n";
    cout << x << "\n";
    return 0;
}
