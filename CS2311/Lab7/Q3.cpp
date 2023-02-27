#include <iostream>

using namespace std;

int main() {
    int setA[10], setB[10];
    cout << "Enter 10 Elements of Set A:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> setA[i];
    }
    cout << "Enter 10 Elements of Set B:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> setB[i];
    }

    int intersections[10], idx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (setA[i] == setB[j]) {
                intersections[idx] = setA[i];
                idx++;
            }
        }
    }

    if (idx == 0) {
        cout << "The Intersected Element of Set A and B are not Found.";
        return 0;
    }
    cout << "The Intersected Elements of Set A and B are:" << endl;
    for (int i = 0; i < idx; i++) {
        cout << intersections[i] << " ";
    }
    return 0;
}
