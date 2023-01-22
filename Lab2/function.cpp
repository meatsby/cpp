#include <stdio.h>

void print(int num);

int main() {

    int num = 2;
    print(num);
    return 0;
}

void print(int num) {
    printf("%d\n", num);
}
