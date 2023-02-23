#include <iostream>

using namespace std;

const int COOKIE_COST = 1, COUPONS_PER_COOKIE = 7;

int main() {
    int dollars, cookies, coupons;
    cout << "Enter the number of dollars you have to spend: ";
    cin >> dollars;
    cookies = dollars / COOKIE_COST;
    coupons = cookies;

    while (coupons >= COUPONS_PER_COOKIE) {
        int redeemedCookies = coupons / COUPONS_PER_COOKIE;
        int leftoverCoupons = coupons % COUPONS_PER_COOKIE;
        cookies += redeemedCookies;
        coupons = leftoverCoupons + redeemedCookies;
    }

    cout << "You can buy " << cookies << " cookies and have " << coupons << " unused coupon(s)." << endl;
    return 0;
}
