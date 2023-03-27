#include <iostream>

using namespace std;

int main() {
    int v = 5, *ptr;
    ptr = &v;
    *ptr = 42;
    cout << "v=" << v << endl; // 42
    cin >> *ptr;   //Let's enter 100
    //What happens if you write cin >> ptr; ?
    cout << "v=" << v << endl; // 100
    v = 7;
    cout << "*ptr is " << *ptr << endl; // 7
    cout << "Address of v is " << ptr << endl;
    return 0;
}
