#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    char str[257];
    cout << "Enter Header:" << endl;
    cin.getline(str, 257);

    int keys[257][7];

    // Handle Headers with length ~ 247
    int comb[7] = {1, 3, 7, 15, 31, 63, 127};
    int idx = 0, len = strlen(str);
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j <= comb[i] && idx < len; j++, idx++) {
            int temp = j;
            int binary = 0;
            for (int k = 1; temp > 0; k *= 10) {
                binary += (temp % 2) * k;
                temp /= 2;
            }
            for (int k = 6; k >= 0; k--) {
                keys[idx][k] = binary % 10;
                binary /= 10;
            }
            for (int k = 0; k < 7; k++) {
                cout << keys[idx][k];
            }
            cout << endl;
        }
    }

    return 0;
}
