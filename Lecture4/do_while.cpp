#include <iostream>

using namespace std;

int main() {
    int x = 10;
    do {
        cout << x << endl;
        x -= 3;
    } while (x > 0);
    return 0;
}
