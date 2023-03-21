#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[257];
    cout << "Enter Header:" << endl;
    cin.getline(str, 257);

    char keys[257][8];

    int comb[7] = {1, 3, 7, 15, 31, 63, 127};
    int idx = 0, len = strlen(str);
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j <= comb[i] && idx < len; j++, idx++) {
            // generate binary
            int temp = j;
            int binary = 0;
            for (int k = 1; temp > 0; k *= 10) {
                binary += (temp % 2) * k;
                temp /= 2;
            }

            // store string
            for (int k = i; k >= 0; k--) {
                keys[idx][k] = char(binary % 10 + 48);
                binary /= 10;
            }
            keys[idx][i + 1] = '\0';
        }
    }

    char code[1025];
    cout << "Enter code:" << endl;
    cin.getline(code, 1025);

    bool first = true;
    unsigned int length, i = 0, clen = strlen(code);
    while (i < clen) {
        // get length
        if (first) {
            length = (int(code[i]) - 48) * 4 + (int(code[i + 1]) - 48) * 2 + (int(code[i + 2]) - 48);
            if (length == 0) {
                break;
            }
            i += 3;
            first = false;
        }

        // read segment
        char key[8];
        bool isEnd = true;
        for (int k = 0; k < length; i++, k++) {
            if (code[i] == '1') {
                isEnd = false;
            }
            key[k] = code[i];
        }
        key[length] = '\0';

        // check if end
        if (isEnd) {
            first = true;
            continue;
        }

        // find corresponding header
        for (int ki = 0; ki < 257; ki++) {
            if (strcmp(key, keys[ki]) == 0) {
                cout << str[ki];
                break;
            }
        }
    }

    return 0;
}
