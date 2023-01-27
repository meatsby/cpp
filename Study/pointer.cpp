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

    int arr[3] = {5, 10, 15};
    int * ptr = arr;
    for (int i = 0; i < 3; i++) {
        printf("배열 값 : %d\n", arr[i]);
        printf("포인터 값 : %d\n", ptr[i]);
    }
    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;
    for (int i = 0; i < 3; i++) {
        printf("배열 값 : %d\n", arr[i]);
        printf("포인터 값 : %d\n", ptr[i]);
    }
    return 0;
}
