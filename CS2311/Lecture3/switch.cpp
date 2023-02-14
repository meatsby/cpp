#include <iostream>

using namespace std;

int main() {
    int day;
    cin >> day;
    switch (day) {
        case 1: cout << "Mon" << endl;
        case 2: cout << "Tue" << endl;
        case 3: cout << "Wed" << endl;
        case 4: cout << "Thur" << endl;
        case 5: cout << "Fri" << endl;
        case 6: cout << "Sat" << endl;
        case 7: cout << "Sun" << endl;
        default: cout << "Invalid" << endl;
    }
}
