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
    cout.width(5); // cout << setw(5); requires iomanip
    cout << 1234567 << endl;
    // - cout << setprecision(2) << fixed << scientific;

    // Ch3. Condition
    // - 0<a<1 == false
    // - Short Circuit Evaluation
    // - if not compounded with {} will only execute 1 line
    // - switch statement will not execute default block when break

    // Ch5. Function
    // - Pass by reference uses '&'
    // - default parameters of function should be declared from right side

    // Ch6. Array
    // - declaring array must include size
    int arr[10];
    // - initializing array can skip size
    int arr2[] = {1,2,3};
    // - function parameter must indicate it is array
    // void func(int arr[]) {
    // }
    // - Bubble sort

    // - Binary search

    // - Multi-dimensional array
    int arr3d[][3] = {1,2,3,4,5,6};
    cout << arr3d[0][2] << " " << arr3d[1][2] << endl;
    // - if passing multidimensional array, last size must be given
    // void func(int arr3d[][3]) {
    // }
    return 0;
}
