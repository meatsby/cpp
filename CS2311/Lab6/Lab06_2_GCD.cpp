#include<iostream>

using namespace std;
const int LEN = 5;

// TODO 1: Complete the function declaration of GCD(), takes 2 interger as parameter.
int GCD(int a, int b) {
    // TODO 2: Complete the function implementation, return the GCD of 2 given number
    for (int i = a > b ? b : a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

int main() {
    int num0, num1, num2, num3, num4;
    int answer;
    cout << "Enter " << LEN << " numbers:" << endl;
    cin >> num0 >> num1 >> num2 >> num3 >> num4;


    cout << "GCD:" << endl;
    // TODO 3: Get the GCD of all input numbers.
    answer = GCD(num0, num1);
    answer = GCD(answer, num2);
    answer = GCD(answer, num3);
    answer = GCD(answer, num4);
    cout << answer << endl;
    return 0;
}
