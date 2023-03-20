#include <iostream>
#include <iomanip>

using namespace std;

void getInput(double &x, double &y) {
    cout << "Please enter two values: ";
    cin >> x >> y;
}

double toResistance(double x, double y) {
    return x / y;
}

void swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

int main() {
    double x, y;
    getInput(x, y);
    cout << fixed << setprecision(2);
    cout << "The value of one resistance is " << toResistance(x, y) << endl;
    swap(x, y);
    cout << "The value of the other resistance is " << toResistance(x, y) << endl;
    return 0;
}
