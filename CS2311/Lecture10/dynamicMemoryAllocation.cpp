#include <iostream>

using namespace std;

int main() {
    // Declaration
    int *p0 = new int(10);
    char *p1 = new char('a');

    delete p0; // free the memory pointed by p0
    delete p1; // free the memory pointed by p1

    // *p0 = 10;  // Illegal after deletion

    // Declaration
    int n;
    cin >> n;
    int *ap0 = new int[n];
    char *ap1 = new char[n];

    delete[] ap0; // free the memory pointed by ap0
    delete[] ap1; // free the memory pointed by ap1

    return 0;
}
