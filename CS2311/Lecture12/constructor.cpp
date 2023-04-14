#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A's default constructor" << endl;
    }
    A(int a) {
        cout << "A's non-default constructor" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "calling A(2311) in B()" << endl;
        A(2311);
        cout << "calling A() in B()" << endl;
        A();
        cout << "B's constructor" << endl;
    }
};

int main() {
    B b;
    // Output:
    // "A's default constructor"
    // "calling A(2311) in B()"
    // "A's non-default constructor"
    // "calling A() in B()"
    // "A's default constructor"
    // "B's constructor"
}
