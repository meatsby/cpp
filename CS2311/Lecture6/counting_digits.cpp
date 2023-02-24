#include <iostream>

using namespace std;

int main() {
    int count[10] = {0};
    int digit;

    do {
        cin >> digit;
        if (digit >= 0 && digit <= 9) {
            count[digit]++;
        }
    } while (digit != -1);

    for (int i = 0; i < 10; i++) {
        cout << "Frequency of " << i << " is " << count[i] << endl;
    }
    return 0;
}
