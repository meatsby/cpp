#include <iostream>

using namespace std;

void Hanoi(int, char, char, char);
void Move(char, char);

int main() {
    return 0;
}

void Hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        Move(a, b);
    } else {
        Hanoi(n - 1, a, c, b);
        Move(a, b);
        Hanoi(n - 1, c, b, a);
    }
}

void Move(char a, char b) {
    cout << "Move from " << a << " to " << b << endl;
}
