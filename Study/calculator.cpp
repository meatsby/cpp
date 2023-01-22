#include <iostream>
#include <string>

using namespace std;

int add(int a, int b);

int sub(int a, int b);

int mul(int a, int b);

int dvd(int a, int b);

int main() {
    int a;
    string sign;
    int b;
    cin >> a >> sign >> b;
    if (sign == "+") {
        cout << add(a, b);
    } else if (sign == "-") {
        cout << sub(a, b);
    } else if (sign == "*") {
        cout << mul(a, b);
    } else if (sign == "/") {
        cout << dvd(a, b);
    }
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int dvd(int a, int b) {
    return a / b;
}
