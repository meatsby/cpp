#include <cstdio>

int main() {
    // integer variable
    int age = 13;
    printf("%d\n", age);

    // float variable
    float f = 46.5f;
    printf("%.2f\n", f);
    double d = 4.428;
    printf("%.2lf\n", d);

    // constant
    const int YEAR = 2000;
    printf("%d\n", YEAR);

    // scanf
    int one, two, three;
    printf("input : ");
    scanf("%d %d %d", &one, &two, &three);
    printf("%d %d %d\n", one, two, three);

    char str[256];
    scanf("%s", str, sizeof(str));
    printf("%s\n", str);
    return 0;
}
