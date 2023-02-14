#include <iostream>

using namespace std;

int main() {
//    int x = 0;
//    bool b = (x == 0 || ++x == 1); // ++x will not be executed
//    cout << b << endl;
//
//    x = 0;
//    b = (x != 0 && ++x == 1);     // ++x will not be executed
//    cout << b << endl;

    int count = 0, limit = 10, x, y;
    bool a = (count == 0) && (limit < 20);
    cout << a << endl;
    bool b = count == 0 && limit < 20;
    cout << b << endl;
    bool c = (limit > 20)  || (count < 5);
    cout << c << endl;
    bool d = !(count == 12);
    cout << d << endl;
    bool e = (count == 1) && (x < y);
    cout << e << endl;
    bool f = (count < 10) || (x < y);
    cout << f << endl;
    bool g = !(((count < 10) || (x < y)) && (count >= 0));
    cout << g << endl;
    bool h = ((limit / count) > 7) || (limit < 20);
    cout << h << endl;
    bool i = (limit < 20) || ((limit / count) > 7);
    cout << i << endl;
    bool j = ((limit / count) > 7) && (limit < 0);
    cout << j << endl;
    bool k = (limit < 0) && ((limit / count) > 7);
    cout << k << endl;
    bool l = (5 && 7) + (!6);
    cout << l << endl;
}
