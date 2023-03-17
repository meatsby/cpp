#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    fin.open("list.txt");
    int cnt = 0, next;
    while (fin >> next) {
        cnt++;
        cout << next << endl;
    }
    fin.close();
    cout << cnt;
    return 0;
}
