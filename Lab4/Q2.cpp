#include <iostream>

using namespace std;

int main() {
    int cur_year, cur_month, cur_age, birth_month, year, month;

    cout << "Enter the current year:" << endl;
    cin >> cur_year;

    cout << "Enter the current month:" << endl;
    cin >> cur_month;
    if (1 > cur_month || cur_month > 12) {
        cout << "Invalid Month Input!";
        return 0;
    }

    cout << "Enter your current age in years:" << endl;
    cin >> cur_age;
    if (cur_age < 0) {
        cout << "The value for age cannot be a negative integer!";
        return 0;
    }
    if (cur_age > 200) {
        cout << "Sorry, people may be dead by this age!";
        return 0;
    }

    cout << "Enter the month in which you were born:" << endl;
    cin >> birth_month;
    if (1 > birth_month || birth_month > 12) {
        cout << "Invalid Month Input!";
        return 0;
    }

    cout << "Enter the year for which you wish to know your age:" << endl;
    cin >> year;

    cout << "Enter the month in the year for which you wish to know your age:" << endl;
    cin >> month;
    if (1 > month || month > 12) {
        cout << "Invalid Month Input!";
        return 0;
    }

    int birth_year = cur_year - cur_age;
    if (cur_month < birth_month) {
        birth_year -= 1;
    }
    int months_lived = (year * 12 + month) - (birth_year * 12 + birth_month);
    int year_age = months_lived / 12;
    int month_age = months_lived % 12;
    if (months_lived < 0) {
        cout << "You were not born!";
        return 0;
    }
    cout << "Your age in " << year << "/" << month << ":" << endl;
    if (year_age > 1) {
        if (month_age > 1) {
            cout << year_age << " years and " << month_age << " months" << endl;
        } else {
            cout << year_age << " years and " << month_age << " month" << endl;
        }
    } else {
        if (month_age > 1) {
            cout << year_age << " year and " << month_age << " months" << endl;
        } else {
            cout << year_age << " year and " << month_age << " month" << endl;
        }
    }
    if (year_age % 2 == 1 && month_age % 2 == 1) {
        cout << "Both of " << year_age << " and " << month_age << " are odd!" << endl;
    } else if (year_age % 2 == 1) {
        cout << year_age << " is odd!" << endl;
    } else if (month_age % 2 == 1) {
        cout << month_age << " is odd!" << endl;
    } else {
        cout << "Both of " << year_age << " and " << month_age << " are not odd!" << endl;
    }
    return 0;
}
