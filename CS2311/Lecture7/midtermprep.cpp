#include <iostream>

void printParkFee(double hours);

using namespace std;

int main() {
    // 1.1.
    int sum = 0;
    cout << sum++ << endl;

    // 1.2.
    double a = 0.5;
    bool b = 0<a && a<1;
    cout << b << endl;
    bool c = 0<a<1;
    cout << c << endl;

    // 2.
    int i = 1;
    while (i <= 15) {
        i++;
        if (i%3 != 2) continue;
        else cout << "i=" << i << endl;
    }
    // i=2, 5, 8, 11, 14

    // 3.
    int num, ret;
    cout << "Let us start.\n";
    cin >> num;
    if (num % 2 == 1)
        ret = num/2;
    else
        ret = 1;
    cout << "ret=" << ret << endl;

    // 4.
    double hours;
    cout << "Enter hours: ";
    cin >> hours;
    if (hours <= 0)
        cout << "Invalid input!" << endl;
    else
        printParkFee(hours);
    return 0;
}

void printParkFee(double hours) {
    int fee;
    double min = hours * 60 - 1;
    if (min <= 0) {
        fee = 0;
    } else if (min <= 120) {
        fee = ((int) (min / 60) + 1) * 50;
    } else if (min <= 300) {
        fee = 100 + ((int) ((min - 120) / 30) + 1) * 20;
    } else {
        fee = 220 + ((int) ((min - 300) / 30) + 1) * 40;
    }
    cout << "$" << fee << endl;
}
