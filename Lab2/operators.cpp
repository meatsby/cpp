#include <iostream>

using namespace std;
int main() {
    int k = 1;
    int a = k++; // a = 1, k = 2
    int b = ++k; // b = 3, k = 3;
    cout << k << endl; // 3
    cout << a << endl; // 1
    cout << b << endl; // 3
    return 0;
}
