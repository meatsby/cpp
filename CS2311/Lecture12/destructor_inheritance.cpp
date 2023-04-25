#include <iostream>

using namespace std;

class A {
public:
    ~A() { cout << "A's destructor\n"; }
};

class B : public A {
public:
    ~B() { cout << "B's destructor\n"; }
};

int main() {
    B *b = new B();
    delete b;
    return 0;
    // Output:
    // "B's destructor"
    // "A's destructor"
}
