#include <iostream>

using namespace std;

int main() {
    cout << "Enter an Integer Number: ";
    int input;
    cin >> input;
    if (input % 3 == 0 && input % 5 == 0) {
        cout << input << " is divisible by 3 and 5";
    } else if (input % 3 == 0) {
        cout << input << " is divisible by 3 only";
    } else if (input % 5 == 0) {
        cout << input << " is divisible by 5 only";
    } else {
        cout << input << " is not divisible by 3 or 5";
    }
    return 0;
}
