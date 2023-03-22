#include <iostream>

using namespace std;

void myFunc(char *myStr) {
    cout << sizeof(myStr); // 4 or 8, which is address depends on computer
}

int main() {
    char str[3];
    strcpy(str, "hi");
    cout << sizeof(str); // 3, which is size of array
    myFunc(str);
    return 0;
}
