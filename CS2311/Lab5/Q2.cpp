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

    for (int r = 0; r < maxEdge; r += 2) {
        int r2 = r * r / 2;
        for (int s = 1; s * s <= r2; s++) {
            if (r2 % s == 0 && minEdge <= r + s && (r + s + r2 / s) <= maxEdge) {
                answer++;
            }
        }
    }
    cout << "The number of all Pythagorean triplets between " << minEdge << " and " << maxEdge << " is " << answer
         << ".";
    return 0;
}
