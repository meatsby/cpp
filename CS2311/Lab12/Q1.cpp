#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Triangle {
private:
    double side1, side2, side3, area;
public:
    Triangle() {

    }

    Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}

    void setSides(double side1, double side2, double side3) {
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }

    void computeArea() {
        double s = (side1 + side2 + side3) / 2;
        this->area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double getArea() {
        return area;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Triangle *triangle1 = new Triangle();
    triangle1->computeArea();
    cout << "Area of triangle1: " << triangle1->getArea() << endl;

    Triangle *triangle2 = new Triangle(3, 4, 5);
    triangle2->computeArea();
    cout << "Area of triangle2: " << triangle2->getArea() << endl;

    double a, b, c;
    cout << "Enter new sides for triangle1:" << endl;
    cin >> a >> b >> c;
    triangle1->setSides(a, b, c);
    triangle1->computeArea();
    cout << "Area of triangle1: " << triangle1->getArea() << endl;

    delete triangle1;
    delete triangle2;
}
