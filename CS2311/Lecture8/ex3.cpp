#include <iostream>

using namespace std;

int main() {
    char str[3000];
    cin.getline(str, 3000);
    int start = 0, longest = 0, longest_pos = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            start = i + 1;
        } else {
            if (i - start > longest) {
                longest = i - start;
                longest_pos = start;
            }
        }
    }
    for (int i = longest_pos; i <= longest_pos + longest; i++) {
        cout << str[i];
    }
    return 0;
}
