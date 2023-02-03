#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a = 1, b = 0;
    b = 1.8 + (a++);
    cout << b << endl;
    cout << a << endl;

    b += ++a;
    cout << setprecision(1);
    cout << scientific << (double) b << endl;
    cout << a << endl;
}
