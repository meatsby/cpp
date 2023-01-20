#include <iostream>

using namespace std;
int a = 0;
namespace level1 {
    int a = 1;
    namespace level2 {
        int a = 2;
    }
}

int main() {
    cout << a << endl;
    cout << level1::a << endl;
    cout << level1::level2::a << endl;
    return 0;
}
