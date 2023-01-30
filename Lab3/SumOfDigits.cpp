#include <iostream>

int sumOfDigits(int input);

int sumOfSquareOfDigits(int input);

using namespace std;

int main() {
    cout << "Please Enter a number of Three Digits:" << endl;
    int input;
    cin >> input;
    cout << "Sum of Digits is:" << endl << sumOfDigits(input) << endl;
    cout << "Sum of Square of Digits is:" << endl << sumOfSquareOfDigits(input) << endl;
    return 0;
}

int sumOfDigits(int input) {
    return input / 100 + input % 100 / 10 + input % 10;
}

int sumOfSquareOfDigits(int input) {
    int a = input / 100;
    int b = input % 100 / 10;
    int c = input % 10;
    return a * a + b * b + c * c;
}
