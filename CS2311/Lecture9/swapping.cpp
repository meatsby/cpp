#include <iostream>

using namespace std;

void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main() {
    int a = 3, b = 7;
    swap(&a, &b);
    cout << a << " " << b << endl; // 7 3
    return 0;
}
