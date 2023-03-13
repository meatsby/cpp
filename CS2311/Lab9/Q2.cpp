#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("Q2input.txt");

    int cCnt = 0, iCnt = 0, oCnt = 0;
    char c;
    while (fin >> c) {
        if (c == ' ') {
            continue;
        }
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            cCnt++;
        } else if ('0' <= c && c <= '9') {
            iCnt++;
        } else {
            oCnt++;
        }
    }
    cout << "The number of characters is " << cCnt << endl;
    cout << "The number of integer numbers is " << iCnt << endl;
    cout << "The number of other characters is " << oCnt << endl;

    fin.close();
    return 0;
}
