#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= i * m; j += i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
