#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    cout << sum++ << endl;
    double a = 0.5;
    bool b = 0<a && a<1;
    cout << b << endl;
    bool c = 0<a<1;
    cout << c << endl;
    return 0;
}
