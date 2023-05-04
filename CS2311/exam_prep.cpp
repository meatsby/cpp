#include <iostream>
#include <iomanip>

using namespace std;

void chapter2() {
    // all effects are permanent

    // default precision 5 digits after decimal points
    cout << 1.23 << endl;           // 1.23
    cout << 1.230 << endl;          // 1.23
    cout << 1.2345678 << endl;      // 1.23457
    cout << 0.000012345678 << endl; // 1.23457e-05

    // fixed precision 6 digits after decimal points
    cout << fixed;
    cout << 1.23 << endl;           // 1.230000
    cout << 1.230 << endl;          // 1.230000
    cout << 1.2345678 << endl;      // 1.234568
    cout << 0.000012345678 << endl; // 0.000012

    // scientific precision always uses scientific notation
    cout << scientific;
    cout << 1.23 << endl;           // 1.230000e+00
    cout << 1.230 << endl;          // 1.230000e+00
    cout << 1.2345678 << endl;      // 1.234568e+00
    cout << 0.000012345678 << endl; // 1.234568e-05

    // setprecision(n) output n significant digits, requires iomanip
    cout << defaultfloat;
    cout << setprecision(2);
    cout << 1.234 << endl;          // 1.2
    cout << 0.0000001234 << endl;   // 1.2e-07
    // using fixed/scientific with setprecision(n) output 2 digits after decimal point
    cout << fixed;
    cout << 1.234 << endl;          // 1.23
    cout << 0.0000001234 << endl;   // 0.00
    cout << scientific;
    cout << 1.234 << endl;          // 1.23e+00
    cout << 0.0000001234 << endl;   // 1.23e-07
}

void chapter3() {
    int day;
    cin >> day;
    switch (day) { // if day is 6
        case 1:
            cout << "Mon" << endl;
        case 2:
            cout << "Tue" << endl;
        case 3:
            cout << "Wed" << endl;
        case 4:
            cout << "Thur" << endl;
        case 5:
            cout << "Fri" << endl;
        case 6:
            cout << "Sat" << endl;
        case 7:
            cout << "Sun" << endl;
        default:
            cout << "Invalid" << endl;
    }
    // output will be
    // Sat
    // Sun
    // Invalid
}

void chapter6() {
    double a[3] = {1.1, 2.2, 3.3};
    cout << a[0] << " " << ++a[1] << " " << a[2] << endl;
    a[1] = a[2]++;
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
}

int main() {
    chapter6();
    int num;
    if (num = 0) {
        cout << "No" << endl;
    }
    if (num = 3.17) {
        cout << "Yes" << endl;
    }

    bool b = 3.17;
    cout << b << endl;
    return 0;
}
