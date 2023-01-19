#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        printf("Hello world %d\n", i);
    }

    int i = 1;
    while (i <= 10) {
        printf("Hello world %d\n", i++);
    }

    i = 1;
    do {
        printf("Hello world %d\n", i++);
    } while (i <= 10);

    for (int j = 2; j < 10; j++) {
        for (int k = 2; k < 10; k++) {
            printf("%d x %d = %d\n", j, k, j * k);
        }
    }

    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < j; k++) {
            printf("*");
        }
        printf("\n");
    }

    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5 - j; k++) {
            printf(" ");
        }
        for (int k = 0; k < j; k++) {
            printf("*");
        }
        printf("\n");
    }

    int floor = 5;
    for (int i = 0; i < floor; i++) {
        for (int j = 0; j < floor - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < (i * 2) + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
