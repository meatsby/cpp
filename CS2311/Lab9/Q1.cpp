#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin;
    ofstream fout;
    fin.open("Q1input.txt");
    fout.open("Q1output.txt");

    int arr[10] = {0};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        fin >> arr[i];
        sum += arr[i];
    }
    cout << "Sum of ";
    fout << "Sum of ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
        fout << arr[i] << " ";
    }
    cout << "is " << sum;
    fout << "is " << sum;

    fin.close();
    fout.close();
    return 0;
}
