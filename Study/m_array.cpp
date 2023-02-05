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


    int arr3[2][2][2] = {{{1, 2},
                                 {1, 2}},
                         {{1, 2},
                                 {1, 2}}};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                cout << arr3[i][j][k] << endl;
            }
        }
    }
    return 0;
}
