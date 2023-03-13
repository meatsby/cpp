#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char str[15];
    cout << "Enter file name (maximum of 15 characters):" << endl;
    cin.getline(str, 15);

    ifstream fin;
    ofstream fout;
    fin.open(str);
    fout.open("Q3output.txt");

    int arr[26] = {0};
    char c;
    while (fin >> c) {
        if (c == ' ') {
            continue;
        }
        if ('a' <= c && c <= 'z') {
            arr[c - 97]++;
        }
        if ('A' <= c && c <= 'Z') {
            arr[c - 65]++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) {
            cout << "The occurrence of '" << char(i + 97) << "' is " << arr[i] << endl;
            fout << char(i + 97) << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
