#include <iostream>

using namespace std;

char *deleteStr(char *str, char delete_char) {
    char *ans = new char[100];
    char *ptr = ans;
    while (*str != '\0') {
        if (*str == delete_char) {
            str++;
            continue;
        }
        *ans = *str;
        ans++;
        str++;
    }
    *ans = '\0';
    return ptr;
}

int main() {
    char *str = new char[100];
    cout << "Enter the input string: " << endl;
    cin.getline(str, 100);

    char c;
    cout << "Enter the input delete_char: " << endl;
    cin.get(c);

    char *ans = deleteStr(str, c);
    cout << "The modified string is: " << ans << endl;
}
