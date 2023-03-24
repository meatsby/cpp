#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char b[100] = "Hello World";
    char *buf = &b[1];
    strcpy(buf, "World");
    cout << b << endl;
    cout << buf << " " << sizeof(buf) << endl;
    return 0;
}
