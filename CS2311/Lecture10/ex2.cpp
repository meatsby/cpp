#include <iostream>

using namespace std;

int main() {
    int x = 20, y = 30;
    int *p = &x;
    int *q = &y;
    cout << *p << " " << *q << endl;
    for (int i = 0; i < 2; i++)
        *p += *q + 3;
    cout << *p << " " << *q << endl;
    cout << x << " " << y << endl;
    return 0;
}
