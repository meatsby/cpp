#include <iostream>
using namespace std;

int main() {
    double vFloat1 = 22.0/7;
    cout << vFloat1 << "\n";

    int i = 5;
    char a = 'b';
    double x = 1.57;
    i = i + x; // i + x will result 6.57 due to binary expression but will be demoted to int type because of assignment
    x = x * a; // char a will be promoted to double. 1.57 * 'b' -> 1.57 * 98 (ASCII value for 'b' is 98)

    cout << i << "\n";
    cout << x << "\n";
    return 0;
}
