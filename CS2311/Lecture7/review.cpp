#include <iostream>

int calc(int a[]);

using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 4, 4, 4, 3, 2, 1, 0};
    int newcnt = calc(a);
    for (int i = 0; i < newcnt; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

int calc(int a[]) {
    double temp[] = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (a[i] == a[j]) {
                bool isin = false;
                for (int k = 0; k < 10; k++) {
                    if (a[i] == temp[k]) {
                        isin = true;
                        break;
                    }
                }
                if (!isin) {
                    temp[cnt] = a[i];
                    cnt++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        a[i] = temp[i];
        cout << a[i] << " ";
    }
    cout << endl;
    return cnt;
}
