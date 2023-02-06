#include <iostream>

using namespace std;

int main() {
    double a, b;
    char op;
    cout << "Enter the equation: ";
    cin >> a >> op >> b;

    if (cin.fail()) {
        cout << "Invalid input.";
        return 0;
    }

    switch (op) {
        case '+':
            cout << a << op << b << "=" << a + b;
            break;
        case '-':
            cout << a << op << b << "=" << a - b;
            break;
        case '*':
            cout << a << op << b << "=" << a * b;
            break;
        case '/':
            cout << a << op << b << "=" << a / b;
            break;
        case '<':
            if (a < b) {
                cout << a << op << b << "=" << 'T';
                break;
            }
            cout << a << op << b << "=" << 'F';
            break;
        case '>':
            if (a > b) {
                cout << a << op << b << "=" << 'T';
                break;
            }
            cout << a << op << b << "=" << 'F';
            break;
        case '=':
            if (a == b) {
                cout << "(" << a << "==" << b << ")" << "=" << 'T';
                break;
            }
            cout << "(" << a << "==" << b << ")" << "=" << 'F';
            break;
        default: cout << "Invalid operation.";
    }
    return 0;
}
