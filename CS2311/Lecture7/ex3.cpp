#include <iostream>

using namespace std;

int main() {
    int arr[4][4] = {0};
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            arr[i][j] = arr[i-1][j-1] + i;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
