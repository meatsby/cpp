#include <iostream>

using namespace std;

int main() {
    int maxEdge, minEdge, answer = 0;
    cout << "Please input the maximal length allowed for the edge: ";
    cin >> maxEdge;
    cout << "Please input the minimal length allowed for the edge: ";
    cin >> minEdge;

    if (cin.fail() || maxEdge <= minEdge || maxEdge < 1 || minEdge < 1) {
        cout << "Invalid inputs!";
        return 0;
    }

    for (int i = minEdge; i <= maxEdge; i++) {
        for (int j = i; j <= maxEdge; j++) {
            for (int k = j; k <= maxEdge; k++) {
                if ((i * i) + (j * j) == k * k) {
                    answer++;
                }
            }
        }
    }
    cout << "The number of all Pythagorean triplets between " << minEdge << " and " << maxEdge << " is " << answer << ".";
    return 0;
}
