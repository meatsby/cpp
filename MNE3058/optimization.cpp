#include <iostream>

using namespace std;

int main() {
    int a, b;
    a = (b - 1) * 3;

    // Use instead
    a = (b - 1);
    a = a + a + a;

    return 0;
}
