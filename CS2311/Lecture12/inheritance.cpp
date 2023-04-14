#include <iostream>

using namespace std;

class A {
private:
    int x;
protected:
    int y;
public:
    int z;
};

class B : public A {
public:
    void print() {
        cout << z;
        y = 0;
        // cout << x; not allowed
    }
};

class C : protected A {
public:
    void print() {
        cout << z;
        y = 0;
        // cout << x; not allowed
    }
};

class D : private A {
public:
    void print() {
        cout << z;
        y = 0;
        // cout << x; not allowed
    }
};

int main() {
    B obj1;
    // obj1.x = 0; not allowed
    // obj1.y = 0; not allowed
    obj1.z = 0;
    obj1.print();

    C obj2;
    // obj2.x = 0; not allowed
    // obj2.y = 0; not allowed
    // obj2.z = 0; not allowed
    obj2.print();

    D obj3;
    // obj3.x = 0; not allowed
    // obj3.y = 0; not allowed
    // obj3.z = 0; not allowed
    obj3.print();
    return 0;
}
