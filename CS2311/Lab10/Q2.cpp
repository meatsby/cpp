#include <iostream>

using namespace std;

int stringCompare(char s1[], char s2[]);

int main() {
    char s1[21], s2[21];
    cout << "Enter the first string:" << endl;
    cin.getline(s1, 21);
    cout << "Enter the second string:" << endl;
    cin.getline(s2, 21);

    int comp = stringCompare(s1, s2);
    if (comp > 0) {
        cout << "The first string is larger." << endl;
    } else if (comp < 0) {
        cout << "The second string is larger." << endl;
    } else {
        cout << "The two strings are equal." << endl;
    }
    return 0;
}

int stringCompare(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
    }
    return 0;
}
