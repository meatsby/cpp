#include <iostream>

using namespace std;

int main() {
    int arr2[2][5] = {{1, 2, 3, 4, 5},
                      {1, 2, 3, 4, 5}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr2[i][j] << endl;
        }
    }
    return 0;
}
