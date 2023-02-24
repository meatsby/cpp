#include <iostream>

using namespace std;

int main() {
    int array1[5] = {10, 5, 3, 5, 1};
    int array2[5];
    cout << "input 5 elements to array2" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> array2[i];
    }
    bool arrayEqual = true;
    for (int i = 0; i < 5 && arrayEqual; i++) {
        if (array1[i] != array2[i]) {
            arrayEqual = false;
        }
    }
    if (arrayEqual) {
        cout << "The arrays are equal" << endl;
    } else {
        cout << "The arrays are not equal" << endl;
    }
    return 0;
}
