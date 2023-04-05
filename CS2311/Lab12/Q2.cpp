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
    int cnt;
    cout << "Enter a number between 1 and 10:" << endl;
    cin >> cnt;

    Triangle arr[10];
    int ord[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < cnt; i++) {
        double a, b, c;
        cout << "Enter the sides of triangle " << i + 1 << ":" << endl;
        cin >> a >> b >> c;
        Triangle *triangle = new Triangle(a, b, c);
        triangle->computeArea();
        arr[i] = *triangle;
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = cnt - 1; j > i; j--) {
            if (arr[j].getArea() < arr[j - 1].getArea()) {
                Triangle tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;

                int n = ord[j];
                ord[j] = ord[j - 1];
                ord[j - 1] = n;
            }
        }
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < cnt; i++) {
        cout << "Area of triangle " << ord[i] << ": " << arr[i].getArea() << endl;
    }
}
