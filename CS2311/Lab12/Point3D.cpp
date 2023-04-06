#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point3D {
private:
    double x;
    double y;
    double z;
public:
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    //set (mutator) functions
    void setX(double x);

    void setY(double y);

    void setZ(double z);

    //get (accessor) functions
    double getX();

    double getY();

    double getZ();

    //overridden function, returns the distance from point (0,0,0)
    double calDistance();

    //friend function to overload the operator << for cout
    //complete the function declaration with two parameters (ostream& output, Point3D& point)
    friend void print(ostream &output, Point3D &point);
};

void Point3D::setX(double x) {
    this->x = x;
}

void Point3D::setY(double y) {
    this->y = y;
}

void Point3D::setZ(double z) {
    this->z = z;
}

double Point3D::getX() {
    return x;
}

double Point3D::getY() {
    return y;
}

double Point3D::getZ() {
    return z;
}

// complete this function
double Point3D::calDistance() {
    return sqrt(x * x + y * y + z * z);
}

// complete the function definition with two parameters (ostream & output, Point3D & point)
/* This function should print in accord with the format as follows 
This point is: (..., ..., ...)
The distance from (0, 0, 0) is ...
*/
void print(ostream &output, Point3D &point) {
    output << fixed << setprecision(2);
    output << "This point is: (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
    output << "The distance from (0, 0, 0) is " << point.calDistance() << endl;
}


int main() {
    double x, y, z;
    cout << "Enter a 3D point's x, y, and z coordinates in order:" << endl;
    cin >> x >> y >> z;
    Point3D *point3D = new Point3D(x, y, z);
    print(cout, *point3D);
    return 0;
}
