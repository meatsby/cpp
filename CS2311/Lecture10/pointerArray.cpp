#include <iostream>

using namespace std;

int main() {
    int a[6] = {0, 1, 2, 3, 4, 5};
    int *m[2] = {&a[0], &a[3]};
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            cout << m[row][col] << " ";
        cout << "\n";
    }
    return 0;
}
