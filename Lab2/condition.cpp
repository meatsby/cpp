#include <stdio.h>

int main() {
    int age = 15;
    if (age >= 20) {
        printf("Adult");
    } else {
        printf("Student");
    }

    age = 25;
    if (age >= 8 && age <= 13) {
        printf("elementary");
    } else if (age >= 14 && age <= 16) {
        printf("middle school");
    } else if (age >= 17 && age <= 19) {
        printf("high school");
    } else {
        printf("Adult");
    }
    return 0;
}
