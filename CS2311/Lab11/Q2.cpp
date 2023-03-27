#include <iostream>

using namespace std;

void countWord(char *arr, int *count) {
    char *rPtr = arr - 1;
    for (; *arr != '\0'; arr++) {
        if (*(arr + 1) == ' ' || *(arr + 1) == '\0') {
            (*count)++;
            cout << "Word " << *count << " has " << arr - rPtr << " characters." << endl;
            rPtr = arr + 1;
        }
    }
    cout << "The number of words in the string is: " << *count << endl;
}

int main() {
    cout << "Enter the content of the string:" << endl;

    char str[100];
    int count = 0;
    cin.getline(str, 100);

    countWord(str, &count);
}
