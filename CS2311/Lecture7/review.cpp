#include <iostream>

using namespace std;

int main() {
    // Ch2. Data, Operators, Basic I/O
    // - Identifiers only can start with letter or int
    int CityU_CS;
    // - Overflow and underflow
    int n = 2147483647;
    cout << n + 1 << endl;
    // - Type Conversion
    cout << 3.14 * 2 * 2 << endl; // Implicit
    cout << (int) 3.14 << endl;   // Explicit (Type-casting)
    // - Pre & Post Operators
    int x = 3;
    cout << ++x << endl;
    cout << x++ << endl;
    cout << x << endl;
    // - Bitwise Operators ('&', '|', '^', '~')
    int c = 3 & 5;
    cout << c << endl;
    // - cout.width()
    cout.width(5); // cout << setw(5);
    cout << 1234567 << endl;
    // - cout << setprecision(2) << fixed << scientific;

    // Ch3. Condition
    // - 0<a<1 == false
    // - Short Circuit Evaluation
    // - if not compounded with {} will only execute 1 line
    // - switch statement will not execute default block when break
    return 0;
}
