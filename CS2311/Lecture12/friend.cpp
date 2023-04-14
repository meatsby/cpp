#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    double s1, s2, s3;
public:
    Triangle() {
        s1 = 0;
        s2 = 0;
        s3 = 0;
    }

    Triangle(double s1, double s2, double s3) : s1(s1), s2(s2), s3(s3) {}

    double getArea() {
        double s = (s1 + s2 + s3) / 2;
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }

    friend bool operator<(Triangle &lhs, Triangle &rhs) {
        return lhs.getArea() < rhs.getArea();
    }

    friend bool operator>(Triangle &lhs, Triangle &rhs) {
        return lhs.getArea() > rhs.getArea();
    }

    friend ostream &operator<<(ostream &outs, Triangle &t) {
        outs << "The sides are: ";
        outs << t.s1 << " " << t.s2 << " " << t.s3 << " ";
        outs << "The area is: ";
        outs << t.getArea() << endl;
        return outs;
    }
};

int main() {
    Triangle t1(3, 4, 5);
    Triangle t2(5, 6, 7);
    cout << t1;
    cout << t2;
    if (t1 < t2) {
        cout << "t1 is smaller" << endl;
    } else {
        cout << "t2 is smaller" << endl;
    }
    return 0;
}
