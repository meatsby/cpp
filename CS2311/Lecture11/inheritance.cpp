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

int main() {
    B obj;
    // obj.x = 0; not allowed
    // obj.y = 0; not allowed
    obj.z = 0;
    obj.print();
    return 0;
}
