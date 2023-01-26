#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    printf("address : %d, value : %d\n", &a, a);
    printf("address : %d, value : %d\n", &b, b);
    printf("address : %d, value : %d\n", &c, c);

    int * pointer_var;
    pointer_var = &a;
    printf("address : %d, value : %d\n", pointer_var, *pointer_var);

    *pointer_var *= 3;
    printf("address : %d, value : %d\n", pointer_var, *pointer_var);
    printf("address : %d, value : %d\n", &pointer_var, pointer_var);
    return 0;
}
