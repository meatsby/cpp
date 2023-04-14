#include <iostream>

using namespace std;

class Circle {
private:
    int radius;
public:
    Circle(int radius) : radius(radius) {};

    bool operator<(Circle &rhs) {
        if (radius < rhs.radius) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Circle a(3);
    Circle b(5);
    cout << (a < b);
    return 0;
}
