#include <iostream>

using namespace std;

int main() {
//    int n, m;
//    cout << "Enter inputs: " << endl;
//    cin >> n >> m;
//    cout << n + m << endl;
//    cout << n * m << endl;
//
//    char c1 = 'A';
//    int c2 = '0';
//    cout << c1 << " " << c2 << endl;
//    cout << ++c1 << endl;

    int m = 3, n = 2;
    double k;
    k = m / n;
    cout << k << endl;
    k = m / double(n);
    cout << k << endl;
    k = double(m) / n;
    cout << k << endl;
    k = double(m / n);
    cout << k << endl;
    k = m / 2;
    cout << k << endl;
    k = m / 2.0;
    cout << k << endl;
    return 0;
}
