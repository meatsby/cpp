#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int payment_method = 0;

    for (int ones = 0; ones <= a; ones++) {
        for (int threes = 0; threes <= b * 3; threes += 3) {
            for (int fives = 0; fives <= c * 5; fives += 5) {
                for (int tens = 0; tens <= d * 10; tens += 10) {
                    int total = ones + threes + fives + tens;

                    if (total == n) {
                        payment_method++;
                    }
                }
            }
        }
    }

    if (payment_method > 0) {
        cout << payment_method << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}
