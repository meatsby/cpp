#include <iostream>

using namespace std;

int main() {
    int a[6] = {0, 1, 2, 3, 4, 5};
    int *pa = &a[1];
    cout << hex << pa << endl;   // 0x16dda72c4
    cout << hex << ++pa << endl; // 0x16dda72c8
    cout << &a[5] - pa << endl;  // 3, distance between a[5] and a[2]

    long b[6] = {5, 4, 3, 2, 1, 0};
    long *pb = &b[1];
    cout << hex << pb << endl;   // 0x16dda7298
    cout << hex << ++pb << endl; // 0x16dda72a0
    cout << &b[4] - pb << endl;  // 2, distance between b[4] and b[2]

    char str[] = "Hello World";
    char *p = str;
    cout << p + 5 << endl;       //  World
    cout << &str[5] << endl;     //  World
    cout << str[2] << endl;      // l
    cout << *(p + 2) << endl;    // l
    return 0;
}
