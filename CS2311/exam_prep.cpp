#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

void chapter2() {
    // overflow
    int n1 = 2147483647;
    int n2 = n1 + 1;
    cout << n2 << endl;

    // type conversion
    int i = 5;
    char a = 'a';
    double x = 1.57;
    i = i + x;
    cout << i << endl;
    x = x * a;
    cout << x << endl;

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
    int num;
    if (num = 0) {
        cout << "No" << endl;
    }
    if (num = 3.17) {
        cout << "Yes" << endl;
    }

    bool b = 3.17;
    cout << b << endl;

    int day = 6;
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

    // bubble sort
    int nums[] = {23, 78, 45, 8, 32, 56};
    for (int i = 0; i < 5; i++) {
        for (int j = 5; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }

    for (int k = 0; k < 6; k++) {
        cout << nums[k] << " ";
    }
    cout << endl;

    // binary search
    int first = 0, last = 5, target = 56;
    while (target >= nums[first] && target <= nums[last]) {
        int mid = (first + last) / 2;
        if (target == nums[mid]) {
            cout << mid;
            break;
        } else if (target > nums[mid]) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
}

void chapter7() {
    char str[9];
    strcpy(str, "Hi Earth");
    str[2] = '\0';
    cout << str << " " << strlen(str);
    // Hi 2
}

void chapter9() {
    int x = 2;
    int *xPtr = &x;        // * used as pointer type
    cout << &xPtr << endl; // 0x16d29b2f0
    cout << &x << endl;    // 0x16d29b2f8
    cout << xPtr << endl;  // 0x16d29b2f8
    cout << *xPtr << endl; // * used as dereference operator which prints 2

    char str[] = "Hello World", *ptr = &str[0];
    int arr[] = {1, 2, 3, 4, 5, 6}, *ptr2 = &arr[0];

    cout << setw(11) << ptr << " " << ptr2 << endl;   // Hello World 0x16b9eb210
    cout << setw(11) << *ptr << " " << *ptr2 << endl; //           H 1
    cout << setw(11) << &ptr << " " << &ptr2 << endl; // 0x16b9eb200 0x16b9eb1f8
    ptr = &str[6], ptr2 = &arr[1];
    cout << setw(11) << ptr << " " << ptr2 << endl;   //       World 0x16b9eb214
}

void func(int &, int, int);

int main() {
    return 0;
}
