#include <iostream>

using namespace std;

// Function prototypes
void print1to9(int n);
void print10to19(int n);

int main() {
    int num;
    cout << "Enter a number in Range [1--19].\n";
    cin >> num;
    if (num >= 1 && num <= 9) {
        print1to9(num);
    } else if (10 <= num && num <= 19) {
        print10to19(num);
    } else {
        cout << num << " is not in range from 1 to 19";
    }
    return 0;
}

void print1to9(int n) {
// the function is not 100% correct, you'll need to debug!
// hint: what's the output if user input is 4 ?
    switch (n) {
        case 1:
            cout << "One";
            break;
        case 2:
            cout << "Two";
            break;
        case 3:
            cout << "Three";
            break;
        case 4:
            cout << "Four";
            break;
        case 5:
            cout << "Five";
            break;
            // add your logic here to handle 6..9
        case 6:
            cout << "Six";
            break;
        case 7:
            cout << "Seven";
            break;
        case 8:
            cout << "Eight";
            break;
        case 9:
            cout << "Nine";
            break;
    }
}

void print10to19(int n) {
    // complete the function print10to19
    switch (n) {
        case 10:
            cout << "Ten";
            break;
        case 11:
            cout << "Eleven";
            break;
        case 12:
            cout << "Twelve";
            break;
        case 13:
            cout << "Thirteen";
            break;
        case 14:
            cout << "Fourteen";
            break;
        case 15:
            cout << "Fifteen";
            break;
        case 16:
            cout << "Sixteen";
            break;
        case 17:
            cout << "Seventeen";
            break;
        case 18:
            cout << "Eighteen";
            break;
        case 19:
            cout << "Nineteen";
            break;
    }
}
