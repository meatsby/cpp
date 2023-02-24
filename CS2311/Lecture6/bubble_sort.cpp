#include <iostream>

using namespace std;

int main() {
    const int n = 6;
    int a[n] = {23, 78, 45, 8, 32, 56};
    int j, k, tmp;
    bool sorted = false;

    for (j = 0; j < n - 1 && !sorted; j++) {
        cout << j;
        sorted = true;
        for (k = n - 1; k > j; k--) { // bubbling
            if (a[k] < a[k - 1]) {
                tmp = a[k];
                a[k] = a[k - 1];
                a[k - 1] = tmp;
                sorted = false;
            }
        }
    }
    cout << "sorted: ";
    for (j = 0; j < n; j++) {
        cout << a[j] << ' ';
    }
    cout << "\n";
    return 0;
}
