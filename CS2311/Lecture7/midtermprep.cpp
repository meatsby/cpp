#include <iostream>

using namespace std;

int main() {
    // 1.1.
    int sum = 0;
    cout << sum++ << endl;

    // 1.2.
    double a = 0.5;
    bool b = 0<a && a<1;
    cout << b << endl;
    bool c = 0<a<1;
    cout << c << endl;

    // 2.
    int i = 1;
    while (i <= 15) {
        i++;
        if (i%3 != 2) continue;
        else cout << "i=" << i << endl;
    }
    // i=2, 5, 8, 11, 14

    // 3.
    int num, ret;
    cout << "Let us start.\n";
    cin >> num;
    if (num % 2 == 1)
        ret = num/2;
    else
        ret = 1;
    cout << "ret=" << ret << endl;

    return 0;
}
