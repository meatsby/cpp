#include <iostream>
#include "today.h"

bool isLeapYear(int year);

bool isValidDate(int year, int month, int day);

bool isFuture(int year, int month, int day);

bool isValidInput(int year, int month, int day);

void printDay(int day);

void printMonth(int month);

void printBirthday(int year, int month, int day);

void printLuckyNumber(int year, int month, int day);

using namespace std;

int main() {
    int year, month, day;

    cout << "Please enter your birth date (yyyy mm dd) : ";
    cin >> year >> month >> day;

    if (!isValidInput(year, month, day)) {
        return 0;
    }

    printBirthday(year, month, day);

    printLuckyNumber(year, month, day);

    return 0;
}

void printLuckyNumber(int year, int month, int day) {
    int luckyNum = year / 1000 + year % 1000 / 100 + year % 100 / 10 + year % 10
                   + month / 10 + month % 10 + day / 10 + day % 10;
    while (luckyNum > 9) {
        luckyNum = luckyNum / 10 + luckyNum % 10;
    }
    cout << "Your lucky number is " << luckyNum << "." << endl;
}

void printBirthday(int year, int month, int day) {
    int cyy = ThisYear();
    int cmm = ThisMonth();
    int cdd = ThisDay();
    if (year == cyy && month == cmm && day == cdd) {
        cout << "Happy Birthday!!" << endl;
        return;
    }
    cout << "Your birthday was on " << day;
    printDay(day);
    printMonth(month);
    cout << year << "." << endl;
}

void printMonth(int month) {
    switch (month) {
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "February ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "August ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << "October ";
            break;
        case 11:
            cout << "November ";
            break;
        case 12:
            cout << "December ";
    }
}

void printDay(int day) {
    switch (day) {
        case 1:
        case 21:
        case 31:
            cout << "st ";
            break;
        case 2:
        case 22:
            cout << "nd ";
            break;
        case 3:
        case 23:
            cout << "rd ";
            break;
        default:
            cout << "th ";
    }
}

bool isValidInput(int year, int month, int day) {
    if (year <= 1900) {
        cout << "Year not in range!!";
        return false;
    }
    if (!isValidDate(year, month, day)) {
        cout << "Invalid date!!";
        return false;
    }
    if (isFuture(year, month, day)) {
        cout << "You are not born yet!!";
        return false;
    }
    return true;
}

bool isFuture(int year, int month, int day) {
    int cyy = ThisYear();
    int cmm = ThisMonth();
    int cdd = ThisDay();
    if (year > cyy) {
        return true;
    }
    if (year == cyy && month > cmm) {
        return true;
    }
    if (year == cyy && month == cmm && day > cdd) {
        return true;
    }
    return false;
}

bool isValidDate(int year, int month, int day) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (1 <= day && day <= 31) {
                break;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if (1 <= day && day <= 30) {
                break;
            }
        case 2:
            if (1 <= day && day <= 29) {
                if (!isLeapYear(year) && day == 29) {
                    return false;
                }
                break;
            }
        default:
            return false;
    }
    return true;
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}
