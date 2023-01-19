#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    srand(time(NULL));
    int num = rand() % 3 + 1;
    printf("%d", num);
    return 0;
}
