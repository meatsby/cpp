#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        printf("Hello world %d\n", i);
    }

    int i = 1;
    while (i <= 10) {
        printf("Hello world %d\n", i++);
    }
    return 0;
}
