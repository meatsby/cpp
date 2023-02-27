#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int students;
    cout << "Number of students?" << endl;
    cin >> students;

    int scores[20];
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cin >> scores[i];
    }

    int sum = 0;
    for (int i = 0; i < students; i++) {
        sum += scores[i];
    }
    cout << setprecision(2) << fixed;
    cout << "Average = " << (float) sum / students << endl;

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < scores[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
