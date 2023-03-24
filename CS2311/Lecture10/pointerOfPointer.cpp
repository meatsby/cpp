#include <iostream>

using namespace std;

void skipSpaces(char *p) {
    while (*p == ' ')
        p++;
    cout << "Address: " << &p << " | Result: " << p << endl;
}

void skipSpaces(char **p) {
    while (**p == ' ')
        (*p)++;
    cout << "Address: " << &(*p) << " | Result: " << *p << endl;
}

int main() {
    char str[] = "    hello";
    char *p = str;
    skipSpaces(p);     // Address: 0x16ce23288 | Result: hello
    cout << p << endl; // Address: 0x16ce232c8 | Result:     hello
    skipSpaces(&p);    // Address: 0x16ce232c8 | Result: hello
    cout << p << endl; // Address: 0x16ce232c8 | Result: hello
    return 0;
}
