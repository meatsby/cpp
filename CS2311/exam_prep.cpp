#include <iostream>

using namespace std;

int main() {
    int temp[10];
    int *ptr = temp;

    cout << temp << endl;
    cout << temp[0] << endl;
    cout << temp[1] << endl;
    cout << &ptr << endl;
}
