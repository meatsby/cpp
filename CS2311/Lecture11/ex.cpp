#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> *arr;
        arr++;
    }

    for (int i = 0; i < n; i++) {
        arr--;
        cout << *arr << " ";
    }

    return 0;
}
