#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter positive integer." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    cout << i - j << " ";
                } else {
                    cout << j - i << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
