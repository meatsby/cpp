#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int N = 6;
    char course[6][50] = {"Mathematics",
                          "English",
                          "Data structures",
                          "C++ Programming",
                          "Internet",
                          "Java Programming"};

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > i; j--) {
            if (strcmp(course[j - 1], course[j]) > 0) {
                char tmp[50];
                strcpy(tmp, course[j]);
                strcpy(course[j], course[j - 1]);
                strcpy(course[j - 1], tmp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << course[i] << endl;
    }

    return 0;
}
