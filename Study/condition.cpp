#include <time.h>
#include <stdlib.h>
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

    for (int i = 0; i < 30; i++) {
        if (i >= 6 && i <= 10) {
            if (i == 7) {
                printf("%d", i);
                continue;
            }
            printf("%d", i);
        }
        if (i == 20) {
            printf("%d", i);
            break;
        }
    }

    srand(time(NULL));
    switch (int i = rand() % 3) {
        case 0:
            printf("rock");
            break;
        case 1:
            printf("paper");
            break;
        case 2:
            printf("scissor");
    }
    return 0;
}
