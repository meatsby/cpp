#include <iostream>

using namespace std;

void foo(int (*x)[3]) {
    cout << *(*(x + 1) + 2) << endl; // p[1][2]
    cout << *(x[2] + 1) << endl;     // p[2][1]
}

int main() {
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    foo(arr);

    int (*x)[3] = arr;
    cout << *(*(x + 1) + 2) << endl; // p[1][2]
    cout << *(x[2] + 1) << endl;     // p[2][1]
    return 0;
}
