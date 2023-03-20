#include <iostream>

using namespace std;

int main() {
    int A, B;
    cout << "Enter value of A: ";
    cin >> A;
    cout << "Enter value of B: ";
    cin >> B;

    int *ptrA = &A, *ptrB = &B;
    cout << "Value of ptrA is " << A << " stored in address " << hex << ptrA << endl;
    cout << dec << "Value of ptrB is " << B << " stored in address " << hex << ptrB << endl;
    return 0;
}
