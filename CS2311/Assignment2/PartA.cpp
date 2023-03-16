#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    char str[256];
    cout << "Enter Header:" << endl;
    cin.getline(str, 256);

    char c;
    cout << "Character?";
    cin.get(c);

    int comb[7] = {1, 3, 7, 15, 31, 63, 127};
    int idx = 0, len = strlen(str);
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j <= comb[i] && idx < len; j++, idx++) {
            if (str[idx] == c) {
                int temp = j;
                int binary = 0;
                for (int k = 1; temp > 0; k *= 10) {
                    binary += (temp % 2) * k;
                    temp /= 2;
                }
                cout << setfill('0') << setw(i + 1) << binary << endl;
            }
        }
    }
    for (int i = 247; i < 256 && idx < len; i++) {
        if (str[idx] == c) {
            cout << "1111111" << endl;
        }
    }
    return 0;
}
