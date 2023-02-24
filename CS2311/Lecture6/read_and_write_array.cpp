#include <iostream>

#define N 10

using namespace std;

int main() {
    int marks[N], sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> marks[i];
    }
    cout << "The mark of the students are: ";
    for (int i = 0; i < N; i++) {
        cout << marks[i];
        sum += marks[i];
    }
    cout << "Average mark = " << (float) sum / N << endl;
    return 0;
}
