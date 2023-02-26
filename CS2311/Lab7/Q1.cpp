#include <iostream>

using namespace std;

int main() {
    int num[10] = {5, 10, 2, 5, 8, 8, 7, 9, 1, 5};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
