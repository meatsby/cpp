#include <iostream>

using namespace std;

class Circle {
public:
    float x, y, r;

    Circle() {
        cout << "Input center and radius:\n";
        cin >> x >> y >> r;
    }

    Circle(float x0, float y0, float r0) {
        x = x0;
        y = y0;
        r = r0;
    }
};

int main() {
    Circle *a = new Circle();
    delete a;

    Circle b(0, 0, 1);

    Circle c; // Circle() will be called

    c = Circle(1, 1, 2); // assign new object

    return 0;
}
