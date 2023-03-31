#include <iostream>

#define M_PI 3.14

using namespace std;

class Circle {
public:
    float x, y, r;

    void setCenter() {
        cout << "Input center:" << endl;
        cin >> x >> y;
    }

    void setRadius() {
        cout << "Input radius:" << endl;
        cin >> r;
    }

    bool isWithin(float x0, float y0);

    float perimeter();

    float area();
};

bool Circle::isWithin(float x0, float y0) {
    return (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y) < r * r;
}

float Circle::perimeter() {
    return 2 * M_PI * r;
}

float Circle::area() {
    return M_PI * r * r;
}

int main() {
    Circle a;
    a.setCenter();
    a.setRadius();
    cout << "The perimeter of circle a is " << a.perimeter() << endl;

    Circle *b = new Circle();
    b->setCenter();
    b->setRadius();
    cout << "The area of circle b is " << b->area() << endl;
    delete b;

    return 0;
}
