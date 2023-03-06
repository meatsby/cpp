#include <iostream>

using namespace std;

bool isVowel(char s);

int main() {
    char s[20];
    cin.getline(s, 20);
    int len = strlen(s);
    int vowelCount = 0;
    for (int i = 0; i < len; i++) {
        if (isVowel(s[i])) {
            vowelCount++;
        }
    }
    cout << "The number of characters is: " << len << endl;
    cout << "The number of vowels is: " << vowelCount << endl;
    return 0;
}

bool isVowel(char s) {
    if (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
        return true;
    }
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
        return true;
    }
    return false;
}
