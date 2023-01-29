#include <stdio.h>

void swap(int a, int b);

void changeArray(int * ptr);

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    printf("address : %d, value : %d\n", &a, a);
    printf("address : %d, value : %d\n", &b, b);
    printf("address : %d, value : %d\n", &c, c);

    int *pointer_var;
    pointer_var = &a;
    printf("address : %d, value : %d\n", pointer_var, *pointer_var);

    *pointer_var *= 3;
    printf("address : %d, value : %d\n", pointer_var, *pointer_var);
    printf("address : %d, value : %d\n", &pointer_var, pointer_var);

    int arr[3] = {5, 10, 15};
    int *ptr = arr;
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

    int x = 10;
    int y = 20;
    printf("Before swap = a : %d, b : %d\n", x, y);
    swap(a, b);
    printf("After swap = a : %d, b : %d\n", x, y);

    int arr2[3] = {10, 20, 30};
    changeArray(arr2);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", arr2[i]);
    }

    return 0;
}

void changeArray(int * ptr) {
    ptr[2] = 50;
}

void swap(int a, int b) {
    printf("Swap 내부 a 의 주소 : %d\n", &a);
    printf("Swap 내부 b 의 주소 : %d\n", &b);

    int temp = a;
    a = b;
    b = temp;
    printf("Inside swap = a : %d, b : %d\n", a, b);
}
